/* Escriba una funcion que tome un arreglo de enteros y un numero "k",
y determine si esxisten los numeros en el arreglo cuya suma sea igual a k*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool suma(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end()); // Ordenamos el arreglo

    int left = 0; // Inicializamos el puntero izquierdo
    int right = arr.size() - 1; // Inicializamos el puntero derecho

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) {
            return true;
        } else if (sum < k) {
            ++left; // Movemos el puntero izquierdo hacia la derecha
        } else {
            --right; // Movemos el puntero derecho hacia la izquierda
        }
    }
    return false;
}


int main() {
    vector<int> arr = {4, 1, 5, 2, 3};
    int k = 5;

    if (suma(arr, k)) {
        cout << "Si existen dos numeros en el arreglo cuya suma es igual a " << k << std::endl;
    } else {
        cout << "No existen dos numeros en el arreglo cuya suma es igual a " << k << std::endl;
    }

    return 0;
}
