#include <iostream>
#include <math.h>

using namespace std;

#define GRADO 3

double f(double x);


int main(int argc, char const *argv[])
{
    int i=0,j=0,k=0;
    double x[GRADO]={0},y[GRADO]={0},xsombrero=0,prod=0,suma=0,error=0;

    printf("\nIngrese los X:\n");
    for(i=0;i<GRADO;i++){
        printf("x[%d]: ",i+1);
        scanf("%lf",&x[i]);
    }
    printf("\nCalcula los Y...\n");
    for(i=0;i<GRADO;i++){
        printf("\ny[%d]: %lf",i+1,f(x[i]));
        y[i]=f(x[i]);
    }

    printf("\n\nIngrese el valor a interpolar: ");
    scanf("%lf",&xsombrero);
    for(k=0;k<GRADO;k++){
        prod=1;
        for(j=0;j<GRADO;j++){
            if(j!=k){
                prod=prod*((xsombrero-x[j])/(x[k]-x[j]));
            }
        }
        suma=suma+y[k]*prod;
    }

    printf("\nEl valor interpolado es: %lf",suma);
    error=fabs(suma-f(xsombrero));
    printf("\nError: %lf",error);

    return 0;
}

double f(double x){

double funcion=0;

funcion=x+2/x;

return funcion;

}
