#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x3f3f3f3f
#define MOD 1000000007

int n, c, a, b, x;
int dp[2][2222];
int f[2][2222];  // Arrays para armazenar os elementos de f[0] e f[1]
int size_f[2];   // Tamanho dos vetores f[0] e f[1]

// Função equivalente a lower_bound
int lower_bound(int arr[], int size, int value) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Função recursiva para calcular o valor mínimo
int go(int x, int i) {
    if (x < 0) return 0;
    if (dp[i][x]) return dp[i][x];
    
    int idx_a = lower_bound(f[i], size_f[i], f[i][x] - a) - 1;
    int idx_b = lower_bound(f[i], size_f[i], f[i][x] - b) - 1;

    int res_a = go(idx_a, i) + a;
    int res_b = go(idx_b, i) + b;

    return dp[i][x] = (res_a < res_b) ? res_a : res_b;
}

int main() {
    while (scanf("%d%d%d%d", &n, &c, &a, &b) != EOF) {
        size_f[0] = 0;
        size_f[1] = 0;

        // Lendo os valores e preenchendo f[0]
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            f[0][size_f[0]++] = x;
        }

        // Preenchendo f[1] com base em f[0]
        f[1][size_f[1]++] = f[0][n - 1];
        for (int i = 1; i < n; ++i) {
            f[1][size_f[1]++] = f[0][i - 1] + c;
        }

        // Resetando o array dp
        memset(dp, 0, sizeof(dp));

        // Imprimindo o resultado mínimo
        int result = (go(n - 1, 0) < go(n - 1, 1)) ? go(n - 1, 0) : go(n - 1, 1);
        printf("%d\n", result);
    }

    return 0;
}
