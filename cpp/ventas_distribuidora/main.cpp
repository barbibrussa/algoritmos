/**
 * Una distribuidora de productos alimenticios libres de gluten, desea realizar un estudio estadístico.
 * Para ello, lo primero que ingresa  son los datos de los 150 prodcutos que comercializa: codigo producto (1 a 150)
 * y precio unitario. Estos datos se ingresan ordenados por codigo de producto. La distribuidora cuenta con 5
 * sucursales codificadas del 1 al 5
 * A continuación se ingresan los datos de las ventas realizadas es un periodo determinado, de los distintos
 * productos en las diferentes sucursales. Se ingresa: codigo de sucursal y cantidad de ventas realizadas y
 * por cada venta: codigo de producto y cantidad. Los datos de las ventas, son totales por producto, es decir,
 * un mismo producto, solo se ingresa una vez. Si puede suceder, que alguno de los productos no se haya vendido.
 * Estos datos se ingresan sin orden
 * Se desea:
 * 1)Determinar e informar en cuantas sucursales se vendió el prodcuto con código 88
 * 2)Informar el siguiente detalle, con los montos totales de ventas de la sucursal 2
 * Codigo de producto    Cantidad $     Monto Total
 *       xxxx               xxx            xxxx
 *       xxxx               xxx            xxxx
 * 3) Permitir el ingreso de un precio  unitario e informar, si existe, el codigo del producto que lo posee.
 * Caso contrario informar "Precio no hallado"
 */

#include <iostream>

using namespace std;

#define PRODUCTOS 150
#define SUCURSALES 5

int main() {
    int codigo_producto, sucursales, cantidad, cantidad_producto, cantidad_sucursal2[PRODUCTOS], bandera;
    float precio, precios_productos[PRODUCTOS], ventas_sucursal2[PRODUCTOS], precio_buscado;

    for (int i = 0; i < PRODUCTOS; ++i) {
        cantidad_sucursal2[i] = 0;
        ventas_sucursal2[i] = 0;
    }

    int ventas88 = 0;

    cout << "-------------------------------" << endl;
    cout << " Carga de precios de productos " << endl;
    cout << "-------------------------------" << endl;

    for (int i = 0; i < PRODUCTOS; ++i) {
        cout << "Ingrese el precio unitario del producto: " << i + 1 << endl;
        cin >> precio;
        precios_productos[i] = precio;
    }

    cout << "------------------------------" << endl;
    cout << " Carga de ventas por sucursal" << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; i < SUCURSALES; ++i) {
        cout << "Ingrese el código de la sucursal" << endl;
        cin >> sucursales;
        cout << "Ingrese la cantidad de ventas realizadas" << endl;
        cin >> cantidad;
        for (int j = 0; j < cantidad; ++j) {
            cout << "Ingrese el código del producto" << endl;
            cin >> codigo_producto;

            if (codigo_producto == 88){
                ventas88 ++;
            }
            cout << "Ingrese la cantidad vendida del producto " << codigo_producto << endl;
            cin >> cantidad_producto;

            if (sucursales == 2){
                cantidad_sucursal2[codigo_producto - 1] += cantidad_producto;
                ventas_sucursal2[codigo_producto - 1] = precios_productos[codigo_producto - 1]*cantidad_producto;
            }
        }
    }

    cout << "La cantidad de sucursales que vendieron el código de producto 88 es de: " << ventas88 << endl;

    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "                        Ventas sucursal 2                                      " << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    cout << "Código producto \t\t" << "Cantidad \t\t" << "Montos Totales" << endl;
    for (int i = 0; i < PRODUCTOS; ++i) {
        cout << "\t" << i + 1 << "\t\t\t\t\t\t" << cantidad_sucursal2[i] << "\t\t\t\t" << ventas_sucursal2[i] << endl;
    }

    cout << "Ingrese el precio a buscar" << endl;
    cin >> precio;
    bandera = 0;
    for (int i = 0; i < PRODUCTOS; ++i) {
        if (precio == precios_productos[i]){
            precio_buscado = precios_productos[i];
            bandera = 1;
            cout << "El precio:$" << precio_buscado << " fue hallado en el producto con código: " << i + 1 << endl;
            i = 999;
        }
    }

    if (bandera == 0){
        cout << "Precio no hallado";
    }

    return 0;

}


