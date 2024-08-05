/* resolver el problema de la mochila */

#include <iostream>

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Haremos uso de la funci�n knapsack, una tecnica de programaci�n din�mica
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
    int W = 50; // Capacidad m�xima de la mochila
    vector<int> weights = {10, 20, 30}; // Pesos de los �tems
    vector<int> values = {60, 100, 120}; // Valores de los �tems
    int n = weights.size(); // N�mero de �tems

    int max_value = knapsack(W, weights, values, n);
    cout << "El valor m�ximo que se puede obtener es: " << max_value << endl;

    return 0;
}
