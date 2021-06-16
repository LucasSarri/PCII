/* Programa exemplo de como ler teclas do teclado e obter os códigos delas   */
/* Como compilar: gcc prog1.c conio_v3.2.4.c -o prog1.exe -Wall -pedantic -Wextra */
/* Versão da conio utilizada: conio_v3.2.4 */

/* Declaração dos arquivos cabeçalhos padrões */
#include <stdio.h>         /* printf() */
#include <locale.h>        /* setlocale(), constante LC_ALL */

/* Declaração dos arquivos cabeçalhos não padrões */
#include "conio_v3.2.4.h"  /* clreol(), getch(), gotoxy(), _setcursortype() */

/* Declaração das diretivas para o pré-processador do GCC */
#define ESC 27

/* Início do programa */
int main( int argc, char *argv[] )
{
    /* Declaração das variáveis locais */
    int tecla; /* variável que armazenará o código da tecla lida */
    int linha_tela; /* variável que armazenará a linha atual na tela */
    
    /* Artifício para silenciar warning dos parâmetros da main pelo "-Wextra" */
    argc = argc;
    argv = argv;
    
    /* Definir a localidade em que o programa deve rodar (acentuação, moeda utilizada etc.)
       -> String "" corresponde a localidade de uso corrente do Sistema Operacional (mais portável);
       -> Também poderia usar uma string "Portuguese", mas a depender do SO, a identificação da língua brasileira poderia ser outra string, como por exemplo, PT_BR, prejudicando a portabilidade */
    setlocale(LC_ALL, "Portuguese"); 
    
    /* Limpar a tela */
    clrscr();
    
    /* Definir que o cursor piscante não seja exibido */
    _setcursortype(_NOCURSOR);
    
    linha_tela = 1;
    do{    
       gotoxy(1, linha_tela++); /* posicionar o cursor: coluna = 1, linha = 1... */
       printf("Pressione uma tecla para identificar o código, ou ESC para encerrar.");
       
       /* Ler uma tecla do teclado e armazenar o código correspondente a mesma */
       tecla = getch(); 
 
       /* Imprimir o código da tecla digitada */
       gotoxy(1, linha_tela++);
       printf("O código da tecla é: %d", tecla );
       
       
      /* Encerrar caso tenha sido digitada a tecla ESC */
      }while( tecla != ESC );
      
    /* Restaurar o cursor piscante antes de encerrar o programa */
     _setcursortype(_NORMALCURSOR); 
     
    /* Retornar para o SO que o programa encerrou corretamente */ 
    return 0;
} /* Fim do programa */