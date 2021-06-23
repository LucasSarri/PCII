/* Programa que imprime todos os parametros passados via linha de comando, letra a letra.
   OBS.: ando com argv, logo perco o endere�o inicial de argv.
   Data da �ltima modifica��o: 27/03/2012        */
#include <stdio.h> /* printf() */

int main(int argc, char **argv)
{
    int i;  /* variavel tempor�ria respons�vel por varrer as letras de um parametro */

	/* Silenciar o parametro n�o utilizado argc */
	argc = argc;
	
    printf("\n------------------------------\n");
    printf("End. inicial de argv: %p", (void *) argv);
    printf("\n------------------------------");
	
    /* Imprimir a linha digitada via linha de comando, letra a letra */
    do{
	     printf("\n\nendereco da palavra na memoria: %p\n", *argv);
		 printf("palavra soletrada: ");
		 i = 0;
         do{
		    printf("%c ", *(*argv + i++));  /* poderia escrever tamb�m: printf("%c ", (*argv)[i++]);  */
		   }while (*(*argv + i)); /* poderia escrever tamb�m: }while ( (*argv)[i] ); */
	  }while(*++argv); /* apontar para a pr�xima linha (++argv) e pegar o valor armazenado nessa linha (*++argv). Se esse valor for um ponteiro NULO ( '\0') entao n�o h� mais palavras digitadas */  	 

    printf("\n\n------------------------------\n");
    printf("End. inicial de argv: %p", (void *) argv);
    printf("\n------------------------------\n");	  
	
    return(0);
}


/* 
ORDEM DE PRECED�NCIA E ASSOCIATIVIDADE DOS OPERADORES:
*, &, sizeof, ++, --, !, (casting) tem IGUAL preced�ncia.
E a associatividade desses operadores � da direita para a esquerda. 

*/

/* exerc�cio: - fa�a duas vers�es de um programa que conte o n�mero de caracteres somente dos par�metros passados para um programa via linha de comando:
     - a primeira vers�o pode usar a fun��o strlen
     - a segunda vers�o n�o pode usar strlen
	 
      Ex.: entrada - prog1 a bfg c3 dab
	   Sa�da:
	   a - 1 caracter
	   bfg - 3 caracteres
	   c3 - 2 caracteres
	   dab - 3 caracteres
*/
