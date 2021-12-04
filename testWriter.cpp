// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
   string renglon;
   string temp;
   string tempo;
   int iterador = 1;
   ifstream myfile ("C:/Users/grave/Documents/videoJuegosCrud/datos.txt");
   if (myfile.is_open()){
      while ( getline (myfile,renglon) ){
         //convertir iterador en string
         //comparar a line
         if(!renglon.compare(to_string(iterador))){
            //si es igual a iterador imprimir un msg especial
            temp+="\n ";
            iterador++;
         }
            
         temp += "-> " + renglon;
         cout << endl << temp;
         temp = "";
      }
      myfile.close();
   }

   else cout << "Unable to open file"; 

   return 0;
}