// #include <stdafx>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;


int main(){
    char renglon[128];
    char finNodo[2] = {',',','};
    int iterador = 0;
    ifstream archivo("C:/Users/grave/Documents/videoJuegosCrud/datos.txt");

    while (!archivo.eof()) {
        archivo >> renglon;
        cout << iterador << " " << renglon << endl;
        // if(strcmp(renglon, finNodo) == 0)
        //     
        // else
        //     cout << "este es un nodo";
        iterador++;
    }
    archivo.close();
    system("pause");
    return 0;
}


case '0':
                 {ifstream archivo;
	            archivo.open("Datos.txt",ios::in);
	            if(archivo.fail())
	            {cout<<"error de lectura"<<endl;}
	           // while(!archivo.eof())  //cadena es un  char[]
	           for(int i=0; i<5;i++)
	            { archivo.getline(cadena,15);
	             h=atoi(cadena);
				  cout<<"Codigo: "<<h; //1
				  //archivo.getline(cadena,15);
				  getline(archivo,nombre);
				   cout<<" Nombre: "<<nombre<<endl;
                    Lista.Insertar(h,nombre);
					}archivo.close();
				}
				cout<<"\nListo, datos guardados"<<endl;
				 x=0;
				break;