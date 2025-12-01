#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "contacts.dat"

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();

int main() {
    int choice;

    while (1) {
        printf("\n===============================\n");
        printf("     CONTACT MANAGEMENT\n");
        printf("===============================\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline

        switch (choice) {
        case 1:
            addContact();
            break;
        case 2:
            viewContacts();
            break;
        case 3:
            searchContact();
            break;
        case 4:
            editContact();
            break;
        case 5:
            deleteContact();
            break;
        case 6:
            printf("Exiting... Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addContact() {
    struct Contact c;
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0;

    printf("Enter Phone: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    fwrite(&c, sizeof(c), 1, fp);
    fclose(fp);

    printf("Contact added successfully!\n");
}

void viewContacts() {
    struct Contact c;
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    printf("\n------ All Contacts ------\n");
    while (fread(&c, sizeof(c), 1, fp)) {
        printf("\nName  : %s\n", c.name);
        printf("Phone : %s\n", c.phone);
        printf("Email : %s\n", c.email);
    }
    fclose(fp);
}

void searchContact() {
    struct Contact c;
    char searchName[50];
    int found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    printf("Enter name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcasecmp(c.name, searchName) == 0) {
            printf("\nContact Found!\n");
            printf("Name  : %s\n", c.name);
            printf("Phone : %s\n", c.phone);
            printf("Email : %s\n", c.email);
            found = 1;
            break;
        }
    }

    fclose(fp);
    if (!found) printf("Contact not found.\n");
}

void editContact() {
    struct Contact c;
    FILE *fp = fopen(FILE_NAME, "rb+");

    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    char nameToEdit[50];
    int found = 0;

    printf("Enter name of contact to edit: ");
    fgets(nameToEdit, sizeof(nameToEdit), stdin);
    nameToEdit[strcspn(nameToEdit, "\n")] = 0;

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcasecmp(c.name, nameToEdit) == 0) {
            printf("Editing Contact...\n");

            printf("Enter New Name : ");
            fgets(c.name, sizeof(c.name), stdin);
            c.name[strcspn(c.name, "\n")] = 0;

            printf("Enter New Phone: ");
            fgets(c.phone, sizeof(c.phone), stdin);
            c.phone[strcspn(c.phone, "\n")] = 0;

            printf("Enter New Email: ");
            fgets(c.email, sizeof(c.email), stdin);
            c.email[strcspn(c.email, "\n")] = 0;

            fseek(fp, -sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(c), 1, fp);

            printf("Contact updated successfully!\n");
            found = 1;
            break;
        }
    }

    fclose(fp);
    if (!found) printf("Contact not found.\n");
}

void deleteContact() {
    struct Contact c;
    char nameToDelete[50];
    int found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter name to delete: ");
    fgets(nameToDelete, sizeof(nameToDelete), stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = 0;

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcasecmp(c.name, nameToDelete) != 0) {
            fwrite(&c, sizeof(c), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("Contact deleted successfully!\n");
    else
        printf("Contact not found.\n");
}
