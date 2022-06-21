""""""
"""
Escreva um programa que implemente um jogo de adivinhação de palavras, conforme descrição abaixo:
a) As palavras estão armazenadas no arquivo DIC.PAL que será fornecido pelo seu professor; todas as palavras
estão em letras maiúsculas; no arquivo, não existem caracteres acentuados e nem o caractere ‘Ç’;

b) O programa deverá selecionar randomicamente uma palavra do arquivo e, em seguida, apresentar na tela uma
linha com N caracteres '_', onde N é a quantidade de letras da palavra; os caracteres '_' devem ser separados por
um espaço em branco;

c) Inicialmente, o programa deve exibir uma mensagem com o nome do jogo, a quantidade de chances que o jogador
terá e os títulos das colunas;

d) O jogador terá 10 chances para tentar adivinhar a palavra; o programa deverá ler uma letra de cada vez, sendo
que o jogador poderá digitar a letra maiúscula ou minúscula;

e) A cada chance, o programa deverá exibir uma coluna com as letras já descobertas na posição correta e outra
coluna com todas as letras já utilizadas;

f) O programa não deverá contabilizar como chance o fato do jogador digitar uma letra utilizada previamente por ele;

g) Se o jogador acertar a palavra, o programa não poderá oferecer mais nenhuma chance e deverá exibir uma
mensagem de parabéns; caso o jogador não acerte a palavra ao final das 10 chances, o programa deverá exibir a
palavra sorteada e a mensagem 'Que falta de sorte! Tente novamente depois!!!';
h) Tente ser o mais fiel possível aos exemplos de execução abaixo.
"""

import random

juntar_lista = lambda lista: ' '.join(lista)

print(f"| JOGO DA ADIVINHACAO\t|\tVOCE TEM 10 CHANCES | ")
print("\tPalavra sorteada:\t|\tLetras ja usadas:")

arquivo = open("DIC.PAL", 'r')
palavra_escolhida = random.choice(arquivo.readlines())

linhas_tam_palavras = "_ " * (len(palavra_escolhida) - 1)

lista_palavras = linhas_tam_palavras.split()
lista_letras_usadas = []

lista_secreta = [lista_palavras, lista_letras_usadas]

print(juntar_lista(lista_palavras))

num_da_jogada = 0
letra = input("\nQual letra deseja escolher? ")
LETRA = letra.upper()

if LETRA not in juntar_lista(lista_palavras) and LETRA not in juntar_lista(lista_letras_usadas):
    num_da_jogada += 1

if LETRA in palavra_escolhida:
    i = palavra_escolhida.index(LETRA)
    lista_palavras[i] = LETRA

elif LETRA not in palavra_escolhida and LETRA not in lista_letras_usadas:
    lista_letras_usadas.append(LETRA)


print("\tPalavra sorteada:\t|\tLetras ja usadas:")
print(f"\t{juntar_lista(lista_palavras)}\t|\t{juntar_lista(lista_letras_usadas)}")

while num_da_jogada < 10:
    letra = input("\nQual letra deseja escolher? ")
    LETRA = letra.upper()

    if LETRA not in juntar_lista(lista_palavras) and LETRA not in juntar_lista(lista_letras_usadas):
        num_da_jogada += 1

    if LETRA in palavra_escolhida:
        i = palavra_escolhida.index(LETRA)
        lista_palavras[i] = LETRA

    elif LETRA not in palavra_escolhida and LETRA not in lista_letras_usadas:
        lista_letras_usadas.append(LETRA)

    print("\tPalavra sorteada:\t|\tLetras ja usadas:")
    print(f"\t{juntar_lista(lista_palavras)}\t|\t{juntar_lista(lista_letras_usadas)}")

    if "_" not in lista_palavras:
        print("Parabens voce acertou a palavra")
        num_da_jogada += 10

if num_da_jogada ==10:
    print('\nQue falta de sorte! Tente novamente depois!!!')
    print("A palavra era " + palavra_escolhida)




