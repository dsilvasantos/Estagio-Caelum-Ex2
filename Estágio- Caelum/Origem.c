#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void main()
{
	FILE * entrada = fopen("Entrada.txt", "r");
	char palavra[20];
	int qtdeLetras;
	int qtdeTotal = 0;
	if (entrada == NULL)
	{
		printf("ERRO NA LEITURA DO ARQUIVO\n");
		exit(1);
	}
	while (fscanf(entrada, "%s",&palavra) == 1)
	{
		qtdeLetras = strlen(palavra);
		for (int i = 0; i < qtdeLetras; i++)
		{
			// Contabilizando o valor total das palavras 
			int valorLetra = palavra[i];
			if ((valorLetra >= 65) && (valorLetra <= 90))
			{
				valorLetra = valorLetra - 38;
			}
			else if ((valorLetra >= 97) && (valorLetra<=122))
			{
				valorLetra = valorLetra - 96;
			}
			qtdeTotal = qtdeTotal + valorLetra;
		}
		if (nPrimo(qtdeTotal) == 0)
		{
			printf("%s It is a prime word \n", palavra);
		}
		else
		{
			printf("%s It is not a prime word \n", palavra);
		}

	}
}

int nPrimo(int numero)
{
	// Esta função retorna 1 se o numero não for primo e 0 se o numero for primo

	int n,i; 
	int count = 0;

	if (numero == 1)
	{
		// Classificaremos o numero 1 sendo não primo
		return 1;
	}
	if ((numero % 2 == 0) && (numero != 2))
	{
		// Nesta parte numeros pares diferente de 2 já são classificados como não primos
		return 1;
	}
	else
	{
		// Definimos o limite do for se algum dos i dividir o numero ele é classiicado como não primo se não ele é primo
		n = sqrt(numero);
		for (i = 2; i < n; i++)
		{
			if (numero%i == 0)
			{
				return 1;
			}
		}
		return 0;
	}
}