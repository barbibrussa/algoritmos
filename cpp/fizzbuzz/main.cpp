/**
 * Escribir un programa que muestre en pantalla los números del 1 al 100, sustituyendo los múltiplos
 * de 3 por la palabra “fizz”, los múltiplos de 5 por “buzz” y los múltiplos de ambos, es decir, los múltiplos
 * de 3 y 5 (o de 15), por la palabra “fizzbuzz”.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    for (int i = 1; i <= 100; ++i) {
        if (i%3 == 0 && i%5 == 0){
            cout << "fizzbuzz ";
        } else if(i%3 == 0){
            cout << "fizz ";
        } else if (i%5 == 0){
            cout << "buzz ";
        } else {
            cout << i << " ";
        }
    }
    return 0;
}
