/*
	Universidad de las Fuerzas Armadas ESPE
	-- Estructura de Datos--
	Alumno/s: Gutiérrez Miguel, Rivera Sebastián, Suquillo Martín
	Fecha de creación: 29/05/2023
	Enunciado: Taller - Ingreso por cabaza y cola a lista simple
	Nivel.- 3  NRC: 9671 
*/

#include "OperacionIngreso.cpp"

int main() {
    OperacionIngreso lista;

    int opcion;
    do {
        cout << "-------------------------" << endl;
        cout << "1. Insertar alumno al principio de la lista." << endl;
        cout << "2. Insertar alumno al final de la lista." << endl;
        cout << "3. Mostrar lista de alumnos." << endl;
        cout << "4. Salir." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                lista.insertarAlumnoCabeza();
                break;
            case 2:
                lista.insertarAlumnoCola();
                break;
            case 3:
                lista.mostrarAlumnos();
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 4);

    return 0;
}
