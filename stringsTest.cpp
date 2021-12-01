#include <iostream>
using namespace std;

int main(){
    string temp = "Esto es una cadena larga con espacios";
    string otherString = "another one";

    temp += " this adds to the current string\n" + otherString;

    string tempo = "";

    if(tempo.length() > 0){
        cout << "more than 0";
    }
    cout << "Not more than 0";
    // cout << temp;
    return 0;
}