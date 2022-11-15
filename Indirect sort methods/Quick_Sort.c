/*
OrdenamientoQuickSort.c
V 1.0 Noviembre 2022
Autores: Riveros González Armando Uriel
         Gamez Rosas Javier de Jesús
         
Programa que lee "n" numeros de la entrada estandar y son
colocados en un arreglo "A", posterioremente son ordenados 
a través del algoritmo de Ordenamiento QuickSort.
Igualmente se contará el tiempo que tarda
en ordenar los numeros
Complejidad O(nlogn)
Compilación:
Windows: gcc OrdenamientoQuickSort.c -o quick
Ejemplo de uso: quick 1000 < numeros1M.txt > salida.txt
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Definimos los prototipos de nuestras funciones
void QuickSort(int *A, int p, int r);
void intercambiar(int *A,int i,int j);
int pivot(int *A, int p, int r);

int main(int n_arg, char *s_arg[]){
	
	int *arreglo;
	int i,n;
	
	//Variables para medir el tiempo
    double t_intervalo;
	clock_t t_inicio, t_final;	
	
	//Se encarga de recibir el numero de argumentos demandados
	if(n_arg!=2){
        printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n",s_arg[0]);
        exit(1);
    }
	
	//Convierte la cadena de caracteres a enteros
	n = atoi(s_arg[1]);
	
	//Se manda a llamar la memoria dinamica		
	arreglo = malloc(sizeof(int)*n);
	
	/*Si no llega a funcionar o no se encuentra memoria dinamica 
	entonces se cierra el programa*/	
	if(!arreglo){
		exit(2);
	}

    printf("\t\tQUICK SORT\n");
	printf("El numero de elementos a ordenar son: %i",n);

	for(i=0;i<n;i++){
		scanf("%i",&arreglo[i]);
	}
	
	//Se inicia el conteo del tiempo de ordenamiento
	t_inicio = clock();
	
	QuickSort(arreglo,0,n-1);		//Llamamos a la función principal 

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

/*Función recibe la direccion del arreglo y ambos iteradores 
para realizar el intercambio.
devuelve void(no retorna valor explicito)*/
void intercambiar(int* A,int i,int j){
	
	//Se realiza el intercambio
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

/*Función recibe la direccion del arreglo y la posción
del inicio y la final del arreglo.
devuelve void(no retorna valor explicito)*/
int pivot(int *A, int p, int r){
	
	int piv = p;
	int i = p;
	int j = r;
	
	while(i<j){
		
		/*Los numeros detras del pivote o iguales, deben de ser menores
		y así continua avanzando hacia el pivote*/
		while((A[i]<=A[piv]) && (i<r)){
			i++;
		}
		
		/*Los numeros delante del pivote deben de ser mayores
		y así continua avanzando hacia el pivote, que en este
		caso se encuentra si retrocede la j*/
		while(A[j]>A[piv]){
			j--;
		}
		if(i<j){

			//Se manda a llamar la funcion de intercambiar
			intercambiar(A,i,j);
		}	
	}
	
	return j; //Devolvemos el nuevo pivote
}

/*Función recibe la direccion del arreglo y la posción
del inicio y la final del arreglo.
devuelve void(no retorna valor explicito)*/
void QuickSort(int *A, int p, int r){
	
	if(p<r){
		int j = pivot(A,p,r);
		
		/*Mandamos a llamar a la función ya que es recursiva y la
		limitamos desde el inicio del arreglo hasta la "j" que es
		el medio*/
		QuickSort(A,p,j-1);	//Ordenamos la sublista izq.
		
		/*Mandamos a llamar a la función ya que es recursiva y la
		limitamos desde el medio hasta el final que es "u"*/
		QuickSort(A,j+1,r);	//Ordenamos la sublista der.
	}
}
