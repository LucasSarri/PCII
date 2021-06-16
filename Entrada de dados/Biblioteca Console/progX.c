 /* Programa exerc�cio: para testar sua desenvoltura com as bibliotecas conio e console */
 /* 24/05/2021 */

 /* Declara��o dos arquivos cabe�alhos */
 #include <wtypes.h>  /* tipo boolean */
 #include "conio_v3.2.4.h"
 #include "console_v1.5.4.h"   
 
 typedef struct _AREA
		        {
					int X;
					int Y;
					int width;
					int height;
		        } AREA;
				
 
 /* Inicio do programa */
int main( int argc , char **argv )
{
    boolean sair;
	EVENTO e;
	AREA areasClicaveis[5];
	int numJanelas = 0;
	int numeroVezesClicouJanela = 0;
	int i;
	
	/* Silenciar o warning relativo aos par�metros n�o usados da fun��o main() */
	argc = argc;
	argv = argv;
	
	areasClicaveis[0].X = 1;
	areasClicaveis[0].Y = 1;
	areasClicaveis[0].width = 40;
	areasClicaveis[0].height = 10;
	
	textbackground( BLUE );
	window( areasClicaveis[0].X , areasClicaveis[0].Y , areasClicaveis[0].width , areasClicaveis[0].height );
	numJanelas++;
	
	sair = FALSE;
	do
	{
		if ( hit( ALL ) )
		{
		     e = Evento();
		     if ( e.tipo_evento & MOUSE_EVENT)
		     { 
				  if ( e.mouse.botao_clicou & BOTAO_ESQUERDO_PRESSIONADO )
				  {
				       for ( i = 0 ; i < numJanelas ; i++ )	
				       {
							 if ( ( ( e.mouse.posicao.X + 1 >= areasClicaveis[i].X )
                                    &&
                                    ( e.mouse.posicao.X + 1 < areasClicaveis[i].X + areasClicaveis[i].width )
								  )
                                  &&
                                  ( ( e.mouse.posicao.Y + 1 >= areasClicaveis[i].Y )
                                    &&
                                    ( e.mouse.posicao.Y + 1 < areasClicaveis[i].Y + areasClicaveis[i].height )
								  ) 
								)
							 {	
							    numeroVezesClicouJanela++;
								textbackground( BLACK );
								window( 1 , 20 , 30 , 2 );
							 	gotoxy( 1 , 20 );
								printf( "\nClicou %d vezes sobre a janela %d" , numeroVezesClicouJanela , i );
							 } 	
								  
				       }
			      } 
		     }
			 else if ( e.tipo_evento & KEY_EVENT )
			 {
			      switch ( e.teclado.codigo_tecla )
				  {
				         case ESC:
						      system( "color" );
						      sair = TRUE;
							  break;
				  }
			 }
		}	 
	}
	while( !sair );
	
	
	/* Retornar que o programa encerrou com sucesso */
	return 0;
	
} /* Fim do programa */


/* Exerc�cios */
/* 1) Comente o programa explicando a l�gica do mesmo e colocando uma descri��o apropriada no in�cio do c�digo sobre o que faz este programa;
   2) O que faz o c�digo das linhas 53 a 60?
   3) Por que foi necess�rio acrescentar o "+1" nas linhas 53, 55, 58 e 60? Dica: analise os valores que a fun��o window() considera e os valores que a variavel areasClicaveis considera 
   4) Qual o objetivo da linha 79?
   5) Se ao inv�s de ter referenciado o campo "botao_clicou" na condi��o do if da linha 49, tivesse referenciado o campo  "botao_pressionado", qual seria o impacto nos valores mostrados na linha 68?
   6) Crie uma fun��o capaz de substituir todas as condi��es do if presente na linha 53. 
   Observa��o: o prot�tipo da sua fun��o deve ser: boolean areaClicavel(AREA *, EVENTO)
   7) Defina outra �rea clic�vel, n�o congruente a �rea j� definida, e ajuste o c�digo de acordo.
   8) Defina outra �rea clic�vel, n�o congruente a nenhuma �rea previamente definida, e ajuste o c�digo de acordo.
   
   Desafio:
   - Fa�a um programa que apresente na tela uma janela "animada" de dimens�es (1, 1, 10, 10) que se mova, automaticamente e de forma aleat�ria (ver material de suporte "Como gerar um n�mero aleat�rio"), a cada 1 segundo na tela (use a fun��o Sleep(): ver material de suporte "Como fazer uma anima��o"). Assuma que a sua janela se deslocar� em uma �rea de tela de dimens�es (1, 1, 100, 30). Se o usu�rio clicar em cima da janela, ser� exibida uma mensagem indicando quantas vezes clicou sobre a janela e, caso clique fora da janela "animada", o seu programa deve encerrar.
   
*/


