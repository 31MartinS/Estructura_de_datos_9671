/*
	UFA-ESPE
	Alumnos: Miguel Gutierrez, Sebastian Rivera, Martin Suquillo.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso Dobles generar datos de empleados de un hospital de ancianos
	Nivel.- 3   NRC: 9671
*/
#pragma once
#include "ClistaSimple.h"
#include "CnodoLS.cpp"
#include "Cdatos.cpp"
#include <cstring>
#include <istream>
#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;

ClistaSimple::ClistaSimple(){
    this->referencial=NULL;
    this->origen=NULL;
	this->cabecera=NULL;
	this->referencial2=NULL;
}

void ClistaSimple::insertarCab(int _entrada){
    CnodoLS *nuevo = new CnodoLS(_entrada,NULL);
    if(ListaVacia()){
        this->origen=nuevo;
    }else{
        nuevo->setSiguiente(origen);
        origen=nuevo;
    }
}


void ClistaSimple::separarUnidades(){
    int* aux = new int[contador];
    int suma=0;
	//cout<<contador;
	CnodoLS *ptr =this->origen;
    if(ListaVacia()){
        std::cout<<"La lista esta vacia, por ende no se puede obtener un minimo"<<endl;
    }else{
        while(ptr){
            for(int i=0;i<contador;i++){
                *(aux+i)=ptr->getEntrada();	
                std::cout<<"La posicion "<<i+1<<" es: "<<*(aux+i)<<endl;
                ptr=ptr->getSiguiente();	
            }		
        }
        //while (ptr)
        //{
            for(int i=0;i<contador;i++){
                *(aux+i)=ptr->getEntrada();	
                std::cout<<"La posicion "<<i+1<<" es: "<<*(aux+i)<<endl;
                ptr=ptr->getSiguiente();	
                suma=suma+*(aux+i)%10;
                *(aux+i)=*(aux+i)/10;
                cout<<">La suma de los dos digitos es: "<<suma<<endl;
            }
        //}
          
    }
}

void ClistaSimple::insertarMCM(int val){
	CnodoLS* nuevo = new CnodoLS(val);
	//nuevo->siguiente=NULL;
		if(ListaVacia()){
			this->origen=nuevo;
			this->referencial=nuevo;
		}
		else{
			nuevo->setSiguiente(origen);	
			this->origen=nuevo;
		}	
		contador++;
}

void ClistaSimple::insertarCol(int _entrada){
    CnodoLS *nuevo=new CnodoLS(_entrada,NULL);
    if(ListaVacia()){
        this->origen=nuevo;
    }else{
        this->referencial->setSiguiente(nuevo);
    }
    this->referencial=nuevo;
}

void ClistaSimple::buscar(int val){
    int aux = 0;
	CnodoLS* num = new CnodoLS(val, NULL);
	CnodoLS* tmp = this->origen;
	if(this->ListaVacia()){
		cout<<"\n>El listado se encuentra vacio por lo que no se encontro su cedula"<<endl;
	}else{
		while (tmp->getSiguiente()){
		if (tmp->getEntrada() == num->getEntrada()){
			cout<<"\n>Su cedula esta registrada en la posicion: "<<aux+1<<", por lo que consta dentro de la empresa"<<endl;
			//imprimir();
			break;
		}
		tmp = tmp->getSiguiente();
		aux++;
	}
	if (tmp->getSiguiente()==NULL){
     if(tmp->getEntrada()== num->getEntrada()){
        cout<<"\n>Su cedula se encuentra registrada en la empresa"<<endl;
    }else
		cout << "\n>Su numero de cedula no se encuentra registrada en la empresa\n";
	}
	}
}
void ClistaSimple::imprimir(){
	CnodoLS *tmp=this->origen;
    int contador=0;
		while(tmp){
            std::cout<<contador+1<<") ";
			cout<<tmp->getEntrada()<<"\n";
			tmp=tmp->getSiguiente();
            contador++;
		}
			cout<<"NULL = Final del Listado\n";
}	

int ClistaSimple:: tamanioLista(){
    CnodoLS* aux = this-> origen;
        int tamanio = 0;
        while (aux != nullptr){
            tamanio++;
            aux = aux->getSiguiente();
        }
        return tamanio;
}

void ClistaSimple::eliminarCab(int eliminar){
    CnodoLS* aux;
    if(ListaVacia()){
        cout<<"\nLa lista esta vacia" << endl;
    }else{  
        if(eliminar<=tamanioLista()){ 
        for (int i=0; i<eliminar;i++){
            aux= this->origen;
            this->origen = this->origen-> getSiguiente();
            aux -> setSiguiente(NULL);
            delete aux;      
        }cout<<"\n";imprimir();
        }else{
             printf("\nNo se puede eliminar mas del tamanio de la lista\n");
        }
    }
}
void ClistaSimple::eliminarCol(int eliminar){
    int i=0;
    CnodoLS* aux= this->origen;
    CnodoLS* aux2;
    if (ListaVacia()){
        cout<< "\nLa lista se encuentra vacia" <<endl;
    }else{
        if (eliminar <= tamanioLista()){
            while (aux->getSiguiente()){
                aux2= aux;
                aux= aux->getSiguiente();
            }
            if(eliminar==tamanioLista()){
				origen= nullptr;
			}else{
        	   do{
            	aux2->setSiguiente(NULL);
                delete aux;
                aux= origen;
                aux2=nullptr;
                while (aux->getSiguiente()){
                aux2= aux;
                aux= aux->getSiguiente();
            	}
                i++;
               }while (i!=eliminar);
            }cout<<"\n";imprimir();
        }else{
			 printf("\nNo se puede eliminar mas del tamanio de la lista\n");
		}
    }
}

char* ClistaSimple::ingresarDatosEnteros(char *msj){ //Puntero sinónimo de arreglo
    char *dato=new char[10],c; //New instancia (fusionar o enlazar una clase con otra)
	int i=0; 
	printf("%s ",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
	return dato;
}

void ClistaSimple::modificarValor(int val, int valmod){
	int cont=0,cont2=1;
	CnodoLS* num = new CnodoLS(val);
	CnodoLS* tmp = this->origen;
	while(tmp){
		if(tmp->getEntrada() == num->getEntrada()){
			cont++;
		}
	tmp=tmp->getSiguiente();
	}
	if(cont == 0){
		cout<<"\nEl elemento a modificar no existe en la lista\n"<<endl;
	}else{
		CnodoLS* aux= origen;
		while(aux != NULL && aux->getEntrada()!=val){
			aux=aux->getSiguiente();
			cont2++;
		}
		if(aux->getEntrada()==val){
			aux->setEntrada(valmod);	
		}
	cout <<"\nLa primera ocurrencia ubicado en la posicion: "<<cont2<<" de la lista ha sido modificado por: "<<valmod<<"\n";	
	}  
}

ClistaSimple::~ClistaSimple(){
    while(cabecera){
        cabecera=cabecera->getSiguiente();
    }
}

NodoDatos* ClistaSimple::getCabecera(){
	return cabecera;
}

void ClistaSimple::agregarListado(Cdatos agregado){
    NodoDatos *nuevo = new NodoDatos(agregado);
    NodoDatos *aux = cabecera;
	if(listaVacia()){
		cabecera=nuevo;
		cabecera->setSiguiente(cabecera);
		cabecera->setOrigen(cabecera);
		referencial2=cabecera;
	}
    else{
		referencial2->setSiguiente(nuevo);
		nuevo->setSiguiente(cabecera);
		nuevo->setOrigen(referencial2);
		referencial2=nuevo;
		cabecera->setOrigen(referencial2);
    }
}

void ClistaSimple::imprimirListado(){
	NodoDatos *nuevo=cabecera;
	if(listaVacia()){
	std::cout<<"La lista se encuentra vacia"<<endl;
    }else{
		do{
			std::cout<<"Cedula: "<<nuevo->getConteo().getCedula()<<endl;
			std::cout<<"Nombre: "<<nuevo->getConteo().getNombre()<<endl;
			std::cout<<"Anticipo: $"<<nuevo->getConteo().getAnticipo()<<endl;
			std::cout<<"Horas Extra: "<<nuevo->getConteo().getHorasExtra()<<endl;
			std::cout<<"----------------------------------"<<endl;
			nuevo=nuevo->getSiguiente();
		}while(nuevo!=cabecera);
	}
}

void ClistaSimple::rolPagos(int cedu,double horasExtra,double anticipo){
    std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"|\t          *ROL DE PAGOS INDIVIDUAL*                 |"<<endl;
    char dato1[10],dato2[10],dato3[10];
    double pago=0,cuotas=0;
    double sueldo=420.2;
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
    std::cout<<"| >Cedula: "<<cedu<<"\t\t\t\t\t   |"<<endl;
    std::cout<<"| >Cargo: Ingeniero en Sistemas                            |"<<endl;
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

Cdatos ClistaSimple::buscarCed(int val){
    int valor_b,count=0;
	Cdatos cel;
	if(this->ListaVacia()){
		cout<<"El catalogo no esta cargado, no se puede buscar"<<endl;
	}
	else{
		NodoDatos* tmp = cabecera;	
		do{
			if (tmp->getConteo().getCedula()== val){
				cel = tmp->getConteo();
        	}
			tmp = tmp->getSiguiente();
		}while(tmp!=cabecera);}
	return cel;
}