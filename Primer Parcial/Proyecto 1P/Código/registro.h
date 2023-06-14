/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 01/05/2023
	Enunciado: Proyecto 1P
	Nivel.- 3  NRC: 9671 
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