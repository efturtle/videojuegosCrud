// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

class Ticket{
	private:
		string nombreJuego;
		double renta;
		double venta;
		int estatus;
        ofstream myfile;
		string getFecha(){
			// Declaring argument for time()
			time_t tt;
			// Declaring variable to store return value of
			// localtime()
			struct tm * ti;
			// Applying time()
			time (&tt);
			// Using localtime()
			ti = localtime(&tt);
			string temp = asctime(ti);
         	return temp;  
		};

		//getters
		string getNombre(){
			return nombreJuego;
		};
		double getRenta(){
			return renta;
		};
		double getVenta(){
			return venta;
		};
		int getEstatus(){
			return estatus;
		};
		//setters
		void setNombre(string nombre){
			nombreJuego = nombre;
		};
		void setRenta(double precioRenta){
			renta = precioRenta;
		};
		void setVenta(double precioVenta){
			venta = precioVenta;
		};
		void setEstatus(int estatusCompra){
			estatus = estatusCompra;
		};

	public:
        //constructor
		Ticket(string nombreJuego, double renta, double venta, int estatus){
			setNombre(nombreJuego);
			setRenta(renta);
			setVenta(venta);
			setEstatus(estatus);
		};

		void guardar(){
            myfile.open("C:/Users/grave/Documents/cPP/ticket/example.txt");
            //renta
            if(getEstatus()){
                myfile << "Tienda de Juegos.\n";
                myfile <<"Ticket de Renta\n Fecha: ";
                myfile << getFecha();
                myfile << "\nNombre del juego: ";
                myfile << getNombre();
                myfile << "\nPrecio Renta: ";
                myfile << getRenta();
            }else{
                myfile << "Tienda de Juegos.\n";
                myfile <<"Ticket de Venta\n Fecha: ";
                myfile << getFecha();
                myfile << "\nNombre del juego: ";
                myfile << getNombre();
                myfile << "\nPrecio Venta: ";
                myfile << getVenta();
            }
            myfile.close();
		};

        string getNombreJuego(){
            return getNombre();
        };

        void writeText(){
            myfile.open ("C:/Users/grave/Documents/cPP/ticket/example.txt");
            myfile << "Writing this to a file.\n";
            myfile.close();
        };
};


// int main () {
//   ofstream myfile ("C:/Users/grave/Documents/cPP/ticket/example.txt");
//   if (myfile.is_open())
//   {
//     myfile << "This is a line.\n";
//     myfile << "This is another line.\n";
//     myfile.close();
//   }
//   else cout << "Unable to open file";
//   return 0;
// }

int main(){
    Ticket ob("turtle", 33, 0, 1);

    ob.guardar();
    return 0;
}