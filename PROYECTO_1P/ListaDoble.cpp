/*
	UFA-ESPE
	Alumnos: Ricardo Rivadeneira, Sebastian Rivera.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso de Listas Simples, Dobles y Circulares para generar un Rol de Pago
	Nivel.- 3   NRC: 9671
*/
#include "ListaDoble.h"
#include <string>
#include "fstream"
#include <iostream>
#include <vector>
using namespace std;

//Constructor
ListaDoble::ListaDoble(){
    this->cabeza = NULL;
    this->actual = NULL;
}
//Destructor
ListaDoble::~ListaDoble() {	
    while(cabeza){
        //delete cabeza;
        cabeza = cabeza->getSiguiente();
    }
}
//Añadir DatosPersona
void ListaDoble::agregarDatosPersona(DatosPersona c){
	
	NodoDatos *nuevo = new NodoDatos(c);
	NodoDatos *tmp =cabeza;

	if(ListaVacia()){
		//cout<<"primero"<<endl;
		nuevo->setSiguiente(nuevo);
		nuevo->setOrigen(nuevo);
		this->cabeza = nuevo;
	//	cout<<"finPrimero"<<endl;
	}
	else if(tmp->getOrigen()==cabeza && tmp->getSiguiente()==cabeza){
	//	cout<<"segundo"<<endl;
		nuevo->setSiguiente(tmp);
		nuevo->setOrigen(tmp->getOrigen());
		tmp->setOrigen(nuevo);
		tmp->setSiguiente(nuevo);
	}
	else{
		//cout<<";askd"<<endl;
		nuevo->setSiguiente(tmp);
		nuevo->setOrigen(tmp->getOrigen());
		tmp->getOrigen()->setSiguiente(nuevo);
		tmp->setOrigen(nuevo);	
	}
}

void ListaDoble::retirarDatosPersona(DatosPersona c){
	
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

DatosPersona ListaDoble::buscarDatosPersona(int  modelo){
	int valor_b,count=0;
	DatosPersona cel;
	if(this->ListaVacia()){
		cout<<"El catalogo no esta cargado, no se puede buscar"<<endl;
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

void ListaDoble::mostrar(){
	NodoDatos *nuevo = cabeza;
		
	while(nuevo->getSiguiente()!=cabeza){
		cout<<">Cedula: "<<nuevo->getConteo().getCedula()<<"\n";
	    cout<<">Nombre: "<<nuevo->getConteo().getNombre()<<"\n";
		cout<<">Apellido: "<<nuevo->getConteo().getApellido()<<"\n";
		cout<<">Cargo: "<<nuevo->getConteo().getCargo()<<"\n";
		cout<<">Sueldo: $"<<nuevo->getConteo().getSueldo()<<"\n";
	    cout<<">Horas Extra: "<<nuevo->getConteo().getHorasExtra()<<"\n";
	    cout<<">Anticipo: $"<<nuevo->getConteo().getAnticipo()<<endl;
        std::cout<<"----------------------------------"<<endl;
		nuevo = nuevo->getSiguiente();
		
	}
	//nuevo = nuevo->getSiguiente();
	cout<<">Cedula: "<<nuevo->getConteo().getCedula()<<"\n";
	cout<<">Nombre: "<<nuevo->getConteo().getNombre()<<"\n";
	cout<<">Apellido: "<<nuevo->getConteo().getApellido()<<"\n";
	cout<<">Cargo: "<<nuevo->getConteo().getCargo()<<"\n";
	cout<<">Sueldo: $"<<nuevo->getConteo().getSueldo()<<"\n";
	cout<<">Horas Extra: "<<nuevo->getConteo().getHorasExtra()<<"\n";
	cout<<">Anticipo: $"<<nuevo->getConteo().getAnticipo()<<endl;
    std::cout<<"----------------------------------"<<endl;
}

void ListaDoble::rolPagos(string nombre, string apellido, string cargo, int cedu, double sueldo, double horasExtra,double anticipo){
    std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"|\t          *ROL DE PAGOS INDIVIDUAL*                |"<<endl;
    char dato1[10],dato2[10],dato3[10];
    double pago=0,cuotas=0;
    //double sueldo=420.2;
    double interesBanco=0,sePago=0,valhorasE,ingresototal,iess,porPagar=0; 
    std::cout<<"+----------------------------------------------------------+"<<endl;
            if (horasExtra<1)
            {
                valhorasE=0;
                iess=sueldo*0.0935;
                porPagar=sueldo-anticipo-iess;
            }else{
                if (horasExtra < 20)
                {
                    valhorasE= (1.5*horasExtra);
                }else{
                    valhorasE= (2*horasExtra);
                }
                ingresototal= sueldo+valhorasE;
                iess=ingresototal*0.0935;
                porPagar=ingresototal-anticipo-iess;
            }
	std::cout<<"| >Nombre: "<<nombre<<" "<<apellido<<endl;
    std::cout<<"| >Cedula: "<<cedu<<"\t\t\t\t\t   |"<<endl;
    std::cout<<"| >Cargo: "<<cargo<<endl;
    std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"|           *INGRESOS*           |      *DESCUENTOS*      "<<endl;
    std::cout<<"| >Sueldo Basico: $"<<sueldo;
    std::cout<<"\t | >Aportes IESS: $"<<iess<<endl;
    std::cout<<"| >Horas Extra: "<<horasExtra;
    std::cout<<"\t\t | >Anticipos: $"<<anticipo<<endl;
    std::cout<<"| >Valor por las Horas Extra: $"<<valhorasE<<endl;
    std::cout<<"+----------------------------------------------------------+"<<endl;    
    std::cout<<"|    Total Ingresos: $"<<(sueldo+valhorasE)<<"    |  Total Descuento: $"<<(iess+anticipo)<<endl;
    std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"|\t TOTAL A RECIBIR: $"<<porPagar<<endl;
    std::cout<<"+----------------------------------------------------------+"<<endl;
}