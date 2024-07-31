/* Dado tres numeros enteros, encuentra el mayor */
#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Introduce tres numeros separados por espacios: ";
    cin >> a >> b >> c;

    int mayor = a;
    if (b > mayor) {
        mayor = b;
    }
    if (c > mayor) {
        mayor = c;
    }

    cout << "El mayor de " << a << ", " << b << " y " << c << " es: " << mayor << endl;

    return 0;
}
