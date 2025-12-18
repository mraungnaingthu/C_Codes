#include <stdio.h>
#include <string.h>
// Define a struct to hold book details
struct Book {
  int id;
  char title[50];
  char author[50];
  int year;
};

void addBook(struct Book book[], int *size, int maxBooks);
void displayBook(struct Book book[], int size);
void deleteBook(struct Book book[], int *size, int bookID);
void searchBook(struct Book book[], int size, int bookID);

int main() {
  struct Book book[50]; // Increased capacity to handle multiple books
  int bookCount = 0;    // Tracks the current number of books
  int maxBooks = 50;    // Maximum allowed books
  int deleteID, searchID;
  int choice = -1;      // Initialize choice to avoid undefined behavior

  while (choice != 0) {
    printf("\n1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Delete Book\n");
    printf("4. Search Book\n");
    printf("0. Exit\n\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume the leftover newline character

    switch (choice) {
      case 1:
        // Add books using the addBook function
        addBook(book, &bookCount, maxBooks);
        break;
      case 2:
        // Display the book details using the displayBook function
        displayBook(book, bookCount);
        break;
      case 3:
        // Delete books by their respective ID
        printf("\nEnter book ID to delete: ");
        scanf("%d", &deleteID);
        deleteBook(book, &bookCount, deleteID);
        break;
      case 4:
        // Search for a book by ID
        printf("\nEnter book ID to search: ");
        scanf("%d", &searchID);
        searchBook(book, bookCount, searchID);
        break;
      case 0:
        printf("\nExiting... Thank you for using the program.\n");
        break;
      default:
        printf("\nInvalid Choice! Try again...\n");
        break;
    }
  }

  return 0;
}

void addBook(struct Book book[], int *size, int maxBooks) {
  if (*size >= maxBooks) {
    printf("\nBook list is full. Cannot add more books.\n");
    return;
  }

  int newBookId;
  printf("Enter Book ID: ");
  scanf("%d", &newBookId);
  getchar(); // Consume the leftover newline character

  for (int i = 0; i < *size; i++) {
    if (book[i].id == newBookId) {
      printf("\nBook with ID already exists. can't add duplicate\n");
      return;
    }
  }

  book[*size].id = newBookId;

  printf("Enter Book Title: ");
  fgets(book[*size].title, sizeof(book[*size].title), stdin);
  book[*size].title[strcspn(book[*size].title, "\n")] = '\0'; // Remove newline

  printf("Enter Book Author: ");
  fgets(book[*size].author, sizeof(book[*size].author), stdin);
  book[*size].author[strcspn(book[*size].author, "\n")] = '\0'; // Remove newline

  printf("Enter Book Year: ");
  scanf("%d", &book[*size].year);
  getchar(); // Consume the leftover newline character

  (*size)++; // Increment book count
  printf("\nBook added successfully!\n");
}

void displayBook(struct Book book[], int size) {
  if (size == 0) {
    printf("\nNo books available to display.\n");
    return;
  }

  for (int i = 0; i < size; i++) {
    printf("\nBook %d Details:\n", i + 1);
    printf("ID: %d\n", book[i].id);
    printf("Title: %s\n", book[i].title);
    printf("Author: %s\n", book[i].author);
    printf("Year: %d\n", book[i].year);
  }
}

void deleteBook(struct Book book[], int *size, int bookID) {
  int found = 0;

  for (int i = 0; i < *size; i++) {
    if (book[i].id == bookID) {
      found = 1;

      // Shift books left to fill the gap
      for (int j = i; j < *size - 1; j++) {
        book[j] = book[j + 1];
      }

      (*size)--; // Decrease the size
      printf("\nBook with ID %d deleted successfully.\n", bookID);
      return;
    }
  }

  if (!found) {
    printf("\nBook with ID %d not found.\n", bookID);
  }
}

void searchBook(struct Book book[], int size, int bookID) {
  for (int i = 0; i < size; i++) {
    if (book[i].id == bookID) {
      printf("\nBook Details:\n");
      printf("ID: %d\n", book[i].id);
      printf("Title: %s\n", book[i].title);
      printf("Author: %s\n", book[i].author);
      printf("Year: %d\n", book[i].year);
      return;
    }
  }

  printf("\nBook with ID %d not found.\n", bookID);
}