/*
OrdenamientoBurbuja.c
V 1.0 Noviembre 2022
Autores: Gamez Rosas Javier de Jesus
         Riveros González Armando Uriel
         
Programa que lee "n" numeros de la entrada estandar y son
colocados en un arreglo "A", posterioremente son ordenados 
a través del algoritmo de Ordenamiento Burbuja.
Igualmente se contará el tiempo que tarda
en ordenar los numeros
Complejidad O(n^2)
Compilación:
Windows: gcc OrdenamientoBurbuja.c -o burbuja
Ejemplo de uso: burbuja 1000 < numeros1M.txt > salida.txt
*/

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

int main(int n_arg, char *s_arg[]){

    //Variables del algotritmo de ordenamiento
    int i=0,n,k,j;
    int cambios=1;
    int *A;
    int aux;

    //Variables para medir el tiempo
    clock_t t_inicio, t_final;
    double t_intervalo;

    //Se encarga de verificar el numero de argumentos demandados
    if(n_arg!=2){
        printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n",s_arg[0]);
        exit(1);
    }
        

    //Convierte la cadena de caracteres a enteros
    n = atoi(s_arg[1]);

	//Se manda a llamar la memoria dinamica	
    A = malloc(n*sizeof(int));

	/*Si no llega a funcionar o no se encuentra memoria dinamica, 
	entonces se cierra el programa*/	
    if(A==NULL){
        exit(2);
    }

    printf("\t\tORDENAMIENTO BURBUJA\n");
	printf("Numero de elementos a ordenar es: %i \n",n);
    for(k=0;k<n;k++)
        scanf("%d",&A[k]);
    
	//Se inicia el conteo del tiempo de ordenamiento
    t_inicio = clock();
    
    /*Se seguirá recorriendo el arreglo mientras no existan
    más cambios, estó significará que el arreglo se encuentra 
    ordenado*/
    while (i<=n-2 && cambios != 0){
        cambios=0;

        /*Con la primera iteración que se realiza, el numero mayor 
        queda posicionado en su lugar y no hace falta compararlo más*/
        for(j=0;j<=(n-2)-i;j++){        //Con el (n-2)-i se reducen el numero de iteraciones que se realizan

            /*Si el de la izquierda es menor que 
            el de la derecha entonces*/
            if(A[j]<A[j+1]){
                
                //Se realiza el intecambio
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                cambios = 1; 
            }
        }
        i=i+1;     //Avanza en el arreglo
    }   

    /*Indicará la posición del arreglo y el entero que 
	lo acompaña*/
   for(i=0;i<n;i++){
     printf("\n%d = %d ",i,A[n-i-1]); 
   }

    //Final del tiempo medido del ordenamiento
    t_final = clock();   
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;

    //Mostrar el tiempo medido 
	printf("\n\nTiempo medido: %.8f segundos.", t_intervalo);
	
	free(A);
	
    return 0;
}   
