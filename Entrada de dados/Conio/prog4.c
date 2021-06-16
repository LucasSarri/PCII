/* Programa para ilustrar a utiliza��o da fun��o window() da conio com a leitura de teclas por meio de getch() */

#include <locale.h>			/* setlocale() */
#include <stdio.h>			/* printf() */
#include <string.h>         /* strlen() */
#include "conio_v3.2.4.h"   /* textbackground(), window(), gotoxy(), getch(), constantes BLACK, BLUE, LIGHTGRAY */

#define ESC 27
#define SETA_PARA_DIREITA 77
#define SETA_PARA_BAIXO 80

#define LINHA_INICIAL_JANELA 1
#define COLUNA_INICIAL_JANELA 1
#define ALTURA_MAXIMA_JANELA 25
#define LARGURA_MAXIMA_JANELA 80

int main(int argc, char *argv[])
{
	char *mensagem = "Pressione setas de dire��o para aumentar e diminuir o tamanho da janela, ou ESC para encerrar...";
	int largura_janela = strlen(mensagem);
	int altura_janela = 15;
	int tecla;
	
	argc = argc;
	argv = argv;
	
	/* Caracteres aparecerem acentuados corretamente no prompt de comando */
	setlocale(LC_ALL, "Portuguese");
	
	/* Limpar a janela do console */
	clrscr();
	
	/* Criar uma subjanela e permitir que o usu�rio aumenta e diminua ela */
	do
	{
		textbackground(BLUE);	
		window(COLUNA_INICIAL_JANELA, LINHA_INICIAL_JANELA, COLUNA_INICIAL_JANELA + largura_janela, LINHA_INICIAL_JANELA + altura_janela);
		
		/* Posicionar a mensagem no canto inferior direito */
		gotoxy(COLUNA_INICIAL_JANELA + largura_janela - strlen(mensagem) + 1, LINHA_INICIAL_JANELA + altura_janela);
		printf("%s", mensagem);
		
		/* Ler uma tecla do usu�rio */
		tecla = getch();
		switch(tecla)
		{	   case 0:	 /* tecla estendida */
			   case 224: /* tecla estendida */
					tecla = getch();
					if ( tecla == SETA_PARA_DIREITA )
						 largura_janela++;
					else if ( tecla == SETA_PARA_BAIXO )
						 altura_janela++;
				    break;
		}
	}while(tecla != ESC);	/* Encerrar o la�o quando o usu�rio pressionar a tecla ESC */
	
	/* Retornar � cor original da janela do prompt de comando. Assumindo que a cor de fundo � BLACK e a da letra � LIGHTGRAY */
	textbackground(BLACK);
	textcolor(LIGHTGRAY);
	clrscr();

	return 0;
}


/* Exerc�cios:
   1) Modifique o programa para que seja respeitado o aumento da janela para o valor m�ximo dado por LARGURA_MAXIMA_JANELA 
   2) Modifique o programa para permitir que o usu�rio tamb�m possa aumentar a altura da janela
   3) Modifique o programa para que seja respeitado o aumento da janela para o valor m�ximo dado por ALTURA_MAXIMA_JANELA 
   4) Modifique o programa para que a cada pressionamento de uma tecla de dire��o (ESQUERDA OU PARA_BAIXO) a cor da janela mude
*/