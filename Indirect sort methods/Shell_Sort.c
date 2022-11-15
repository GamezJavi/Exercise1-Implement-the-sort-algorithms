/*
OrdenamientoShell.c
V 1.0 Noviembre 2022
Autores: Gamez Rosas Javier de Jesus
         Riveros González Armando Uriel
         
Programa que lee "n" numeros de la entrada estandar y son
colocados en un arreglo "A", posterioremente son ordenados 
a través del algoritmo de Ordenamiento Shell.
Igualmente se contará el tiempo que tarda
en ordenar los numeros
Complejidad O(n^2)
Compilación:
Windows: gcc OrdenamientoShell.c -o shell
Ejemplo de uso: shell 1000 < numeros1M.txt > salida.txt
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>	//Para la función "trunc"

//Declaramos el prototipo de la función
void procedimientoShell(int *A, int n);

int main(int n_arg, char *s_arg[]){

    int *arreglo,n,i;
    
    //Variables para medir el tiempo del ordenamiento
    double t_intervalo;
	clock_t t_inicio, t_final;
	
	//Se encarga de verificar el numero de argumentos demandados
    if(n_arg!=2){
        printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n",s_arg[0]);
        exit(1);
    }
    
    /*Se va a encargar de transformar las cadenas de caracteres	a enteros*/
    n = atoi(s_arg[1]);
    
    //Mandamos a llamar la memoria dinamica
    arreglo = malloc(sizeof(int)*n);
    
	/*Si no llega a funcionar o no se encuentra memoria dinamica, 
	entonces se "mata el programa"*/
    if(arreglo==NULL){
    	exit(2);
	}
    
    printf("\t\tORDENAMIENTO SHELL\n");
	printf("Numero de elementos a ordenar es: %i \n",n);
	for(i=0;i<n;i++){
		scanf("%i",&arreglo[i]);
	}
    
    //Se inicia el conteo del tiempo de ordenamiento
	t_inicio = clock();
	
	//Se llama a la función del Algoritmo
	procedimientoShell(arreglo,n);
	
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
void procedimientoShell(int *A, int n){

	//Variables del algoritmo
    int i,k,b,temp;
	
    k = trunc(n/2);		//Nos regresará el valor entero sin el decimal

	/*Mientras estén ordenados los elementos al terminar n iteraciones,
	el salto se divide entre 2*/
  	while(k>=1){	
  		b = 1;
  		
		/*Mientras aún haya numeros desordenados (b=0), 
		no se dividirá el salo entre 2*/
  		while(b!=0){
  			b = 0;
  			
  			for(i=k;i<n;i++){
  				if(A[i-k] > A[i]){	//Los elementos no están ordenados
  					
					//Se realiza el intercambio
  					temp = A[i];
  					A[i] = A[i-k];
  					A[i-k] = temp;
  					b = b+1;
				  }
			  }
		  }
		/*Se continua dividiendo el salto
		hasta que sea igual a 1*/
  		k = trunc(k/2);
	  }
}
