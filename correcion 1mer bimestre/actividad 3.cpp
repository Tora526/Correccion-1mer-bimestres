#include <iostream>
using namespace std;

void mostrarSerie(int cantidad) {
    int valor = 0;
    for (int i = 1; i <= cantidad; i++) {
        valor = (i * (i + 1)) / 2; 
        cout << valor << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos de la serie: ";
    cin >> n;

    cout << "Serie numerica: ";
    mostrarSerie(n);

    return 0;
}

