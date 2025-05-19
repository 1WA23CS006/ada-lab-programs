#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int profit[], int n) {
    int i, w;
    int K[n+1][W+1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(profit[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
            else
            K[i][w] = K[i-1][w];
        }
    }

    // Print the DP table
    printf("\nDP Table (Rows: Items, Columns: Knapsack Capacity):\n\n");
    printf("     ");
    for (w = 0; w <= W; w++)
        printf("%3d ", w);
    printf("\n");

    for (i = 0; i <= n; i++) {
        printf("i=%d ", i);
        for (w = 0; w <= W; w++) {
            printf("%3d ", K[i][w]);
        }
        printf("\n");
    }

    return K[n][W];
}

int main() {
    int profit[] = {60, 100, 120}; // profits (values)
    int wt[] = {10,20,30};         // weights
    int m = 50;                       // knapsack capacity
    int n = sizeof(profit) / sizeof(profit[0]);

    int result = knapsack(m, wt, profit, n);
    printf("\nMaximum profit in knapsack: %d\n", result);

    return 0;
}
