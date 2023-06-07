/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 01/05/2023
	Enunciado: Proyecto 1P
	Nivel.- 3  NRC: 9671 
*/

#pragma once
#include "registro.h"
#include "ClistaSimple.cpp"
#include <fstream>
#include <sstream>
#include <windows.h>
#define N 30
#define TECLA_ARRIBA 'i'
#define TECLA_ABAJO 'k'
#define ENTER 13
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition;

void gotoXY(int x, int y) {
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Ingreso para Datos Enteros
char* ingresarDatosEnteros(char *msj){ //Puntero sinónimo de arreglo
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
char* ingresarDatosFlotantes(char *msj){
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

int validacion_numeros(char num[]){
	int num_valido;
	for(int i=0;i<strlen(num);i++){
		if(!(isdigit(num[i]))){
			printf("Ingresa solo n%cmeros\n",163);
			return 0; //0 valor de retorno
		}
	}
}	
//Ingreso de Datos Char - Solo Letras
char* ingresarChar(char *msj){
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

int menu3(const char *opciones[],int n){
	int opcionSeleccionada=1;
	int tecla;
	bool repite = true;
	do{
		system("cls");
		gotoXY(4,3+opcionSeleccionada); std::cout<<"~~>";
		gotoXY(1,0); std::cout<<"\t\t Desea Solicitar un Adelanto";
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

int inscribir_participante(int i, ofstream &registro){
	ClistaSimple listaCedula;
	int longitud;
	int n;
	int escogido=participantes[i].saldo;
	bool repite=true;
	char dato1[10],dato2[10],dato3[10],dato4[10],dato5[10],dato6[10],dato7[10],dato8[10],dato9[10];
	//Opciones
	const char *opciones[]={"Si, deseo hacer un adelanto","No, continuar el formulario"};
	int p=2;
	fflush(stdin);
    system("color 0A");
	std::cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout<<"\t\t\t|            REGISTRO DE EMPLEADOS              |\n";
	std::cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";	
	std::cout<<"Ingrese el Nombre completo del participante | Escriba <<fin>> para finalizar: "<<endl;
	std::cout<<"\t *El sistema no completara su inscripcion si no ingresa sus 2 apellidos y 2 nombres*"<<endl;
    do{
		strcpy(participantes[i].apellidos_nombres,ingresarChar("\n>Ingrese su Nombre: "));
		strupr(participantes[i].apellidos_nombres);
	}while(participantes[i].apellidos_nombres=="");
	if(strcmp(participantes[i].apellidos_nombres,"FIN")==0){
		registro.open("inscripcion.txt",ios::out|ios::app);
		if(registro.is_open()){
			for(int b=0;b<i;b++){
				registro<<" "<<participantes[b].apellidos_nombres<<" "<<participantes[b].nombre2<<" "<<participantes[b].apellido1<<" "<<participantes[b].apellido2<<" "<<participantes[b].cedula<<" "<<participantes[b].cargo<<" "<<participantes[b].salario<<" "<<participantes[b].valorAnticipo<<" "<<participantes[b].horasExtra<<" "<<participantes[b].pagaPorRecibir<<endl;
				};					
		}	
		system("cls");
		std::cout<<"Registro guardado con exito...\n";
		system("pause");   
		system("cls");
		registro.close();	
		return 1;
		}	else{
		do{
			strcpy(participantes[i].nombre2,ingresarChar("\n>Ingrese su Segundo Nombre: "));
			strupr(participantes[i].nombre2);
		}while(participantes[i].nombre2=="");
		do{
			strcpy(participantes[i].apellido1,ingresarChar("\n>Ingrese su Primer Apellido: "));
			strupr(participantes[i].apellido1);
		}while(participantes[i].apellido1=="");
		do{
			strcpy(participantes[i].apellido2,ingresarChar("\n>Ingrese su Segundo Apellido: "));
			strupr(participantes[i].apellido2);
		}while(participantes[i].apellido2=="");
		string dataIn;
    	int auxcedAG;
	    char data[15];
        bool dataEntered = false;
        while (!dataEntered){
            ingresoCedula:
			strcpy(data,ingresarDatosEnteros("\n>Ingrese su cedula: "));
            dataIn=atoi(data);
            auxcedAG=atoi(data);
			//auxcedAG=auxcedAG;
			int listaCed=atoi(data);
			listaCedula.insertarCab(listaCed);
			//
            if (dataIn.empty()){
                std::cout << "No se ingreso un dato" << endl;
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
			if (participantes[i].cedula==auxcedAG)
			{
				std::cout<<"\t<-- Ingrese otra cedula, esta ya existe"<<endl;
				goto ingresoCedula;
			}
        }while (v==0);
		participantes[i].cedula=auxcedAG;
		listaCedula.insertarCab(auxcedAG);
		do{
			strcpy(participantes[i].cargo,ingresarChar("\n> Ingrese su Cargo: "));
			strupr(participantes[i].cargo);
		}while(participantes[i].cargo=="");
		do{
			strcpy(dato9,ingresarDatosFlotantes("\n> Ingrese el valor su Salario: $"));
			participantes[i].salario=atof(dato9);
		}while(participantes[i].salario>3000.5 || participantes[i].salario<425);
		escogido=menu3(opciones, p);
        //system("cls");
		double adelanto;
        switch (escogido){
			case 1:
				if (escogido==1)
				{
					adelantomenu:
					strcpy(dato4,ingresarDatosFlotantes("\n\n> Ingrese el valor del Anticipo que solicito previamente: "));
                	adelanto=atof(dato4);
					if(adelanto>227.5){
						goto adelantomenu;
					}else{
						participantes[i].valorAnticipo=adelanto;
					}
				}
				break;
			case 2:
				if (escogido==2)
				{
					adelanto=0;
					participantes[i].valorAnticipo=adelanto;
				}
				break;										
		}
		int res=0;
		double auxHE;
					do{
							std::cout<<"\n> Realizo horas extras?:(1=SI | 2=NO) ";
							strcpy(dato3,ingresarDatosEnteros(": "));
							res=atoi(dato3);
						if (res==1)
						{
							strcpy(dato5,ingresarDatosEnteros("\n> Ingrese las Horas Extra que ha realizado: "));
							auxHE=atof(dato5);
						}if (res==2)
						{
							auxHE=0;
							break;
						}
					}while(auxHE==0);
					participantes[i].horasExtra=auxHE;
	}
	std::cout<<endl;
	system("cls");
	//
	std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"|\t          *FICHA DE EMPLEADO INDIVIDUAL*                 |"<<endl;
    
	std::cout<<"| >Nombre: "<<participantes[i].apellidos_nombres<<" "<<participantes[i].nombre2<<" "<<participantes[i].apellido1<<" "<<participantes[i].apellido2<<endl;
    std::cout<<"| >Cedula: "<<participantes[i].cedula<<"\t\t\t\t\t   |"<<endl;
    std::cout<<"| >Cargo: "<<participantes[i].cargo<<endl;
    std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"|           *INGRESOS*                                      "<<endl;
    std::cout<<"| >Salario: $"<<participantes[i].salario;
    std::cout<<"+----------------------------------------------------------+"<<endl;    
    std::cout<<"+----------------------------------------------------------+"<<endl;
    std::cout<<"| >Fecha de ingreso: $"<<endl;
    std::cout<<"+----------------------------------------------------------+"<<endl;
    system("pause");
    system("cls");
    return 0;
}

void buscaCedula(){
	ClistaSimple listaCedula;
	listaCedula.imprimir();
}

void imprime_inscritos(ifstream &lectura){
	char nombre1[15],nombre2[15],apellido1[15],apellido2[15];
	int c=0,i,j,cedula;		
	system("cls");
	//system("color 06");
	lectura.open("inscripcion.txt",ios::in);
	if (lectura.is_open()){
		lectura>>nombre1;
		while(!lectura.eof()){
			lectura>>participantes[c].nombre2;
			lectura>>participantes[c].apellido1;
			lectura>>participantes[c].apellido2;
			lectura>>participantes[c].cedula;
			lectura>>participantes[c].cargo;
			lectura>>participantes[c].salario;
			
			strcpy(participantes[c].apellidos_nombres,nombre1);	
			strcat(participantes[c].apellidos_nombres," ");			
			strcat(participantes[c].apellidos_nombres,apellido1);
			c++;			
			lectura>>nombre1;
		}
	}
	lectura.close();
	system("color 04");
	cout<<"\t\tx~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~x"<<endl;
	cout<<"\t\t|                                       EMPLEADOS REGISTRADOS                                  |"<<endl;
	cout<<"\t\tx~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~x"<<endl;
	cout<<"\t\t|  ORD.\t | \tNOMBRE Y APELLIDO\t|     CEDULA\t |\t POR RECIBIR ESTE MES"<<endl;
	for(i=0;i<c;i++){
		cout<<"\t\t|---------------------------------------------------------------------------------------------|"<<endl;
		cout<<"\t\t|    "<<i+1<<"\t\t\t\t\t|   "<<participantes[i].cedula<<"\t|\t\t "<<"$"<<participantes[i].pagaPorRecibir<<endl;
		cout<<"\t\t\t |\t"<<participantes[i].apellidos_nombres<<participantes[i].apellido1<<"\t"<<endl;
	}	cout<<"\t\tx---------------------------------------------------------------------------------------------x"<<endl;
	cout<<"\n\t\t> Para retornar al menu. ";
	system("pause");
}
