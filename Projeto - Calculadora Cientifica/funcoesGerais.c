#include <stdio.h> /* scanf(), printf()*/

void menuSelecao ()
{
	int funcao, aproximacao, casoEspecial;
	float valor;
	
	printf("Informe a entrada dos valores seguindo o seguinte padrão \n Funcao Valor Aproximacao Caso Especial ");
	scanf("%d %d %d %f", &funcao, &aproximacao, &casoEspecial, &valor);
	
	switch(funcao)
	{
		case 0:
			/*
				saida
			*/
		break;
		
		case 1:
			/*
			seno
			passar valor e aproximacao
			*/
		break;
		
		case 2:
			/*
			cosseno
			passar valor e aproximacao
			*/
		break;
		
		case 3:
			/*
			logaritmo natural
			passar valor e aproximacao
			*/
		break;
		
		case 4:
			/*
			raiz
			passar valor, aproximacao e caso especial
			*/
		break;
		
		case 5:
			/*
			potencia
			passar valor e aproximacao
			*/
		break;
		
		case 6:
			/*
			seno hiperbolico
			passar valor e aproximacao	
			*/
		break;
		
		default
			/* Caso invalido*/
	}
}