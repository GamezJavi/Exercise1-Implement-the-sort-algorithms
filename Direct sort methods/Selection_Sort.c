/*
OrdenamientoSeleccion.c
V 1.0 Noviembre 2022
Autores: Gamez Rosas Javier de Jesus
         Riveros Gonz�lez Armando Uriel
         
Programa que lee "n" numeros de la entrada estandar y son
colocados en un arreglo "A", posterioremente son ordenados 
a trav�s del algoritmo de Ordenamiento Selecci�n.
Igualmente se contar� el tiempo que tarda
en ordenar los numeros
Complejidad O(n^2)
Compilaci�n:
Windows: gcc OrdenamientoSelecci�n.c -o seleccion
Ejemplo de uso: seleccion 1000 < numeros1M.txt > salida.txt
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
int main(int n_arg, char *s_arg[]){

    //Se declaran las variables del algoritmo
    int k,n,i,p;
    int *A;
    int temp;

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
	entonces se "mata el programa"*/	
    if(A==NULL){
        exit(2);
    }

    printf("\t\tORDENAMIENTO SELECCION\n");
	printf("Numero de elementos a ordenar es: %i \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

	//Se inicia el conteo del tiempo de ordenamiento
    t_inicio = clock();

    for(k=0;k<=n-2;k++){
        p = k;          //Se declara el primer elemento como el minimo

        for(i=k+1;i<=n-1;i++){      //k+1 ya que recorre desde una posici�n delante del minimo
            if(A[i]<A[p])          //si hay otro numero minimo que "numeros[j]", entonces se
                p = i;             //situa el nuevo elemento como el menor
        }

        //Se realiza el intercambio
        temp=A[p];
        A[p]=A[k];
        A[k]=temp;
    }  
        /*Indicar� la posici�n del arreglo y el entero que 
	    lo acompa�a*/
        for(i=0;i<n;i++){
            printf("\n%d = %d ",i,A[i]);
        }
     
    //Final del tiempo medido del ordenamiento
    t_final = clock();   
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;  
      
    //Mostrar el tiempo medido 
	printf("\n\nTiempo medido: %.8f segundos.", t_intervalo);
	
	free(A);
	
    return 0;
}   
