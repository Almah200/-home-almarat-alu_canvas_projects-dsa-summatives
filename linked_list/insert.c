#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char firstName[50];
    char lastName[50];
    char email[100];
    int age;
    struct node *next;
};

void printLinkedlist(struct node *p) {
    while (p != NULL) {
        printf("First Name: %s, Last Name: %s, Email: %s, Age: %d\n",
               p->firstName, p->lastName, p->email, p->age);
        p = p->next;
    }
}

void insertInMiddle(struct node **head, int position, char *firstName, char *lastName, char *email, int age) {
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    strcpy(newNode->firstName, firstName);
    strcpy(newNode->lastName, lastName);
    strcpy(newNode->email, email);
    newNode->age = age;

    if (position == 1) {
        // Insert at the beginning
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *temp = *head;

    for (int i = 2; i < position; i++) {
        if (temp->next != NULL) {
            temp = temp->next;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    struct node *head = NULL;

    // Initialize nodes
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *four = NULL;
    struct node *five = NULL;

    // Allocate memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    four = malloc(sizeof(struct node));
    five = malloc(sizeof(struct node));

    // Assign values
    strcpy(one->firstName, "Almarat");
    strcpy(one->lastName, "Ngutulu");
    strcpy(one->email, "almarat.arnu@example.com");
    one->age = 25;

    strcpy(two->firstName, "Hephziba");
    strcpy(two->lastName, "Ihesi");
    strcpy(two->email, "hephsiba.ihesi@example.com");
    two->age = 30;

    strcpy(three->firstName, "Abissa");
    strcpy(three->lastName, "Isaka");
    strcpy(three->email, "abissa.isaka@example.com");
    three->age = 22;

    strcpy(four->firstName, "Rammy");
    strcpy(four->lastName, "hessen");
    strcpy(four->email, "rammy.hessen@example.com");
    four->age = 21;

    strcpy(five->firstName, "Said");
    strcpy(five->lastName, "Omar");
    strcpy(five->email, "said.omar@example.com");
    five->age = 26;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = NULL;

    // Print linked list
    head = one;
    printf("Original Linked List:\n");
    printLinkedlist(head);

    // Insert a new node in the middle
    insertInMiddle(&head, 3, "John", "Doe", "john.doe@example.com", 28);

    // Print linked list after insertion
    printf("\nLinked List after Insertion:\n");
    printLinkedlist(head);

    // Free allocated memory
    free(one);
    free(two);
    free(three);
    free(four);
    free(five);

    return 0;
}