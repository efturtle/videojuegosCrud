#include <iostream>
using namespace std;

class Cliente{
    private:
        string nombre;
        string telefono;

        void setNombre(string nombreTemp){
            nombre = nombreTemp;
        };
        void setTelefono(string telefonoTemp){
            telefono = telefonoTemp;
        };

    public:
        Cliente(string nombreConstructor, string telefonoConstructor){
            setNombre(nombreConstructor);
            setTelefono(telefonoConstructor);
        };
        string getNombre(){
            return nombre;
        }
        string getTelefono(){
            return telefono;
        }
};

int main(){
    Cliente ob("Alberto", "3323948101");

    cout << ob.getNombre();
    cout << ob.getTelefono();
    return 0;
}