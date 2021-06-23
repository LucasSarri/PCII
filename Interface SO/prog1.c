#include <stdio.h> /* printf() */

int main(int argc, char *argv[], char *env[])
{
	/* Silenciar os parametro nãos utilizados argv e env */
	argv = argv;
	env = env;

    printf("Numero de parametros: %i", argc);
    return 0;
}

/* exemplos de execução:
     Ex.1:
	  Entrada: prog1
	  Saída: 1
      Ex.2:
	   Entrada: prog1 a b c
	   Saída: 4
*/
