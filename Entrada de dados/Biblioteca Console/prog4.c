 /* Descrição: Ler uma tecla específica do teclado */
 /* 14/03/2015 */

 /* Declaração dos arquivos cabeçalhos */
 #include <stdio.h>            /* função printf() */
 #include "console_v1.5.4.h"   /* função Evento() */
 
 /* Inicio do programa */
int main(int argc, char **argv)
{
	/* Variável que armazenará o evento do teclado */
	EVENTO keyEvent;
	
	/* Silenciar o warning relativo aos parämetros não usados da função main() */
	argc = argc;
	argv = argv;
	
	/* Iniciar laço que fará a leitura dos eventos ocorridos */
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


/* Exercícios:
   1) Faça um programa que imprima na tela o código de todas as teclas que o usuário pressionar e somente encerre ao ser pressionada a tecla ESC;
   2) Faça um programa que faça com que seu programa encerre somente com a LIBERAÇÃO do pressionamento da tecla F12 
   3) Faça um programa que imprima na tela se as luzes das seguintes teclas estão acessas e/ou apagadas: CAPSLOCK e NUMLOCK
   4) Faça um programa que imprima na tela se as luzes das seguintes teclas estão PRESSIONADAS ou NÃO: SHIFT ESQUERDO, SHIFT DIREITO, CTRL ESQUERDO, CTRL DIREITO, ALT ESQUERDO
   5) ADVANCED: a) Explique quais os códigos que são gerados ao pressionar a tecla ALT GR.
			    b) Faça um programa que identifique o pressionamento da tecla ALT GR (nos teclados que esta tecla existir).
*/

