/*
	UFA-ESPE
	Alumnos: Miguel Gutierrez, Sebastian Rivera, Martin Suquillo.
	Fecha de creación: 20/11/2022
	Fecha de modificación: 30/11/2022
	Enunciado: Proyecto con uso Dobles generar datos de empleados de un hospital de ancianos
	Nivel.- 3   NRC: 9671
*/
#ifndef CNODOLS_H
#define CNODOLS_H
#include <iostream>
using namespace std;

class CnodoLS{
    private:
        int entrada;
        CnodoLS *siguiente;

    public:
        CnodoLS(int, CnodoLS *siguiente);
        CnodoLS();
        ~CnodoLS();
        int getEntrada();
        CnodoLS *getSiguiente();
        void setEntrada(int);
        void setSiguiente(CnodoLS *siguiente);
};
#endif