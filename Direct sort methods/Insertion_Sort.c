/*
OrdenamientoInsercion.c
V 1.0 Noviembre 2022
Autores: Gamez Rosas Javier de Jesus
         Riveros González Armando Uriel
         
Programa que lee "n" numeros de la entrada estandar y son
colocados en un arreglo "A", posterioremente son ordenados 
a través del algoritmo de Ordenamiento Insercion.
Igualmente se contará el tiempo que tarda
en ordenar los numeros
Complejidad O(n^2)
Compilación:
Windows: gcc OrdenamientoInsercion.c -o insercion
Ejemplo de uso: insercion 1000 < numeros1M.txt > salida.txt
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Prototipos de las funciones
void ProcedimientoInsercion(int arreglo[], int n);

int main(int n_arg, char *s_arg[]){

     //Se declaran las variables
	int i,n;	
	int *arreglo;

	//Se declaran las variables de medición del tiempo
    double t_intervalo;
	clock_t t_inicio, t_final;

	//Se encarga de recibir el numero de argumentos demandados
    if(n_arg!=2){
        printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n",s_arg[0]);
        exit(1);
    }	
	
	//Transforma las cadenas de caracteres	a enteros
	n = atoi(s_arg[1]);
	
	//Se manda a llamar la memoria dinamica
	arreglo = malloc(sizeof(int)*n);
	
	/*Si no llega a funcionar o no se encuentra memoria dinamica, 
	entonces se cierra el programa*/
	if(arreglo==NULL){
		exit(2);
	}
	
	printf("\t\tORDENAMIENTO INSERCION\n");
	printf("Numero de elementos a ordenar es: %i \n",n);
	for(i=0;i<n;i++){
		scanf("%i",&arreglo[i]);
	}
	
	//Se inicia el conteo del tiempo de ordenamiento
	t_inicio = clock();
	
	//Se llama a la funcíon del ordenamiento
	ProcedimientoInsercion(arreglo,n);

	/*Indicará la posición del arreglo y el entero que 
	lo acompaña*/
	for(i=0;i<n;i++){
		printf("\n[%i] = %i",i,arreglo[i]);
	}
    
    //Final del tiempo medido del ordenamiento
	t_final = clock();   
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
	   
    //Mostrar el tiempo medido 
	printf("\n\nTiempo medido: %.8f segundos.", t_intervalo);
	
	free(arreglo);
	
	return 0;
}

/*Función recibe la direccion del arreglo y el tamaño de este.
devuelve void(no retorna valor explicito)*/
void ProcedimientoInsercion(int arreglo[], int n){
	
	//Una variable llamada "pos" que indicara la posicion del arreglo
	int i,pos,temp;
	
	for(i=0;i<n;i++){
		pos = i;				//Indica en que posición se encuentra y lo recorrerá
		temp = arreglo[i];		//Indica en que numero del arreglo se encuentra
		
		/*Mientars la posicion sea mayor a 0 y el numero de la 
		izquierda sea mayor al numero de la derecha*/
		while((pos>0)  &&  (arreglo[pos-1]>temp)){
			arreglo[pos] = arreglo[pos-1];			//Se intercambian los valores
			pos--;									//La posición va a ir disminuyendo
		}
		arreglo[pos] = temp;
	}
}
