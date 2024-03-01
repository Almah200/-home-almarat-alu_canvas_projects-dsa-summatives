// Linked list implementation in C
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

// print the linked list value
void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("First Name: %s, Last Name: %s, Email: %s, Age: %d\n",
           p->firstName, p->lastName, p->email, p->age);
    p = p->next;
  }
}

int main() {
  // Initialize nodes
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;
  struct node *four = NULL;
  struct node *five = NULL;
  struct node *six = NULL;
  struct node *seven = NULL;
  struct node *eight = NULL;
  struct node *nine = NULL;
  struct node *ten = NULL;

  // Allocate memory
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));
  four = malloc(sizeof(struct node));
  five = malloc(sizeof(struct node));
  six = malloc(sizeof(struct node));
  seven = malloc(sizeof(struct node));
  eight = malloc(sizeof(struct node));
  nine = malloc(sizeof(struct node));
  ten = malloc(sizeof(struct node));

  // Assign value values
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

  // Print linked list
  //printLinkedlist(one);
  head = one;
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
