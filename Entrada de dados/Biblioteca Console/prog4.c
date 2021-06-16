 /* Descri��o: Ler uma tecla espec�fica do teclado */
 /* 14/03/2015 */

 /* Declara��o dos arquivos cabe�alhos */
 #include <stdio.h>            /* fun��o printf() */
 #include "console_v1.5.4.h"   /* fun��o Evento() */
 
 /* Inicio do programa */
int main(int argc, char **argv)
{
	/* Vari�vel que armazenar� o evento do teclado */
	EVENTO keyEvent;
	
	/* Silenciar o warning relativo aos par�metros n�o usados da fun��o main() */
	argc = argc;
	argv = argv;
	
	/* Iniciar la�o que far� a leitura dos eventos ocorridos */
	do
	{	
		/* Armazenar o evento ocorrido */
		keyEvent = Evento();
		/* Identificar se ocorreu algum evento do teclado */
        if ( keyEvent.tipo_evento & KEY_EVENT ) 
		{
			 printf("\nFoi gerado um evento pelo teclado" );
			
			 /* Se for pressionada a tecla F12, encerrar o programa */
			 if ( keyEvent.teclado.codigo_tecla == F12 )
			 {
			      printf( "\nPressionada tecla de encerramento F12\n" );
				  break;
			 }
		}	
	}
	while(1); 
	
	
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */


/* Exerc�cios:
   1) Fa�a um programa que imprima na tela o c�digo de todas as teclas que o usu�rio pressionar e somente encerre ao ser pressionada a tecla ESC;
   2) Fa�a um programa que fa�a com que seu programa encerre somente com a LIBERA��O do pressionamento da tecla F12 
   3) Fa�a um programa que imprima na tela se as luzes das seguintes teclas est�o acessas e/ou apagadas: CAPSLOCK e NUMLOCK
   4) Fa�a um programa que imprima na tela se as luzes das seguintes teclas est�o PRESSIONADAS ou N�O: SHIFT ESQUERDO, SHIFT DIREITO, CTRL ESQUERDO, CTRL DIREITO, ALT ESQUERDO
   5) ADVANCED: a) Explique quais os c�digos que s�o gerados ao pressionar a tecla ALT GR.
			    b) Fa�a um programa que identifique o pressionamento da tecla ALT GR (nos teclados que esta tecla existir).
*/

