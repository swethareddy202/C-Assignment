#include <stdio.h>

#define MAX_N 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maximalNetworkRank(int n, int cables[MAX_N][2]) {
    int connections[MAX_N] = {0};  // Array to store the count of connections for each lab
    int maxRank = 0;

    for (int i = 0; i < n; i++) {
        int lab1 = cables[i][0];
        int lab2 = cables[i][1];
        connections[lab1]++;
        connections[lab2]++;
    }

    for (int i = 0; i < n; i++) {
        int lab1 = cables[i][0];
        int lab2 = cables[i][1];
        int currentRank = connections[lab1] + connections[lab2] - 1;
        maxRank = max(maxRank, currentRank);
    }

    return maxRank;
}

int main() {
    int n;
    printf("Enter the number of labs: ");
    scanf("%d", &n);

    int cables[MAX_N][2];
    printf("Enter the connections between labs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cables[i][0], &cables[i][1]);
    }

    int result = maximalNetworkRank(n, cables);
    printf("Maximal network rank of the infrastructure: %d\n", result);

    return 0;
}