#include <stdio.h>

#define MAX 100

// Function to initialize the memoization array
void initialize(int memo[]) {
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;  // -1 indicates that the value has not been computed yet
    }
}

// Memoized Fibonacci function
int fibonacci(int n, int memo[]) {
    if (n == 0 || n == 1) {
        return n;
    }

    // If the value is already computed, return it
    if (memo[n] != -1) {
        return memo[n];
    }

    // Otherwise, compute and store the value
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);

    return memo[n];
}

int main() {
    int n;

    printf("Enter the number of terms\n");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    // Initialize the memoization array
    int memo[MAX];
    initialize(memo);

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i, memo));
    }

    return 0;
}