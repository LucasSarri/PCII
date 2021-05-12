/*
	Programa: Caixa de Input
	Descrição: O objetivo do programa é criar uma janela colorida na tela do prompt que permite a entrada de dados.
	Basicamente as principais funções são: permitir a customização da janela, o posicionamento da janela na tela e validação dos dados.
	Programador: Lucas Sarri de Mello
	RGM: 43975
	Data da última modificação: 11/05/2021
*/

/* Como compilar: gcc caixa_input.c conio_v3.2.4.c -o caixa_input.exe -Wall -pedantic -Wextra*/

#include <stdio.h> /* printf(), scanf()*/
#include <string.h> /* strlen() */
#include "conio_v3.2.4.h" /* textbackground(), window(), getch(), gotoxy(), constantes BLUE, BLACK */ 


int main (int argc, char *argv[])
{
	char mensagem [100];
	int linha, coluna;
	int largura,altura;
	
	/* Artifício para tirar o warning do "-Wextra" causado pelos parâmetros da main */
	argc = argc;
	argv = argv;
	
	/* Recebendo a mensagem que será exibida na caixa de input*/
	printf("Informe a mensagem para a caixa do input : ");
	scanf("%s", mensagem);
	
	/* Recebendo a linha e coluna para posicionar a janela */
	printf("Informe a coluna que deseja posicionar a janela : ");
	scanf("%d", linha);
	printf("Informe a linha que deseja posicionar a janela : ");
	scanf("%d", coluna);
	
	/* Recebendo as dimensões (Altura e largura) da janela */
	printf("Informe a largura da janela : ");
	scanf("%d", largura);
	printf("Informe a altura da janela : ");
	scanf("%d", altura);
	
	/*Criando a janela*/
	textbackground(BLUE);
	textcolor(BLACK);
	window(coluna,linha,largura,altura);
	gotoxy(1,1);
	printf("%s ", mensagem);
	getch();
	
	
	
	/* Retornando para o sistema operacional que sistema encerrou corretamente */
	return 0;
}