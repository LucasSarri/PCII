#include <stdio.h>  /* scanf(); printf() */
#include <string.h> /* strncmp() */
#include <stdlib.h> /* variavel global environ. Desse modo n�o preciso declarar outra variavel global no programa */

/* Definicao dos tipos */
   typedef enum {false, true} boolean;

/* definicao dos prototipos das funcoes */
   char *Getenv(const char *);
   
   
/* Notar que a vari�vel envp contendo as vari�veis de ambiente n�o � standard C , portanto a sua aus�ncia n�o � reclamada pelo gcc*/
int main(int argc, char *argv[])
{
    /*  declara��o das variaveis locais */
      char variavel[30];  /* variavel de ambiente que o usuario vai buscar */
      char *valor;        /* valor da variavel de ambiente obtido */  

	/* Silenciar os par�metros n�o utilizados argc e argv */
	argc = argc;
	argv = argv;
	  
    /* pedir  ao usu�rio que digite a vari�vel de ambiente a ser localizada */
      printf("Digite a variavel a ser procurada: ");
      scanf("%s", variavel);

    /* Chamar a fun��o que vai retornar o valor da vari�vel de ambiente ou NULL, caso n�o seja encontrada */
	  valor = Getenv(variavel);

    /* Imprimir o valor encontrado para aa vari�vel de ambiente */
	  valor ? printf("%s", valor) : printf("Nao encontrada");
	
	/* retornar ao SO um valor indicando que o programa terminou normalmente */
      return 0;
}

char *Getenv(const char *variavel)
{
     const char *s; /* criar um ponteiro para um caracter e tornar o conte�do apontado por s "read-only", isto �, impedir opera��es do tipo, (*s)++ */
	 int n = strlen(variavel); /* armazenar o tamanho da vari�vel de ambiente procurada pelo usu�rio */
	 
	 /* Descri��o do la�o FOR
	       -> fazer s apontar para a primeira linha das vari�veis de ambiente: s = *environ
	       -> verificar se o endereco de terminaram as linhas: s
	       -> ir para a pr�xima linha das vari�veis de ambiente env: ++environ
		pegar o endere�o dessa pr�xima linha: *++environ
                    fazer s receber esse endere�o: s = *++environ		  */
	   for (s = *environ; s; s = *++environ)
       {
	        if (!strncmp(s, variavel, n) && s[n] == '=') /* verificar se as n primeiras posicoes de s cont�m a palavra "variavel" e se a pr�xima posicao (posicao n) contem o caracter 'n' */
                return ((char *) &s[n+1]);  /* se a condi��o do if for verdadeira, entao retornar o endereco do primeiro caracter ap�s o sinal de '=' */
       }
	 /* caso n�o tenha sido encontrada a variavel de ambiente procurada ent�o retornar NULL */
       return (NULL);

}

/* aprimoramento que deve fazer no programa:
     - Fazer com que o programa reconhe�a uma vari�vel de ambiente com o mesmo nome, independente de ter caracteres mai�sculos ou min�sculos. Ex.: deve reconhecer tanto se o usu�rio digitar PATH, quanto Path. por exemplo.
*/	 
  
