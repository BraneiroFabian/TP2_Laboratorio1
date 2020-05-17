/*
 * BraneiroTP2.c
 *
 *  Created on: 15 may. 2020
 *      Author: admin
 */

#include "BraneiroTP2.h"
#include "Validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menuEmpleados(){
	system("cls");
	int opcion;


	printf("*****MENU OPCIONES*****\n\n");
	printf("1. Alta empleado\n");
	printf("2. Modificar empleado\n");
	printf("3. Baja empleado\n");
	printf("4. Listar empleado\n");
	printf("5. Salir\n\n");
	printf("Ingrese opcion deseada: ");

	scanf("%d",&opcion);

	return opcion;

}

int altaEmpleado(int idx, eEmpleado vec[], int tam){

	int todoOk=-1;
	eEmpleado auxEmpleado;
	int indice;
	float auxFloat;
	char auxChar[51];
	int auxInt;




	indice = buscarLibre(vec,tam);

	if(indice==-1){
		printf("Sistema completo\n\n");
	}else{
		while(todoOk==-1){

			if((utn_getCadena(auxChar,51,3,"Ingrese su nombre: ","Nombre no valido. Reingrese\n"))==0){
				strcpy(auxEmpleado.nombre, auxChar);
			}else{
				printf("Se quedo sin intentos\n");
				todoOk=0;
				break;
			}

			if((utn_getCadena(auxChar,51,3,"Ingrese su apellido: ","Apellido no valido. Reingrese\n"))==0){
				strcpy(auxEmpleado.apellido,auxChar);
			}else{
				printf("Se quedo sin intentos\n");
				todoOk=0;
				break;
			}

			if((utn_getFlotante(&auxFloat,3,"Ingrese salario: ", "Salario no valido. Reigrese\n",1,999999999))==0){
				auxEmpleado.salario=auxFloat;
			}else{
				printf("Se quedo sin intentos\n");
				todoOk=0;
				break;
			}

			if((utn_getEntero(&auxInt,3,"Ingrese sector: ","Sector no valido. Reingrese\n",0,999999999))==0){
				auxEmpleado.sector=auxInt;
				todoOk=1;
			}else{
				printf("Se quedo sin intentos\n");

				break;
			}



		}
		if(todoOk==1){
			auxEmpleado.id=idx;
			auxEmpleado.isEmpty=0;
			vec[indice]=auxEmpleado;
			printf("\n\nEl ID del nuevo empleado es: %d\n ",idx);
		}
	}

	return todoOk;

}


int buscarLibre(eEmpleado vec[], int tam){

	int indice=-1;

	for(int i=0; i<tam;i++){
		if(vec[i].isEmpty==1){
			indice=i;
			break;
		}
	}
	return indice;
}


void inicializarEmpleados(eEmpleado vec[], int tam){

	for(int i=0;i<tam;i++){

		vec[i].isEmpty=1;
	}
}

void modificarEmpleado(eEmpleado vec[], int tam){

	int indice;
	char confirma;
	int id;
	char auxChar[51];
	int auxInt;
	float auxFloat;

		printf("Ingrese ID de empleado: ");
		scanf("%d",&id);

	indice=buscarEmpleado(id,vec,tam);

	if (indice==-1){
		printf("No hay ningun empleado con el id:%d ",id);

	}else{
		printf("ID     NOMBRE     APELLIDO     SALARIO     SECTOR     \n\n");
		mostrarEmpleado(vec[indice]);
		printf("Desea modificar este empleado? (s/n): ");
		fflush(stdin);
		scanf("%c",&confirma);
		if(confirma=='s'){

			switch(menuModificar()){

				case 'a':
					utn_getCadena(auxChar,51,3,"Ingrese nuevo nombre: ","Nombre no valido. Reingrese\n");
					strcpy(vec[indice].nombre,auxChar);
					system("cls");
					printf("Se actualizo el nombre\n");
					break;
				case 'b':
					utn_getCadena(auxChar,51,3,"Ingrese nuevo apellido: ","Apellido no valido. Reingrese\n");
					strcpy(vec[indice].apellido,auxChar);
					system("cls");
					printf("Se actualizo el apellido\n");
					break;
				case 'c':
					utn_getFlotante(&auxFloat,3,"Ingrese nuevo salario: ", "Salario no valido. Reingrese\n",1,999999999);
					vec[indice].salario=auxFloat;
					system("cls");
					printf("Se actualizo el salario\n");
					break;
				case 'd':
					utn_getEntero(&auxInt,3,"Ingrese nuevo sector: ","Sector no valido. Reingrese\n",0,999999999);
					vec[indice].sector=auxInt;
					system("cls");
					printf("Se actualizo el sector\n");
					break;



			}




		}

	}










}

int buscarEmpleado(int idx, eEmpleado vec[], int tam){

	int indice=-1;

		for(int i=0; i<tam;i++){
			if(vec[i].id==idx && vec[i].isEmpty==0){
				indice=i;
				break;
			}
		}
		return indice;
}

void mostrarEmpleado(eEmpleado x){

	printf("%d      %s     %s     %.2f     %d     \n\n",x.id,x.nombre,x.apellido,x.salario,x.sector);



}

void mostrarEmpleados(eEmpleado vec[], int tam){
	int flag=0;

	printf("* * * * *LISTA DE EMPLEADOS* * * * *\n\n");
	printf("ID     NOMBRE     APELLIDO     SALARIO     SECTOR     \n\n");

	for(int i=0;i<tam;i++){
		if(vec[i].isEmpty==0){

			mostrarEmpleado(vec[i]);
			flag=1;
		}


	}
	if (flag==0){

		printf("No hay empleados que listar\n");
	}

}

int menuModificar(){
	system("cls");
	char opcion;
	printf("a. Modificar nombre\n");
	printf("b. Modificar apellido\n");
	printf("c. Modificar salario\n");
	printf("d. Modificar sector\n\n");
	printf("Ingrese opcion deseada: ");
	fflush(stdin);
	scanf("%c",&opcion);

	return opcion;
}

void bajaEmpleado(eEmpleado vec[], int tam){

	int id;
	int indice;
	char confirma;


		printf("Ingrese ID de empleado: ");
		scanf("%d",&id);

	indice=buscarEmpleado(id,vec,tam);

	if (indice==-1){
		printf("No hay ningun empleado con el id:%d ",id);

	}else{
		printf("ID     NOMBRE     APELLIDO     SALARIO     SECTOR     \n\n");
		mostrarEmpleado(vec[indice]);
		printf("Desea eliminar este empleado? (s/n): ");
		fflush(stdin);
		scanf("%c",&confirma);
		if(confirma=='s'){
			vec[indice].isEmpty=1;
			printf("Se ha realizado la baja con exito.\n");

		}else{

			printf("\nSe cancelo la operacion\n\n");

		}
}
}

void ordenarEmpleados(eEmpleado vec[], int tam){


	eEmpleado auxEmpleado;
	int orden;

	printf("Ingrese como desea ordenar los empleados, 1 para ordenar ASCENDENTE o 0 para ordenar DESCENDENTE : \n");
	scanf("%d",&orden);

    for(int i=0; i<tam -1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {
            if (orden==1){
            	if(vec[i].isEmpty==0 && vec[i].sector>vec[j].sector){

            		auxEmpleado=vec[i];
            		vec[i]=vec[j];
            		vec[j]=auxEmpleado;

            	}else
            		if(vec[i].sector == vec[j].sector && strcmp(vec[i].apellido,vec[j].apellido)>0){

            		auxEmpleado=vec[i];
            		vec[i]=vec[j];
            		vec[j]=auxEmpleado;
            	}
            }else
            {
            	if(vec[i].isEmpty==0 && vec[i].sector<vec[j].sector){

            	            		auxEmpleado=vec[i];
            	            		vec[i]=vec[j];
            	            		vec[j]=auxEmpleado;

            	            	}else
            	            		if(vec[i].sector == vec[j].sector && strcmp(vec[i].apellido,vec[j].apellido)==-1){

            	            		auxEmpleado=vec[i];
            	            		vec[i]=vec[j];
            	            		vec[j]=auxEmpleado;
            }
        }
    }

}
    mostrarEmpleados(vec,tam);
}

    int menuInformes()
    {
	int opcion;
	system("cls");
	printf("1. Listado de empleados ordenados por sector y apellido\n");
	printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n\n");
	printf("3. Volver al menu anterior\n\n");
	printf("Ingrese opcion deseada: ");
	scanf("%d",&opcion);

	return opcion;
}


    void informeSueldos(eEmpleado vec[], int tam)
    {

	float total=0;
	int cantidadEmpleados=0;
	float promedio;
	int empleadosPasandoPromedio=0;

	for(int i=0;i<tam;i++){

		if(vec[i].isEmpty==0){

			total+=vec[i].salario;
			cantidadEmpleados++;
		}
	}
	promedio=(float)total/cantidadEmpleados;
	for (int i=0;i<tam;i++){

		if (vec[i].isEmpty==0 && vec[i].salario>promedio){
			empleadosPasandoPromedio++;

		}

	}

	system("cls");
	printf("El total de los sueldos es: %.f\n",total);
	printf("El promedio de los sueldos es: %.2f\n ",promedio);
	printf("Los empleados que superan el promedio son: %d\n",empleadosPasandoPromedio);
}

    void informar(eEmpleado vec[],int tam)
{
			char seguir='s';
			char confirma;
			do{
				switch(menuInformes()){
				case 1:
					ordenarEmpleados(vec,tam);
					system("pause");
					break;
				case 2:
					informeSueldos(vec,tam);
					system("pause");
					break;
				case 3:
					printf("Confirma salida? (s/n): ");
					fflush(stdin);
					scanf("%c",&confirma);
					if(confirma=='s'){

						seguir='n';

					}
					break;
				default:
					printf("Opcion no valida \n\n");
					break;
				}
				fflush(stdin);
			}while(seguir=='s');
}


