/* exerc�cio: - fa�a duas vers�es de um programa que conte o n�mero de caracteres somente dos par�metros passados para um programa via linha de comando:
     - a primeira vers�o pode usar a fun��o strlen
     - a segunda vers�o n�o pode usar strlen
	 
      Ex.: entrada - prog1 a bfg c3 dab
	   Sa�da:
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