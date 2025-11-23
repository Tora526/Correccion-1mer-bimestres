#include <iostream>
#include <string>
using namespace std;

string cedula, nombre;
int edad, tipoTarifa;
double saldo = 0;

double calcularCostoTarjeta() {
    return 0 + (0 * 0.15); 
}

double obtenerTarifaViaje(int tipo) {
    if (tipo == 1) return 0.22; 
    if (tipo == 2) return 0.45; 
    if (tipo == 3) return 0.22; 
    if (tipo == 4) return 0.10; 
    return 0.45;
}

bool validarTarifa(int tipo, int edad, bool carnetEst, bool carnetConadis) {
    if (tipo == 1) return (edad >= 5 && edad <= 18 && carnetEst);
    if (tipo == 2) return true;
    if (tipo == 3) return (edad >= 65);
    if (tipo == 4) return carnetConadis;
    return false;
}

void registrarUsuario() {
    cout << "*** REGISTRO DE USUARIO ***"<<endl;
    cout << "Ingrese cedula: ";
    cin >> cedula;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese edad: ";
    cin >> edad;

    cout << "Seleccione tipo de tarifa:"<<endl;
    cout << "1. Estudiante ($0.22)"<<endl;
    cout << "2. General ($0.45)"<<endl;
    cout << "3. Adulto Mayor ($0.22)"<<endl;
    cout << "4. Preferencial ($0.10)"<<endl;
    cout << "Opcion: ";
    cin >> tipoTarifa;

    bool carnetEst = false, carnetConadis = false;
    if (tipoTarifa == 1) {
        cout << "¿Tiene carnet estudiantil? (1=Sí, 0=No): ";
        int op; cin >> op; carnetEst = (op == 1);
    }
    if (tipoTarifa == 4) {
        cout << "¿Tiene carnet CONADIS? (1=Sí, 0=No): ";
        int op; cin >> op; carnetConadis = (op == 1);
    }

    if (validarTarifa(tipoTarifa, edad, carnetEst, carnetConadis)) {
        double costoTarjeta = calcularCostoTarjeta();
        double tarifaViaje = obtenerTarifaViaje(tipoTarifa);

        cout << "Costo de tarjeta ciudadana (incluye IVA): $" << costoTarjeta << endl;
        cout << "Costo de pasaje: $" << tarifaViaje << " por viaje"<<endl;
        cout << "Recarga inicial obligatoria: $1"<<endl;
        cout << "Saldo actual: $" << saldo << endl;
        cout << "Usuario registrado exitosamente."<<endl;
    } else {
        cout << "No cumple con los requisitos para la tarifa seleccionada."<<endl;
    }
}

void recargarTarjeta() {
    cout << "*** RECARGA DE TARJETA ***"<<endl;
    string ced;
    cout << "Ingrese numero de cedula: ";
    cin >> ced;

    if (ced == cedula) {
        cout << "Usuario: " << nombre << endl;
        cout << "Saldo actual: $" << saldo << endl;
        double monto;
        cout << "Ingrese monto a recargar (mínimo $1.00, máximo $100): $";
        cin >> monto;
        if (monto >= 1.00 && monto <= 100) {
            saldo += monto;
            cout << "Recarga exitosa. Saldo actual: $" << saldo << endl;
        } else {
            cout << "Monto invalido."<<endl;
        }
    } else {
        cout << "Usuario no encontrado."<<endl;
    }
}

void pagarPasaje() {
    cout << "*** PAGAR PASAJE ***"<<endl;
    string ced;
    cout << "Ingrese número de cedula: ";
    cin >> ced;

    if (ced == cedula) {
        double costo = obtenerTarifaViaje(tipoTarifa);
        cout << "Usuario: " << nombre << endl;
        cout << "Saldo actual: $" << saldo << endl;
        cout << "Costo de pasaje: $" << costo << endl;
        if (saldo >= costo) {
            saldo -= costo;
            cout << "Pasaje pagado exitosamente."<<endl;
            cout << "Saldo restante: $" << saldo << endl;
        } else {
            cout << "Saldo insuficiente."<<endl;
        }
    } else {
        cout << "Usuario no encontrado."<<endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "=== MENU METRO DE QUITO ==="<<endl;
        cout << "1. Registrar Usuario"<<endl;
        cout << "2. Recargar Tarjeta"<<endl;
        cout << "3. Pagar Pasaje"<<endl;
        cout << "4. Salir"<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) registrarUsuario();
        else if (opcion == 2) recargarTarjeta();
        else if (opcion == 3) pagarPasaje();
        else if (opcion == 4) cout << "Gracias por usar nuestro sistema."<<endl;
        else cout << "Opción invalida."<<endl;

    } while (opcion != 4);

    return 0;
}


