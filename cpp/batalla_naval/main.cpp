//
// Created by barbibrussa on 18/1/21.
//
/**Se han escrito las líneas de código necesarias para obtener una matriz
* NAVAL[5] [5], como muestra la figura.
* Agregue las líneas de código y las variables que considere necesarias para
* permitir determinar si un usuario, logra acertar la ubicación de las letras B
* (es decir, la ubicación de un barco en la batalla naval), de la siguiente
* manera:
* El usuario puede efectuar 3 ingresos de la dupla: FILA y COLUMNA
* Determine cuántas A y cuántas B acertó.
* Si el total de B es igual a 3, informe “BARCO HUNDIDO”.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string tablero[5][5];
    int fila, columna, aciertos_A, aciertos_B;

    aciertos_A = 0;
    aciertos_B = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            tablero[i][j] = "A";
        }
    }

    for (int i = 1; i < 4; ++i) {
        tablero[2][i] = "B";
    }

    cout << "BATALLA NAVAL" << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "Ingrese el número de fila: ";
        cin >> fila;
        cout << "Ingrese el número de columna: ";
        cin >> columna;

        if (tablero[fila][columna] == "B") {
            aciertos_B++;
            cout << "¡Le diste al barco! Fila: " << fila << " Columna: " << columna << endl;
        } else {
            aciertos_A++;
            cout << "¡Fallaste!" << endl;
        }

    }

    if (aciertos_B == 3) {
        cout << "BARCO HUNDIDO";
    } else {
        cout << "Tuviste " << aciertos_B << " aciertos ¡Sigue intentando!";
    }

    return 0;
}