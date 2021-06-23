
/* Atencao: esta vers�o de getenv diferencia variaveis mai�sculas de min�sculas. Portanto, para uma variavel de ambiente ser
     localizada, ela deve ser digitada EXATAMENTE como aparece quando da execu��o de "prog3a.c" 
    Ver ao final deste arquivo, o aprimoramento que deve fazer neste programa. 
*/
#include <stdio.h>  /* scanf(); printf() */
#include <string.h> /* strncmp() */

/* Definicao dos tipos */
   typedef enum {false, true} boolean;

/* definicao das variaveis globais */
   char **pointer_env;

/* definicao dos prototipos das funcoes */
   char *Getenv(const char *);

int main(int argc, char *argv[], char *env[])
{
    /*  declara��o das variaveis locais */
      char variavel[30];  /* variavel de ambiente que o usuario vai buscar */
      char *valor;        /* valor da variavel de ambiente obtido */  

	/* Silenciar os par�metros n�o utilizados argc e argv */
	argc = argc;
	argv = argv;
	
    pointer_env = env;  /* apontar para o mesmo endere�o que a vari�vel de ambiente env*/
	
    /* pedir  ao usu�rio que digite a vari�vel de ambiente a ser localizada */
      printf("Digite a variavel a ser procurada: ");
      scanf("%s", variavel);

    /* Chamar a fun��o que vai retornar o valor da vari�vel de ambiente ou NULL, caso n�o seja encontrada */
	  valor = Getenv(variavel);

    /* Imprimir o valor encontrado para aa vari�vel de ambiente */
	  printf("%s", valor);
	
	/* retornar ao SO um valor indicando que o programa terminou normalmente */
      return 0;
}

char *Getenv(const char *variavel)
{
     const char *s; /* criar um ponteiro para um caracter e tornar o conte�do apontado por s "read-only", isto �, impedir opera��es do tipo, (*s)++ */
     int n = strlen(variavel); /* armazenar o tamanho da vari�vel de ambiente procurada pelo usu�rio */
	 
	 /* Descri��o do la�o FOR
	       -> fazer s apontar para a primeira linha de env: s = *pointer_env
	       -> verificar se o endereco de uma linha � nulo: s
	       -> ir para a pr�xima linha de env: ++pointer_env
		pegar o endere�o dessa pr�xima linha: *++pointer_env
                    fazer s receber esse endere�o: s = *++pointer_env		  */
	   for (s = *pointer_env; s; s = *++pointer_env)
       {
            if (!strncmp(s, variavel, n) && s[n] == '=') /* verificar se as n primeiras posicoes de s cont�m a palavra "variavel" e se a pr�xima posicao (posicao n) contem o caracter 'n' */
                return ( (char *)(&s[n+1]) );  /* se a condi��o do if for verdadeira, entao retornar o endereco do primeiro caracter ap�s o sinal de '=' */
       }
	 /* caso n�o tenha sido encontrada a variavel de ambiente procurada ent�o retornar NULL */
       return (NULL);

}

/* aprimoramento que deve fazer no programa:
     - Fazer com que o programa reconhe�a uma vari�vel de ambiente com o mesmo nome, independente de ter caracteres mai�sculos ou min�sculos. Ex.: deve reconhecer tanto se o usu�rio digitar PATH, quanto Path. por exemplo.
*/	 
  
