#include <stdio.h> /* printf(), scanf()*/
#include <string.h> /* strlen() */
#include "conio_v3.2.4.h" /* textbackground(), window(), gotoxy(), constantes dentro de COLORS */ 

/*Definindo a localidade do programa para poder interpretar a acentua��o da lingua */
setlocale(LC_ALL, "Portuguese");

/* Fun��o que cria a janela com base nas informa��es recebidas de outros procedimentos*/
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
			Somente as letras min�sculas do alfabeto;
			Somente as letras mai�sculas do alfabeto;
			Somente as letras min�sculas e mai�sculas do alfabeto;
			Somente as letras min�sculas/mai�sculas do alfabeto e os d�gitos de 0 a 9;

	*/
	switch(tipo)
	{
		/* N�mero inteiro */
		case 1:
			printf("Informe um n�mero inteiro: ");
			scanf("%d", &inteiro);
		break;
		/* N�mero inteiro sem sinal*/
		case 2:
			printf("Informe um n�mero inteiro sem sinal:");
			scanf("%d", &inteiro);
			while(inteiro < 0)
			{
				print("Valor invalido \n");
				printf("Informe um n�mero inteiro sem sinal:");
				scanf("%d", &inteiro);
			}
		break;
		/* string */
		case 3:
			printf("Informe a string:");
			scanf("%s", mensagem);
		break;
		case 4:
			printf("Informe um n�mero com ponto flutuante: ");
			scanf("%f", &real);
		break;
	}
}