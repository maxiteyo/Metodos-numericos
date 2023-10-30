#include <iostream>
#include <math.h>

using namespace std;

double f(double x);
void lecturaDeTabla();
void trapecioSinTabla();
void trapecioConTabla();
void trapecioConTablaNoEqui();
void simpsonSinTabla();
void simpsonConTabla();

int main(int argc, char const *argv[])
{   
    int opcion=0;
    do
    {
        
    printf("\n-----MENU-----  \n");
    printf("1- Trapecio compuesto sin tabla\n");
    printf("2- Trapecio compuesto con tabla\n");
    printf("3- Trapecio compuesto con tabla no equiespaciados\n");
    printf("4- Simpson compuesto sin tabla\n");
    printf("5- Simpson compuesto con tabla\n");
    printf("6- SALIR");
    printf("\n----------\n");
    printf("OPCION: ");
    scanf("%d",&opcion);

    switch (opcion)
    {
    case 1:
    trapecioSinTabla();
    break;
    
    case 2:
    trapecioConTabla();
    break;

    case 3:
    trapecioConTablaNoEqui();
    break;

    case 4:
    simpsonSinTabla();
    break;

    case 5:
    simpsonConTabla();
    break;

    default:
        printf("\nOpcion incorrecta");
        break;
    }
    } while (opcion != 6);
    return 0;
}

double f(double x){
    double f=0;

    f=pow(x,2)+1;
    return f;
}

void lecturaDeTabla(){
    
    FILE *fp;
    char ch;
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/Programa Guia 7/matriz.dat","r");
    if ( fp == NULL )
    {
        puts ( "No se puede abrir el archivo");
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
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/Programa Guia 7/matriz.dat","r");
    double x[filas];
    double y[filas]; //Termino independiente


    //Cargo los datos leidos en el array
    int xi=0;
    int yi=0;
    int j=0;
    int i;
	for(i = 0; i < filas; i++) {
		j = 0;
		
		do {
			if(j==0)
			{
				 fscanf(fp, "%lf", &(x[xi]));
				 xi++;
				 j++;
			}else{
				 fscanf(fp, "%lf", &(y[yi]));
				 yi++;
			}
		} while((c = fgetc(fp)) != '\n');
		
	}

	columnas = j;
	
	printf("numero de columnas=%i\n\n",columnas);

    //imprimo la matriz para verificar que lo leyo correctamente
      
	printf("LOS ELEMENTOS DE LA TABLA SON:\n");
    	
    for(i=0;i<filas;i++){
	        printf( "%lf \t %lf", x[i], y[i]);
	        printf("\n");
	}
	

	
	//ejemplo de como escribir en archivo
	/*
	    FILE * file;
        file= fopen("matriz_1.dat", "w");
		
      for(i=0;i<3;i++){
            fprintf(file, "%lf	%lf	%lf	%lf\n", m[i][0],m[i][1],m[i][2],m[i][3]);
        }
        
      */  


}

void trapecioSinTabla(){
    double a=0,b=0,subintervalos=0;

    printf("\nIngrese el limite a: ");
    scanf("%lf",&a);
    printf("\nIngrese el limite b: ");
    scanf("%lf",&b);
    printf("\nIngrese cantidad de subintervalos: ");
    scanf("%lf",&subintervalos);
    double h=(b-a)/subintervalos;
    double suma=0;

    suma=f(a)+f(b);

    for(int i=1;i<subintervalos;i++){
        suma=suma+2*f(a+i*h);
    }
    double I=0;

    I=((b-a)/(2*subintervalos))*suma;

    printf("\nIntegral= %lf",I);
}

void simpsonSinTabla(){

    double a=0,b=0;
    int subintervalos=0;
    printf("\nIngrese el limite a: ");
    scanf("%lf",&a);
    printf("\nIngrese el limite b: ");
    scanf("%lf",&b);
    printf("\nIngrese cantidad de subintervalos: ");
    scanf("%d",&subintervalos);
    if(subintervalos % 2 != 0){
        printf("\nLa cantidad de subintervalos debe ser par");
        return;
    }
    double suma=0;
    double x=0;
    suma=f(a)+f(b);
    double h=(b-a)/(subintervalos);

    for(int i=1;i<((subintervalos)/2);i++){
        x=a+2*i*h;
        suma=suma+2*f(x)+4*f(x-h);
    }
    double integral=(h/3)*(suma+4*f(b-h));
    printf("\nIntegral= %lf",integral);
}

void trapecioConTabla(){

    FILE *fp;
    char ch;
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/Programa Guia 7/matriz.dat","r");
    if ( fp == NULL )
    {
        puts ( "No se puede abrir el archivo");
    }

    //contador de filas
    int filas=0;
    char c;
    int maxValues = 0;
	int columnas=0;
    
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n'){
            filas++;
		}
    }

    printf("numero de filas=%i\n",filas);

    //cerramos y reabrimos el archivo para resetear el puntero
    fclose(fp);
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/Programa Guia 7/matriz.dat","r");
    double x[filas];
    double y[filas]; //Termino independiente


    //Cargo los datos leidos en el array
    int xi=0;
    int yi=0;
    int j=0;
    int i;
	for(i = 0; i < filas; i++) {
		j = 0;
		
		do {
			if(j==0)
			{
				 fscanf(fp, "%lf", &(x[xi]));
				 xi++;
				 j++;
			}else{
				 fscanf(fp, "%lf", &(y[yi]));
				 yi++;
			}
		} while((c = fgetc(fp)) != '\n');
		
	}

	columnas = j;
	
	printf("numero de columnas=%i\n\n",columnas);

    //imprimo la matriz para verificar que lo leyo correctamente
      
	printf("LOS ELEMENTOS DE LA TABLA SON:\n");
    	
    for(i=0;i<filas;i++){
	        printf( "%lf \t %lf", x[i], y[i]);
	        printf("\n");
	}
	

	
	//ejemplo de como escribir en archivo
	/*
	    FILE * file;
        file= fopen("matriz_1.dat", "w");
		
      for(i=0;i<3;i++){
            fprintf(file, "%lf	%lf	%lf	%lf\n", m[i][0],m[i][1],m[i][2],m[i][3]);
        }
        
      */  

    int n=filas;
	double h;
	double aprox;
	double sum=0; //suma los valores internos 

	//controlar q esta equiespaciada!!! =)
	h=x[1]-x[0];

	for(int i=1; i <= n-2; i++){
		sum+=y[i];
	}
	
	aprox=(h/2)*((y[0] + y[n-1])+2*sum);

    printf("La integral f(x) con puntos EQUIDISTANTES en el intervalo [%lf;%lf] es: %lf", x[0],x[n-1],aprox);
}

void trapecioConTablaNoEqui(){
FILE *fp;
    char ch;
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/Programa Guia 7/matriz.dat","r");
    if ( fp == NULL )
    {
        puts ( "No se puede abrir el archivo");
    }

    //contador de filas
    int filas=0;
    char c;
    int maxValues = 0;
	int columnas=0;
    
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n'){
            filas++;
		}
    }

    printf("numero de filas=%i\n",filas);

    //cerramos y reabrimos el archivo para resetear el puntero
    fclose(fp);
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/Programa Guia 7/matriz.dat","r");
    double x[filas];
    double y[filas]; //Termino independiente


    //Cargo los datos leidos en el array
    int xi=0;
    int yi=0;
    int j=0;
    int i;
	for(i = 0; i < filas; i++) {
		j = 0;
		
		do {
			if(j==0)
			{
				 fscanf(fp, "%lf", &(x[xi]));
				 xi++;
				 j++;
			}else{
				 fscanf(fp, "%lf", &(y[yi]));
				 yi++;
			}
		} while((c = fgetc(fp)) != '\n');
		
	}

	columnas = j;
	
	printf("numero de columnas=%i\n\n",columnas);

    //imprimo la matriz para verificar que lo leyo correctamente
      
	printf("LOS ELEMENTOS DE LA TABLA SON:\n");
    	
    for(i=0;i<filas;i++){
	        printf( "%lf \t %lf", x[i], y[i]);
	        printf("\n");
	}
	

	
	//ejemplo de como escribir en archivo
	/*
	    FILE * file;
        file= fopen("matriz_1.dat", "w");
		
      for(i=0;i<3;i++){
            fprintf(file, "%lf	%lf	%lf	%lf\n", m[i][0],m[i][1],m[i][2],m[i][3]);
        }
        
      */  

    double suma=0;
    int n=filas;


     for(i=0;i<n-1;i++){
        suma=suma+((x[i+1]-x[i])/(2))*(y[i+1]+y[i]);
     }
     printf("La integral f(x) con puntos NO EQUIDISTANTES en el intervalo [%lf;%lf] es: %lf", x[0],x[n-1],suma);

}

void simpsonConTabla(){

    FILE *fp;
    char ch;
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/Programa Guia 7/matriz.dat","r");
    if ( fp == NULL )
    {
        puts ( "No se puede abrir el archivo");
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
    fp = fopen("C:/Users/Gabriel/Desktop/Metodos-numericos/Metodos numericos/Programa Guia 7/matriz.dat","r");
    double x[filas];
    double y[filas]; //Termino independiente


    //Cargo los datos leidos en el array
    int xi=0;
    int yi=0;
    int j=0;
    int i;
	for(i = 0; i < filas; i++) {
		j = 0;
		
		do {
			if(j==0)
			{
				 fscanf(fp, "%lf", &(x[xi]));
				 xi++;
				 j++;
			}else{
				 fscanf(fp, "%lf", &(y[yi]));
				 yi++;
			}
		} while((c = fgetc(fp)) != '\n');
		
	}

	columnas = j;
	
	printf("numero de columnas=%i\n\n",columnas);

    //imprimo la matriz para verificar que lo leyo correctamente
      
	printf("LOS ELEMENTOS DE LA TABLA SON:\n");
    	
    for(i=0;i<filas;i++){
	        printf( "%lf \t %lf", x[i], y[i]);
	        printf("\n");
	}

    int n=filas;
	double h;
	double aprox;
	double sumImp=0; //suma los valores internos impares
	double sumPar=0; //suma los valores internos pares

	//controlar q esta equiespaciada!!! =)
	h=x[1]-x[0];

	if(n%2==0){
		cout << "No se puede aplicar el metodo de Simpson! Usar Trapecio!! o interpolar para buscar mas puntos!" << endl;
		exit(0);	
	}

	for(int i=1; i <= n-2; i++){
		sumImp+=y[i];
		i++;
	}
	
	for(int i=2; i <= n-3; i++){
		sumPar+=y[i];
		i++;
	}
	
	aprox=(h/3)*((y[0] + y[n-1])+(4*sumImp)+(2*sumPar));
	
	printf("La integral f(x) en el intervalo [%lf;%lf] es: %lf", x[0],x[n-1],aprox);

}