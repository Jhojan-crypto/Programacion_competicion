/* Dado un numero mostrar la suma de sus digitos */
#include <iostream>

using namespace std;

int main() {
    int numero;
    cout << "Introduce un numero: ";
    cin >> numero;

    int suma = 0;
    while (numero > 0) {
        suma += numero % 10;
        numero /= 10;
    }

    cout << "La suma de los digitos es: " << suma << endl;

    return 0;
}
