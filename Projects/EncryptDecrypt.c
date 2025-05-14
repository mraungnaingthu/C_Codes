#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* encryptFun(const char* text, int shift);
char* decryptFun(const char* text, int shift);
void writeToFile(const char* data);
char* readFromFile(const char *filename);


int main() {
  int shift = 3; // Example shift value
  char inputText[2000];
  printf("Enter data to encrypt: ");
  fgets(inputText, sizeof(inputText), stdin);

  inputText[strcspn(inputText, "\n")] = 0;

  //Function call to encrypt data
  char* encryptKey = encryptFun(inputText, shift);
  printf("Encrypted key: %s\n", encryptKey);
  writeToFile(encryptKey);
  printf("Encrypted keys are saved to the file successfully.\n\n");

  char filename[256]; // Buffer for the filename
  // Prompt user for the filename
  printf("Please enter encrypt file name to decrypt data: ");
  fgets(filename, sizeof(filename), stdin);

  // Remove newline character from filename (if exists)
  size_t len = strlen(filename);
  if (len > 0 && filename[len - 1] == '\n') {
    filename[len - 1] = '\0';
  }

  char *fileContent = readFromFile(filename);
  //Function call to decrypt data
  char* decryptKey = decryptFun(fileContent, shift);
  printf("Decrypted key: %s\n", decryptKey);
  writeToFile(decryptKey);
  printf("Decrypted keys are saved to the file successfully.\n\n");


  return 0;
}

char* encryptFun(const char* text, int shift) {
  static char result[2000];

  for (int i = 0; text[i] != '\0'; i++) {
    char c = text[i];
    if (isalpha(c)) {
      if (isupper(c)) {
        result[i] = ((c - 'A' + shift) % 26) + 'A'; // Encrypt uppercase
      } else {
        result[i] = ((c - 'a' + shift) % 26) + 'a'; // Encrypt lowercase
      }
    } else {
      result[i] = c; // Non-alphabetic characters remain unchanged
    }
  }
  result[strlen(text)] = '\0'; // Null-terminate the result
  return result;
}

char* decryptFun(const char* text, int shift) {
  static char result[2000];

  for (int i = 0; text[i] != '\0'; i++) {
    char c = text[i];
    if (isalpha(c)) {
      if (isupper(c)) {
        result[i] = ((c - 'A' - shift + 26) % 26) + 'A'; // Decrypt uppercase
      } else {
        result[i] = ((c - 'a' - shift + 26) % 26) + 'a'; // Decrypt lowercase
      }
    } else {
      result[i] = c; // Non-alphabetic characters remain unchanged
    }
  }
  result[strlen(text)] = '\0'; // Null-terminate the result

  return result;
}

//Data Storage
void writeToFile(const char* data) {
  char filename[256]; // Buffer for the filename

  // Prompt user for the filename
  printf("Please enter encrypt/ decrypt file name: ");
  fgets(filename, sizeof(filename), stdin);

  // Remove newline character from filename (if exists)
  size_t len = strlen(filename);
  if (len > 0 && filename[len - 1] == '\n') {
    filename[len - 1] = '\0';
  }

  FILE *file = fopen(filename, "w");
  if (!file) {
    printf("Failed to open file for writing.\n");
    return;
  }

  fprintf(file, "%s", data);

  //close the file
  fclose(file);
}

// Function to read data from a file
char* readFromFile(const char *filename) {
  // Open the file in read mode ("r")
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  // Determine the file size
  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  rewind(file);

  // Allocate memory for the file content (+1 for null terminator)
  char *content = (char *)malloc(fileSize + 1);
  if (content == NULL) {
    perror("Memory allocation failed");
    fclose(file);
    exit(EXIT_FAILURE);
  }

  // Read the file into the allocated memory
  fread(content, 1, fileSize, file);
  content[fileSize] = '\0'; // Null-terminate the string

  // Close the file
  fclose(file);

  return content;
}
