/* Programa exemplo de como ler teclas do teclado e obter os c�digos delas   */
/* Como compilar: gcc prog1.c conio_v3.2.4.c -o prog1.exe -Wall -pedantic -Wextra */
/* Vers�o da conio utilizada: conio_v3.2.4 */

/* Declara��o dos arquivos cabe�alhos padr�es */
#include <stdio.h>         /* printf() */
#include <locale.h>        /* setlocale(), constante LC_ALL */

/* Declara��o dos arquivos cabe�alhos n�o padr�es */
#include "conio_v3.2.4.h"  /* clreol(), getch(), gotoxy(), _setcursortype() */

/* Declara��o das diretivas para o pr�-processador do GCC */
#define ESC 27

/* In�cio do programa */
int main( int argc, char *argv[] )
{
    /* Declara��o das vari�veis locais */
    int tecla; /* vari�vel que armazenar� o c�digo da tecla lida */
    int linha_tela; /* vari�vel que armazenar� a linha atual na tela */
    
    /* Artif�cio para silenciar warning dos par�metros da main pelo "-Wextra" */
    argc = argc;
    argv = argv;
    
    /* Definir a localidade em que o programa deve rodar (acentua��o, moeda utilizada etc.)
       -> String "" corresponde a localidade de uso corrente do Sistema Operacional (mais port�vel);
       -> Tamb�m poderia usar uma string "Portuguese", mas a depender do SO, a identifica��o da l�ngua brasileira poderia ser outra string, como por exemplo, PT_BR, prejudicando a portabilidade */
    setlocale(LC_ALL, "Portuguese"); 
    
    /* Limpar a tela */
    clrscr();
    
    /* Definir que o cursor piscante n�o seja exibido */
    _setcursortype(_NOCURSOR);
    
    linha_tela = 1;
    do{    
       gotoxy(1, linha_tela++); /* posicionar o cursor: coluna = 1, linha = 1... */
       printf("Pressione uma tecla para identificar o c�digo, ou ESC para encerrar.");
       
       /* Ler uma tecla do teclado e armazenar o c�digo correspondente a mesma */
       tecla = getch(); 
 
       /* Imprimir o c�digo da tecla digitada */
       gotoxy(1, linha_tela++);
       printf("O c�digo da tecla �: %d", tecla );
       
       
      /* Encerrar caso tenha sido digitada a tecla ESC */
      }while( tecla != ESC );
      
    /* Restaurar o cursor piscante antes de encerrar o programa */
     _setcursortype(_NORMALCURSOR); 
     
    /* Retornar para o SO que o programa encerrou corretamente */ 
    return 0;
} /* Fim do programa */