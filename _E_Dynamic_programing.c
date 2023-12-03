#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void findOptimalChange(int coins[], int numCoins, int amount) {
    int dp[amount + 1];
    int parent[amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        parent[i] = -1;
    }

    for (int i = 0; i < numCoins; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX && dp[j - coins[i]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i]] + 1;
                parent[j] = i;
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        printf("No solution exists for the given amount using the provided coins.\n");
    } else {
        printf("Optimal change: ");
        while (amount > 0) {
            int coin = coins[parent[amount]];
            printf("%d ", coin);
            amount -= coin;
        }
        printf("\n");
    }
}

int main() {
    int coins[] = {1, 2, 5, 8, 10};
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int amount = 7;

    printf("Available coins: ");
    for (int i = 0; i < numCoins; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");

    printf("Change to be given: %d\n", amount);

    findOptimalChange(coins, numCoins, amount);

    return 0;
}
