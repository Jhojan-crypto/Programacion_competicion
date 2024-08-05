/* resolver el problema de la mochila */

#include <iostream>

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Haremos uso de la función knapsack, una tecnica de programación dinámica
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50; // Capacidad máxima de la mochila
    vector<int> weights = {10, 20, 30}; // Pesos de los ítems
    vector<int> values = {60, 100, 120}; // Valores de los ítems
    int n = weights.size(); // Número de ítems

    int max_value = knapsack(W, weights, values, n);
    cout << "El valor máximo que se puede obtener es: " << max_value << endl;

    return 0;
}
