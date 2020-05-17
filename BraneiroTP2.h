/*
 * BraneiroTP2.h
 *
 *  Created on: 15 may. 2020
 *      Author: admin
 */

#ifndef BRANEIROTP2_H_
#define BRANEIROTP2_H_
typedef struct{

	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;


}eEmpleado;


#endif /* BRANEIROTP2_H_ */


int menuInformes();
/** \brief llama al menu de informes y a la funcion elegida por el usuario
 * \return devuelve la opcion elegida por el usuario
 */
int menuEmpleados();
/** \brief llama al menu ABM y a la funcion elegida por el usuario
 * \return devuelve la opcion elegida por el usuario
 */
int menuModificar();
/** \brief llama al menu interno para elegir el dato a modificar
 * \return devuelve la opcion elegida por el usuario
 */

int altaEmpleado(int idx, eEmpleado vec[], int tam);
/** \brief busca en el vector de tipo eEmpleado si hay espacio y da de alta a un empleado con los datos ingresados
 * \param id del empleado ingresado
 * \param vector de eEmpleado a recorrer
 * \param tamanio del vector a recorrer
 * \return devuelve -1 si el espacio no esta vacio o devuelve 0 y el indice del lugar vacio
 */
int buscarLibre(eEmpleado vec[], int tam);
/** \brief busca el primer lugar libre o no de un empleado usando un id en un vector de eEmpleado
 * \param vector de eEmpleado a recorrer
 * \param tamanio del vector
 * \return devuelve el indice del primer lugar vacio o sino muestra un mensaje de error (sistema lleno)
 */

void inicializarEmpleados(eEmpleado vec[], int tam);
/** \brief busca un espacio vacio en un vector de eEmpleado y le carga los datos si estan ingresados correctamente
 * \param vector de eEmpleado a utilizar para cargar el nuevo empleado
 * \param tamanio del vector de eEmpleado para recorrer
 */

void modificarEmpleado(eEmpleado vec[], int tam);
/** \brief recorre el vector de tipo eEmpleado para modificarlo segun el usuario quiera
 * \param recibe un vector de tipo eEmpleado
 * \param recibe el tamanio del vector a modificar
 */

int buscarEmpleado(int idx, eEmpleado vec[], int tam);
/** \brief sirve para buscar un empleado dentro del array
 * \param id del empleado a buscar
 * \param vector de eEmpleado a recorrer para la busqueda
 * \param tamanio del vector de eEmpleado a recorrer
 * \return devuelve 1 si encontro al empleado, sino, devuelve un mensaje de error.
 */
void mostrarEmpleado(eEmpleado x);
/** \brief muestra a un empleado
 * \param recibe un escalar de tipo eEmpleado
 */
void mostrarEmpleados(eEmpleado [], int tam);
/** \brief muestra a todos los empleados cargados
 * \param recibe un vector de tipo eEmpleado
 * \param recibe el tamanio del vector a recorrer
 */
void bajaEmpleado(eEmpleado vec[], int tam);
/** \brief elimina del sistema a un empleado en particular
 * \param recibe un vector de tipo eEmpleado
 * \param recibe el tamanio del vector a recorrer
 */
void informeSueldos(eEmpleado vec[], int tam);
/** \brief realiza las operaciones para obtener el promedio de los salarios y el total
 * \param recibe un vector de tipo eEmpleado
 * \param recibe el tamanio del vector a recorrer
 */
void ordenarEmpleados(eEmpleado vec[], int tam);
/** \brief Ordena los empleados segun el criterio pedido
 * \param recibe un vector de tipo eEmpleado
 * \param recibe el tamanio del vector a recorrer
 */
void informar(eEmpleado vec[], int tam);
/** \brief contiene dentro las funciones donde se informan los empleados segun el criterio pedido y las distintos casos de informes
 * \param recibe un vector de tipo eEmpleado
 * \param recibe el tamanio del vector a recorrer
 */
