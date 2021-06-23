/* Programa que imprime todos os parametros passados via linha de comando, letra a letra.
   OBS.: crio uma variável auxiliar para varrer os parâmetros, preservando o endereço inical
         de argv.
   Data da última modificação: 27/03/2012        */
#include <stdio.h> /* printf() */

int main(int argc, char **argv)
{
    char **p;  /* variavel auxiliar */
	char *c;   /* variavel auxiliar */

	/* Silenciar o parametro não utilizado argc */
	argc = argc;	
	
    printf("\n------------------------------\n");
    printf("End. inicial de argv: %p", (void *) argv);
    printf("\n------------------------------");
	
	p = argv; /* fazer p apontar para o mesmo endereço apontado por argv */
    /* Imprimir a linha digitada via linha de comando, letra a letra */
    do{
	     printf("\n\nendereco da palavra na memoria: %p\n", *p);
		 printf("palavra soletrada: ");
 	     c = *p;
         do{
		    printf("%c ", *c++);
			}while (*c);
	  }while(*++p); /* apontar para a próxima linha (++p) e pegar o valor armazenado nessa linha (*++p). Se esse valor for '\0' entao não há mais palavras digitadas */  	 

    printf("\n\n------------------------------\n");
    printf("End. inicial de argv: %p", (void *) argv);
    printf("\n------------------------------\n");	  
	
    return(0);
}


/* 
ORDEM DE PRECEDÊNCIA E ASSOCIATIVIDADE DOS OPERADORES:
*, &, sizeof, ++, --, !, (casting) tem IGUAL precedência.
E a associatividade desses operadores é da direita para a esquerda. 

*/

/* exercício: - faça duas versões de um programa que conte o número de caracteres somente dos parâmetros passados para um programa via linha de comando:
     - a primeira versão pode usar a função strlen
     - a segunda versão não pode usar strlen
	 
      Ex.: entrada - prog1 a bfg c3 dab
	   Saída:
	   a - 1 caracter
	   bfg - 3 caracteres
	   c3 - 2 caracteres
	   dab - 3 caracteres
*/
