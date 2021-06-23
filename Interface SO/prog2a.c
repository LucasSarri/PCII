#include <stdio.h> /* printf() */

int main(int argc, char *argv[])
{
    int i; /* variavel contadora */

    /* Imprimindo todos os valores digitados no prompt de comando */
    for (i = 0; i < argc; i++)
         printf("Parametro %d: %s\n", i, argv[i]);

    return(0);
}
