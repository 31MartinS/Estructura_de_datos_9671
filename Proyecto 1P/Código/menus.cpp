/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 01/05/2023
	Enunciado: Proyecto 1P
	Nivel.- 3  NRC: 9671 
*/

#pragma once
#include <conio.h>
#include <ctype.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <istream>
#include <iostream>
#include "menus.h"
//#include "ClistaSimple.cpp"
#include "ClistaDoble.cpp"
//#include "ClistaDCircular.cpp"
#include "NodoDatos.cpp"
#include "registro.cpp"
#include <fstream>
#include <sstream>
#include <windows.h>
#include <vector> 
#define N 30
#define TECLA_ARRIBA 'i'
#define TECLA_ABAJO 'k'
#define ENTER 13
#define BACKSPACE 8
using namespace std;

menus::menus(){}
menus::menus(ClistaSimple* lcel,Cdatos* cd){
	this->lista=*lcel;
	this->datosRol=*cd;
}

//Ingreso para Datos Enteros
char* menus::ingresarDatosEnteros(char *msj){ //Puntero sinónimo de arreglo
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
//Ingreso de Datos Flotantes - Decimales
char* menus::ingresarDatosFlotantes(char *msj){
    char *dato=new char[10],c;
	int i=0, punto=0;
    printf("%s ",msj);
    while((c=getch())!=13){
        if(c>='0'&& c<='9'){
            printf("%c",c);
            dato[i++]=c;
        }
        else if(c=='.' && punto==0){
            printf("%c",c);
            punto--;
            dato[i++]=c;
        }
        else if(c==8 || c==127){
            printf("\b \b");
            punto=0;
            dato[i--]=0;
        }
	}
	dato[i]='\0';
	return dato;
}

//Ingreso de Datos Char - Solo Letras
char* menus::ingresarChar(char *msj){
	char *dato=new char[20],c;
	int i=0;
	printf("%s ",msj);
	while((c=getch())!=13){
		if(c>=97 && c<=122){
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

void menus::verificar_user(){
	vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("admin");	
    // Se añaden claves al vector
    claves.push_back("123");
    
    string usuario, password;
    bool ingresa = false;
    
	char  usuario2[] = {"admin"}, 
	password2[] = {"123"},contrasenia, caracter;
    std::string valorString="";
	system("color 0C");
    printf("\t\t+~~~~+\n");
	printf("\t\t|  INICIO DE SESION  |\n");
	printf("\t\t+~~~~+\n\n");
	ingresoSesion:
	printf("  > Ingrese su usuario : ");
	getline(cin, usuario);
	printf("  > Ingrese su contrase%ca : ",164);
	caracter =getch();
	password="";
    while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
    }

    for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }
		
        if (!ingresa)
        {
            system("cls");
        	system("color 06");
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            printf("\t\t---------------------\n");
			printf("\t\tX~Acceso denegado~X\n");
			printf("\t\t---------------------\n\n");
			goto ingresoSesion;

        }else{
        	system("cls");
		system("color 0A");
		printf("\t\t---------------------\n");
		printf("\t\tX~Acceso permitido~X\n");
		printf("\t\t---------------------\n");
		system("pause");
    }
}

int menu(const char *opciones[],int n){
	int opcionSeleccionada=1;
	int tecla;
	bool repite = true;
	do{
		system("cls");
		system("color 0D");
		gotoXY(4,3+opcionSeleccionada); std::cout<<"==>";
		gotoXY(1,0); std::cout<<"+~~~~~~~~~~~~~~~~~~~~~~~~~~+\n |  Registro de Empleados   |\n |  +---------------------+ |\n |  |                     | |\n";
		gotoXY(1,6); std::cout<<"|  |                     | |\n |  +---------------------+ |\n |             O            |\n +~~~~~~~~~~~~~~~~~~~~~~~~~~+";
		gotoXY(1,11); std::cout<<"\n Para moverse arriba use 'i' para bajar use 'k'\n Para ingresar aplaste ENTER";
		for(int i=0;i<n;i++){
			gotoXY(10,4+i); std::cout<<i+1<<")"<<opciones[i];
		}
		do{
			tecla=getch();
		}while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!=ENTER);
		switch(tecla){
			case TECLA_ARRIBA:
				opcionSeleccionada--;
				if(opcionSeleccionada == 0){
					opcionSeleccionada = n;
				}
				break;
			
			case TECLA_ABAJO:
				opcionSeleccionada++;
				if(opcionSeleccionada > n){
					opcionSeleccionada = 1;
				}
				break;
			
			case ENTER:
				repite=false;
				break;
		}
	}while(repite);
	return opcionSeleccionada;
}

int menus::menuIngreso(){
	ofstream registro;
	menus men;
    char val[3];
    char* op;
    int auxi,escogido;
	bool repite=true;
	//Opciones
	const char *opciones[]={"Ingresar","Salir"};
	int n=2;
	do{
		escogido=menu(opciones, n);
        system("cls");
        switch (escogido){
        case 1:{
            system("cls");
			verificar_user();
			menuLSDC();
            }break;
        case 2:{
            return 0;
            }break;
        }
    }while (escogido>2 || escogido>0);
    return 0;
}

int menu2(const char *opciones[],int n){
	int opcionSeleccionada=1;
	int tecla;
	bool repite = true;
	do{
		system("cls");
		gotoXY(4,3+opcionSeleccionada); std::cout<<"~~>";
		gotoXY(1,0); std::cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t|        *** MENU ***       |\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		gotoXY(1,11); std::cout<<"\n Para moverse arriba use 'i' para bajar use 'k'\n Para ingresar aplaste ENTER";
		for(int i=0;i<n;i++){
			gotoXY(10,4+i); std::cout<<i+1<<")"<<opciones[i];
		}
		do{
			tecla=getch();
		}while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!=ENTER);
		switch(tecla){
			case TECLA_ARRIBA:
				opcionSeleccionada--;
				if(opcionSeleccionada == 0){
					opcionSeleccionada = n;
				}
				break;
			
			case TECLA_ABAJO:
				opcionSeleccionada++;
				if(opcionSeleccionada > n){
					opcionSeleccionada = 1;
				}
				break;
			
			case ENTER:
				repite=false;
				break;
		}
	}while(repite);
	return opcionSeleccionada;
}

int menuListas(const char *opciones[],int n){
	int opcionSeleccionada=1;
	int tecla;
	bool repite = true;
	do{
		system("cls");
		gotoXY(4,3+opcionSeleccionada); std::cout<<"~~>";
		gotoXY(1,0); std::cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t|      *** Tipo de Lista en la que Trabajar  ***       |\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		gotoXY(1,11); std::cout<<"\n Para moverse arriba use 'i' para bajar use 'k'\n Para ingresar aplaste ENTER";
		for(int i=0;i<n;i++){
			gotoXY(10,4+i); std::cout<<i+1<<")"<<opciones[i];
		}
		do{
			tecla=getch();
		}while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!=ENTER);
		switch(tecla){
			case TECLA_ARRIBA:
				opcionSeleccionada--;
				if(opcionSeleccionada == 0){
					opcionSeleccionada = n;
				}
				break;
			
			case TECLA_ABAJO:
				opcionSeleccionada++;
				if(opcionSeleccionada > n){
					opcionSeleccionada = 1;
				}
				break;
			
			case ENTER:
				repite=false;
				break;
		}
	}while(repite);
	return opcionSeleccionada;
}

int menus::menuLSDC(){
	ifstream lectura;
	char dato1[10],dato2[10],dato3[10],dato4[10],dato5[10],dato6[10],dato7[10];
	int cedulaAg;
	string nombreAg;
	double anticipoAG,horasAG;
	NodoDatos *ndat = new NodoDatos();
	Cdatos* obj1 = new Cdatos(1725212326,"Sebastian Rivera",4,100.45);
    ClistaSimple listaCedula;
    ClistaSimple* listaConsultados = new ClistaSimple();
	listaConsultados->agregarListado(*obj1);
	system("cls");
	int escogido;
	bool repite=true;
	//Opciones
	const char *opciones[]={"Lista Doblemente Enlazada","Salir"};
	int n=2;
    menus menuL;
    char val[3];
    char* op;
    int auxi;
    do{
		system("colo 0D");
        escogido=menuListas(opciones, n);
        system("cls");
        switch (escogido){
            case 1:{
					system("color 02");
					system("cls");
					menuL.menuDoble();
                    cout<<"\n";
					system("pause");
                    system("cls");
                	}break;
			case 2:{
         	    	printf("\t\t+~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
					printf("\t\t|  Gracias por Visitarnos  |\n");
					printf("\t\t+~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n");
    	    		exit(0);
                	}break;
        }
    }while (escogido<2 || escogido>0);
    return 0;
}



int menus::menuDoble(){
	char dato1[10],dato2[10],dato3[10],dato4[10],dato5[10],dato6[10],dato7[10],dato8[10],dato9[10];
	int cedulaAg,cedejem=1725212326;
	string nombreAg,apellidoAg,cargoAg,nomejem={"Sebastian Rivera"};
	double sueldoAg,anticipoAG,horasAG,antieje=100.45,horaseje=4;
	NodoDatos *ndat = new NodoDatos();
	Cdatos* obj1 = new Cdatos(cedejem,nomejem,horaseje,antieje);
	//Cdatos* obj3 = new Cdatos(1723212326,"GWEN","VALLADAREZ","Jefa de Area",630.34,12,80.33);
	ClistaDoble* listadoble = new ClistaDoble();
	//listadoble->agregarCdatos(*obj1);
	//listadoble->agregarCdatos(*obj3);
    
	system("cls");
	int escogido;
	bool repite=true;
	//Opciones
	const char *opciones[] = {"Registro Empleado", "Eliminar", "Vaciar registros", "Mostrar Registro Individual", "Imprimir Todos los Registros", "Salir"};
	int n = 6; 
    menus men2;
    char val[3];
    char* op;
    int auxi;
    do{
		system("colo 0D");
        escogido=menu2(opciones, n);
        system("cls");
        switch (escogido){
            case 1:{
					system("cls");
					system("color 01");
					char va[10],col[9],mar[9],mod[9];
					float costo;
					string dataIn;
					int auxcedAG;
					char data[15];
					bool dataEntered = false;
					std::cout<<"\t\t **Registro de empleado**";
					while (!dataEntered){
						ingresoCedula:
						strcpy(data,ingresarDatosEnteros("\n> Ingrese su cedula: "));
						dataIn=atoi(data);
						auxcedAG=atoi(data);
						//auxcedAG=auxcedAG;
						int listaCed=atoi(data);
						//
						if (dataIn.empty()){
							std::cout << "No se ingreso un dato" << endl;
							goto ingresoCedula;
						}else{
							dataEntered = true;
						}
					}
					int z, A[ 10 ], mul, sumpar, sumimp, sumtotal, c, dcsup, digitov, v;
					long int coc,ced;
					do{
						ced = auxcedAG;
						sumimp = 0 ;
						sumpar = 0 ;
						z = 9 ;
						if (auxcedAG < 10 )
							A [ 0 ] = 0 ;
						do{
							coc = auxcedAG / 10 ;
							A [z] = auxcedAG% 10 ;
							auxcedAG = coc;
							z--;
						}while (auxcedAG!=0 );
						for(z =0; z<9; z+=2 ){
							mul = A[z]*2 ;
							if (mul> 9 )
								mul-=9 ;
							sumpar+=mul;
						}
						for(z=1; z<8; z+=2){
							sumimp+=A[z];
						}
						sumtotal=sumpar+sumimp;
						c = sumtotal/10;
						dcsup = c*10+10 ;
						digitov=dcsup-sumtotal;
						if(digitov==10)
							digitov=0 ;
						if(digitov==A[9 ]){
							auxcedAG=ced;
							v=1;
						}else{
							goto ingresoCedula;
							v=0;
						}
						Cdatos repitCed;
						repitCed =  listadoble->buscarCdatos(auxcedAG);
						if (repitCed.getCedula()==auxcedAG)
						{
							std::cout<<"\t<<Ingrese otra cedula, esta ya existe>>"<<endl;
							goto ingresoCedula;
						}
					}while (v==0);
					do{
						strcpy(dato2,ingresarChar("\n> Ingrese su nombre: "));
						strupr(dato2);
						nombreAg=dato2;
					}while(nombreAg=="");
					do{
						strcpy(dato1,ingresarChar("\n> Ingrese su apellido: "));
						strupr(dato1);
						apellidoAg=dato1;
					}while(apellidoAg=="");
					do{
						strcpy(dato8,ingresarChar("\n> Ingrese su Cargo: "));
						strupr(dato8);
						cargoAg=dato8;
					}while(cargoAg=="");
					do{
						strcpy(dato9,ingresarDatosFlotantes("\n> Ingrese el valor su sueldo: $"));
						sueldoAg=atof(dato9);
					}while(sueldoAg>3000.5 || sueldoAg<1);
					Cdatos* obj2 = new Cdatos(auxcedAG,nombreAg,apellidoAg,cargoAg,sueldoAg,horasAG,anticipoAG);
					std::cout<<"\n";
					system("cls");
					listadoble->registro(nombreAg,apellidoAg,cargoAg,auxcedAG,sueldoAg,horasAG,anticipoAG);
					listadoble->agregarCdatos(*obj2);
					system("pause");
                    system("cls");
                    }break;
            case 2:{
					system("color 02");
					system("cls");
					char va[10],col[9],mar[9],mod[9];
					float costo;
					std::cout<<"\t\t **Elimina la informacion de tu Rol de Pagos**"<<endl;
					printf("  Busca por tu No. de cedula dentro de los Registros de la Empresa ");
					strcpy(dato2,ingresarDatosEnteros("\n>Ingrese tu cedula: "));
					int buscar=atoi(dato2);
					Cdatos cdat;
					cdat =  listadoble->buscarCdatos(buscar);
					if(cdat.getCedula()!=buscar){
						std::cout<<"\n>La cedula no se encuentra registrada"<<endl;
					}
					else{
						cout<<"\n>Usted ha eliminado correctamente la informacion:"<<endl;
						
						cout<<"\n>Cedula: "<<cdat.getCedula();
						
						cout<<"\n>Nombre: "<<cdat.getNombre();

						cout<<"\n>Apellido: "<<cdat.getApellido();

						cout<<"\n>Cargo: "<<cdat.getCargo();

						cout<<"\n>Sueldo $:"<<cdat.getSueldo();
					}
					std::cout<<"\n";
					system("pause");
                    system("cls");
                	}break;
            case 3:{
				    system("cls");
				    system("color 03");
				    std::cout << "\t\t **Vaciar registros**" << std::endl;
				
				    std::ofstream archivo("datos.txt", std::ofstream::trunc);  // Abre el archivo en modo truncado
				
				    if (archivo.is_open()) {
				        archivo.close();  // Cierra el archivo
				        std::cout << "Registros vaciados correctamente." << std::endl;
				    } else {
				        std::cout << "Error al abrir el archivo." << std::endl;
				    }
				
				    std::cout << std::endl;
				    system("pause");
				    system("cls");
				    }break;
//					system("cls");
//					system("color 03");
//					std::cout<<"\t\t **Mostrar el listado emplados**"<<endl;
//					listadoble->mostrar();
//					std::cout<<"\n";
//                	system("pause");
//                    system("cls");
//                    }break;
			case 4:{
					printf("\t\t  **Mostrar Registro**  \n");
					printf(" Busca por tu No. de cedula dentro de los Registros de la Empresa ");
					strcpy(dato6,ingresarDatosEnteros("\n>Ingrese tu cedula: "));
					int buscar=atoi(dato6);
					Cdatos cdat;
					cdat =  listadoble->buscarCdatos(buscar);
					if(cdat.getCedula()!=buscar){
						std::cout<<"\n>La cedula no se encuentra registrada"<<endl;
					}
					else{
						std::cout<<endl;
						listadoble->registro(cdat.getNombre(),cdat.getApellido(),cdat.getCargo(),cdat.getCedula(),cdat.getSueldo(),cdat.getHorasExtra(),cdat.getAnticipo());
					}
					system("pause");
					}break;
			case 5:{
					system("cls");
               		system("color 06");
               		cout << "\t\t **Imprimir Todos los Registros**" << endl;
               		listadoble->imprimirRegistros();
                	cout << "\n";
                	system("pause");
               		system("cls");
				}break;
//			case 6: {
//				    system("cls");
//				    vaciarRegistro();
//				    std::cout << std::endl;
//				    system("pause");
//				    system("cls");
//				} break;
			case 6:{
					system("cls");
					printf("\t\t+~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
					printf("\t\t|  Gracias por Visitarnos  |\n");
					printf("\t\t+~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\n");
    	    		exit(0);
					}break;
        }
    }while (escogido<5 || escogido>0);
    return 0;
}