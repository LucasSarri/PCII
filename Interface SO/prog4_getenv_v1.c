
/* Atencao: esta versão de getenv diferencia variaveis maiúsculas de minúsculas. Portanto, para uma variavel de ambiente ser
     localizada, ela deve ser digitada EXATAMENTE como aparece quando da execução de "prog3a.c" 
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
    /*  declaração das variaveis locais */
      char variavel[30];  /* variavel de ambiente que o usuario vai buscar */
      char *valor;        /* valor da variavel de ambiente obtido */  

	/* Silenciar os parâmetros não utilizados argc e argv */
	argc = argc;
	argv = argv;
	
    pointer_env = env;  /* apontar para o mesmo endereço que a variável de ambiente env*/
	
    /* pedir  ao usuário que digite a variável de ambiente a ser localizada */
      printf("Digite a variavel a ser procurada: ");
      scanf("%s", variavel);

    /* Chamar a função que vai retornar o valor da variável de ambiente ou NULL, caso não seja encontrada */
	  valor = Getenv(variavel);

    /* Imprimir o valor encontrado para aa variável de ambiente */
	  printf("%s", valor);
	
	/* retornar ao SO um valor indicando que o programa terminou normalmente */
      return 0;
}

char *Getenv(const char *variavel)
{
     const char *s; /* criar um ponteiro para um caracter e tornar o conteúdo apontado por s "read-only", isto é, impedir operações do tipo, (*s)++ */
     int n = strlen(variavel); /* armazenar o tamanho da variável de ambiente procurada pelo usuário */
	 
	 /* Descrição do laço FOR
	       -> fazer s apontar para a primeira linha de env: s = *pointer_env
	       -> verificar se o endereco de uma linha é nulo: s
	       -> ir para a próxima linha de env: ++pointer_env
		pegar o endereço dessa próxima linha: *++pointer_env
                    fazer s receber esse endereço: s = *++pointer_env		  */
	   for (s = *pointer_env; s; s = *++pointer_env)
       {
            if (!strncmp(s, variavel, n) && s[n] == '=') /* verificar se as n primeiras posicoes de s contém a palavra "variavel" e se a próxima posicao (posicao n) contem o caracter 'n' */
                return ( (char *)(&s[n+1]) );  /* se a condição do if for verdadeira, entao retornar o endereco do primeiro caracter após o sinal de '=' */
       }
	 /* caso não tenha sido encontrada a variavel de ambiente procurada então retornar NULL */
       return (NULL);

}

/* aprimoramento que deve fazer no programa:
     - Fazer com que o programa reconheça uma variável de ambiente com o mesmo nome, independente de ter caracteres maiúsculos ou minúsculos. Ex.: deve reconhecer tanto se o usuário digitar PATH, quanto Path. por exemplo.
*/	 
  
