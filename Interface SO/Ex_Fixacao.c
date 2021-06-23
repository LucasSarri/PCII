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

/*gcc Ex_Fixacao.c -o Ex_Fixacao.exe -Wall -pedantic -Wextra -Werror*/

#include <stdio.h> 

int main (int argc, char *argv[])
{
	char **aux; 
	char *auxiliar;
	int i = 0;
	
	argc = argc;
	aux = argv;
	aux += 1;
	
	/*a ab abc abcd*/
	/*a b c*/
    do
	{
 	    auxiliar = *aux;
		i = 0;
		
        do
		{
			i++;
		}while (*++auxiliar);

		printf(" %d ", i);
		printf("\n");
		
	}while(*++aux);
	
	scanf("%d", &i);
	
	return(0);
}