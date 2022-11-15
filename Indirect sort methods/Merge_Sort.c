/*
OrdenamientoMergeSort.c
V 1.0 Noviembre 2022
Autores: Riveros González Armando Uriel
         Gamez Rosas Javier de Jesús
         
Programa que lee "n" numeros de la entrada estandar y son
colocados en un arreglo "A", posterioremente son ordenados 
a través del algoritmo de Ordenamiento MergeSort.
Igualmente se contará el tiempo que tarda
en ordenar los numeros
Complejidad O(n)
Compilación:
Windows: gcc OrdenamientoMergeSort.c -o merge
Ejemplo de uso: merge 1000 < numeros1M.txt > salida.txt
*/

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

//Declaramos los prototipos de las funciones
void MergeSort(int* A, int p, int r);
void Merge(int* A, int p, int q, int r);

int main(int n_arg, char *s_arg[]){
	
	//Variables del algoritmo
	int n=0,i;
    int *A;
	int primero,medio,ultimo;
	
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
	A = malloc(n*sizeof(int));
	
	/*Si no llega a funcionar o no se encuentra memoria dinamica, 
	entonces se "mata el programa"*/	
	if(A==NULL){
        exit(2);
    }

	printf("\t\tMERGE SORT\n");
	printf("Numero de elementos a ordenar es: %i ",n);
		
	for(i=0;i<n;i++){	
		scanf("%d",&A[i]);
	}
	
	//Se inicia el conteo del tiempo de ordenamiento
	t_inicio = clock();
	
	//Se llama a la función principal
	MergeSort(A, 0, n - 1);
	
	/*Indicara la posicion del arreglo y el entero que 
	lo acompaña*/
	for(i=0;i<n;i++){
		printf("\n[%d] = %d",i,A[i]);
	}
    
    //Final del tiempo medido del ordenamiento
	t_final = clock();   
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
	   
    //Mostrar el tiempo medido 
	printf("\n\nTiempo medido: %.8f segundos.", t_intervalo);
	
	free(A);
	
	return 0;
}
/*Función recibe la direccion del arreglo, ademas 
de la primer y ultima posicion del arreglo.
Devuelve void(no retorna valor explicito)*/
void MergeSort(int *A, int p, int r){
	
	if(p<r){

		//Se vuelven a llamar las funciones por recursividad
		int q = ((p+r)/2);
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}

/*Función recibe la direccion del arreglo, 
ademas de la primer posicion, ultima 
posicion y la parte del medio del arreglo.
Devuelve void(no retorna valor explicito)*/
void Merge(int *A, int p, int q, int r){
	
	int k;
	int *C;
	int l = r-p+1;
	int i = p;
	int j = q+1;
	C = malloc(l*sizeof(int));
	
	for(k=0;k<l;k++){
		if((i<=q) && (j<=r)){
			if(A[i]<A[j]){
				C[k] = A[i];
				i++;
			}
			else{
				C[k] = A[j];
				j++;
			}
		}else if(i<=q){
			C[k] = A[i];
			i++;
		}
		else{
			C[k] = A[j];
			j++;
		}
	}
	for(k=p,i=0;k<=r;k++,i++){
		A[k] = C[i];
	}
	free(C);
}
