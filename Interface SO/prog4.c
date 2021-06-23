#include <stdio.h> /* printf() */
#include <stdlib.h> /* getenv(), NULL */

int main(int argc, char *argv[], char *env[])
{
    int i = 0;
    char *variavel;

	/* Silenciar os parâmetros não utilizados argc e argv */
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

/* Faça uma função de sua autoria, denominada Getenv que faça exatamente o mesmo que faz a função getenv */
