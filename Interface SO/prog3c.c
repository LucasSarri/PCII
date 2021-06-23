/* Imprimir todas as variaveis de ambiente sem o uso de nenhuma variavel i local */
#include <stdio.h> /* printf()  */

int main(int argc, char *argv[], char *env[])
{

	/* Silenciar os parâmetros não utilizados argc e argv */
	argc = argc;
	argv = argv;

    for(;printf("%s\n", *env++), *env;);
    
    
    return(0);
}


