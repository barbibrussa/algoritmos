/**
* Una compañía le entregó a cada uno de sus 10 gerentes, un celular para poder comunicarse fácilmente. A
* cada celular se le acreditó un monto inicial diferente.
* Se ingresa, para cada uno de los 10 gerentes, los siguientes datos: código de gerente (1 a 10), nombre del
* gerente, monto inicial acreditado.
* Luego, se cargan los datos de las llamadas efectuadas por los gerentes en un mes:
* código de gerente y cantidad de llamadas y, por cada llamada realizada se ingresa: día, hora (0..23) y
* monto de la llamada.
* Se desea:
* a) Generar el siguiente listado:
* Cgo. Gerente    Nombre del gerente    Mto Asignado    Saldo
*    xxxxx             xxxxxxx             xxxxx         xxx
*    xxxxx             xxxxxxx             xxxxx         xxx
* b) Informar la cantidad de gerentes que superaron el monto inicial asignado
* c) El gerente que realizó el mayor gasto total en llamadas
**
*/

#include <iostream>
#include <string>

#define GERENTES 3

using namespace std;

int main() {
    int codigo, cantidad_llamadas, dia, hora, superaron_monto, gerente_mayor;
    float montos [GERENTES][3], monto_inicial, monto_llamada, gasto_mayor, monto;
    string gerentes[GERENTES], nombre;

    superaron_monto = 0;
    gasto_mayor = 0;

    cout << "***************************************" << endl;
    cout << " Carga de gerentes y montos asignados" << endl;
    cout << "***************************************" << endl;

    for (int i = 0; i < GERENTES; ++i) {
        cout << "Ingrese el codigo del gerente";
        cin >> codigo;
        cout << "Ingrese el nombre del gerente de codigo: " << codigo << endl;
        cin.get();
        getline(cin, nombre);
        gerentes[codigo - 1] = nombre;
        cout << "Ingrese el monto asignado al gerente de codigo: " << codigo << endl;
        cin >> monto;
        montos[codigo - 1][0] = monto;
        montos[codigo - 1][1] = 0;
        montos[codigo - 1][2] = 0;
    }

    cout << "****************************************************" << endl;
    cout << " Inicio de carga de llamadas de gerentes en el mes" << endl;
    cout << "****************************************************" << endl;

    cout << "Ingrese el codigo del gerente o 99 para salir" << endl;
    cin >> codigo;
    while (codigo != 99){
        cout << "Ingrese la cantidad de llamadas efectuadas por el gerente: " << codigo << endl;
        cin >> cantidad_llamadas;
        for (int i = 0; i < cantidad_llamadas; ++i) {
            cout << "Ingrese el día que realizó la llamada número: " << i + 1 << endl;
            cin >> dia;
            cout << "Ingrese la hora que realizó la llamada número: " << i + 1 << endl;
            cin >> hora;
            cout << "Ingrese el monto de la llamada número: " << i + 1 << endl;
            cin >> monto_llamada;
            montos[codigo - 1][1] += monto_llamada;
        }

        montos[codigo - 1][2] = montos[codigo - 1][0] - montos[codigo - 1][1];

        cout << "Ingrese el codigo del gerente o 99 para salir" << endl;
        cin >> codigo;
    }

    for (int i = 0; i < GERENTES; ++i) {
        if (montos[i][2] < 0){
            superaron_monto ++;
        }
        if (montos[i][1] > gasto_mayor){
            gasto_mayor = montos[i][1];
            gerente_mayor = i;
        }
    }

    cout << "*****************************************************************************" << endl;
    cout << "Código de Gerente \t \t Nombre Gerente \t \t Monto Asignado \t \t Saldo" << endl;
    for (int i = 0; i < GERENTES; ++i) {
        cout << "\t\t" << i + 1 << "\t\t\t\t\t"  << gerentes[i] << "\t\t\t\t\t" << montos[i][0] << "\t\t\t\t\t" << montos[i][2] << endl;
    }

    cout << "Cantidad de gerentes que superaron el monto asigando: " << superaron_monto << endl;
    cout << "El gerente de mayor gasto realizado es el de codigo: " << gerente_mayor + 1 << " Nombre: " << gerentes[gerente_mayor] << endl;

    cout << "*****************************************************************************" << endl;

    return 0;
}
