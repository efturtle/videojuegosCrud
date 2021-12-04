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