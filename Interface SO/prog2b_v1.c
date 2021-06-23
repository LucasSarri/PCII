/* Programa que imprime todos os parametros passados via linha de comando, linha a linha.
   OBS.: ando com argv, logo perco o endereço inicial de argv.
   Data da última modificação: 27/03/2012        */

#include <stdio.h> /* printf() */

int main(int argc, char *argv[])
{
	/* Silenciar o parametro não utilizado argc */
	argc = argc;

    printf("\n------------------------------\n");
    printf("End. inicial de argv: %p", (void *) argv);
    printf("\n------------------------------\n");	
    /* Imprimir a linha digitada via linha de comando, palavra a palavra */	
    do{
	     printf("endereco da palavra na memoria: %p\n", *argv);
         printf("palavra: %s\n\n", *argv); /* imprimir a string armazenada no endereço *p */
	  }while(*++argv); /* apontar para a próxima linha (++argv) e pegar o valor armazenado nessa linha (*++argv). Se esse valor for '\0' entao não há mais palavras digitadas */  	 

    printf("\n------------------------------\n");	  
	printf("End. final de argv: %p", (void *) argv);
    printf("\n------------------------------\n");	  
	  return(0);
}


/* 
ORDEM DE PRECEDÊNCIA E ASSOCIATIVIDADE DOS OPERADORES:
*, &, sizeof, ++, --, !, (casting) tem IGUAL precedência.
E a associatividade desses operadores é da direita para a esquerda. 

*/

