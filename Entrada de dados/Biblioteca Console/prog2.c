 /* Descrição: Identificar a resolução atual do monitor */
 /* 14/03/2015 */

 /* Declaração dos arquivos cabeçalhos */
 #include <stdio.h>            /* função printf() */
 #include "console_v1.5.4.h"   /* função getResolucaoMonitor() */
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
	/* Variável que armazenará a resolução atual do monitor */
	COORD resolution;
	
	/* Silenciar o warning relativo aos parämetros não usados da função main() */
	argc = argc;
	argv = argv;
	
	/* Armazenar a resolução atual da tela */
	resolution = getResolucaoMonitor();
	
	/* Imprimir na tela a resolução atual do monitor */
	printf( "\nQuantidade pixels de largura: %d" , resolution.X );
	printf( "\nQuantidade pixels de altura: %d\n" , resolution.Y );	
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */


/* Exercício:
   - Faça um programa que imprima na tela a quantidade de pixels de largura e de altura da fonte atual definida para a janela de console */
