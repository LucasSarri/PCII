 /* Programa exercício: para testar sua desenvoltura com as bibliotecas conio e console */
 /* 24/05/2021 */

 /* Declaração dos arquivos cabeçalhos */
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
	
	/* Silenciar o warning relativo aos parämetros não usados da função main() */
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


/* Exercícios */
/* 1) Comente o programa explicando a lógica do mesmo e colocando uma descrição apropriada no início do código sobre o que faz este programa;
   2) O que faz o código das linhas 53 a 60?
   3) Por que foi necessário acrescentar o "+1" nas linhas 53, 55, 58 e 60? Dica: analise os valores que a função window() considera e os valores que a variavel areasClicaveis considera 
   4) Qual o objetivo da linha 79?
   5) Se ao invés de ter referenciado o campo "botao_clicou" na condição do if da linha 49, tivesse referenciado o campo  "botao_pressionado", qual seria o impacto nos valores mostrados na linha 68?
   6) Crie uma função capaz de substituir todas as condições do if presente na linha 53. 
   Observação: o protótipo da sua função deve ser: boolean areaClicavel(AREA *, EVENTO)
   7) Defina outra área clicável, não congruente a área já definida, e ajuste o código de acordo.
   8) Defina outra área clicável, não congruente a nenhuma área previamente definida, e ajuste o código de acordo.
   
   Desafio:
   - Faça um programa que apresente na tela uma janela "animada" de dimensões (1, 1, 10, 10) que se mova, automaticamente e de forma aleatória (ver material de suporte "Como gerar um número aleatório"), a cada 1 segundo na tela (use a função Sleep(): ver material de suporte "Como fazer uma animação"). Assuma que a sua janela se deslocará em uma área de tela de dimensões (1, 1, 100, 30). Se o usuário clicar em cima da janela, será exibida uma mensagem indicando quantas vezes clicou sobre a janela e, caso clique fora da janela "animada", o seu programa deve encerrar.
   
*/


