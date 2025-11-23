#include <iostream>
#include <string>
using namespace std;

string provincias[25] = {
    "Azuay", "Bolivar", "Cañar", "Carchi", "Chimborazo", "Cotopaxi",
    "El Oro", "Esmeraldas", "Galápagos", "Guayas", "Imbabura", "Loja",
    "Los Ríos", "Manabí", "Morona Santiago", "Napo", "Orellana", "Pastaza",
    "Pichincha", "Santa Elena", "Santo Domingo de los Tsáchilas",
    "Sucumbíos", "Tungurahua", "Zamora Chinchipe", "  "
    };
int cantidad = 25;

void mostrarProvincias() {
    cout << "Listado de provincias:" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (provincias[i] != "") { 
            cout << i << " -> " << provincias[i] << endl;
        }
    }
}

void agregarProvincia(string nueva) {
    if (cantidad < 25) {
        provincias[cantidad] = nueva;
        cantidad++;
    } else {
        cout << "No se pueden agregar más provincias (arreglo lleno)." << endl;
    }
}

void cambiarProvincia(int indice, string nuevoNombre) {
    if (indice >= 0 && indice < cantidad) {
        provincias[indice] = nuevoNombre;
    } else {
        cout << "Índice inválido." << endl;
    }
}

void eliminarProvincia(int indice) {
    if (indice >= 0 && indice < cantidad) {
        provincias[indice] = ""; 
    } else {
        cout << "Índice inválido." << endl;
    }
}

int main() {
    mostrarProvincias();

    agregarProvincia("Guayas");
    agregarProvincia("Azuay");
    mostrarProvincias();

    cambiarProvincia(1, "Manabi");
    mostrarProvincias();

    eliminarProvincia(0);
    mostrarProvincias();

    return 0;
}


