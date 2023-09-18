#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>

using namespace std;

#define FIL 4 //cambiar para ingresar los "b"
#define COL 4

int main(int argc, char const *argv[])
{
    
    int i=0,j=0,opcion=0;
    double b[FIL]={0},x0=0,xv=0;

    FILE *fp;
    char ch;
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/matriz.dat","r");
    if ( fp == NULL )
    {
        perror( "No se puede abrir el archivo");
		return 1;
    }

    //contador de filas
    int filas=0;
    char c;
    int maxValues = 0;
	int columnas;
    
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n'){
            filas++;
		}
    }

    printf("numero de filas=%i\n",filas);

    //cerramos y reabrimos el archivo para resetear el puntero
    fclose(fp);
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/matriz.dat","r");
    double arreglo[filas][100]={0};


    //Cargo los datos leidos en el array
    
	for(i = 0; i < filas; i++) {
		j = 0;
		do {
        fscanf(fp, "%lf", &(arreglo[i][j]));
        j++;
			} while((c = fgetc(fp)) != '\n');
	}

	columnas = j;
	
	printf("numero de columnas= %i\n",columnas);
    //imprimo la matriz para verificar que lo leyo correctamente
    
        for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            printf("%lf ",arreglo[i][j]);
        }
        printf("\n");
    }

    printf("\n---Carga de los b---");
        for(i= 0; i < FIL; i++){
            printf("\nb[%d]= ",i);
            scanf("%lf",&b[i]);
        }

    do
    {
        
        printf("\n---MENU---");
        printf("1- Jacobi");
        printf("2- Gauss - Seidel");
        printf("----------");
        scanf("%d",&opcion);

        switch(opcion){

            case 1:

            break;

            case 2:

            break;

        }




    } while (opcion != 3);
    


    return 0;
}
