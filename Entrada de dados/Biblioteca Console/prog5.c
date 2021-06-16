 /* Descri��o: Identificar um clique do bot�o esquerdo do mouse */
 /* 15/03/2015 */

 /* Declara��o dos arquivos cabe�alhos */
 #include <stdio.h>            /* fun��o printf() */
 #include "console_v1.5.4.h"   /* fun��o Evento() */
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
	/* Vari�vel que armazenar� o evento do mouse */
	EVENTO mouseEvent;
	
	/* Silenciar o warning relativo aos par�metros n�o usados da fun��o main() */
	argc = argc;
	argv = argv;

	/* Exibir uma mensagem na tela para saber o que o programa est� esperando */
    printf( "\nAguardando o pressionamento do botao esquerdo do mouse..." );	
	
	/* Iniciar la�o que far� a leitura dos eventos ocorridos */
	do
	{
		/* Armazenar o evento ocorrido */
		mouseEvent = Evento();
		/* Identificar se ocorreu algum evento do mouse */
        if ( mouseEvent.tipo_evento & MOUSE_EVENT ) 
		{
			/* Se for pressionado o bot�o esquerdo do mouse, imprimir na tela esse fato */
			if ( mouseEvent.mouse.botao_pressionado & BOTAO_ESQUERDO_PRESSIONADO )
			{
			     printf( "\nPressionado botao esquerdo do mouse, nas coordenadas: X = %d e Y = %d\n" , mouseEvent.mouse.posicao.X , mouseEvent.mouse.posicao.Y );				 
				 break;
			}
		}	
	}
	while(1); 
	
	
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */

/* Exerc�cios:
   1) Fa�a um programa que fa�a com que seu programa encerre somente com a LIBERA��O do pressionamento do bot�o esquerdo do mouse 
   2) Fa�a um programa que identifique o PRESSIONAMENTO do bot�o direito do mouse;
   3) Fa�a um programa que imprima na tela o PIXEL em que houve um CLIQUE com o bot�o direito do mouse;
   4) Fa�a um programa que identifique se a "roda de rolagem" do mouse foi girada PARA CIMA ou PARA BAIXOimprima na tela o pixel em que foi pressionado o botao e se as luzes das seguintes teclas est�o acessas e/ou apagadas: CAPSLOCK e NUMLOCK
      Dica: veja como a fun��o IdentificarEvento() faz a identifica��o desse tipo de evento
*/

