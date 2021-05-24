#include <stdio.h> /* printf(), scanf() */
#include <locale.h> /* setlocale(), constante LC_ALL */
#include <string.h> /* strlen() */
#include "conio_v3.2.4.h" /* textbackground(), window(), gotoxy(), constantes dentro de COLORS */ 

/* Recebendo a mensagem que ser� exibida na caixa de input*/
void mensagemInput (char *mensagem)
{
	/*Definindo a localidade do programa para poder interpretar a acentua��o da lingua */
	setlocale(LC_ALL, "Portuguese");
	
	printf("Informe a mensagem para a caixa do input : ");
	scanf("%s", mensagem);
}

/* Fun��o que cria a janela com base nas informa��es recebidas de outros procedimentos*/
void criarJanela (int corFundo, int corTexto, int coluna, int linha, int largura, int altura, char *mensagem)
{
	textbackground(corFundo);
	textcolor(corTexto);
	window(coluna, linha, largura, altura);
	gotoxy(1,1);
	printf("%s", mensagem);
}