#include <stdio.h>

int compress(char* chars, int charsSize) {
    if (charsSize == 0) return 0;
    
    int write_index = 0;
    int read_index = 0;
    
    while (read_index < charsSize) {
        char current_char = chars[read_index];
        int count = 0;
        

        while (read_index < charsSize && chars[read_index] == current_char) {
            count++;
            read_index++;
        }

        chars[write_index++] = current_char;

        if (count > 1) {
            // Convert count to string and write digit by digit
            char count_str[5];
            int len = sprintf(count_str, "%d", count);
            
            for (int i = 0; i < len; i++) {
                chars[write_index++] = count_str[i];
            }
        }
    }
    
    return write_index;
}

int main() {
    char chars[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int len = sizeof(chars) / sizeof(char);
    
    printf("Original: ");
    for (int i = 0; i < len; i++) {
        printf("%c ", chars[i]);
    }
    printf("\n");
    
    int new_length = compress(chars, len);
    
    printf("Compressed length: %d\n", new_length);
    printf("Compressed array: ");
    for (int i = 0; i < new_length; i++) {
        printf("%c ", chars[i]);
    }
    printf("\n");
    
    return 0;
}