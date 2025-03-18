#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "TADFILA.h"
#include <string.h>

int randomizarAcao(void)
{
	return rand() % 2;
}

TpElemento LerArquivo(FILE *Ptr)
{
	TpElemento reg;
         
    fscanf(Ptr,"%[^,],%[^,],%[^,],%c\n",&reg.idVeic, &reg.corVeic, &reg.fabVeic, &reg.prior);
    return reg;
}

int main()
{
	TpFilaP Fila;
	FILE *Ptr = fopen("DadosVeiculos.txt","r");
	do
	{
		system("cls");
		switch (randomizarAcao()) {
	    case 0:
	        if(!Cheia(Fila.FIM))
	        	LerArqInserir(Fila,LerArquivo(Ptr));
	        
	        Exibir(Fila);
	        break;
	    case 1:
	        if(!Vazia(Fila.FIM))
	        	Retirar(Fila);
	        	
	        Exibir(Fila);
	        break;

		}
	} while(getche() != 27);
	
	fclose(Ptr);
	
	return 0;
}
