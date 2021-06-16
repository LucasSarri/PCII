/* Programa exemplo de como ler teclas do teclado SEM PARAR o programa: função kbhit()  */
/* Como compilar: gcc prog2.c conio_v3.2.4.c -o prog2.exe -Wall -pedantic -Wextra */
/* Versão da conio utilizada: conio_v3.2.4 */

/* Declaração dos arquivos cabeçalhos padrões */
#include <stdio.h>         /* printf() */
#include <locale.h>        /* setlocale(), constante LC_ALL */

/* Declaração dos arquivos cabeçalhos não padrões */
#include "conio_v3.2.4.h"  /* _setcursortype(), clreol(), getch(), gotoxy(), kbhit(),
                              textcolor(), constante COLORS, _NOCURSOR, _NORMALCURSOR, BLACK */

/* Declaração das diretivas para o pré-processador do GCC */
#define ESC 27

/* Início do programa */
int main( int argc, char *argv[] )
{
    /* Declaração das variáveis locais */
    int contador = 0;
    int tecla;
    COLORS cor = BLACK;
    
    /* Artifício para silenciar warning dos parâmetros da main pelo "-Wextra" */
    argc = argc;
    argv = argv;
    
    /* Definindo a localidade para a mesma do SO o que permitirá imprimir caracteres acentuados */
    setlocale(LC_ALL, "");
    
    /* Limpar a tela */
    clrscr();
    
    /* Definir que o cursor piscante não seja exibido */
    _setcursortype(_NOCURSOR);
    
    contador = 0;
    do{    
       gotoxy(1, 1); /* posicionar o cursor: coluna = 1, linha = 1... */
       printf("%d", contador++);
       
       /* Se tiver sido pressionada alguma tecla */
       if(kbhit())
       {
             /* Imprimir o código da tecla digitada */
             gotoxy(1, 10);
             clreol();
             tecla = getch();
             switch(tecla)
             {
                    case 0:    /* código indicativo de tecla estendida */
                    case 224: /* Windows prefix extended key */
                         /* Alternar a cor da letra dentro do intervalo da paleta de cores disponível (16 cores), pulando a cor BLACK*/
                         textcolor( 1 + cor++ % 15);
                         
                         /* Definir a cor de fundo da letra */
                         textbackground(BLACK);
                         
                         /* Indicar que é uma tecla estendida */
                         printf("Tecla estendida\n");
                         
                         /* Ler o código da tecla */
                         tecla = getch();
                         printf("O código da tecla é: %d\n", tecla );
                         break;
                    default:
                         printf("O código da tecla é: %d\n", tecla );
                         break;
             }
       }
       
      /* Loop infinito */
      }while( 1 );
      
    /* Restaurar o cursor piscante antes de encerrar o programa */
     _setcursortype(_NORMALCURSOR); 
     
    /* Retornar para o SO que o programa encerrou corretamente */ 
    return 0;
} /* Fim do programa */


/* Exercícios:
   1) As linhas 64 e 67 são repetidas. Como poderia modificar o programa para ter somente uma linha dessas escrita no código, mas sem modificar o que o programa faz.
   2) Alterar o programa para que ele seja capaz de encerrar ao ser pressionada a tecla ESC.
   3) Alterar o programa para que ele seja capaz de encerrar ao ser pressionada a tecla CTRL + A;
*/   