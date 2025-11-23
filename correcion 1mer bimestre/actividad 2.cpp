#include <iostream>
#include <string>
using namespace std;

string nombres[] = {"Juan Garcia","Luis Coba","Ana Solis","Andy Salas"};
string cargos[]  = {"director","subdirector","analista","analista"};
int ids[]        = {104,103,102,101};
double sueldosBase[] = {2400,1560,1250,1250};
int cantidad = 4; 

void mostrarEmpleados(double sueldos[]) {
    cout << "Listado de empleados:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Nombre: " << nombres[i]
             << " | Cargo: " << cargos[i]
             << " | ID: " << ids[i]
             << " | Sueldo: " << sueldos[i] << endl;
    }
}

double promedioSalarial() {
    double suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += sueldosBase[i];
    }
    return suma / cantidad;
}

double sueldoMaximo() {
    double max = sueldosBase[0];
    for (int i = 1; i < cantidad; i++) {
        if (sueldosBase[i] > max) {
            max = sueldosBase[i];
        }
    }
    return max;
}

double* SalarioNeto() {
    static double sueldosNetos[4]; 
    for (int i = 0; i < cantidad; i++) {
        double descuentoSS = sueldosBase[i] * 0.0945; 
        double descuentoImp = sueldosBase[i] * 0.0765; 
        sueldosNetos[i] = sueldosBase[i] - descuentoSS - descuentoImp;
    }
    return sueldosNetos;
}

int main() {
    cout << "=== Empleados con sueldo base ===" << endl;
    mostrarEmpleados(sueldosBase);

    cout << "Promedio salarial: " << promedioSalarial() << endl;

    cout << "Sueldo mas alto: " << sueldoMaximo() << endl;

    double* netos = SalarioNeto();
    cout << "=== Empleados con sueldo neto ===" << endl;
    mostrarEmpleados(netos);

    return 0;
}

