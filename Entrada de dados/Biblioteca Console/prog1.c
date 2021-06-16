 /* Descrição: Alterar titulo da janela de Console */
 /* 14/03/2015 */

 /* Declaração dos arquivos cabeçalhos */
 #include <stdlib.h>		   /* função system() */
 #include "console_v1.5.4.h"   /* função setTituloConsole() */
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
	/* Silenciar o warning relativo aos parämetros não usados da função main() */
	argc = argc;
	argv = argv;
	
	/* Alterar o titulo da janela de console */
	setTituloConsole( "PC II" );
	
	/* Pausar para poder comprovar a troca do título da janela */
	system( "pause" );
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */

/* Exercício:
   - Faça um programa que imprima na tela o título atual da janela de console */
