#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  	int *p;
  	int i;
  	int n;
    
  	printf("entre com a quantidade de memoria: ");

  	scanf("%d",&n);
  
  	p = (int *)malloc(n * sizeof(int));

  	for (i = 0; i < n; i++)
    		p[i] = i;
  	for (i = 0; i < n; i++)
    		printf("%d ",p[i]);

	printf("\n");
     
	free(p);

  	return 0;
}
