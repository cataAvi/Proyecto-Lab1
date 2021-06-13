
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "funciones.h"

// -------------------------JUGAR---------------------------------

void cargarMatriz (int matriz [] [6],int xtam, int ytam){
    for (int x = 0; x<xtam; x++){
        for (int i = 0; i<ytam; i++){
            matriz [x][i] = rand()%9+1;
        }
    }

}

void mostrarMatriz (int matriz [] [6], bool matrizb [][6], int xtam, int ytam){
    for (int x = 0; x<xtam; x++){
        cout << endl;
        for (int i = 0; i<ytam; i++){
            if (!matrizb [x][i]){
                cout << matriz [x][i] << " ";
            }
            else {
                cout << "X ";
            }


        }
    }
    cout << endl;

}

bool validacionOperacion (int matriz [][6],int f1, int c1, int f2, int c2, int f3, int c3, char op){

    switch(op){
        case '+':
            if (matriz [f1] [c1] + matriz [f2] [c2] == matriz [f3] [c3]){
                //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
                return true;
            }
            else {
                return false;
            }
            break;
        case '-':
            if (matriz [f1] [c1] - matriz [f2] [c2] == matriz [f3] [c3]){
                //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
                return true;
            }
            else {
                return false;
            }
            break;
        case '*':
            if (matriz [f1] [c1] * matriz [f2] [c2] == matriz [f3] [c3]){
                //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
                return true;
            }
            else {
                return false;
            }
            break;
        case '/':
            if (matriz [f1] [c1] / matriz [f2] [c2] == matriz [f3] [c3]){
                //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
                return true;
            }
            else {
                return false;
            }
            break;
        case '%':
            if (matriz [f1] [c1] % matriz [f2] [c2] == matriz [f3] [c3]){
                //cout << endl << "A: " matriz [f1][c1] << "B: " << matriz [f2] [c2] << "C: " << matriz [f3][c3];
                return true;
            }
            else {
                return false;
            }
            break;
        default:
            cout << "Default";
            break;
    }




}

int calcularPuntaje (int matriz [] [6], int f1, int c1, int f2, int c2, int f3, int c3){
    int acu;
    acu = matriz [f1][c1] + matriz [f2][c2] + matriz [f3][c3];
    return acu;

}

void borrarEspacios  (bool matriz [] [6], int f1, int c1, int f2, int c2, int f3, int c3){
    matriz [f1][c1] = matriz [f2][c2] = matriz [f3] [c3] = true;

}

bool validacionEspacios (bool matrizb [][6], int f1 , int c1, int f2 , int c2, int f3, int c3){

    if (matrizb [f1][c1] || matrizb [f2][c2] || matrizb[f3][c3]){
        return false;
    }
    else {
        return true;
    }

}

bool rango (int valor, int maxi){
    if (valor >= 0 && valor<= maxi-1){
        return true;
    }
    else {
        return false;
    }
}

bool validacionRango (int f1, int c1, int f2, int c2, int f3, int c3, int xmax, int ymax){
    if ( rango (f1, xmax) && rango (f2, xmax) && rango (f3, xmax)){
        if (rango (c1, ymax) && rango (c2, ymax) && rango (c3, ymax)){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }

}

void mostrarInfo (char nombre [], int pilas, int ronda, int puntaje){
    cout << endl << "Nombre: ";
    puts (nombre);
    cout << "Cantidad de pilas: " << pilas;
    cout << endl << "Ronda numero " << ronda;
    cout << endl << "Puntaje: " << puntaje;
}

// -------------------------MENU---------------------------------

void mostrarMenu (){
    cout << endl << "MATRIX";
    cout << endl << "------------------------------";
    cout << endl << "1 - JUGAR";
    cout << endl << "2 - ESTADISTICAS";
    cout << endl << "3 - CREDITOS";
    cout << endl << "------------------------------";
    cout << endl << "0 - SALIR" << endl;
}


