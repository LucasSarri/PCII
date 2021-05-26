/*
	Programa: Caixa de Input
	Descri��o: O objetivo do programa � criar uma janela colorida na tela do prompt que permite a entrada de dados.
	Basicamente as principais fun��es s�o: permitir a customiza��o da janela, o posicionamento da janela na tela e valida��o dos dados.
	Programador: Lucas Sarri de Mello
	RGM: 43975
	Data da �ltima modifica��o: 11/05/2021
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
	
	/* Artif�cio para tirar o warning do "-Wextra" causado pelos par�metros da main */
	argc = argc;
	argv = argv;
	
	/*Definindo a localidade do programa para poder interpretar a acentua��o da lingua */
	setlocale(LC_ALL, "Portuguese");
	
	/********************* Chamada das fun��es de Personaliza��o ***********************************/
	mensagemInput (mensagem);
	posicaoJanela (&linha, &coluna);
	dimencionamentoJanela(&largura, &altura);
	definicaoPlanoFundoMsg(&corFundo);
	definicaoCorLetraMsg(&corTexto);
	
	/********************* Chamada da cria��o da janela ***********************************/	
	criarJanela (corFundo, corTexto, coluna, linha, largura, altura, mensagem);
	
	/********************* Preenchendo espa�o vazio *************************************/
	diferenca = strlen(mensagem) - largura;
	preenchimento = preencheEspaco (diferenca);
	
	definicaoPlanoFundoMsg(&corFundo);
	definicaoCorLetraMsg(&corTexto);
	
	/*
		A cria��o � feita com base em conceitos matem�ticos onde a posi��o da coluna � igual ao tamanho total da mensagem +1, ou seja uma posi��o a frente do final da mensagem
		a posi��o na linha � feita pela divis�o entre o tamanho da mensagem pela largura, encontrando "quantas vezes a mensagem cabe na largura",
		a largura em si � a diferen�a entre o tamanho da mensagem em si pela largura total 
		e por fim a altura � a diferen�a divida pela largura, encontrando "quantas vezes a diferen�a cabe na largura"
	*/
	
	criarJanela (corFundo, corTexto, strlen(mensagem)+1 , linha, diferenca, altura, preenchimento);
	
	getch();
	
	/* Retornando para o sistema operacional que sistema encerrou corretamente */
	return 0;
}