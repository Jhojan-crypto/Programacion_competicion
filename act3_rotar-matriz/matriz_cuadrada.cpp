/* Dado una matriz cuadrada de nxn, escribe una funcion que rote
la matriz 90 grados en sentido horario y devuelve la matriz*/

#include <iostream>
#include <vector>
using namespace std;

void rotarMatriz90Grados(vector<vector<int>>& matriz) {
    int n = matriz.size();

    // Transponer la matriz
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matriz[i][j], matriz[j][i]);
        }
    }

    // Invertir las columnas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matriz[i][j], matriz[i][n - 1 - j]);
        }
    }
}

void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elem : fila) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matriz = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);

    rotarMatriz90Grados(matriz);

    cout << "Matriz rotada 90 grados en sentido horario:" << endl;
    imprimirMatriz(matriz);

    return 0;
}
