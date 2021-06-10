//TP n:Segundo Parcial
//Actividad: Test 3
//Comentarios:
/*

*/

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string.h>

void mostrar_menu ();
void jugar();
void estadisticas();
void creditos ();
void salir(bool &rta);

int main(){
    int opcion;
    bool rta = false;

	while (!rta){

	    mostrar_menu();

        cout << endl;
        cin >> opcion;

        switch (opcion){
            case 0:
                salir(rta);
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                creditos();
                break;
            default:
                cout << "Opcion invalida";

        }

        //cout << endl << rta << endl;

	}

 return 0;
}

void mostrar_menu (){

cout << endl << "MATRIX";
cout << endl << "------------------------------";
cout << endl << "1 - JUGAR";
cout << endl << "2 - ESTADISTICAS";
cout << endl << "3 - CREDITOS";
cout << endl << "------------------------------";
cout << endl << "0 - SALIR" << endl;


}

void creditos (){
bool volver = false;
cout << endl << "EL MEJOR TEAM";
cout << endl <<  "-----------------------";
cout << endl << "24464, Avila Rotela Catalina";
cout << endl << "24495, Falduti Matias Nicolas";
cout << endl << "24512, Illanes Saldivia Maria Jose" << endl;
while (!volver){
    cout << endl << "Ingrese un 1 para volver al menu" << endl;
    cin >> volver;
}



}

void salir(bool &rta){
cout << endl << "Esta seguro que desea salir? (1 - Si | 0 - No)" << endl;
cin >> rta;



}
