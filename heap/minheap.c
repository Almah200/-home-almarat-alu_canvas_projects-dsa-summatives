// Build a Heap from an Array with C
#include <stdio.h>

// swap function
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Function to print the Heap as array
// will print as - 'message array[]\n'
void printArray(char message[], int arr[], int n)
{
    printf("%s ", message);

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// To heapify a subtree with node i as root
// Size of heap is n
void heapify(int arr[], int n, int i)
{
    int smallest = i; // Initialize smallest as root
    int leftChild = 2 * i + 1; // left child = 2*i + 1
    int rightChild = 2 * i + 2; // right child = 2*i + 2

    // If left child is smaller than root
    if (leftChild < n && arr[leftChild] < arr[smallest])
        smallest = leftChild;

    // If right child is smaller than new smallest
    if (rightChild < n && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    // If smallest is not the root
    if (smallest != i)
    {
        // swap root with the new smallest
        swap(&arr[i], &arr[smallest]);

        // Recursively heapify the affected sub-tree i.e., subtree with root as smallest
        heapify(arr, n, smallest);
    }
}

// Function to build a Min-Heap from a given array
void buildHeap(int arr[], int n)
{
    // Index of last non-leaf node
    int lastNonLeafNode = (n / 2) - 1;

    // Perform level order traversal in reverse from last non-leaf node to the root node and heapify each node
    for (int i = lastNonLeafNode; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// Driver Code
int main()
{
    // Array
   //int arr[] = {18, 17, 10, 19, 20, 14};
    int arr[] = {10, 14, 17, 18, 19, 20};

    // Size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray("Array is : ", arr, n);

    buildHeap(arr, n);
    printArray("Array representation of Heap is : ", arr, n);

    return 0;
}