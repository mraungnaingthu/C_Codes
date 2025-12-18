#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char arr[20][2][MAX_LENGTH] = {{}}; // Array to hold words and definitions
int wordCount = 0;  // Tracks the number of words

// Function Declarations
void displayWords();
void addWord();
void deleteWord(char *word);
void searchWord(char *word);
void updateWord(char *word);
void writeToFile();
void readFromFile();

// Main Function
int main() {
    readFromFile(); // Load data from file at the start

    int choice = -1;
    while (choice != 0) {
        printf("\n1. Add Word\n");
        printf("2. Display Words\n");
        printf("3. Search Word\n");
        printf("4. Delete Word\n");
        printf("5. Update Word\n");
        printf("0. Exit\n\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline character

        switch (choice) {
        case 1:
            addWord();
            break;
        case 2:
            displayWords();
            break;
        case 3: {
            char searchWordInput[MAX_LENGTH];
            printf("Enter word to search: ");
            fgets(searchWordInput, MAX_LENGTH, stdin);
            searchWordInput[strcspn(searchWordInput, "\n")] = '\0';  // Remove newline
            searchWord(searchWordInput);
            break;
        }
        case 4: {
            char deleteWordInput[MAX_LENGTH];
            printf("Enter word to delete: ");
            fgets(deleteWordInput, MAX_LENGTH, stdin);
            deleteWordInput[strcspn(deleteWordInput, "\n")] = '\0';  // Remove newline
            deleteWord(deleteWordInput);
            break;
        }
        case 5: {
            char searchWordInput[MAX_LENGTH];
            printf("Enter word to search: ");
            fgets(searchWordInput, MAX_LENGTH, stdin);
            searchWordInput[strcspn(searchWordInput, "\n")] = '\0';  // Remove newline
            updateWord(searchWordInput);
            break;
        }
        case 0:
            printf("Exiting... Thank you for using the program.\n");
            break;
        default:
            printf("Invalid Choice! Try again...\n");
            break;
        }
    }

    return 0;
}

void addWord() {
    char word[MAX_LENGTH];
    char definition[MAX_LENGTH];

    // Read the word
    printf("Enter word: ");
    fgets(word, MAX_LENGTH, stdin);
    word[strcspn(word, "\n")] = '\0';  // Remove the newline character

    // Read the definition
    printf("Enter definition: ");
    fgets(definition, MAX_LENGTH, stdin);
    definition[strcspn(definition, "\n")] = '\0';  // Remove the newline character

    // Store the word and definition in the array
    strcpy(arr[wordCount][0], word);
    strcpy(arr[wordCount][1], definition);

    wordCount++;
    printf("Word added successfully!\n");
    writeToFile(); // Update file with new word.
}

void displayWords() {
    if (wordCount == 0) {
        printf("No words to display.\n");
        return;
    }

    for (int i = 0; i < wordCount; i++) {
        printf("Word: %s\n", arr[i][0]);
        printf("Definition: %s\n", arr[i][1]);
    }
}

void searchWord(char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(arr[i][0], word) == 0) {
            printf("\nWord found:\n");
            printf("Word: %s\n", arr[i][0]);
            printf("Definition: %s\n", arr[i][1]);
            return;
        }
    }
    printf("\nWord '%s' not found.\n", word);
}

void deleteWord(char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(arr[i][0], word) == 0) {
            // Shift elements to remove the word
            for (int j = i; j < wordCount - 1; j++) {
                strcpy(arr[j][0], arr[j + 1][0]);
                strcpy(arr[j][1], arr[j + 1][1]);
            }

            wordCount--;  // Decrease the word count
            writeToFile();  // Update the file after deletion
            printf("Word '%s' deleted successfully.\n", word);
            return;
        }
    }
    printf("Word '%s' not found.\n", word);
}

void updateWord(char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(arr[i][0], word) == 0) {
            printf("\nWord found to update:\n");
            printf("Current Word: %s\n", arr[i][0]);
            printf("Current Definition: %s\n", arr[i][1]);

            // Prompt user for new word
            char newWord[MAX_LENGTH];
            printf("\nEnter new word (or press Enter to keep the current word): ");
            fgets(newWord, MAX_LENGTH, stdin);
            newWord[strcspn(newWord, "\n")] = '\0';  // Remove newline character

            // If the user entered a new word, update it
            if (strlen(newWord) > 0) {
                strcpy(arr[i][0], newWord);
            }

            // Prompt user for new definition
            char newDefinition[MAX_LENGTH];
            printf("\nEnter new definition (or press Enter to keep the current definition): ");
            fgets(newDefinition, MAX_LENGTH, stdin);
            newDefinition[strcspn(newDefinition, "\n")] = '\0';  // Remove newline character

            // If the user entered a new definition, update it
            if (strlen(newDefinition) > 0) {
                strcpy(arr[i][1], newDefinition);
            }

            printf("\nWord updated successfully!\n");
            writeToFile();  // Save updated data to the file
            return;
        }
    }
    printf("\nWord '%s' not found.\n", word);
}

void writeToFile() {
    FILE *file = fopen("defination.txt", "w");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    for (int i = 0; i < wordCount; i++) {
        fprintf(file, "%s\n %s\n\n", arr[i][0], arr[i][1]);
    }

    fclose(file);
    printf("Data saved to file successfully.\n");
}

void readFromFile() {
    FILE *file = fopen("defination.txt", "r");
    if (!file) {
        printf("File not found. Starting with an empty definition list.\n");
        return;
    }

    wordCount = 0;

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file)) {
        // Trim any leading or trailing whitespace (including newlines)
        line[strcspn(line, "\n")] = '\0';

        // If the line is empty, skip it
        if (strlen(line) == 0) {
            continue;
        }

        // Read the word (line) into arr[wordCount][0]
        strcpy(arr[wordCount][0], line);

        // Read the definition (next line)
        if (fgets(line, MAX_LENGTH, file)) {
            line[strcspn(line, "\n")] = '\0';  // Remove newline from definition
            strcpy(arr[wordCount][1], line);
            wordCount++;
        } else {
            // If there is no definition after a word, break the loop
            break;
        }
    }

    fclose(file);
    printf("Data loaded from file successfully.\n");
}