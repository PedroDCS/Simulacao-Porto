#include<stdlib.h>
#include<stdio.h>

typedef struct Pcelula *TapontP;
typedef struct Pcelula{
	int conteiner;
	TapontP prox;
}Pcelula;

typedef struct Pilha{
	TapontP fundo, topo;
	int tamanho;
}Pilha;

typedef struct Navio{
	int ID, tempo_espera, existe, conteiners;
	Pilha pilha[4];
}Navio;

typedef struct Fcelula *TapontF;
typedef struct Fcelula{
	Navio navio;
	TapontF prox;
}Fcelula;

typedef struct Fila{
	int tamanho;
	TapontF frente, atras;
}Fila;

typedef struct Grua{
	int viagens;
	int carro;
}Grua;

typedef struct Atracamento{
	Grua grua;
	Navio navio_atual;
	int ocupada;
}Atracamento;

typedef struct No *TapontA;
typedef struct No{
	Navio navio;
	int fb;
	TapontA esq, dir;
}No;

typedef struct Porto{
	Atracamento atracamento[4];
	Pilha travessa[4];
}Porto;

void FFVazia(Fila *f); // inicia a fila vazia
void enfileira(Navio n, Fila *f);//Enfilera o navio na ultima posição
void desenfilera(Navio *n, Fila *f);// Desenfilera o navio da primeira posição
int FVazia(Fila f);// Retorna se a fila esta vazia ou não
void ImprimeFila(Fila *fila);
int tamanhoFila(Fila *f);


int qtdID;
int PVazia(Pilha p);
void FPVazia(Pilha *p);//inicia a pilha vazia
void empilha(int conteiner, Pilha *p);//empilha um conteiner
void desempilha(Pilha *p);//desempilha um conteiner

void FAVazia(TapontA *raiz);//inicia a arvore vazia
int insere_AVL(TapontA *p, Navio x, int *cresceu);//insere um navio na arvore
void pesquisa(Navio n, TapontA *raiz);//verifica se um navio esta na arvore
int vazia(TapontA *arvore);
void imprimeInOrdem(TapontA arvore);
int Altura(TapontA *arvore);

void gera_navio(Fila *f1, Fila *f2, Fila *f3, Fila *f4, Porto porto);// Ira gerar novos navios e inseri-los no final das filas
void atraca_navio(Fila *f, Atracamento *a);// ira remover um dos navios da fila para a area de atracamento para ser descarregado
void descarrega(Porto *p, int a,TapontA *raiz, Fila *f5);// descarrega o navio na grua
void esvazia_travessa_carrinho(Porto *p, int a, int t);// esvazia a travessa quando cheia
void umtempo(Porto *porto, TapontA *raiz, Fila *f1, Fila *f2, Fila *f3, Fila *f4, Fila *f5);



void rot_dir(TapontA *r);
void rot_esq (TapontA *r);
void rot_esq_dir (TapontA *r);
void rot_dir_esq(TapontA *r);


void NivelAtual(TapontA arvore, int nivel);
void InNivel(TapontA arvore);

float tempomedio(Fila f);
void tempoEspera(Fila f);



/*
O porto que possui 4 áreas de atracamento definidos pela struct 'Atracamento', para descarregar os navios (struct 'Navio') que chegam no porto.

Quando um novo navio chega no porto ele entra em uma das 4 filas definidas pela struct 'Fila', através da função 'enfileira'.

A função 'gera_navio' irá gerar a cada unidade de tempo de 0 a 3 navios que podem entrar em qualquer uma das 4 filas, preferencialmente a com o menor tempo de espera.

Será usada a função 'atraca_navio', que ira desenfileirar o primeiro navio da fila pela função 'desenfileira' e ira atracá-lo na área de atracamento correspondente.

Os navios são descarregados pela grua nas travessas do porto, enquanto o navio estiver na área de atracamento, a função 'descarrega' ira descarregar este navio em uma das travessas que estiver disponível, descarregando um contêiner por unidade de tempo.

Na struct Porto está contida as pilhas das travessas, que pode armazenar ate 5 contêineres.

A função 'esvazia_travessa_carrinho' ira descarregar uma travessa que estiver cheia, esta operação demora 2 unidades de tempo.

a função 'umtempo' ira reproduzir todas as outras funçoes que sejam possiveis uma vez

a cada momento que um navio se retirar da área de atracamento ele será inserido em uma árvore
balanceada pela função 'insere_arvore', tendo como direcionador o tempo de espera dos navios.
*/











