#include <iostream>
#include <math.h>

using namespace std;

double f(double x);

int main(int argc, char *argv[]) {
	
	double a=0,b=0,tolerancia=0,c=0,cvieja=0;
	double error=1;
	int iteracion=0,opcion=0;
	
	printf("\nIngrese a :");
	scanf("%lf",&a);
	printf("\nIngrese b :");
	scanf("%lf",&b);
	printf("\nIngrese la tolerancia deseada: ");
	scanf("%lf",&tolerancia);
	
	if(f(a)*f(b) > 0){
		printf("\nNo hay raiz");
		return 1;
	}
	
	do{
		printf("\n----MENU----\n");
		printf("1- Metodo de biseccion");
		printf("\n2- Metodo de falsa posicion");
		printf("\n3- Metodo de falsa posicion 2.0");
		printf("\n4- Salir");
		printf("\nOpcion: ");
		scanf("%d",&opcion);
	
	switch(opcion){
	case 1:
		printf("\t--Iteracion--\t--Error relativo--\n");
		do{
			c=(a+b)/2;
			
			if(f(a)*f(c) > 0){
				a=c;
			}else{
				if(f(a)*f(c) < 0){
					b=c;
				}else{
					printf("\nLa raiz es: %lf",c);
					return 2;
				}
			}
			iteracion++;
			error= (b-a)/2;
			printf("\t%d\t\t%lf\n",iteracion,error);
		} while(error > tolerancia);
		
		printf("\nLa raiz es: %lf",c);
		printf("\nEl error es: %.12lf",error);
		printf("\nNumero de iteraciones: %d",iteracion);
		break;
	
	case 2:
		printf("\t--Iteracion--\t--Error relativo--\n");
		do{
			c=(a*f(b)-b*f(a))/(f(b)-f(a));
			
			if(f(a)*f(c) > 0){
				a=c;
			}else{
				if(f(a)*f(c) < 0){
					b=c;
				}else{
					printf("\nLa raiz es: %lf",c);
					return 2;
				}
			}
			iteracion++;
			error= (b-a)/2;
			printf("\t%d\t\t%lf\n",iteracion,error);
		} while(error > tolerancia);
		
		printf("\nLa raiz es: %lf",c);
		printf("\nEl error es: %.12lf",error);
		printf("\nNumero de iteraciones: %d",iteracion);
		break;

	case 3:
		printf("\t--Iteracion--\t--Error relativo--\n");
		do{
			c=(a*f(b)-b*f(a))/(f(b)-f(a));
			if(f(a)*f(c) > 0){
				a=c;
			}else{
				if(f(a)*f(c) < 0){
					b=c;
				}else{
					printf("\nLa raiz es: %lf",c);
					return 2;
				}
			}
			error= fabs((c-cvieja)/c);
			cvieja=c;
			iteracion++;
			printf("\t%d\t\t%lf\n",iteracion,error);
		} while(error > tolerancia);
		
		printf("\nLa raiz es: %lf",c);
		printf("\nNumero de iteraciones: %d",iteracion);
		break;
	}
	}while(opcion != 4);
}

double f(double x){
	
	double funcion=0;
	
	funcion= 0.117*pow(x,3)-1.35*pow(x,2)+4.23*x-3;
	//-2+7*x-5*pow(x,2)+6*pow(x,3);
	//log(x)+pow(2.71828,sin(x))-x;
	return funcion;
	
}
