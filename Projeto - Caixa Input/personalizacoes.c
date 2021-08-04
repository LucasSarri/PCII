#include <stdio.h> /* printf(), scanf() */
#include <locale.h> /* setlocale(), constante LC_ALL */

/* Recebendo a linha e coluna para posicionar a janela */
void posicaoJanela (int *linha, int *coluna)
{
	/*Definindo a localidade do programa para poder interpretar a acentuação da lingua */
	setlocale(LC_ALL, "Portuguese");
	
	printf("Informe a coluna que deseja posicionar a janela : ");
	scanf("%d", linha);
	printf("Informe a linha que deseja posicionar a janela : ");
	scanf("%d", coluna);
}

/* Recebendo as dimensões (Altura e largura) da janela */
void dimencionamentoJanela(int *largura, int *altura)
{
	/*Definindo a localidade do programa para poder interpretar a acentuação da lingua */
	setlocale(LC_ALL, "Portuguese");
	
	printf("Informe a largura da janela : ");
	scanf("%d", largura);
	printf("Informe a altura da janela : ");
	scanf("%d", altura);
}

/* Definindo cor do plano de fundo da mensagem*/
void definicaoPlanoFundoMsg(int *corFundo)
{
	/*Definindo a localidade do programa para poder interpretar a acentuação da lingua */
	setlocale(LC_ALL, "Portuguese");
	
	printf("Informe uma cor de fundo dentre as seguintes opções: \n  0 = Preto \t 1 = Azul \n 2 = Verde \t 3 = Ciano \n 4 = Vermelho \t 5 = Magenta \n 6 = Marrom \t 7 = Cinza Claro \n 8 = Cinza Escuro \t 9 = Azul Claro \n 10 = Verde Claro \t 11= Ciano Claro \n 12 = Vermelho Claro \t 13 = Magenta Claro \n 14 = Amarelo \t 15 = Branco \n");
	scanf("%d", corFundo);
}

/* Definindo a cor do texto da mensagem */
void definicaoCorLetraMsg (int *corTexto)
{
	/*Definindo a localidade do programa para poder interpretar a acentuação da lingua */
	setlocale(LC_ALL, "Portuguese");
	
	printf("Informe uma cor do texto dentre as seguintes opções: \n  0 = Preto \t 1 = Azul \n 2 = Verde \t 3 = Ciano \n 4 = Vermelho \t 5 = Magenta \n 6 = Marrom \t 7 = Cinza Claro \n 8 = Cinza Escuro \t 9 = Azul Claro \n 10 = Verde Claro \t 11= Ciano Claro \n 12 = Vermelho Claro \t 13 = Magenta Claro \n 14 = Amarelo \t 15 = Branco \n");
	scanf("%d", corTexto);
}