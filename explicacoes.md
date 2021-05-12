## Estrutura de programas em C
#include <stdio.h> // biblioteca básica para execução

int main ()
{
    //sentenças
}

## Variáveis    
Variáveis são basicamente espaços reservados na memória que servem para guardar determinados valores.

tipo nome //criando variável

* nome: qualquer sequência de letras, dígitos e '_', devendo começar com uma letra. Letras maiusculas e minusculas são diferenciadas e nomes reservados não são permitidos.
* tipo: char, int, float e double.

## Constantes
Basicamente é um conceito semelhante de variável mas a variável permite alteração de valor e a constante mantém o valor.

#define nome valor //Define uma constante com o valor especificado

## Funções
Funções basicamente são blocos de código que servem para realizar tarefas específicas.

printf(string de controle e sequência de escape, argumento 1, argumento 2, ..., argumento n) //Função que apresenta para o usuário uma saída de dados.
* String de controle, especifica um formato sendo iniciada por %, que podem ser as seguintes:
    %c: imprime o conteúdo com a representação ASCII.
    %d: imprime o conteúdo na forma decimal com sinal.
    %f: imprime o conteúdo na forma ponto decimal.
    %u: imprime a variavel na forma decimal sem sinal.
* Sequência de escape:
    \n: quebra linha.
    \t: tabulação horizontal.
    \b: retrocede o cursor em um caractere (backspace).
    \r: volta ao começo da linha sem mudar de linha.
    \a: emite sinal sonoro.
    \": aspas duplas.
    \': aspas simples.
    \\: bara invertida.
* Argumentos: são valores, que podem ser fixos ou vindos de variáveis.

scanf(string de controle,argumentos) //Função que recebe um valor digitado e guarda em uma variável
* String de controle:
    %d: usado nos tipos int, short, unsigned short e unsigned char.
    %u: usado para unsigned inteiro.
    %c: usado para char.
    %s: usado para char e string.
    %f: float.
    %ef: double.