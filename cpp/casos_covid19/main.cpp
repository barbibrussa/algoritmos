/**
 * Se desea tener estadísticas acerca de los casos de COVID-19 en las provincias del país (se incluye a la Ciudad
 * Autónoma de Buenos Aires como si fuera una provincia más). En primera instancia se ingresan los datos
 * del código (numerado del 1 al 24) de cada provincia y su nombre. Luego se ingresan los datos de los pacientes
 * que dieron positivos de covid-19, solicitando el numero de dni, sexo (F y M), edad, la condicion que puede ser
 * A para aislado, I para internado y D para domiciliario; y el còdigo de departemento. El fin de datos se da con
 * dni = 0.
 * Se requiere saber
 * 1) Un listado de la cantidad de casos en cada condición por departamento
 *   Departamento      INTERNADO    AISLADO     DOMICILIO
 *      xxxx             xxxx         xxx          xxxx
 *      xxxx             xxxx         xxx          xxxx
 * 2) Un listado ordenado de forma ascendente por el total de casos positivos en cada departamento
 *   Departamento      Total
 *     xxxx             xxx
 *     xxxx             xxx
 * 3) Porcentaje de casos positivos de menores de trece años
 * 4) Cantidad de casos positivos de mujeres mayores a 80 años y de hombres menores a 75.
 */

#include <iostream>
#include <string>

using namespace std;

#define DEPARTAMENTOS 3

int main() {
    int codigo_departamento;
    string departamentos[DEPARTAMENTOS];
    string departamento;
    string auxiliar_nombres; //Para el ordenamiento
    int dni;
    int edad;
    string condicion;
    string sexo;

    //Variables para el punto 3 y 4
    int menores_trece;
    float porcentaje;
    int menores_75;
    int mayores_80;

    int datos_departamentos[DEPARTAMENTOS][3]; //Aca guardo por departamento la cantidad en cada condicion
    int total_departamentos[DEPARTAMENTOS]; //Acá guardo el total de casos en cada departamento
    int auxiliar; //Para el ordenamiento
    int contador_casos; //Para luego sacar el porcentaje

    //Pongo en 0 las matrices y variables contadoras
    for (int i = 0; i < DEPARTAMENTOS; ++i) {
        total_departamentos[i] = 0;
        for (int j = 0; j < 3; ++j) {
            datos_departamentos[i][j] = 0;
        }
    }

    menores_75 = 0;
    mayores_80 = 0;
    menores_trece = 0;
    contador_casos = 0;

    //Carga de datos de nombre y código de departamento
    cout << "-----------------------------------------------" << endl;
    cout << "      Carga de datos departamentos             " << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < DEPARTAMENTOS; ++i) {
        cout << "Ingrese el código de departamento" << endl;
        cin >> codigo_departamento;
        cout << "Ingrese el nombre del departamento de código: " << codigo_departamento << endl;
        cin.get();
        getline(cin, departamento);
        departamentos[codigo_departamento - 1] = departamento;
    }

    //Comienza la carga de datos
    cout << "-----------------------------------------------" << endl;
    cout << "      Carga de datos positivos COVID 19" << endl;
    cout << "-----------------------------------------------" << endl;

    cout << "Ingrese el número de dni" << endl;
    cin >> dni;
    while (dni != 0){
        cout << "Ingrese el sexo. 'F' para femenino y 'M' para masculino" << endl;
        cin.get();
        getline(cin, sexo);
        cout << "Ingrese la edad" << endl;
        cin >> edad;
        cout << "Ingrese la condicion. 'A' para aislado, 'I' para internado y 'D' para domiciliario" << endl;
        cin.get();
        getline(cin, condicion);
        cout << "Ingrese codigo de departamento" << endl;
        cin >> codigo_departamento;
        total_departamentos[codigo_departamento - 1] ++;

        if (condicion == "I"){
            datos_departamentos[codigo_departamento - 1][0] ++;
        } else if (condicion == "A"){
            datos_departamentos[codigo_departamento - 1][1] ++;
        } else if (condicion == "D"){
            datos_departamentos[codigo_departamento - 1][2] ++;
        }

        if (edad > 13 && edad < 75 && sexo == "M"){
            menores_75++;
        } else if (edad > 80 && sexo == "F"){
            mayores_80++;
        } else if (edad < 13) {
            menores_trece++;
        }

        contador_casos++;

        cout << "Ingrese el número de dni o 0 para finalizar" << endl;
        cin >> dni;

    }

    //Ordenamiento
    for (int i = 0; i < DEPARTAMENTOS - 1; ++i) {
        for (int j = 1; j < DEPARTAMENTOS; ++j) {
            if (total_departamentos[i] < total_departamentos[j]){
                auxiliar = total_departamentos[i];
                total_departamentos[i] = total_departamentos[j];
                total_departamentos[j] = auxiliar;

                auxiliar_nombres = departamentos[i];
                departamentos[i] = departamentos[j];
                departamentos[j] = auxiliar_nombres;
            }
        }

    }

    porcentaje = (menores_trece * 100) /contador_casos;

    //Punto 1
    cout << "Departamento \t\t" << "INTERNADO \t\t" << "AISLADO \t\t" << "DOMICILIO \t\t" << endl;
    for (int i = 0; i < DEPARTAMENTOS; ++i) {
        cout << departamentos[i] << "\t\t\t\t\t" << datos_departamentos[i][0] << "\t\t\t\t" << datos_departamentos[i][1] << "\t\t\t\t" << datos_departamentos[i][2] << endl;
    }

    //Punto 2
    cout << "Departamento \t\t" << "Total" << endl;
    for (int i = 0; i < DEPARTAMENTOS; ++i) {
        cout << departamentos[i] << "\t\t\t\t\t" << total_departamentos[i] << endl;
    }

    //Punto 3
    cout << "Porcentaje de menores de trece años: " << porcentaje << "%" << endl;

    //Punto 4
    cout << "Cantidad de mujeres mayores a 80 años: " << mayores_80 << endl;
    cout << "Cantidad de hombres menores a 75: " << menores_75 << endl;

    return 0;
}