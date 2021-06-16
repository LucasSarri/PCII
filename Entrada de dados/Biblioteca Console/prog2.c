 /* Descri��o: Identificar a resolu��o atual do monitor */
 /* 14/03/2015 */

 /* Declara��o dos arquivos cabe�alhos */
 #include <stdio.h>            /* fun��o printf() */
 #include "console_v1.5.4.h"   /* fun��o getResolucaoMonitor() */
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
	/* Vari�vel que armazenar� a resolu��o atual do monitor */
	COORD resolution;
	
	/* Silenciar o warning relativo aos par�metros n�o usados da fun��o main() */
	argc = argc;
	argv = argv;
	
	/* Armazenar a resolu��o atual da tela */
	resolution = getResolucaoMonitor();
	
	/* Imprimir na tela a resolu��o atual do monitor */
	printf( "\nQuantidade pixels de largura: %d" , resolution.X );
	printf( "\nQuantidade pixels de altura: %d\n" , resolution.Y );	
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */


/* Exerc�cio:
   - Fa�a um programa que imprima na tela a quantidade de pixels de largura e de altura da fonte atual definida para a janela de console */
