/* Programa para ilustrar a utilização das funções _gettext() e puttext() */

#include <stdio.h>			/* printf() */
#include "conio_v3.2.4.h"   /* gotoxy(), getch(), _gettext(), puttext() */

#define LARGURA_TELA_SALVAR 80
#define ALTURA_TELA_SALVAR 25

int main(int argc, char *argv[])
{
   char Tela[LARGURA_TELA_SALVAR * ALTURA_TELA_SALVAR * 2];
   int i;

   /* Silenciar warning */
   argc = argc;
   argv = argv;
   
   /* Limpar tela */
   clrscr();
   
   /* Preencher a tela com algumas informações */
   for (i = 0; i <= 20; i++)
       printf("Linha #%d\n", i);

   /* Salvar a tela do prompt de comando */	   
   _gettext(1, 1, LARGURA_TELA_SALVAR, ALTURA_TELA_SALVAR, Tela);
   gotoxy(1, 25);
   printf("Pressione alguma tecla para limpar a tela...");
   getch();
   
   /* Limpar a tela do prompt de comando */
   clrscr();
   gotoxy(1, 25);
   printf("Pressione alguma tecla para restaurar a tela...");
   getch();
   
   /* Restaurar a tela do prompt de comando */
   puttext(1, 1, LARGURA_TELA_SALVAR, ALTURA_TELA_SALVAR, Tela);
   gotoxy(1, 25);
   printf("Pressione alguma tecla para encerrar o programa...");
   getch();
   
   return 0;
}
