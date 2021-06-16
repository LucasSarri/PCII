 /* Descri��o: Imprimir na tela o tamanho atual da janela de console em quantidade de caracteres */
 /* 14/03/2015 */

 /* Declara��o dos arquivos cabe�alhos */
 #include <stdio.h>            /* fun��o printf() */
 #include "console_v1.5.4.h"   /* fun��o tamanhoJanelaConsole() */
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
	/* Vari�vel que armazenar� a resolu��o atual do monitor */
	COORD dimensionConsoleWindow;
	
	/* Silenciar o warning relativo aos par�metros n�o usados da fun��o main() */
	argc = argc;
	argv = argv;
	
	/* Armazenar as dimens�es da janela de console em quantidade de caracteres */
	dimensionConsoleWindow = tamanhoJanelaConsole();
	
	/* Imprimir na tela as quantidades de caracteres que se pode imprimir nas dimens�es atuais da janela de console */
	printf( "\nQuantidade caracteres de largura: %d" , dimensionConsoleWindow.X );
	printf( "\nQuantidade caracteres de altura: %d\n" , dimensionConsoleWindow.Y );	
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */


/* Exerc�cio:
   - Fa�a um programa que fa�a com que a janela de console ocupe o tamanho m�ximo da tela poss�vel. Observa��o: ap�s o encerramento do seu programa, 
     tudo deve voltar exatamente como era antes da execu��o de seu programa (tamanho da janela e posi��o na tela). */
