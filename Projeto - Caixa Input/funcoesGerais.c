#include <stdio.h> /* printf(), scanf() */
#include <locale.h> /* setlocale(), constante LC_ALL */
#include <stdlib.h> /* malloc() */
#include "conio_v3.2.4.h" /* textbackground(), window(), gotoxy(), constantes dentro de COLORS */ 

/* Recebendo a mensagem que ser� exibida na caixa de input*/
void mensagemInput (char *mensagem)
{
	/*Definindo a localidade do programa para poder interpretar a acentua��o da lingua */
	setlocale(LC_ALL, "Portuguese");
	
	printf("Informe a mensagem para a caixa do input : ");
	scanf("%s", mensagem);
}

char *preencheEspaco (int tam)
{
	/* Criando vari�vel para receber o caractere _ que ir� preencher o espa�o vazio, para isso realizei a aloca��o din�mica 
	de acordo com o tam que ser� a diferen�a do tamanho da mensagem para o tamanho da janela*/
	int alocacao = tam * sizeof(char);
	char *mensagem;
	int i;
	
	mensagem = malloc (alocacao);
	
	printf("%d",alocacao);
	for (i = 0; i < alocacao; i++)
	{
		mensagem[i] = '_';
	}
	
	return mensagem;
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