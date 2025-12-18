#include <stdio.h>
#include <string.h>

char arr[20][4][20] = {{}}; // Array to hold contacts.
int contactCount = 0;       // Tracks the current number of contacts.

// Function Declarations
void displayContact();
void addContact();
void deleteContact(int deleteID);
void searchContact(int searchID);
void writeToFile();
void readFromFile();

// Main Function
int main() {
    readFromFile(); // Load data from file at the start.

    int choice = -1; // Initialize choice
    while (choice != 0) {
        printf("\n1. Add Contact\n");
        printf("2. Display Contact\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("0. Exit\n\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline character

        switch (choice) {
        case 1:
            addContact();
            break;
        case 2:
            displayContact();
            break;
        case 3: {
            int searchID;
            printf("Enter contact ID to search: ");
            scanf("%d", &searchID);
            searchContact(searchID);
            break;
        }
        case 4: {
            int deleteID;
            printf("Enter contact ID to delete: ");
            scanf("%d", &deleteID);
            deleteContact(deleteID);
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

void addContact() {
    if (contactCount >= 20) {
        printf("Contact list is full!\n");
        return;
    }

    char id[20], name[20], phone[20], address[20];

    printf("Enter ID: ");
    scanf("%s", id);

    for (int i = 0; i < contactCount; i++) {
      if (strcmp(id, arr[i][0]) == 0) {
          printf("\nContact with ID already exists. can't add duplicate...\n");
          return;
      }
    }

    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Phone: ");
    scanf("%s", phone);
    printf("Enter Address: ");
    scanf("%s", address);

    strcpy(arr[contactCount][0], id);
    strcpy(arr[contactCount][1], name);
    strcpy(arr[contactCount][2], phone);
    strcpy(arr[contactCount][3], address);

    contactCount++;
    printf("Contact added successfully!\n");
    writeToFile(); // Update file with new contact.
}

void displayContact() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\nContacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("ID: %s\n", arr[i][0]);
        printf("Name: %s\n", arr[i][1]);
        printf("Phone: %s\n", arr[i][2]);
        printf("Address: %s\n\n", arr[i][3]);
    }
}

void searchContact(int searchID) {
    char searchIDStr[20];
    sprintf(searchIDStr, "%d", searchID); // Convert integer ID to string for comparison.

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(arr[i][0], searchIDStr) == 0) {
            printf("\nContact Found:\n");
            printf("ID: %s\n", arr[i][0]);
            printf("Name: %s\n", arr[i][1]);
            printf("Phone: %s\n", arr[i][2]);
            printf("Address: %s\n", arr[i][3]);
            return;
        }
    }

    printf("\nContact with ID %d not found.\n", searchID);
}

void deleteContact(int deleteID) {
    char deleteIDStr[20];
    sprintf(deleteIDStr, "%d", deleteID); // Convert integer ID to string for comparison.

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(arr[i][0], deleteIDStr) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                strcpy(arr[j][0], arr[j + 1][0]);
                strcpy(arr[j][1], arr[j + 1][1]);
                strcpy(arr[j][2], arr[j + 1][2]);
                strcpy(arr[j][3], arr[j + 1][3]);
            }

            contactCount--; // Reduce the count of contacts.
            writeToFile();  // Update the file after deletion.
            printf("Contact with ID %d deleted successfully.\n", deleteID);
            return;
        }
    }

    printf("Contact with ID %d not found.\n", deleteID);
}

void writeToFile() {
    FILE *file = fopen("contact.txt", "w");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s %s %s %s\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
    }

    fclose(file);
    printf("Data saved to file successfully.\n");
}

void readFromFile() {
    FILE *file = fopen("contact.txt", "r");
    if (!file) {
        printf("File not found. Starting with an empty contact list.\n");
        return;
    }

    contactCount = 0; // Reset contact count before loading.
    while (fscanf(file, "%s %s %s %s", arr[contactCount][0], arr[contactCount][1], arr[contactCount][2], arr[contactCount][3]) == 4) {
        contactCount++;
    }

    fclose(file);
}