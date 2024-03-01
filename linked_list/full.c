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

// Print the linked list values
void printLinkedlist(struct node *p) {
    while (p != NULL) {
        printf("First Name: %s, Last Name: %s, Email: %s, Age: %d\n",
               p->firstName, p->lastName, p->email, p->age);
        p = p->next;
    }
}

// Add a new node in the middle of the linked list
void addInMiddle(struct node *head, int position, char *firstName, char *lastName, char *email, int age) {
    struct node *newNode = malloc(sizeof(struct node));
    strcpy(newNode->firstName, firstName);
    strcpy(newNode->lastName, lastName);
    strcpy(newNode->email, email);
    newNode->age = age;

    struct node *temp = head;
    for (int i = 2; i < position; i++) {
        if (temp->next != NULL) {
            temp = temp->next;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete the last element from the linked list
void deleteLastElement(struct node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        // List is empty or has only one element
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp = *head;
    struct node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL) {
        // If there is more than one node in the list
        prev->next = NULL;
    } else {
        // If there is only one node in the list
        free(temp);
        *head = NULL;
    }
}

 

int main() {
    // Initialize nodes
    struct node *head;
    struct node *one = malloc(sizeof(struct node));
    struct node *two = malloc(sizeof(struct node));
    struct node *three = malloc(sizeof(struct node));
    struct node *four = malloc(sizeof(struct node));
    struct node *five = malloc(sizeof(struct node));
    struct node *six = malloc(sizeof(struct node));
    struct node *seven = malloc(sizeof(struct node));
    struct node *eight = malloc(sizeof(struct node));
    struct node *nine = malloc(sizeof(struct node));
    struct node *ten = malloc(sizeof(struct node));
    

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

    strcpy(six->firstName, "Chununu");
    strcpy(six->lastName, "Arnu");
    strcpy(six->email, "chununi.arnu@example.com");
    six->age = 17;

    strcpy(seven->firstName, "Kalu");
    strcpy(seven->lastName, "musa");
    strcpy(seven->email, "kalu.musa@example.com");
    seven->age = 29;

    strcpy(eight->firstName, "Anthony");
    strcpy(eight->lastName, "locho");
    strcpy(eight->email, "anythony.locho@example.com");
    eight->age = 28;

    strcpy(nine->firstName, "Kevin");
    strcpy(nine->lastName, "Oyan");
    strcpy(nine->email, "kevin.oyan@example.com");
    nine->age = 22;

    strcpy(ten->firstName, "Denis");
    strcpy(ten->lastName, "LOrot");
    strcpy(ten->email, "denis.lorot@example.com");
    ten->age = 25;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = ten;
    ten->next = NULL;

    // Print original linked list
    head = one;
    printf("Original Linked List:\n");
    printLinkedlist(head);

    // Add a new node in the middle
    addInMiddle(head, 3, "NewFirstName", "NewLastName", "new.email@gmail.com", 35);

    // Print linked list after addition
    printf("\nLinked List after Adding in the Middle:\n");
    printLinkedlist(head);

    // Delete the last element
    deleteLastElement(&head);

    // Print linked list after deletion
    printf("\nLinked List after Deletion of Last Element:\n");
    printLinkedlist(head);

    // Free allocated memory
    free(one);
    free(two);
    free(three);
    free(four);
    free(five);
    free(six);
    free(seven);
    free(eight);
    free(nine);
    free(ten);

    return 0;
}
