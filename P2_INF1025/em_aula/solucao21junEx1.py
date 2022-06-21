# -*- coding: utf-8 -*-
"""
Spyder Editor

JOISA

Ex1 da lista de 21/06
"""
import math

def exibe_perimetro(nomearq):
    arq= open(nomearq,'r')
    for linha in arq:
        fig= linha.strip().split(',')
        if fig[0]=='triangulo':
            per= float(fig[2])+float(fig[3])+float(fig[4])
        elif fig[0]=='retangulo':
            per= 2*float(fig[2])+ 2*float(fig[3])     
        elif fig[0]=='circulo':
            per= 2*math.pi*float(fig[2])    
        else:  # sobrou quadrado
            per= 4* float(fig[2])   
        print('%s tem perimetro :%.1f'%(fig[1],per))
    arq.close()
        
exibe_perimetro('fig.txt')