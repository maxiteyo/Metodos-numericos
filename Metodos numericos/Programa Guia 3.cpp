#include <iostream>
#include <math.h>

#define FIL 4
#define COL 4

using namespace std;

int main(int argc, char const *argv[])
{
	
	int opcion=0,iteracion=0,i=0,j=0,p=0,l=0,m=0,k=0;
	double arreglo[FIL][COL]={0},dato=0,swap=0,b[FIL]={0},factor=0,det=1,x[FIL]={0},suma=0;
	
	printf("\n---CARGA DE LA MATRIZ---");
	for (i = 0; i < FIL; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("\narreglo[%d][%d]= ",i,j);
			scanf("%lf",&dato);
			arreglo[i][j]=dato;
		}
		
	}
	
	for(i=0;i<FIL;i++){
		printf("\n");
		for(j=0;j<COL;j++){
			printf("%lf\t",arreglo[i][j]);
		}
	}
	
	
	printf("\n---Carga de los b---");
	for(i= 0; i < FIL; i++){
		printf("\nb[%d]= ",i);
		scanf("%lf",&b[i]);
	}
	
	do
	{
		
		printf("\n----MENU----\n");
		printf("1- Eliminacion gaussiana\n");
		printf("2- Salir\n");
		printf("------------\n");
		printf("OPCION: ");
		scanf("%d",&opcion);
		
		switch (opcion)
		{
		case 1:
			for(j=0;j<FIL;j++){
				p=j;
				
				if(fabs(arreglo[j][j]) < 0.00001){
					l=j+1;
					do
					{
						if(fabs(arreglo[l][j]) > fabs(arreglo[j][j])){
							p=l;
						}
					} while (l < FIL);
					
					m=0;
					do
					{
						swap=arreglo[p][m];
						arreglo[p][m]=arreglo[j][m];
						arreglo[j][m]=swap;
					} while (m <= FIL);
					
					swap=b[p];
					b[p]=b[j];
					b[j]=swap;
				}
				for(i=j+1;i<FIL;i++){
					factor=(-1)*(arreglo[i][j]/arreglo[j][j]);
					
					for(k=j;k<COL;k++){
						arreglo[i][k]=arreglo[i][k]+factor*arreglo[j][k];
					}
					b[i]=b[i]+factor*b[j];
				}
			}//esta en forma triangular
			
			for(i=0;i<FIL;i++){
				det=det*arreglo[i][i];
			}
			
			
			printf("b[3]: %lf\n",b[3]);
			printf("\narreglo[3][3]: %lf\n",arreglo[3][3]);
			
			if(det==0){
				printf("\nMatriz singular");
				return 1;
			}
			else{
				for(i=FIL-1;i>=0;i--){
					suma=b[i];
					for(k=i+1;k<FIL;k++){
						suma=suma-arreglo[i][k]*x[k];
					}
					x[i]=suma/arreglo[i][i];
				}
				
			}
			
			for(i=0;i<FIL;i++){
				printf("\nx[%d]= %lf",i,x[i]);
			}
			
			printf("\nDeterminante: %lf",det);
			break;
		}
	} while (opcion != 2);
	return 0;
}
