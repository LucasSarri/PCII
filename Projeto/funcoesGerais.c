#include <stdio.h> /* printf(), scanf() */
#include <locale.h> /* setlocale(), constante LC_ALL */
#include "conio_v3.2.4.h" /* textbackground(), window(), gotoxy(), constantes dentro de COLORS */ 

/* Recebendo a mensagem que será exibida na caixa de input*/
void mensagemInput (char *mensagem)
{
	/*Definindo a localidade do programa para poder interpretar a acentuação da lingua */
	setlocale(LC_ALL, "Portuguese");
	
	printf("Informe a mensagem para a caixa do input : ");
	scanf("%s", mensagem);
}

char *preencheEspaco (int tam)
{
	/* Criando variável para receber o caractere _ que irá preencher o espaço vazio, para isso realizei a alocação dinâmica 
	de acordo com o tam que será a diferença do tamanho da mensagem para o tamanho da janela*/
	int alocacao = tam * sizeof(char);
	char *mensagem;
	mensagem = malloc (alocacao);
	
	int i = 0;
	while (i < alocacao)
	{
		mensagem[i] = '_';
	}
	
	return mensagem;
}

/* Função que cria a janela com base nas informações recebidas de outros procedimentos*/
void criarJanela (int corFundo, int corTexto, int coluna, int linha, int largura, int altura, char *mensagem)
{
	textbackground(corFundo);
	textcolor(corTexto);
	window(coluna, linha, largura, altura);
	gotoxy(1,1);
	printf("%s", mensagem);
}