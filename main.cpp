#include <iostream>
#include <string.h>
#include <fstream>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define ASCENDENTE 1



class Ticket{
	private:
      string detallesJuego;
      int estatusCompra;
      string clientenovo;
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
      string getDetalles(){
         return detallesJuego;
      }
      string getCliente(){
         return clientenovo;
      }
      int getEstatusCompra(){
         return estatusCompra;
      }
      //setters
      void setDetalles(string detalles){
         detallesJuego = detalles;
      }
      void setcliente(string novocliente){
         clientenovo = novocliente;
      }
      void setEstatusCompra(int estatus){
         estatusCompra = estatus;
      }

	public:
        //constructor
		Ticket(int estatus, string clientedatos, string detalles){
         setEstatusCompra(estatus);
         setcliente(clientedatos);
         setDetalles(detalles);
		};

		void guardar(){
            myfile.open("C:/Users/grave/Documents/videoJuegosCrud/example.txt");
            //renta
            if(getEstatusCompra() == 1){
               myfile << "Tienda de Juegos.\n";
               myfile <<"Ticket de Renta\n\nFecha: ";
               myfile << getFecha()+"\n";
               myfile << getDetalles();
               myfile << "\n\nEntregar en 30 Dias";
               myfile << "\n\n\n" + getCliente()+"\n\nGracias por su compra";

            }else{
               myfile << "Tienda de Juegos.\n";
               myfile <<"Ticket de Venta\n Fecha: ";
               myfile << getFecha() + "\n";
               myfile << getDetalles() + "\n\n\nGracias por su compra";
            }
            myfile.close();
            return;
		};
};

class nodo {
   public:
      nodo(int v, string nombre, double precioRenta, double precioVenta, string fecha, int estatusCompra,
         nodo *sig = NULL, nodo *ant = NULL) ://
         valor(v), nombre(nombre), renta(precioRenta), venta(precioVenta), fecha(fecha), estatus(estatusCompra), siguiente(sig), anterior(ant) {}
   private:
      int valor;
      string nombre;
      double renta;
      double venta;
      string fecha;
      int estatus;
      nodo *siguiente;
      nodo *anterior;

   friend class lista;
};

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



typedef nodo *pnodo;

class lista {
   public:
      lista() : plista(NULL) {}
      ~lista();
      void Insertar(int v, string name, double precioRenta, double precioVenta, string fecha, int estatusCompra);
      void BorrarPorId(int v);
      void BorrarPorNombre(string nombre);
      bool ListaVacia() { return plista == NULL; }
      void Mostrar(int);
      void Siguiente();
      void Anterior();
      void Primero();
      void Ultimo();
      bool Actual() { return plista != NULL; }
      int ValorActual() { return plista->valor; }
      string nActual(){return plista->nombre;}
      void BuscarId(int v);
      void BuscarNombre(string nombre);
      string show(int v, int estatusCompra);
      void mostrarDatos();
   
      string getHora(){
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
      }

   private:
      pnodo plista;
};

lista Lista;

lista::~lista(){
   pnodo aux;
   Primero();
   while(plista) {
      aux = plista;
      plista = plista->siguiente;
      delete aux;
   }
}



// Busqueda por ID //
void lista::BuscarId(int v){ 
   pnodo nodo,aux;
   nodo = plista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;
   if(!nodo || nodo->valor != v){
      cout<<"El dato "<<v<<" que buscas no existe"<<endl;
   }else{
         cout << "-> "<< nodo->valor
            << "\n-> Nombre: " << nodo->nombre<< "\n"
            << "-> Precio Renta $" << nodo->renta << " -> Precio Venta $" << nodo->venta
            << "\n \n";
	   return;
   }
}

// Busqueda por nombre //
void lista::BuscarNombre(string nombre){
   pnodo nodo,aux;
   nodo = plista;
   while(nodo && nodo->nombre < nombre) nodo = nodo->siguiente;
   while(nodo && nodo->nombre > nombre) nodo = nodo->anterior;
   if(!nodo || nodo->nombre != nombre){
      cout<<"El dato "<<nombre<<" que buscas no existe"<<endl;
   }else{
      cout << "-> "<< nodo->valor
            << "\n-> Nombre: " << nodo->nombre<< "\n"
            << "-> Precio Renta $" << nodo->renta << " -> Precio Venta $" << nodo->venta
            << "\n \n";
   }
}

string lista::show(int v, int estatusCompra){
   pnodo nodo,aux;
   nodo = plista;
   string temp;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;
   if(!nodo || nodo->valor != v){
      temp = "";
      return temp;
   }else{
      //renta
      if(estatusCompra == 1){
         temp += "Nombre " + nodo->nombre + "\n";
         temp += "Precio Renta " + to_string(nodo->renta) + "\n";
         return temp;
      }else{
         //venta
         temp += "Nombre " + nodo->nombre + "\n";
         temp += "Precio Venta " + to_string(nodo->venta) + "\n";
         return temp;
      }
   }
}


// Insertar //
void lista::Insertar(int v, string nombre, double precioRenta, double precioVenta, string fecha, int estatusCompra){ 
   pnodo nuevo;
   Primero();
   // Si la lista est??? vac???a
   if(ListaVacia() || plista->valor > v) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual
      nuevo = new nodo(v, nombre, precioRenta, precioVenta, fecha, estatusCompra);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }else{
      // Buscar el nodo de valor menor a v
      // Avanzamos hasta el ultimo elemento o hasta que el siguiente tenga un valor mayor que v
      while(plista->siguiente && plista->siguiente->valor <= v) Siguiente();

      // Creamos un nuevo nodo despues del nodo actual
      nuevo = new nodo(v, nombre, precioRenta, precioVenta, fecha, estatusCompra, plista->siguiente, plista);
      plista->siguiente = nuevo;

      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

// Borrar por Nombre //
void lista::BorrarPorNombre(string nombre){
   pnodo nodo,aux;
   nodo = plista;
   while(nodo && nodo->nombre < nombre) nodo = nodo->siguiente;
   while(nodo && nodo->nombre > nombre) nodo = nodo->anterior;

   if(!nodo || nodo->nombre != nombre){
      cout<<nombre<<" no existe, no utilizar espacios"<<endl;
      return;
   }

   // Borrar el nodo
   if (nodo->anterior==NULL&&nodo->siguiente==NULL){
      Primero();
      while(plista) {
         aux = plista;
         plista = plista->siguiente;
         delete aux;
         return;
      }
   }
   if (nodo->anterior==NULL&&nodo->siguiente!=NULL){
      aux=nodo;
      aux->anterior=NULL;
      nodo=aux->siguiente;
      aux->siguiente=NULL;
      nodo->anterior=NULL;
      delete aux;
      plista=nodo;
      return;
   }else{
      if(nodo->anterior) // no es el primer elemento
         nodo->anterior->siguiente = nodo->siguiente;
      if(nodo->siguiente) // no el el ultimo nodo
         nodo->siguiente->anterior = nodo->anterior;
      delete nodo;
   }
}

// Borrar por id //
void lista::BorrarPorId(int v){
   pnodo nodo,aux;
   nodo = plista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   if(!nodo || nodo->valor != v){
      cout<<"El dato "<<v<<" que buscas no existe"<<endl;
      return;
   }   
   // Borrar el nodo
   if (nodo->anterior==NULL&&nodo->siguiente==NULL){
      Primero();
      while(plista) {
         aux = plista;
         plista = plista->siguiente;
         delete aux;
         return;
      }
   }
   if (nodo->anterior==NULL&&nodo->siguiente!=NULL){
      aux=nodo;
      aux->anterior=NULL;
      nodo=aux->siguiente;
      aux->siguiente=NULL;
      nodo->anterior=NULL;
      delete aux;
      plista=nodo;
      return;
   }else{
      if(nodo->anterior) // no es el primer elemento
         nodo->anterior->siguiente = nodo->siguiente;
      if(nodo->siguiente) // no el el ultimo nodo
         nodo->siguiente->anterior = nodo->anterior;
      delete nodo;
   }
}

void lista::mostrarDatos(){
   string renglon;
   string temp;
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
   return;
}

// Show //
void lista::Mostrar(int orden)
{   
   pnodo nodo;
   Primero();
   nodo = plista;
   if(orden == ASCENDENTE){
      while(nodo){
			cout << "-> "<< nodo->valor << " Nombre: " << nodo->nombre
            << "-> Precio Renta $" << nodo->renta << "-> Precio Venta $" << nodo->venta
            << "-> Fecha: " << nodo->fecha<<endl;
         nodo = nodo->siguiente;
      }
   }else{ 
      Ultimo();
      nodo = plista;
      while(nodo){
         cout << nodo->valor << "-> ";
         nodo = nodo->anterior;
      }
   }
   cout << endl;
}

void lista::Siguiente(){    
   if(plista) plista = plista->siguiente;
}

void lista::Anterior(){
   if(plista) plista = plista->anterior;
}

void lista::Primero(){   
   while(plista && plista->anterior) plista = plista->anterior;
}

void lista::Ultimo()
{
   while(plista && plista->siguiente) plista = plista->siguiente;
}


void adminAPI(){
   char opc;
   int x,cant;
   string nombre;
   double renta;
   double venta;
   string fecha;
   int estatusCompra;
   string stringTemporal;

   do{
      cout<<endl<<"Welcome"<<endl;
      cout<<"1.-Insertar un elemento"<<endl;
      cout<<"2.-Mostrar todo"<<endl;
      cout<<"3.-Borrar por ID"<<endl;
      cout<<"4.-Borrar por Nombre"<<endl;
      cout<<"5.-Accesar al primer videojuego"<<endl;
      cout<<"6.-Accesar al ultimo videojuego"<<endl;
      cout<<"7.-Buscar por ID"<<endl;
      cout<<"8.-Buscar por Nombre"<<endl;
      cout<<"9.-Mostrar Archivo txt"<<endl;
      cout<<"0.-Regresar"<<endl;
      cout<<"Selecciona una opcion: ";
      cout<<endl;
      cin>>opc;
      // fflush(stdin); solo si es necesario limpiar bufer
      switch (opc){
//---------Inserta
         case '1': cout<<"Cuantos datos deseas ingresar: #";
            cin>>cant;
            for (int i=0; i < cant; i++){
               cout<<endl<<"Ingresa el dato a registrar: ";
               cin>>x;
               cout<<endl<<"Ingresa el nombre a registrar: ";
               cin>>nombre;

               cout<<endl<<"Ingresa el precio renta: ";
               cin>>renta;

               cout<<endl<<"Ingresa el precio venta: ";
               cin>>venta;
               Lista.Insertar(x,nombre, renta, venta, Lista.getHora(), 0);
            }
            cout<<"\nListo, datos guardados"<<endl;
            x=0;
         break;

//---------mostrar
         case '2':
            if(Lista.ListaVacia()){
               cout<<"Tu lista esta vacia"<<endl;
            }else{
               cout<<"Su lista es: ";
               Lista.Mostrar(ASCENDENTE);
            }
         break;
         
//-------Borrar Elemento por ID
         case '3':
            cout<<"Ingresa el dato que quieras eliminar: ";
            cin>>x;
            Lista.BorrarPorId(x);
            x=0;
         break;

//-------Borrar elemento por Nombre
         case '4':
            cout<<"Ingresa el nombre del juego a eliminar: ";
            cin>>stringTemporal;
            Lista.BorrarPorNombre(stringTemporal);
            x=0;
         break;

//-----Mostrar el primer dato
         case '5':
            if(Lista.ListaVacia()){
               cout<<"Tu lista esta vacia"<<endl;
            }else{
               Lista.Primero();
               cout<<"\nTu primer dato de la lista es: "<<Lista.ValorActual();
               cout<<"\nTu primer nombre de la lista es: "<<Lista.nActual();
            }
         break;

//-----Mostrar el ultimo dato
         case '6':
            if(Lista.ListaVacia()){
               cout<<"Tu lista esta vacia"<<endl;
            }else{
               Lista.Ultimo();
               cout<<"\nTu ultimo dato de la lista es: "<<Lista.ValorActual();
               cout<<"\nTu ultimo nombre de la lista es: "<<Lista.nActual();
            }
         break;

//------- buscar por ID
         case '7':
            if (Lista.ListaVacia()){
               cout<<"Tu lista esta vacia"<<endl;
            }else{
               cout<<"Ingresa el ID ";
               cin>>x;
               Lista.BuscarId(x);
            }
            x=0;
         break;

//------- Buscar por Nombre
         case '8':
            if(Lista.ListaVacia()){
               cout<<"Tu lista esta vacia"<<endl;
            }else{
               cout<<"Ingresa el nombre ";
               cin>>stringTemporal;
               Lista.BuscarNombre(stringTemporal);
            }
         break;

         case '9':
            Lista.mostrarDatos();
         break;

//------- Exit
         case '0':
            cout<<"Sale"<<endl;
         break;

//------- Default Action
         default:
            cout<<" cometiste un error, intentalo otra vez"<<endl;
         break;
	   }
   }while(opc != '0');
   cin.get();
   return;
}

void puntoVenta(){
   char opcPuntoVenta;
   int xtemp, tempo, tempor, tempora, iterador;
   string nombreTemp;
   string telefonoTemp;
   string renglon;
   string temp;
   string datosCliente;
   ifstream myfile ("C:/Users/grave/Documents/videoJuegosCrud/datos.txt");
   do{
      cout << endl << endl << "+= += += Menu Punto de Venta += += +=" << endl;
      cout << endl << "1 - Rentar" << endl;
      cout << endl << "2 - Vender" << endl;
      cout << endl << "0 - Regresar" << endl;

      cin >> opcPuntoVenta;
      switch (opcPuntoVenta){
///------Renta         
         case '1':{
            iterador = 0;
            cout << endl << "Ingrese el ID del juego" << endl;
            cin >> xtemp;
            tempo = xtemp + 1;

            cout << endl << "Ingrese el nombre del Cliente" <<endl;
            cin >> nombreTemp;

            // cliente telefono
            cout << endl << "Ingrese el telefono del cliente" <<endl;
            cin >> telefonoTemp;
            Cliente obCliente(nombreTemp, telefonoTemp);

            datosCliente = "Nombre: "+obCliente.getNombre()+"\nTelefono: "+obCliente.getTelefono();

            myfile.open("C:/Users/grave/Documents/videoJuegosCrud/datos.txt");

            if (myfile.is_open()){               
               while (getline(myfile,renglon)){
                  //comienza la lectura
                  //usar la comparacion para conocer el siguiente nodo
                  tempor = renglon.compare(to_string(tempo));

                  tempora = renglon.compare(to_string(xtemp));

                  if(tempora == 0){
                     temp = "";
                  }
                  if(tempor == 0){
                     //lo bueno
                     Ticket ob(1, datosCliente, temp);
                     ob.guardar();
                     // cout << temp;
                     temp = "";
                     tempo = 0;
                  }else{
                     iterador++;
                     if(tempora != 0){
                        temp += renglon + "\n";
                        if((iterador % 2) == 0){
                           temp+="Precio Renta: ";
                        }
                     }
                  }
               }
            }else{
               cout << "unable to open file";
            }
            myfile.close();
            cout << endl << "-*/-*/-*/-*/Venta Realizada -*/-*/-*/-*/";
         }
         break;
///------Venta
         case '2':
            iterador = 0;
            cout << endl << "Ingrese el ID del juego" << endl;
            cin >> xtemp;
            tempo = xtemp + 1;
            myfile.open("C:/Users/grave/Documents/videoJuegosCrud/datos.txt");

            if (myfile.is_open()){               
               while (getline(myfile,renglon)){
                  tempor = renglon.compare(to_string(tempo));

                  tempora = renglon.compare(to_string(xtemp));

                  if(tempora == 0){
                     temp = "";
                  }
                  if(tempor == 0){
                     //lo bueno
                     Ticket ob(2, datosCliente, temp);
                     ob.guardar();
                     // cout << temp;
                     temp = "";
                     tempo = 0;
                  }else{
                     iterador++;
                     if(tempora != 0){
                        temp += renglon + "\n";
                        if((iterador % 2) != 0){
                           temp+="Precio Venta: ";
                        }
                     }
                  }
               }
            }else{
               cout << "unable to open file";
            }
            myfile.close();
            cout << endl << "-*/-*/-*/-*/Venta Realizada -*/-*/-*/-*/";

            // cout << endl << "Ingrese el ID del juego" << endl;
            // cin >> xtemp;

            // if(Lista.show(xtemp, 1).length() > 0){
            //    Ticket ob(Lista.show(xtemp, 2), 2, "");
            //    ob.guardar();
            // }
            // cout <<endl << "-*/-*/-*/-*/Venta Realizada -*/-*/-*/-*/";
         break;

         case '0':
            cout << endl << "Sale" << endl;
         break;
         
         default:
            cout << endl << "Opcion erronea" <<endl;
         break;
      }
   }while(opcPuntoVenta != '0');
   cin.get();
   return;
}


int main()
{
   string password;
   cout<<"\nclave: ";
   cin>>password;
   if(password.compare("turtle")){
      return 0;
   }

   char opcMenuPrincipal;
   do{
      cout << endl << endl << "=- =- =- Menu Principal =- =- =-" << endl;
      cout << endl << "1 - admin" <<endl;
      cout << endl << "2 - Punto de Venta" <<endl;
      cout << endl << "0 - Salir del Programa" <<endl;
      cin >> opcMenuPrincipal;
      switch(opcMenuPrincipal){
         case '1':
            //lo que habia hecho la maestra
            adminAPI();
         break;

         case '2':
            //lo nuevo
            puntoVenta();
         break;

         case '0':
            cout << endl << "Menu principal" << endl;
         break;
         default: 
            cout << endl << "Opcion erronea" <<endl;
         break;
      }
   }while(opcMenuPrincipal != '0');
   cin.get();
   return 0;
}
