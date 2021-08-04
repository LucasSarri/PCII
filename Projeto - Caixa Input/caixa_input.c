/*
	Programa: Caixa de Input
	Descrição: O objetivo do programa é criar uma janela colorida na tela do prompt que permite a entrada de dados.
	Basicamente as principais funções são: permitir a customização da janela, o posicionamento da janela na tela e validação dos dados.
	Programador: Lucas Sarri de Mello
	RGM: 43975
	Data da última modificação: 11/05/2021
*/

/* Como compilar: gcc caixa_input.c conio_v3.2.4.c personalizacoes.c funcoesGerais.c -o caixa_input.exe -Wall -pedantic -Wextra*/

#include <stdio.h> /* printf(), scanf() e sizeof()*/
#include <locale.h> /* setlocale(), constante LC_ALL */
#include <string.h> /* strlen() */
#include <stdlib.h> /* malloc() */
#include "conio_v3.2.4.h" /* getch()*/ 
#include "personalizacoes.h" /* mensagemInput(), posicaoJanela(), dimencionamentoJanela(), definicaoPlanoFundoMsg(), definicaoCorLetraMsg()*/
#include "funcoesGerais.h" /* criarJanela() */

int main (int argc, char *argv[])
{
	char mensagem[100];
	char *preenchimento;
	int linha, coluna;
	int largura,altura;
	int corFundo, corTexto;
	int diferenca;
	
	/* Artifício para tirar o warning do "-Wextra" causado pelos parâmetros da main */
	argc = argc;
	argv = argv;
	
	/*Definindo a localidade do programa para poder interpretar a acentuação da lingua */
	setlocale(LC_ALL, "Portuguese");
	
	/********************* Chamada das funções de Personalização ***********************************/
	mensagemInput (mensagem);
	posicaoJanela (&linha, &coluna);
	dimencionamentoJanela(&largura, &altura);
	definicaoPlanoFundoMsg(&corFundo);
	definicaoCorLetraMsg(&corTexto);
	
	/********************* Chamada da criação da janela ***********************************/	
	criarJanela (corFundo, corTexto, coluna, linha, largura, altura, mensagem);
	
	/********************* Preenchendo espaço vazio *************************************/
	diferenca = strlen(mensagem) - largura;
	preenchimento = preencheEspaco (diferenca);
	
	definicaoPlanoFundoMsg(&corFundo);
	definicaoCorLetraMsg(&corTexto);
	
	/*
		A criação é feita com base em conceitos matemáticos onde a posição da coluna é igual ao tamanho total da mensagem +1, ou seja uma posição a frente do final da mensagem
		a posição na linha é feita pela divisão entre o tamanho da mensagem pela largura, encontrando "quantas vezes a mensagem cabe na largura",
		a largura em si é a diferença entre o tamanho da mensagem em si pela largura total 
		e por fim a altura é a diferença divida pela largura, encontrando "quantas vezes a diferença cabe na largura"
	*/
	
	criarJanela (corFundo, corTexto, strlen(mensagem)+1 , linha, diferenca, altura, preenchimento);
	
	getch();
	
	/* Retornando para o sistema operacional que sistema encerrou corretamente */
	return 0;
}