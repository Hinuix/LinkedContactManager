#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for contact
typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact *next;
} Contact;

// Function to create a new contact
Contact *createContact(char name[], char phone[]) {
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    if (newContact != NULL) {
        strcpy(newContact->name, name);
        strcpy(newContact->phone, phone);
        newContact->next = NULL;
    }
    return newContact;
}

// Function to add a contact to the end of the list
void addContact(Contact **head, Contact *newContact) {
    if (*head == NULL) {
        *head = newContact;
    } else {
        Contact *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newContact;
    }
}

// Function to print all contacts
void printContacts(Contact *head) {
    printf("Contact List:\n");
    while (head != NULL) {
        printf("Name: %s, Phone: %s\n", head->name, head->phone);
        head = head->next;
    }
}

int main() {
    Contact *head = NULL;
    char name[50], phone[15];
    int choice;

    while (1) {
        printf("\nContact Management System Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Print Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1:
                printf("Enter contact name: ");
                scanf("%[^\n]", name);
                getchar(); // Clear input buffer
                printf("Enter contact phone: ");
                scanf("%s", phone);
                getchar(); // Clear input buffer
                addContact(&head, createContact(name, phone));
                printf("Contact added successfully.\n");
                break;
            case 2:
                printContacts(head);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
