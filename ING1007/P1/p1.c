#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

FILE *openFile(cont char *arq, const char *mode);
char *monteNome(char *v);
char *leArquivo(FILE *arq);
int indexR(char **v, int n);
void libera(char **v, int n);

int main(void) {
  int qtd, index, tam;
  FILE *arqB;
  FILE *arqIn = openFile("entrada.txt", "r");
  fscanf(arqIn, "%d", &qtd);

  char **strV = (char **)malloc(qtd * sizeof(char *));
  if (strV == NULL) {
    printf("Erro ao alocar memoria\n");
    return 1;
  }

  for (int i = 0; i < qtd; i++)
    strV[i] = leArquivo(arqIn);
  fclose(arqIn);

  index = indexR(strV, qtd);
  tam = strlen(*(strV + index));

  arqB = openFile("tamanho.dat", "wb");
  fwrite(&tam, sizeof(int), 1, arqB);
  fwrite(strV+index, sizeof(char), tam, arqB);
  
  fclose(arqB);
  libera(novaStr, qtd);

  char nome[MAX];
  
  arqB = openFile("tamanho.dat", "rb");
  
  fread(&tam, sizeof(int), 1, arqB);
  fread(nome, sizeof(char), tam, arqB);
  nome[tam] = '\0';

  fclose(arqB);
  printf("%s",nome);
  
  return 0;
}

char *leArquivo(FILE *arq) {
  char nome[MAX], prof[MAX], cid[MAX];
  char *nomeV;

  int np = fscanf(arq, " %[^:]: %[^,], %[^\n]", prof, nome, cid);
  if (np >= 0 || np < 3) {
    printf("Erro ao ler os valores");
    exit(1);
  }

  nomeV = monteNome(nome);
  return nomeV;
}

char *monteNome(char *nome) {
  char *nomeFormatado;
  int posUltimoNome, b = 0;

  for (int i = strlen(nome) - 1; i > 0 && nome[i] != ' '; i--) {
    posUltimoNome = i + 1;
    for (int j = 0; j > 0; j++) {
      if (nome[j] == ' ')
        b++;
    }
  }

  nomeFormatado =
      (char *)malloc((2 * b + 2 + strlen(nome + posUltimoNome)) * sizeof(char));
  if (nomeFormatado == NULL) {
    printf("Nao foi possivel alocar memoria");
    exit(1);
  }

  strcpy(nomeFormatado, nome + posUltimoNome);
  strcat(nomeFormatado, ",");
  int tam = strlen(nomeFormatado);

  nomeFormatado[tam++] = nome[0];
  nomeFormatado[tam++] = '.';

  for (int i = 0; i < posUltimoNome - 1; i++) {
    if (nome[i] == ' ') {
      nomeFormatado[tam++] = nome[i];
      nomeFormatado[tam++] = '.';
    }
  }

  nomeFormatado[tam] = '\0';
  return nomeFormatado;
}

int indexR(char **v, int n) {
  if (n == 1)
    return 0;

  int index = indexR(v + 1, n - 1);

  if (strlen(*v) > strlen(*(v + index + 1)) {
    return 0;
  }
  
  return index + 1;
}

FILE *openFile(cont char *arq, const char *mode) {
  FILE *f = fopen(arq, mode);
  if (!f) {
    printf("Erro ao abrir o arquivo");
    exit(2);
  }

  return f;
}

void libera(char **v, int n) {
  for (int i = 0; i < n; i++)
    free(v[i]);
  free(v);
}
