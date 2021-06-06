//TP n: Segundo Parcial
//Actividad: Test
//Comentarios:
/*

*/

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

void mostrar_matriz (int matrix [][6], bool matrixCasBloc [] [6], int, int);
void llenar_naleatorios (int matrix [][6], int, int);
void eliminar_espacios (bool matrixCasBloc [][6], int, int, int, int, int, int);
int calcular_puntaje (int matrix [][6], int, int, int, int, int, int);
bool validacion1 (bool matrixCasBloc [] [6], int, int, int, int, int, int); //No se puede elaborar una ecuación si no se dispone de tres celdas adyacentes válidas en la dirección que el usuario seleccione
bool validacion2 (int, int, int, int, int, int); //No se puede elaborar una ecuación si alguna de las celdas que intervienen en la misma se encuentran fuera de los rangos de la matriz
bool auxVal2 (int); //Verifica si los indicen se encuentran dentro del rango permitido


int main(){
    const int nfilas = 6, ncolumnas = 6;
	int matriz [nfilas] [ncolumnas]; // Matriz del juego
	bool casillasBloqueadas [nfilas][ncolumnas] = {};
	int i,x; // Variables para ciclos
	//Input del usuario
	int fila, columna;
	int fila2, columna2, fila3, columna3;
	char op; //Operador matematico
	int direccion;
	int a,b,c; //Referencia para la ecuacion
	bool correcto = false; //Flag para eleminar espacios
	int pilas = 3; //vidas-pilas
	bool primer_ingreso = true; //Flag para entrar al while
	int puntaje = 0;
	const int tamaniovPosC = 6; //Para no pedir tantos datos en las funciones que invoco, decidi almacenar las posiciones
	int vPosCas [tamaniovPosC]; // de las casillas en un vector.

	//Asigno numeros aleatorios a la matriz del juego
	llenar_naleatorios (matriz, nfilas, ncolumnas);


	//Muestro la matriz
	mostrar_matriz(matriz, casillasBloqueadas, nfilas, ncolumnas);


	while (primer_ingreso || pilas > 0){

        primer_ingreso = false;

        //Pido inputs al usuario
        cout << "Ingrese la fila del casillero: ";
        cin >> fila;
        fila --;
        cout << "Ingrese la columna del casillero: ";
        cin>> columna;
        columna--;
        cout << "Ingrese el operador matematico: ";
        cin >> op;
        cout << "Ingrese la direccion de la operacion: ";
        cin >> direccion;


        switch (direccion){
        case 8:
            fila2 = fila - 1;
            fila3 = fila - 2;
            columna2 = columna3 = columna;
        break;
        case 2:
            fila2 = fila + 1;
            fila3 = fila + 2;
            columna2 = columna3 = columna;
        break;
        case 4:
            fila2 = fila3 = fila;
            columna2 = columna - 1;
            columna3 = columna - 2;
        break;
        case 6:
            fila2 = fila3 = fila;
            columna2 = columna + 1;
            columna3 = columna + 2;
        break;
        }

        cout << endl << "Validacion 1: " << validacion1 (casillasBloqueadas, fila, fila2, fila3, columna, columna2, columna3);
        cout << endl<< "Validacion 2: " << validacion2 (fila, fila2, fila3, columna, columna2, columna3);


        switch (op){
        case '+':
            if (matriz [fila][columna] + matriz [fila2][columna2] == matriz [fila3][columna3]){
                correcto = true;
            }
            else {
                cout << endl << "Incorrecto";
            }
        break;
        case '-':
            if (matriz [fila][columna] - matriz [fila2][columna2] == matriz [fila3][columna3]){
                correcto = true;
            }
            else {
            cout << endl << "Incorrecto";
            }
        break;
        case '*':
            if (matriz [fila][columna] * matriz [fila2][columna2] == matriz [fila3][columna3]){
                correcto = true;
            }
            else {
            cout << endl << "Incorrecto";
            }
        break;
        case '/':
            if (matriz [fila][columna] / matriz [fila2][columna2] == matriz [fila3][columna3]){
                correcto = true;
            }
            else {
                cout << endl << "Incorrecto";
            }
        break;
        case '%':
            if (matriz [fila][columna] % matriz [fila2][columna2] == matriz [fila3][columna3]){
                correcto = true;
            }
            else {
                cout << endl << "Incorrecto";
            }
        break;
	}

        if (correcto){
            eliminar_espacios (casillasBloqueadas, fila, fila2, fila3, columna, columna2, columna3);
            puntaje += calcular_puntaje (matriz, fila, fila2, fila3, columna, columna2, columna3);
            cout << endl << "Puntaje: " << puntaje;
            correcto = false;
        }
        else {
            pilas --;
        }

        cout << endl;

        mostrar_matriz(matriz, casillasBloqueadas, nfilas, ncolumnas);
	}


	cout << endl << "-----------------------------------------";
	cout << endl << endl << "               GAME OVER" << endl;
	cout << endl << "-----------------------------------------";
	cout << endl << endl;



 return 0;
}

void llenar_naleatorios (int matrix [][6],int numfilas,int numcolum)
{
int i,x;
srand ((unsigned) time (0));
	for (i=0; i<numfilas; i++){
        for (x=0; x<numcolum; x++){
            matrix [i][x] = rand()%9;
        }
	}
}

void mostrar_matriz (int matrix [][6], bool matrixCasBloc [] [6], int numfilas, int numcolum)
{
int i, x;
for (i=0; i<numfilas; i++){
        for (x=0; x<numcolum; x++){
            if (!matrixCasBloc [i][x]){
                cout << matrix [i][x] << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
	}
}

void eliminar_espacios (bool matrixCasBloc [][6], int fi1, int fi2, int fi3, int colum1, int colum2, int colum3)
{
    matrixCasBloc [fi1] [colum1] = matrixCasBloc [fi2] [colum2] = matrixCasBloc [fi3] [colum3] = true;
}

int calcular_puntaje (int matrix [][6], int fi1, int fi2, int fi3, int colum1, int colum2, int colum3)
{
    int p = 0;
    p += matrix [fi1] [colum1] + matrix [fi2] [colum2] + matrix [fi3] [colum3];
    return p;
}

bool validacion1 (bool matrixCasBloc [] [6], int fi1, int fi2, int fi3, int colum1, int colum2, int colum3) //int fi1, int fi2, int fi3, int colum1, int colum2, int colum3)
{
    if (!matrixCasBloc [fi1][colum1] && !matrixCasBloc [fi2] [colum2] && !matrixCasBloc [fi3] [colum3]){
        return true; //Valida
    }

    else{
        return false; //No valida
    }

}

bool auxVal2 (int x){
    if (x >=0 && x <=5){
        return true;
    }
    else {
        return false;
    }
}

bool validacion2 (int fi1, int fi2, int fi3, int colum1, int colum2, int colum3)
{

   if (auxVal2(fi1) && auxVal2(fi2) && auxVal2 (fi3) && auxVal2 (colum1) && auxVal2 (colum2) && auxVal2 (colum3) ){
    return true;
   }
   else{
    return false;
   }

}
