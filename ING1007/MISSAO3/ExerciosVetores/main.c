/*
GABRIEL LOBO DE SANT'ANNA ROSAS
MATRICULA:2210689
TURMA:33D
*/
#include <stdio.h>
#define TOT 10

int min_max(int* vetor, int tot);
int buscaRei(int valor, int* vR, int tot);
void votosRei(int tot, int* vR, int* vVR);
void votosRainha(int tot, int* vRa, int* vVRa);

int main(void)
{
	int vRei[TOT];
	int vVotosRei[TOT] = { 0,0,0,0,0,0,0,0,0,0 };
	int vVotosRainha[TOT] = { 0,0,0,0,0,0,0,0,0,0 };
	int qtd_alunos;

	printf("Quantos alunos fazem parte da turma?\n --> ");
	scanf_s("%d",&qtd_alunos);

	for (int i = 0; i < TOT; i++)
	{
		printf("--Rei %d--\n", i + 1);
		printf("Escolha um numero (1 - 10)\n --> ");
		scanf_s("%d", vRei + i);
	}

	votosRainha(qtd_alunos, vVotosRainha, TOT);
	votosRei(qtd_alunos, vRei, vVotosRei, TOT);

	int* posM;
	int* posMa = min_max(vVotosRei, TOT);
	printf("O rei %d recebeu o maior numero de votos e o rei %d recebeu o menor numeros de votos", *(posMa + 1), *(posM + 1));

	posMa = min_max(vVotosRainha, TOT);
	printf("A rainha %d recebeu o maior numero de votos e o rainha %d recebeu o menor numeros de votos", *(posM + 1), *(posMa + 1));

}

int min_max(int* vetor, int tot) {
	int posMin = vetor[0], posMax = vetor[0];
	for (int i = 0; i < tot; i++)
	{
		if (*(vetor + i + 1) > posMax)
			posMax = *(vetor + i + 1);
		else if (*(vetor + i + 1) < posMin)
			posMin = *(vetor + i + 1);
	}

	return posMax;
}
int buscaRei(int valor, int* vR, int tot) {
	for (int i = 0; i < TOT; i++)
	{
		if (*(vR + i) == valor)
			return i;
	}
}
void votosRei(int qtdAl, int* vR, int* vVR, int tot) {
	for (int j = 0; j < qtdAl; j++)
	{
		int voto;
		printf("--Aluno %d--\n", j + 1);
		printf("Escolha o numero da rei que deseja votar (1 - 10)\n --> ");
		scanf_s("%d", &voto);
		int pos  = buscaRei(voto, vR, tot);
		vVR[pos] += 1;
	}
	return;
}
void votosRainha(int qtdAl, int* vVRa, int tot) {
	for (int k = 0; k < qtdAl; k++)
	{
		int posVoto;
		printf("--Aluno %d--\n", k + 1);
		printf("Escolha o numero da rainha que deseja votar (1 - 10)\n --> ");
		scanf_s("%d", &posVoto);
		vVRa[posVoto - 1] += 1;
	}
	return;
}