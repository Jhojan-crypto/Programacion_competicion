/* Sumar dos numeros a + b */
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "Introduce el primer numero: ";
    cin >> a;
    cout << "Introduce el segundo numero: ";
    cin >> b;
    
    int suma = a + b;
    cout << "La suma de " << a << " y " << b << " es: " << suma << endl;
    
    return 0;
}
