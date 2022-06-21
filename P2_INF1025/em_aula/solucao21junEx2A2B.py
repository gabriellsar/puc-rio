# -*- coding: utf-8 -*-
"""
Spyder Editor

JOISA

Ex2 da lista de 21/06
"""


def exibe_turmas():
    arqEnt= open('notasdisciplina.txt','r')
    turma = arqEnt.readline()
    while turma !='':
        turma = turma.strip()
        qtAlunos= int(arqEnt.readline().strip())
        lnotas=[]
        while qtAlunos>0:
            nota= float(arqEnt.readline().strip())
            lnotas.append(nota)
            qtAlunos-=1
        maiorNota= max(lnotas)
        menorNota= min(lnotas)
        media= sum(lnotas)/len(lnotas)
        print('Turma %s - Max:%.1f, Min:%.1f,Med:%.1f'%(turma,maiorNota,menorNota,media))
        turma = arqEnt.readline()
        
    arqEnt.close()
 

def cria_aprovados():
    arqEnt= open('notasdisciplina.txt','r')
    arqSai= open('aprovados.txt','w')
    turma = arqEnt.readline()
    while turma !='':
        turma= turma.strip()
        qtAlunos= int(arqEnt.readline().strip())
        contApv=0
        while qtAlunos>0:
            nota= float(arqEnt.readline().strip())
            if nota>=5:
                contApv+=1
            qtAlunos-=1
        arqSai.write('%s %d\n'%(turma,contApv))  
        turma = arqEnt.readline()
        
    arqEnt.close()
    arqSai.close()
 

#BP       
exibe_turmas()
cria_aprovados()