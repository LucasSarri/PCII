#include <stdio.h> /* printf() */

int main(int argc, char *argv[], char *env[])
{
	/* Silenciar os parametro n�os utilizados argv e env */
	argv = argv;
	env = env;

    printf("Numero de parametros: %i", argc);
    return 0;
}

/* exemplos de execu��o:
     Ex.1:
	  Entrada: prog1
	  Sa�da: 1
      Ex.2:
	   Entrada: prog1 a b c
	   Sa�da: 4
*/
