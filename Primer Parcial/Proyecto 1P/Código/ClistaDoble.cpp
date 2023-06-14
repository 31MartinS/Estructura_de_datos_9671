/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 01/05/2023
	Enunciado: Proyecto 1P
	Nivel.- 3  NRC: 9671 
*/

#include "ClistaDoble.h"
#include <string>
#include "fstream"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

//Constructor
ClistaDoble::ClistaDoble(){
    this->cabeza = NULL;
    this->actual = NULL;
}
//Destructor
ClistaDoble::~ClistaDoble() {	
    while(cabeza){
        //delete cabeza;
        cabeza = cabeza->getSiguiente();
    }
}
//Añadir Cdatos
void ClistaDoble::agregarCdatos(Cdatos c){
	NodoDatos* nuevo = new NodoDatos(c);
    NodoDatos* tmp = cabeza;

    if (ListaVacia()) {
        nuevo->setSiguiente(nuevo);
        nuevo->setOrigen(nuevo);
        this->cabeza = nuevo;
    } else if (tmp->getOrigen() == cabeza && tmp->getSiguiente() == cabeza) {
        nuevo->setSiguiente(tmp);
        nuevo->setOrigen(tmp->getOrigen());
        tmp->setOrigen(nuevo);
        tmp->setSiguiente(nuevo);
    } else {
        nuevo->setSiguiente(tmp);
        nuevo->setOrigen(tmp->getOrigen());
        tmp->getOrigen()->setSiguiente(nuevo);
        tmp->setOrigen(nuevo);
    }

    // Obtener la fecha y hora actual
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* fechaActual = std::localtime(&tiempoActual);

    // Guardar datos en un archivo de texto
    std::ofstream archivo("datos.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << "Cedula: " << c.getCedula() << std::endl;
        archivo << "Nombre: " << c.getNombre() << std::endl;
        archivo << "Apellido: " << c.getApellido() << std::endl;
        archivo << "Cargo: " << c.getCargo() << std::endl;
        archivo << "Sueldo: " << c.getSueldo() << std::endl;
        archivo << "Fecha Registro: " << std::put_time(fechaActual, "%Y-%m-%d %H:%M:%S") << std::endl;
        archivo << std::endl;
        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo para guardar los datos." << std::endl;
    }
}

void ClistaDoble::retirarCdatos(Cdatos c){
	
	NodoDatos *nuevo = new NodoDatos(c);
	NodoDatos *tmp = new NodoDatos();
	tmp = cabeza;
	if(ListaVacia()){
		std::cout<<"La lista se encuentra vacia"<<endl;
	}else{
		while(tmp->getSiguiente()!=cabeza  && tmp->getConteo().getCedula()!=c.getCedula() ){ 
			tmp= tmp->getSiguiente();
		}
		}
		tmp->getOrigen()->setSiguiente(tmp->getSiguiente());
		tmp->getSiguiente()->setOrigen(tmp->getOrigen());
		tmp->setSiguiente(NULL);
		tmp->setOrigen(NULL);
		delete tmp;	
}

Cdatos ClistaDoble::buscarCdatos(int  modelo){
	int valor_b,count=0;
	Cdatos cel;
	if(this->ListaVacia()){
		cout<<"---"<<endl;
	}
	else{
		NodoDatos* tmp = cabeza;	
		do{
			if (tmp->getConteo().getCedula()== modelo){
				cel = tmp->getConteo();
        	}
			tmp = tmp->getSiguiente();
		}while(tmp!=cabeza);}
	return cel;
}

void ClistaDoble::mostrar(){
	NodoDatos *nuevo = cabeza;
		
	while(nuevo->getSiguiente()!=cabeza){
		cout<<">Cedula: "<<nuevo->getConteo().getCedula()<<"\n";
	    cout<<">Nombre: "<<nuevo->getConteo().getNombre()<<"\n";
		cout<<">Apellido: "<<nuevo->getConteo().getApellido()<<"\n";
		cout<<">Cargo: "<<nuevo->getConteo().getCargo()<<"\n";
		cout<<">Sueldo: $"<<nuevo->getConteo().getSueldo()<<"\n";
        std::cout<<"----------------------------------"<<endl;
		nuevo = nuevo->getSiguiente();
		
	}
	//nuevo = nuevo->getSiguiente();
	cout<<">Cedula: "<<nuevo->getConteo().getCedula()<<"\n";
	cout<<">Nombre: "<<nuevo->getConteo().getNombre()<<"\n";
	cout<<">Apellido: "<<nuevo->getConteo().getApellido()<<"\n";
	cout<<">Cargo: "<<nuevo->getConteo().getCargo()<<"\n";
	cout<<">Sueldo: $"<<nuevo->getConteo().getSueldo()<<"\n";
    std::cout<<"----------------------------------"<<endl;
}

/*void ClistaDoble::vaciarLista() {
        NodoDatos* actual = primerNodo;
        while (actual != nullptr) {
            NodoDatos* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        primerNodo = nullptr;
        ultimoNodo = nullptr;
        cantidadNodos = 0;
    }*/
void ClistaDoble::imprimirRegistros() {
    NodoDatos* nuevo = cabeza;

    while (nuevo->getSiguiente() != cabeza) {
        std::cout << "Cedula: " << nuevo->getConteo().getCedula() << "\n";
        std::cout << "Nombre: " << nuevo->getConteo().getNombre() << "\n";
        std::cout << "Apellido: " << nuevo->getConteo().getApellido() << "\n";
        std::cout << "Cargo: " << nuevo->getConteo().getCargo() << "\n";
        std::cout << "Sueldo: $" << nuevo->getConteo().getSueldo() << "\n";
        std::cout << "----------------------------------" << std::endl;
        nuevo = nuevo->getSiguiente();
    }

    std::cout << "Cedula: " << nuevo->getConteo().getCedula() << "\n";
    std::cout << "Nombre: " << nuevo->getConteo().getNombre() << "\n";
    std::cout << "Apellido: " << nuevo->getConteo().getApellido() << "\n";
    std::cout << "Cargo: " << nuevo->getConteo().getCargo() << "\n";
    std::cout << "Sueldo: $" << nuevo->getConteo().getSueldo() << "\n";
    std::cout << "----------------------------------" << std::endl;
}

void ClistaDoble::registro(string nombre, string apellido, string cargo, int cedu, double sueldo, double horasExtra,double anticipo){
    std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"|\t        *FICHA DE EMPLEADO INDIVIDUAL*              |"<<endl;
    char dato1[10],dato2[10],dato3[10];
    std::cout<<"+----------------------------------------------------------+"<<endl;
	std::cout<<"| >Nombre: "<<nombre<<" "<<apellido<<endl;
    std::cout<<"| >Cedula: "<<cedu<<"\t\t\t\t\t   |"<<endl;
    std::cout<<"| >Cargo: "<<cargo<<endl;
    std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"|           *INGRESOS*                                      "<<endl;
    std::cout<<"| >Sueldo: $"<<sueldo<<endl;
    std::cout<<"+----------------------------------------------------------+"<<endl;    
    std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"| >Fecha de ingreso: "<<endl;
    std::cout<<"+----------------------------------------------------------+"<<endl;
}