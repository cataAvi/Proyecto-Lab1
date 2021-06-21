#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "funciones.h"
#include "rlutil.h"

/*
rlutil::cls(); // Limpia la consola
rlutil::setBackgroundColor(rlutil::LIGHTCYAN);// Dar color de fondo
rlutil::setColor(rlutil::LIGHTMAGENTA);// Dar color de letra

const int comienzoLinea = 18;

        gotoxy(32,comienzoLinea);
        cin >> fila;
        gotoxy(35,comienzoLinea+1);
        cin >> columna;                    //Posicionamiento en consola
        gotoxy(33,comienzoLinea+2);
        cin >> op;
        gotoxy(39,comienzoLinea+3);
        cin >> direccion;

*/

using namespace std;

void jugar (char nombrePuntajeMax [], int &puntajeMax);
void estadisticas (char [], int);
void creditos ();
void salir (char &rta);


int main()
{

    setlocale(LC_ALL, "Spanish");
    int opcion;
    char rta = 'N';
    char nombrePuntajeMax [45];
    int puntajeMax = -1;

    srand(time(NULL));

    divMathrixGame();
    rlutil::setColor(rlutil::WHITE);
    cout << "Presiona cualquier tecla para ir al menu  ";
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::anykey();

    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);

    while (rta == 'N')
    {
        rlutil::cls();
        mostrarMenu();
        cout << endl << "Ingrese el numero correspondiente a la opcion deseada: ";
        cin >> opcion;

        switch (opcion)
        {
        case 0:
            salir(rta);
            break;
        case 1:
            jugar(nombrePuntajeMax, puntajeMax);
            break;
        case 2:
            estadisticas(nombrePuntajeMax, puntajeMax);
            break;
        case 3:
            creditos();
            break;
        default:
            rlutil::setBackgroundColor(rlutil::GREY);
            rlutil::setColor(rlutil::RED);
            cout << endl << "                  =======================               " << endl;
            cout << "                           ERROR                        ";
            cout << endl << "                  =======================               ";
            cout << endl << "Opcion invalida, presione cualquier tecla para continuar";
            rlutil::anykey();
            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
            rlutil::setColor(rlutil::LIGHTMAGENTA);
            break;

        }




    }




    return 0;
}









// ----------------------------------------

void jugar (char nombrePuntajeMax [], int &puntajeMax)
{

    char opFinalJuego = 'N';

    while (opFinalJuego == 'N')
    {

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

        rlutil::cls();
        rlutil::setBackgroundColor(rlutil::WHITE);
        rlutil::setColor(rlutil::BLUE);
        cout << "=======================" << endl;
        rlutil::setColor(rlutil::BROWN);
        cout << "       JUGAR           ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << endl << "=======================" << endl;
        rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        divCalculadora();

        gotoxy(30,11);
        cout << "Ingrese su nombre: ";
        gotoxy(48,11);
        cin.ignore();
        cin.getline(vnombre, 45);


        cargarMatriz(matrizJugar, x, y);

        while (pilas > 0)
        {
            rlutil::cls();
            rlutil::setBackgroundColor(rlutil::WHITE);
            rlutil::setColor(rlutil::BLUE);
            cout << "=======================" << endl;
            rlutil::setColor(rlutil::BROWN);
            cout << "       JUGAR           ";
            rlutil::setColor(rlutil::LIGHTCYAN);
            cout << endl << "=======================" << endl;
            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
            rlutil::setColor(rlutil::LIGHTMAGENTA);

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
            while (operador != '+' && operador != '-' && operador != '*' && operador != '/' && operador != '%'){
                rlutil::setBackgroundColor(rlutil::GREY);
                rlutil::setColor(rlutil::RED);
                cout << "Ingreso invalido, vuelva a ingresar (operadores permitidos: '+' | '-' | '*' | '/' | '%' ): ";
                rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cin >> operador;
            }
            cout << endl << "Ingrese direccion: ";
            cin >> direccion;
            while (direccion != 8 && direccion != 2 && direccion != 4 && direccion != 6){
                rlutil::setBackgroundColor(rlutil::GREY);
                rlutil::setColor(rlutil::RED);
                cout << "Ingreso invalido, vuelva a ingresar (8 - Arriba | 2 - Abajo | 4 - Izquierda | 6 - Derecha): ";
                rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cin >> direccion;
            }


            switch (direccion)
            {
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

            if (validacionEspacios(matrizSombra, f1, c1, f2, c2, f3, c3) && validacionRango(f1, c1, f2, c2, f3, c3, x, y))
            {

                //cout << endl << "A: " << matrizJugar [f1][c1] << " B: " << matrizJugar [f2] [c2] << " C: " << matrizJugar [f3][c3];
                //cout << endl << "Valida?: " << validacionOperacion (matrizJugar, f1, c1, f2, c2, f3, c3, operador);

                if (validacionOperacion (matrizJugar, f1, c1, f2, c2, f3, c3, operador))
                {
                    puntaje += calcularPuntaje(matrizJugar, f1, c1, f2, c2, f3, c3);
                    borrarEspacios (matrizSombra, f1, c1, f2, c2, f3, c3);
                }
                else
                {
                    pilas --;
                }

            }

            else
            {

                pilas --;
                cout << endl <<  "Pilas: " << pilas;

            }


        }
        rlutil::cls();
        rlutil::setBackgroundColor(rlutil::CYAN);
        rlutil::setColor(rlutil::BLACK);
        cout << "_____________________________________________________________________" << endl;
        //rlutil::setBackgroundColor(rlutil::CYAN);
        rlutil::setColor(rlutil::BLACK);
        cout << "                                                                     " << endl;
        cout << "   ___|     \\      \\  |  ____|           _ \\ \\ \\     /  ____|   _ \\  " << endl;
        rlutil::setColor(rlutil::DARKGREY);
        cout << "  |        _ \\    |\\/ |  __|            |   | \\ \\   /   __|    |   | " << endl;
        rlutil::setColor(rlutil::DARKGREY);
        cout << "  |   |   ___ \\   |   |  |              |   |  \\ \\ /    |      __ <  " << endl;
        rlutil::setColor(rlutil::GREY);
        cout << " \\____| _/    _\\ _|  _| _____|         \\___/    \\_/    _____| _| \\_\\ " << endl;
        rlutil::setColor(rlutil::GREY);
        cout << "                                                                     " << endl;
        cout << "_____________________________________________________________________" << endl;
        cout << "                                                                     " << endl;
        rlutil::setColor(rlutil::BLUE);
        rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
        cout << endl << "Puntuacion final: " << puntaje;
        cout << endl;
        rlutil::setColor(rlutil::LIGHTMAGENTA);
        if (puntaje > puntajeMax){
            pasajeNombre (nombrePuntajeMax,vnombre);
            pasajePuntaje (puntajeMax, puntaje);
        }

        cout << endl << "'N' - New Game |  'M' - Back to Menu ";
        cin >> opFinalJuego;
        while (opFinalJuego != 'N' && opFinalJuego != 'M'){
            cout << "Opcion invalida, vuelva a imgresar";
            cin >> opFinalJuego;
        }


    }

}
// -------------------------------------------------

void estadisticas (char nombrePmax[], int pMax)
{
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLUE);
    cout << endl << "=======================" << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "     ESTADISTICAS      ";
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl << "=======================";
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);

char volver = 'N';
if (pMax == -1){
    cout << endl << endl << "Aun no se cargaron datos, intente jugar una partida";
}
else {
    cout << endl << endl << "El mayor puntaje fue de " << pMax << " obtenido por ";
    puts(nombrePmax);
}

while (volver != 'Y')
    {
        cout << endl << "Want to go back? ('N'- No, 'Y'- Yes)" << endl;
        cin >> volver;
    }
}

//-------------------------------------------------

void creditos ()
{
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLUE);
    cout << endl << "=======================" << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "      CREDITOS         ";
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl << "=======================";
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::BLACK);
    char volver = 'N';
    cout << endl;
    rlutil::setBackgroundColor(rlutil::RED);
    cout << endl << "        Why M, C, M?              ";
    rlutil::setBackgroundColor(rlutil::BROWN);
    cout << endl <<  "----------------------------------";
    rlutil::setBackgroundColor(rlutil::GREEN);
    cout << endl << "24464, Avila Rotela Catalina      ";
    rlutil::setBackgroundColor(rlutil::BLUE);
    cout << endl << "24495, Falduti Matias Nicolas     ";
    rlutil::setBackgroundColor(rlutil::MAGENTA);
    cout << endl << "24512, Illanes Saldivia Maria Jose" << endl;
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    while (volver != 'Y')
    {
        cout << endl << "Want to go back? ('N'- No, 'Y'- Yes)" << endl;
        cin >> volver;
    }
}

//---------------------------------------------------

void salir (char &rta)
{
    rlutil::cls();
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLUE);
    cout << endl << "=======================" << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "         SALIR         ";
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl << "=======================";
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::LIGHTMAGENTA);

    cout << endl << endl << "Exit? ('N'- No, 'Y'- Yes)";
    cout << endl;
    cin >> rta;
}




