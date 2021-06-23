#include <stdio.h> /* printf() */
#include <stdlib.h> /* getenv(), NULL */

int main(int argc, char *argv[], char *env[])
{
    int i = 0;
    char *variavel;

	/* Silenciar os par�metros n�o utilizados argc e argv */
	argc = argc;
	argv = argv;
	
    printf("VARIAVEIS DE AMBIENTE\n");
    printf("-----------------------");
    for (i = 0; env[i] != NULL; i++)
    {
         printf("%s\n", env[i]);
    }
    printf("-----------------------");

    variavel = getenv("PATH");

    printf("\n\nVALOR DA VARIAVEL PATH\n");    
    printf("%s", variavel);
    return(0);
}

/* Fa�a uma fun��o de sua autoria, denominada Getenv que fa�a exatamente o mesmo que faz a fun��o getenv */
