/* Dado un numero determina si es par o impar */
#include <iostream>

using namespace std;

int main() {
    int numero;
    cout << "Introduce un numero: ";
    cin >> numero;

    if (numero % 2 == 0) {
        cout << numero << " es par." << endl;
    } else {
        cout << numero << " es impar." << endl;
    }

    return 0;
}
