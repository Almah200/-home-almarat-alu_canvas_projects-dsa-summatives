#include <stdio.h>
#include <stdlib.h>

struct node {
   int size;
   struct node *leftChild;
   struct node *rightChild;
};
struct node *root = NULL;
void insert(int size){
   struct node *newNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   newNode->size = size;
   newNode->leftChild = NULL;
   newNode->rightChild = NULL;

//if tree is empty
   if(root == NULL) {
      root = newNode;
   } else {
      current = root;
      parent = NULL;
      while(1) {
         parent = current;

         //go to left of the tree
         if(size < parent->size) {
            current = current->leftChild;

            //insert to the left
            if(current == NULL) {
               parent->leftChild = newNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->rightChild;

            //insert to the right
            if(current == NULL) {
               parent->rightChild = newNode;
               return;
            }
         }
      }
   }
}

void inorder_traversal(struct node* root){
   if(root != NULL) {
      inorder_traversal(root->leftChild);
      printf("%d ",root->size);
      inorder_traversal(root->rightChild);
   }
}

void smallest(struct node *root) {
    while(root != NULL && root->leftChild != NULL) {
        root = root->leftChild;
    }
    printf("\nSmallest value is %d\n", root->size);
}
/*Delete minimal node*/
struct node* findSmallest(struct node* root) {
    while(root != NULL && root->leftChild != NULL) {
        root = root->leftChild;
    }
    return root;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;

    if (key < root->size)
        root->leftChild = deleteNode(root->leftChild, key);
    else if (key > root->size)
        root->rightChild = deleteNode(root->rightChild, key);
    else {
        if (root->leftChild == NULL) {
            struct node* temp = root->rightChild;
            free(root);
            return temp;
        } else if (root->rightChild == NULL) {
            struct node* temp = root->leftChild;
            free(root);
            return temp;
        }

        struct node* temp = findSmallest(root->rightChild);
        root->size = temp->size;
        root->rightChild = deleteNode(root->rightChild, temp->size);
    }

    return root;
}



int main(){
   int i;
   int array[20] = {20, 15, 8, 16, 4, 5, 9, 10, 13, 11, 12, 0, 14, 17, 19, 6, 18, 3, 2, 1};
   for(i = 0; i < 20; i++)
      insert(array[i]);

   printf("\nInorder traversal: ");
   inorder_traversal(root);
   
   smallest(root);
   
    root = deleteNode(root, findSmallest(root)->size);

   printf("\nAfter deletion of the smallest node:\n");
   printf("Inorder traversal: ");
   inorder_traversal(root);

   return 0;
}