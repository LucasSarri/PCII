#include <stdio.h> /* printf(), scanf()*/
#include <string.h> /* strlen() */
#include "conio_v3.2.4.h" /* textbackground(), window(), gotoxy(), constantes dentro de COLORS */ 

/*Definindo a localidade do programa para poder interpretar a acentuação da lingua */
setlocale(LC_ALL, "Portuguese");

/* Função que cria a janela com base nas informações recebidas de outros procedimentos*/
void criarJanela (int corFundo, int corTexto, int coluna, int linha, int largura, int altura, char *mensagem)
{
	textbackground(corFundo);
	textcolor(corTexto);
	window(coluna, linha, largura, altura);
	gotoxy(1,1);
	printf("%s", mensagem);
}

void tipoDados (int tipo)
{
	int inteiro, i = 0;
	char mensagem[100];
	float real;
	/*
			Somente as letras minúsculas do alfabeto;
			Somente as letras maiúsculas do alfabeto;
			Somente as letras minúsculas e maiúsculas do alfabeto;
			Somente as letras minúsculas/maiúsculas do alfabeto e os dígitos de 0 a 9;

	*/
	switch(tipo)
	{
		/* Número inteiro */
		case 1:
			printf("Informe um número inteiro: ");
			scanf("%d", &inteiro);
		break;
		/* Número inteiro sem sinal*/
		case 2:
			printf("Informe um número inteiro sem sinal:");
			scanf("%d", &inteiro);
			while(inteiro < 0)
			{
				print("Valor invalido \n");
				printf("Informe um número inteiro sem sinal:");
				scanf("%d", &inteiro);
			}
		break;
		/* string */
		case 3:
			printf("Informe a string:");
			scanf("%s", mensagem);
		break;
		case 4:
			printf("Informe um número com ponto flutuante: ");
			scanf("%f", &real);
		break;
	}
}