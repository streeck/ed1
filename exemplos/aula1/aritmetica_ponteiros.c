#include <stdio.h>
#define TAM 5

int main(void)
{    
    	int v[TAM]={5,7,8,2,1};   
    	int i;
		
    	for(i=0; i<TAM; i++)
			printf("%d ",v[i]); /* indexa��o */
    	printf("\n");

    	for(i=0; i<TAM; i++)
			printf("%d ",*(v+i)); /* aritm�tica de ponteiros */               
    	printf("\n");
	    
    	return 0;
}
