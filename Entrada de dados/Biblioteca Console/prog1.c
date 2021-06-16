 /* Descri��o: Alterar titulo da janela de Console */
 /* 14/03/2015 */

 /* Declara��o dos arquivos cabe�alhos */
 #include <stdlib.h>		   /* fun��o system() */
 #include "console_v1.5.4.h"   /* fun��o setTituloConsole() */
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
	/* Silenciar o warning relativo aos par�metros n�o usados da fun��o main() */
	argc = argc;
	argv = argv;
	
	/* Alterar o titulo da janela de console */
	setTituloConsole( "PC II" );
	
	/* Pausar para poder comprovar a troca do t�tulo da janela */
	system( "pause" );
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */

/* Exerc�cio:
   - Fa�a um programa que imprima na tela o t�tulo atual da janela de console */
