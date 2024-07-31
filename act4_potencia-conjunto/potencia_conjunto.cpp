/*Dado un arreglo de enteros unicos,
genera tods los subconjuntos posibles (potencia de conjunto)*/

#include <iostream>
#include <vector>
using namespace std;

// Función para generar todos los subconjuntos
void generarSubconjuntos(vector<int>& nums, vector<int>& subconjuntoActual, int indice, vector<vector<int>>& todosLosSubconjuntos) {
    if (indice == nums.size()) {
        todosLosSubconjuntos.push_back(subconjuntoActual);
        return;
    }

    // Incluir el elemento en el subconjunto actual
    subconjuntoActual.push_back(nums[indice]);
    generarSubconjuntos(nums, subconjuntoActual, indice + 1, todosLosSubconjuntos);

    // No incluir el elemento en el subconjunto actual
    subconjuntoActual.pop_back();
    generarSubconjuntos(nums, subconjuntoActual, indice + 1, todosLosSubconjuntos);
}

vector<vector<int>> potenciaConjunto(vector<int>& nums) {
    vector<vector<int>> todosLosSubconjuntos;
    vector<int> subconjuntoActual;
    generarSubconjuntos(nums, subconjuntoActual, 0, todosLosSubconjuntos);
    return todosLosSubconjuntos;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> resultado = potenciaConjunto(nums);

    cout << "Todos los subconjuntos son:" << endl;
    for (const auto& subconjunto : resultado) {
        cout << "{ ";
        for (int num : subconjunto) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
