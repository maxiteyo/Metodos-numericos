
/*
PREGUNTAR:
-EL METODO DE PUNTO FIJO CREO QUE NO ANDA (REVISAR)
-EL METODO DE NEWTON-RAPHSON NO ME MUESTRA EL ERROR Y SIEMPRE HACE 10000 ITERACIONES (VER)
-CONTROLAR RESULTADOS DE LOS EJERCICIOS SI ESTAN BIEN
*/

#include <iostream>
#include <math.h>

using namespace std;

double g(double x);
double f(double x);
double fprima(double x);
double fprimasecante(double x0, double x1);

int main(int argc, char *argv[]) {
	
	double x0=0,xviejo=0,tolerancia=0;
	double error=1;
	int iteracion=0,opcion=0;
	
	printf("Ingrese x0: ");
	scanf("%lf",&x0);
    printf("Ingrese tolerancia: ");
    scanf("%lf",&tolerancia);

	do{
		printf("\n----MENU----\n");
		printf("1- Metodo de Punto Fijo");
		printf("\n2- Metodo de Newton-Raphson");
        printf("\n3- Metodo de la secante");
		printf("\n4- Salir");
		printf("\n------------");
		printf("\nOpcion: ");
		scanf("%d",&opcion);
	
	switch(opcion){
	case 1:
		do
        {
            iteracion++;

            if(fabs((g(xviejo+0.0001)-g(xviejo))/0.0001) >= 1){
                printf("\nNo se cumple el criterio de convergencia");
                return 1;
            }else{
                x0=g(xviejo);
                error=fabs(xviejo-x0);
                xviejo=x0;
            }
        } while (error > tolerancia);
         
        printf("\nX0: %lf",x0);
        printf("\nError: %.12lf",error);
        printf("\nIteraciones: %d",iteracion);
	break;
	case 2:

		xviejo=x0;
		//printf("\niteracion\txviejo\tf(xviejo)\tfprima(xviejo)");
		do
		{
			iteracion++;
			if(fabs(fprima(xviejo)) < 0.00001){
				printf("\nDerivada muy pequeña");
				printf("\nfprima: %lf",fprima(xviejo));
				printf("\nxviejo: %lf",xviejo);
				return 2;
			}else{
				x0=xviejo-(f(xviejo)/fprima(xviejo));
				error=fabs(x0-xviejo);
				//printf("\n%d\t%lf\t%lf\t%lf\t%lf\t",iteracion,xviejo,f(xviejo),fprima(xviejo),error);
				xviejo=x0;
			}
		} while (error > tolerancia && iteracion < 10000);
		
		printf("\nRaiz: %lf",x0);
		printf("\nError: %lf",error);
		printf("\nIteraciones: %d",iteracion);

	break;

	case 3:

	//mi x0 es el x(i-1) y el x1 es el x(i) y mi xnuevo es el x(i+1)

	double x1=0;
	double xnuevo=0;

	printf("\nIngrese X1: ");
	scanf("%lf",&x1);
		do
		{
			iteracion++;
			xnuevo=x1-(f(x1)/fprimasecante(x0,x1));
			error=fabs(x1-xnuevo);
			x1=xnuevo;
		} while (error > tolerancia && iteracion < 10000);
		
		printf("\nRaiz: %lf",x1);
		printf("\nError: %lf",error);
		printf("\nIteraciones: %d",iteracion);

	break;
	
	}
	}while(opcion != 4);
}

//PARA pasar de "g" a "f" hay que restarle x y para pasar de "f" a "g" hay que sumarle x

double g(double x){//acordarse de que es g, osea habira que restarle x
	
	double funcion=0;
	
	funcion=cos(sin(x));
	//pow(x,x-cos(x));
	//cos(sin(x));(Preguntar si no cumple con el criterio xq no tiene raiz)
    //pow(x,5)-3*pow(x,3)-2*pow(x,2)+2;(Dudoso lo que da, PREGUNTAR)
    //pow(x,2)+x-4;

	return funcion;
	
}

double f(double x){

	double funcion=0;

	funcion=cos(sin(x))-x;
	//pow(x,x-cos(x));(raiz: nan)
	//cos(sin(x));(derivada muy pequeña)
	//pow(x,5)-3*pow(x,3)-2*pow(x,2)+2;(derivada muy pequeña)
	//pow(x,2)+x-4;

	return funcion;
}

double fprima(double x){

	double funcion=3*pow(x,2)-2;

	//funcion=fabs((f(x+0.01)-f(x))/0.01);

	return funcion;
}

double fprimasecante(double x0,double x1){

double funcion=(f(x1)-f(x0)/(x1-x0));

return funcion;

}