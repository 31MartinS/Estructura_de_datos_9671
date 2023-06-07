/*
	UFA-ESPE
	Alumnos: Miguel Gutierrez, Sebastian Rivera, Martin Suquillo.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso Dobles generar datos de empleados de un hospital de ancianos
	Nivel.- 3   NRC: 9671
*/
#pragma once
#include <ctype.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <istream>
#include <conio.h>
#include <iostream>
#include "menus.h"
#include <fstream>
#define N 30
using namespace std;
struct registro{
	char apellidos_nombres[100];
	char nombre2[20];
	char apellido1[20];
	char apellido2[20];
	char cargo[20];
	double salario;
	int cedula;
	int horasExtra;
	double anticipo;
	double valorAnticipo;
    int saldo; //Opcion menu
	double pagaPorRecibir;
}participantes[100];