#include <stdio.h>  /* scanf(); printf() */
#include <string.h> /* strncmp() */
#include <stdlib.h> /* variavel global environ. Desse modo não preciso declarar outra variavel global no programa */

/* Definicao dos tipos */
   typedef enum {false, true} boolean;

/* definicao dos prototipos das funcoes */
   char *Getenv(const char *);
   
   
/* Notar que a variável envp contendo as variáveis de ambiente não é standard C , portanto a sua ausência não é reclamada pelo gcc*/
int main(int argc, char *argv[])
{
    /*  declaração das variaveis locais */
      char variavel[30];  /* variavel de ambiente que o usuario vai buscar */
      char *valor;        /* valor da variavel de ambiente obtido */  

	/* Silenciar os parâmetros não utilizados argc e argv */
	argc = argc;
	argv = argv;
	  
    /* pedir  ao usuário que digite a variável de ambiente a ser localizada */
      printf("Digite a variavel a ser procurada: ");
      scanf("%s", variavel);

    /* Chamar a função que vai retornar o valor da variável de ambiente ou NULL, caso não seja encontrada */
	  valor = Getenv(variavel);

    /* Imprimir o valor encontrado para aa variável de ambiente */
	  valor ? printf("%s", valor) : printf("Nao encontrada");
	
	/* retornar ao SO um valor indicando que o programa terminou normalmente */
      return 0;
}

char *Getenv(const char *variavel)
{
     const char *s; /* criar um ponteiro para um caracter e tornar o conteúdo apontado por s "read-only", isto é, impedir operações do tipo, (*s)++ */
	 int n = strlen(variavel); /* armazenar o tamanho da variável de ambiente procurada pelo usuário */
	 
	 /* Descrição do laço FOR
	       -> fazer s apontar para a primeira linha das variáveis de ambiente: s = *environ
	       -> verificar se o endereco de terminaram as linhas: s
	       -> ir para a próxima linha das variáveis de ambiente env: ++environ
		pegar o endereço dessa próxima linha: *++environ
                    fazer s receber esse endereço: s = *++environ		  */
	   for (s = *environ; s; s = *++environ)
       {
	        if (!strncmp(s, variavel, n) && s[n] == '=') /* verificar se as n primeiras posicoes de s contém a palavra "variavel" e se a próxima posicao (posicao n) contem o caracter 'n' */
                return ((char *) &s[n+1]);  /* se a condição do if for verdadeira, entao retornar o endereco do primeiro caracter após o sinal de '=' */
       }
	 /* caso não tenha sido encontrada a variavel de ambiente procurada então retornar NULL */
       return (NULL);

}

/* aprimoramento que deve fazer no programa:
     - Fazer com que o programa reconheça uma variável de ambiente com o mesmo nome, independente de ter caracteres maiúsculos ou minúsculos. Ex.: deve reconhecer tanto se o usuário digitar PATH, quanto Path. por exemplo.
*/	 
  
