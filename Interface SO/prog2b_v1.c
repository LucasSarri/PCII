/* Programa que imprime todos os parametros passados via linha de comando, linha a linha.
   OBS.: ando com argv, logo perco o endere�o inicial de argv.
   Data da �ltima modifica��o: 27/03/2012        */

#include <stdio.h> /* printf() */

int main(int argc, char *argv[])
{
	/* Silenciar o parametro n�o utilizado argc */
	argc = argc;

    printf("\n------------------------------\n");
    printf("End. inicial de argv: %p", (void *) argv);
    printf("\n------------------------------\n");	
    /* Imprimir a linha digitada via linha de comando, palavra a palavra */	
    do{
	     printf("endereco da palavra na memoria: %p\n", *argv);
         printf("palavra: %s\n\n", *argv); /* imprimir a string armazenada no endere�o *p */
	  }while(*++argv); /* apontar para a pr�xima linha (++argv) e pegar o valor armazenado nessa linha (*++argv). Se esse valor for '\0' entao n�o h� mais palavras digitadas */  	 

    printf("\n------------------------------\n");	  
	printf("End. final de argv: %p", (void *) argv);
    printf("\n------------------------------\n");	  
	  return(0);
}


/* 
ORDEM DE PRECED�NCIA E ASSOCIATIVIDADE DOS OPERADORES:
*, &, sizeof, ++, --, !, (casting) tem IGUAL preced�ncia.
E a associatividade desses operadores � da direita para a esquerda. 

*/

