/* Dado un arreglo de de enteros hallar el producto maximo de 3 numeros diferentes,
entrada : cantidad de numeros: 6, los numeros separados por espacios: 2,3,4,6,8,1
salida: El producto maximo de 3 numeros : 192
*/

#include <iostream>
#include <vector>
#include <algorithm>

int maxProductOfThree(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end()); // Ordenamos el arreglo

    int n = arr.size();

    // Consideramos el producto de los tres números más grandes
    int max1 = arr[n-1] * arr[n-2] * arr[n-3];

    // Consideramos el producto de los dos números más pequeños y el número más grande
    int max2 = arr[0] * arr[1] * arr[n-1];

    // Retornamos el mayor de los dos productos
    return std::max(max1, max2);
}

int main() {
    int n;
    std::cout << "Cantidad de numeros: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Introduce los numeros separados por espacios: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int result = maxProductOfThree(arr);
    std::cout << "El producto maximo de 3 numeros: " << result << std::endl;

    return 0;
}
