/*
GABRIEL LOBO DE SANT'ANNA ROSAS
MATRICULA:2210689
TURMA:33D
*/
#include <stdio.h>
#define TOT 10

void obtemCodigo(int* vC, int tot);
void zeroContador(int* v, int n);
int buscaRei(int valor, int* vR, int tot);
int min_max(int* vetor, int tot, int* mim, int* max);

int main(void)
{
	int vRei[TOT], vVotosRei[TOT], vVotosRainha[TOT];
	int qtd_alunos, rei, rainha, pos, maior, menor;

	printf("Quantos alunos fazem parte da turma?\n --> ");
	scanf_s("%d", &qtd_alunos);

	obtemCodigo(vRei, TOT);
	zeroContador(vVotosRei, TOT);
	zeroContador(vVotosRainha, TOT);

	for (int i = 0; i < qtd_alunos; i++)
	{
		printf("Qaul seu voto para Rei e Rainha?\n");
		scanf("%d%d", &rei, &rainha);
		pos = buscaRei(TOT, vVotosRei, rei);
		if (pos != -1)
			vVotosRei[pos]++;
		else if (0 <= rainha && rainha <= 10)
			vVotosRainha[rainha - 1]++;
	}
	min_max(vVotosRei, TOT, &maior, &menor);
	printf("%d%d\n",vRei[maior],vRei[menor]);
	min_max(vVotosRainha, TOT, &maior, &menor);
	printf("%d%d\n", maior + 1, menor + 1);
	return 0;
}

void obtemCodigo(int* vC, int tot)
{
	for (int j = 0; j < tot; j++)
	{
		printf("Forneca um cof para rei");
		scanf("%d", &vC[j]);
	}
}

void zeroContador(int* v, int n)
{
	for (int k = 0; k < n; k++)
	{
		v[k] = 0;
	}
}

int buscaRei(int valor, int* vR, int tot) {
	for (int i = 0; i < TOT; i++)
	{
		if (*(vR + i) == valor)
			return i;
	}
	return -1;
}

int min_max(int* vetor, int tot, int* mim, int* max) {
	int posMin = 0, posMax = 0;
	for (int w = 0; w < tot; w++)
	{
		if (vetor[w] < vetor[posMin])
			posMin = w;
		else if (vetor[w] > vetor[posMax])
			posMax = w;
	}
	*mim = posMin;
	*max = posMax;
}
