#include <stdio.h>
#define TAM 10

float calculaMedia(int* vInt, int n);
int busca1(int* vInt, int n, int x);
int busca2(int* vInt, int n, int x);
int verificaOrd(int* vInt, int n);
void inverte(int* vPint, int n, int* vInt2);

int main(void)
{
	int vInt[TAM], menorValor;
	
	for (int i = 0; i < TAM; i++)
	{
		printf("Valor inteiro: ");
		scanf_s("%d", vInt + i);
	}
	menorValor = *(vInt + TAM - 1);
	
	printf(" Menores q o ultimo valor lido (%d)\n", menorValor);
	for (int j = 0; j < TAM; j++)
	{
		if (*(vInt + j) < menorValor)
			printf("%d\n", *(vInt + j));
	}

	printf(" A media dos valores do vertor eh %.1f\n", calculaMedia(vInt, TAM));
	
	int encontrado = busca1(vInt, TAM, 4);
	int pos = busca2(vInt, TAM, 4);
	if (encontrado)
		printf("O valor esta no vetor na posicao %d\n", pos);
	else printf("O valor nao esta no vetor\n");
	
	int ordem = verificaOrd(vInt, TAM);
	if (ordem)
		printf("O vetor esta em ordem crescente\n");
	else printf("O vetor nao esta em ordem crescente\n");

	printf("Vetor => {");
	for (int k = 0; k < TAM; k++)
	{
		printf("%d ", *(vInt + k));
	}
	printf("}\n");

	int vNovo[TAM];
	printf("Vetor Invertido => {");
	inverte(vInt, TAM, vNovo);
	for (int w = 0; w < TAM; w++)
	{
		printf("%d ", *(vNovo + w));
	}
	printf("}\n");

	return 0;
}

float calculaMedia(int* vInt, int n)
{
	int soma = 0;
	for (int i = 0; i < n; i++)
	{
		soma += *(vInt + i);
	}
	return (float)soma / n;
}
int busca1(int* vInt, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (*(vInt + i) == x)
			return 1;
	}
	return 0;
}
int busca2(int* vInt, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (*(vInt + i) == x)
			return i;
	}
	return -1;
}
int verificaOrd(int* vInt, int n)
{
	int val = 0;
	for (int i = 1; i < (n-1); i++)
	{
		if (vInt[i - 1] < vInt[i])
			val = 1;
		else val = 0;
	}
	return val;
}
void inverte(int* vPint, int n, int* vInt2)
{
	for (int i = 0; i < n; i++)
	{
		vInt2[i] = vPint[n - i - 1];
	}
	return;
}
