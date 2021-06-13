#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "funciones.h"

using namespace std;

void jugar ();
void estadisticas ();
void creditos ();
void salir (char &rta);

int main()
{

    int opcion;
    char rta = 'N';

    srand(time(NULL));


    while (rta == 'N'){

        mostrarMenu();
        cout << "Ingrese el numero correspondiente a la opcion deseada: ";
        cin >> opcion;

        switch (opcion){
        case 0:
            salir(rta);
            break;
        case 1:
            jugar();
            break;
        case 2:
            estadisticas();
            break;
        case 3:
            creditos();
            break;
        default:
            cout << endl << "Opcion invalida, vuelva a ingresar";
            break;

        }




    }




return 0;
}









// ----------------------------------------

void jugar (){
    const int x = 6, y = 6;
    int matrizJugar [x][y];
    //Matriz Sombra
    bool matrizSombra [x][y] = {};
    //Entrada datos usuarios
    int f1, c1, f2, c2, f3, c3, direccion;
    char operador;
    //Pilas
    int pilas = 3;
    int puntaje = 0;
    //Nombre
    char vnombre [45]; // 45 son las letras del nombre mas largo del mundo: Nominchuluunukhaanzayamunkherdeneenkhtuguldur ;)
    int cantRondas = 0;


    cout << "Ingrese su nombre: ";
    cin.ignore();
    cin.getline(vnombre, 45);


    cargarMatriz(matrizJugar, x, y);

    while (pilas > 0){
        cantRondas ++;

        cout << endl;
        mostrarInfo (vnombre, pilas, cantRondas, puntaje);
        cout << endl;
        mostrarMatriz(matrizJugar,matrizSombra, x, y);
        cout << endl;

        cout << "Ingrese las coordenadas";
        cout << endl << "Fila: ";
        cin >> f1;
        f1 --;
        cout << "Columna: ";
        cin >> c1;
        c1 --;
        cout << endl << "Ingrese el operador: ";
        cin >> operador;
        cout << endl << "Ingrese direccion: ";
        cin >> direccion;


        switch (direccion){
        case 2:
            f2 = f1 + 1;
            f3 = f2 + 1;
            c2 = c3 = c1;
            break;
        case 4:
            c2 = c1 - 1;
            c3 = c2 - 1;
            f2 = f3 = f1;
            break;
        case 6:
            c2 = c1 + 1;
            c3 = c2 + 1;
            f2 = f3 = f1;
            break;
        case 8:
            f2 = f1 - 1;
            f3 = f2 - 1;
            c2 = c3 = c1;
            break;
        default:
            cout << "Opcion invalida";

        }

        if (validacionEspacios(matrizSombra, f1, c1, f2, c2, f3, c3) && validacionRango(f1, c1, f2, c2, f3, c3, x, y)){

            cout << endl << "A: " << matrizJugar [f1][c1] << " B: " << matrizJugar [f2] [c2] << " C: " << matrizJugar [f3][c3];
            cout << endl << "Valida?: " << validacionOperacion (matrizJugar, f1, c1, f2, c2, f3, c3, operador);

            if (validacionOperacion (matrizJugar, f1, c1, f2, c2, f3, c3, operador)){
                puntaje += calcularPuntaje(matrizJugar, f1, c1, f2, c2, f3, c3);
                borrarEspacios (matrizSombra, f1, c1, f2, c2, f3, c3);
            }
            else {
                pilas --;
                cout << endl << "Pilas: " << pilas;
            }

            cout << endl << "Puntaje: " << puntaje;

        }

        else {

         pilas --;
            cout << endl <<  "Pilas: " << pilas;

        }


    }

    cout << endl << "-----------------------------------------";
	cout << endl << endl << "               GAME OVER" << endl;
	cout << endl << "-----------------------------------------";
	cout << endl << "Puntuacion final: " << puntaje;
	cout << endl << endl;


}

// -------------------------------------------------

void estadisticas (){

}

//-------------------------------------------------

void creditos (){
    char volver = 'N';
    cout << endl << "    Why M, C, M?";
    cout << endl <<  "-----------------------";
    cout << endl << "24464, Avila Rotela Catalina";
    cout << endl << "24495, Falduti Matias Nicolas";
    cout << endl << "24512, Illanes Saldivia Maria Jose" << endl;
    while (volver != 'Y'){
    cout << endl << "Want to go back? ('N'- No, 'Y'- Yes)" << endl;
    cin >> volver;
    }
}

//---------------------------------------------------

void salir (char &rta){
    cout << endl << "Exit? ('N'- No, 'Y'- Yes)";
    cout << endl;
    cin >> rta;
}




