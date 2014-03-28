#include <stdio.h>
#define TAM 5

int main(void)
{    
    	int v[TAM]={5,7,8,2,1};   
    	int i;
		
    	for(i=0; i<TAM; i++)
			printf("%d ",v[i]); /* indexação */
    	printf("\n");

    	for(i=0; i<TAM; i++)
			printf("%d ",*(v+i)); /* aritmética de ponteiros */               
    	printf("\n");
	    
    	return 0;
}
