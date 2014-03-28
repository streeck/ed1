/* ----------------------------------------------------
	Charles David de Moraes			26/03/2013
	RA: 489662
---------------------------------------------------- */


// Definicoes basicas: bibliotecas, constantes e registros
#include <stdio.h>

#define QTDEBACIAS 5     //qtde de bacias
#define ESTOQUEINICIAL 10 //estoque inicial de cada tipo de petroleo
#define VALOR 100 //valor de cada unidade de petroleo
#define INSUFICIENCIA "Estoque insuficiente.\n" //Mensagem de insuficiencia de estoque

struct dados{
	int pesado;
	int leve;
	int renda;
};

typedef struct dados tp_dados;

// Prototipos das funcoes
void inicializa(tp_dados bacias[]);
void descoberta(tp_dados bacias[], int numBacia, char tipoPetroleo, int qtdePetroleo);
void consumo(tp_dados bacias[], int numBacia, char tipoPetroleo, int qtdePetroleo);
void venda(tp_dados bacias[], int numBacia, char tipoPetroleo, int qtdePetroleo);
void maior(tp_dados bacias[], int *pMaxEstoque, int *pMaxRenda);
void imprimirBacia(tp_dados bacias[], int numBacia);
void imprimirRelatorio(tp_dados bacias[], int maxEstoque, int maxRenda);

// Rotina Principal
int main(void)
{
	tp_dados bacias[QTDEBACIAS];
	char operacao, tipoPetroleo;
	int numBacia, qtdePetroleo, maxRenda = 0, maxEstoque = 0;

	inicializa(bacias);
	
	do{
		scanf("\n%c", &operacao);
			
		switch(operacao)
		{
			case 'd':
				scanf("%d\n%c%d", &numBacia, &tipoPetroleo, &qtdePetroleo);
				descoberta(bacias, numBacia, tipoPetroleo, qtdePetroleo);
				imprimirBacia(bacias, numBacia);
				break;
			case 'c':
				scanf("%d\n%c%d", &numBacia, &tipoPetroleo, &qtdePetroleo);
				consumo(bacias, numBacia, tipoPetroleo, qtdePetroleo);
				imprimirBacia(bacias, numBacia);                
				break;
			case 'v':
				scanf("%d\n%c%d", &numBacia, &tipoPetroleo, &qtdePetroleo);
				venda(bacias, numBacia, tipoPetroleo, qtdePetroleo);
				imprimirBacia(bacias, numBacia);                
				break;
			case 'f':
				break;
			default: 
				printf("Operacao Invalida!\n");
		}
		
	} while(operacao != 'f');
		
	maior(bacias, &maxRenda, &maxEstoque);
	imprimirRelatorio(bacias, maxRenda, maxEstoque);

	return 0;
}

// Inicializa estoque inicial das bacias com unidades de petroleo leve e pesado e renda igual a 0
void inicializa(tp_dados bacias[])
{
	int i;
	for (i = 0; i < QTDEBACIAS; i++)
	{
		bacias[i].pesado = 10;
		bacias[i].leve = 10; 
		bacias[i].renda = 0;
	}
}

// Adiciona qtde descoberta de petroleo de tipo ('l': leve | 'p': pesado) na bacia correspondente
void descoberta(tp_dados bacias[], int numBacia, char tipoPetroleo, int qtdePetroleo)
{
	if (tipoPetroleo == 'l')
	{
		bacias[numBacia].leve += qtdePetroleo;
	}
	else
	{
		bacias[numBacia].pesado += qtdePetroleo;
	}
}

// Subtrai qtde consumida de petroleo de tipo ('l': leve | 'p': pesado) da bacia correspondente.
// Se nao houver disponibilidade no estoque entao imprimir mensagem de insuficiencia.
void consumo(tp_dados bacias[], int numBacia, char tipoPetroleo, int qtdePetroleo)
{
	if (tipoPetroleo == 'l')
	{
		if (qtdePetroleo > bacias[numBacia].leve)
		{
			printf(INSUFICIENCIA);
		}
		else
		{
			bacias[numBacia].leve -= qtdePetroleo;
		}
	}
	else
	{
		if (qtdePetroleo > bacias[numBacia].pesado)
		{
			printf(INSUFICIENCIA);
		}
		else
		{
			bacias[numBacia].pesado -= qtdePetroleo;
		}
	}
}

// Realiza venda e atualiza estoque e renda da bacia de petroleo de tipo ('l': leve | 'p': pesado) da bacia correspondente.
// Se nao houver disponibilidade no estoque entao imprimir mensagem de insuficiencia.
void venda(tp_dados bacias[], int numBacia, char tipoPetroleo, int qtdePetroleo)
{
	if (tipoPetroleo == 'l')
	{
		if (qtdePetroleo > bacias[numBacia].leve)
		{
			printf(INSUFICIENCIA);
		}
		else
		{
			bacias[numBacia].renda += qtdePetroleo * 100;
			bacias[numBacia].leve -= qtdePetroleo;
		}
	}
	else
	{
		if (qtdePetroleo > bacias[numBacia].pesado)
		{
			printf(INSUFICIENCIA);
		}
		else
		{
			bacias[numBacia].renda += qtdePetroleo * 100;
			bacias[numBacia].pesado -= qtdePetroleo;
		}
	}
}

// Retorna valor da maior renda e qtde do maior estoque de petroleo
void maior(tp_dados bacias[], int *pMaxEstoque, int *pMaxRenda)
{  
	int i;
	for (i = 0; i < QTDEBACIAS; i++)
	{
		if (*pMaxEstoque < (bacias[i].leve + bacias[i].pesado))
		{
			*pMaxEstoque = bacias[i].leve + bacias[i].pesado;
		}
		if (*pMaxRenda < (bacias[i].renda))
		{
			*pMaxRenda = bacias[i].renda;
		}
	}
}

// Imprime os dados da cada bacia requisitada
void imprimirBacia(tp_dados bacias[], int numBacia)
{
	printf("%d %d %d %d %d\n", numBacia, (bacias[numBacia].pesado+bacias[numBacia].leve), bacias[numBacia].pesado, bacias[numBacia].leve, bacias[numBacia].renda);
}


// Imprime os dados de cada bacia, além de qual bacia tem maior estoque e maior renda, respectivamente
void imprimirRelatorio(tp_dados bacias[], int maxEstoque, int maxRenda)
{
	int i;
	
	/* imprime os dados de cada bacia */  
	for(i=0; i < QTDEBACIAS; i++)
		printf("%d %d %d %d %d\n", i, (bacias[i].pesado+bacias[i].leve), bacias[i].pesado, bacias[i].leve, bacias[i].renda);

	/* imprime a(s) bacia(s) de maior estoque */
	for(i=0; i < QTDEBACIAS; i++)
	{
		if(bacias[i].pesado + bacias[i].leve == maxEstoque)
			printf("%d ", i);
	}
	printf("\n");

	/* imprime a(s) bacia(s) de maior renda */
	for(i=0; i < QTDEBACIAS; i++)
	{
		if(bacias[i].renda == maxRenda)
			printf("%d ", i);
	}

	printf("\n");
}