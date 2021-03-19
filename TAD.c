#include"TAD.h"
#include<time.h>
int qtdID;
void FFVazia(Fila *f){ // inicia a fila vazia
	f->frente = NULL;
	f->atras = NULL;
	//f->frente->navio.existe = 0;
	f->tamanho =0;
}

int FVazia(Fila f){//verifica se fila esta vazia
	return (f.frente == NULL && f.atras == NULL);
}

void enfileira(Navio n, Fila *f){//Enfilera o navio na ultima posição
	if(FVazia(*f)){
		f->atras = (TapontF) malloc(sizeof(Fcelula));
		f->frente = f->atras;
		f->atras->prox = NULL;
		f->atras->navio = n;
		(*f).tamanho++;
	}else{
		f->atras->prox = (TapontF) malloc(sizeof(Fcelula));
		f->atras = f->atras->prox;
		f->atras->navio = n;
		f->atras->prox = NULL;
		(*f).tamanho++;
	}
	//(*f).tamanho++;
	//printf("\n\tTamanho %d----------------\n",f->tamanho);
	//f->atras->prox->navio.existe = 0;
}

void desenfilera(Navio *n, Fila *f){// Desenfilera o navio da primeira posição
	TapontF q;
	
	if(FVazia((*f))){
		printf("Erro fila esta vazia\n" );
		return;
	}
	q = f->frente;
	(*n) = f->frente->navio;
	f->frente = f->frente->prox;
	free(q);
	f->tamanho--;
	if(f->tamanho == 0){
		FFVazia(&(*f));
	}
	
	
	
//	printf ("Navio ID: %d\n", n->ID);
//	printf("asasas\n");
//	system("pause");
}

int tamanhoFila(Fila *f){//verifica o tamanho da fila
	/*
	int tamanho =0;
	if(FVazia((*f))){
		return 0;
	}
	TapontF aux;
	aux = f->frente;
	while(aux->prox != NULL){
		tamanho++;
		aux = aux->prox;
	};
	return tamanho;
	*/
	return f->tamanho;
}

void ImprimeFila(Fila *fila){
	TapontF Aux;
	int i, cont=0;
	Aux = fila->frente;
	
	while(Aux != NULL){
		printf ("Navio ID: %d\n", Aux->navio.ID);
		cont=0;
		for(i=0;i<4;i++){
			cont += Aux->navio.pilha[i].tamanho;
		}
		printf("Conteiners: %d\n",cont);
		printf("Tempo Na Fila: %d\n\n",Aux->navio.tempo_espera);
		Aux = Aux->prox;
	}
}


void FPVazia(Pilha *p){//inicia a pilha vazia
	p->topo = NULL;
	p->fundo = NULL;
	p->tamanho = 0;
}

int PVazia(Pilha p){
	return(p.topo == NULL && p.fundo == NULL);
}

void empilha(int conteiner, Pilha *p){//empilha um conteiner
	
	if(PVazia(*p)){
		p->topo = (TapontP) malloc(sizeof(Pcelula));
		p->fundo = p->topo;
		p->topo->prox = NULL;
		p->topo->conteiner = 1;
		p->tamanho++;
	}else{
		p->topo->prox = (TapontP) malloc(sizeof(Pcelula));
		p->topo = p->topo->prox;
		p->topo->conteiner = 1;
		p->topo->prox = NULL;
		p->tamanho++;
	}
}

void desempilha(Pilha *p){//desempilha um conteiner
	TapontP q;
	if(PVazia(*p)){
		printf("Erro : Pilha vazia\n");
		return;
	}
	q = p->fundo;
	while(q->prox != NULL){
		q = q->prox;
	}
	if(q->prox == NULL){
		q = NULL;
		p->tamanho--;
	}
}



void FAVazia(TapontA *raiz){//inicia a arvore vazia
	*raiz = NULL;
}

void pesquisa(Navio x, TapontA *p){//verifica se um navio esta na arvore
	TapontA aux = *p;
	if (*p == NULL){
		printf("Registro não presente na arvore");
		return;
	}
	while(*p != NULL && (*p)->navio.ID != x.ID){
		if(x.ID < (*p)->navio.ID){
			aux = (*p)->esq;
		
		}else{
			aux = (*p)->dir;
		
		}
	}

}


int vazia(TapontA *arvore){
	if(*arvore == NULL)
		return 1;
	else
		return 0;
}

void imprimeInOrdem(TapontA arvore){
    if(vazia(&arvore) == 1){
        return;
    }else{
    	imprimeInOrdem(arvore->esq);
	    printf("ID: %d\n",arvore->navio.ID);
		printf("Tempo de Espera: %d\n",arvore->navio.tempo_espera);
	    imprimeInOrdem(arvore->dir);
	}
}

void imprimePreOrdem(TapontA arvore){
	if(vazia(&arvore) == 1){
        return;
    }else{
	    printf("ID: %d\n",arvore->navio.ID);
		printf("Tempo de Espera: %d\n",arvore->navio.tempo_espera);
		imprimePreOrdem(arvore->esq);
	    imprimePreOrdem(arvore->dir);
	}
}

void imprimePosOrdem(TapontA arvore){
	if(vazia(&arvore) == 1){
        return;
    }else{
		imprimePosOrdem(arvore->esq);
	    imprimePosOrdem(arvore->dir);
	    printf("ID: %d\n",arvore->navio.ID);
		printf("Tempo de Espera: %d\n",arvore->navio.tempo_espera);
	}
}

int Altura(TapontA *arvore){//verifica a altura da arvore
    if (arvore == NULL)
        return 0;
    if (*arvore == NULL)
    	return 0;
    int alt_esquerda = Altura(&((*arvore)->esq));
    int alt_direita = Altura(&((*arvore)->dir));    
    if (alt_esquerda > alt_direita)
        return (alt_esquerda + 1);
    else
        return(alt_direita + 1);
}






void rot_dir(TapontA *r) {
	TapontA b=*r;
	TapontA a= b->esq;
	b->esq = a->dir;
	a->dir=b;
	a->fb=0;
	b->fb=0;
	*r=a;
}

void rot_esq (TapontA *r) {
	TapontA a=*r;
	TapontA b=a->dir;
	a->dir=b->esq;
	b->esq=a;
	a->fb=0;
	b->fb=0;
	*r=b;
}

void rot_esq_dir (TapontA *r) {
	TapontA c=*r;
	TapontA a=c->esq;
	TapontA b=a->dir;
	c->esq=b->dir;
	a->dir=b->esq;
	b->esq=a;
	b->dir=c;
	switch (b->fb) {
		case -1:
			a->fb=0;
			c->fb=1;
		break;
		case 0:
			a->fb=0;
			c->fb=0;
		break;
		case 1:
			a->fb= -1;
			c->fb=0;
		break;
	}
	b->fb=0;
	*r=b;
}

void rot_dir_esq(TapontA *r) {
	TapontA a=*r;
	TapontA c=a->dir;
	TapontA b=c->esq;
	c->esq=b->dir;
	a->dir=b->esq;
	b->esq=a;
	b->dir=c;
	switch (b->fb){
		case -1:
			a->fb=0;
			c->fb=1;
		break;
		case 0:
			a->fb=0;
			c->fb=0;
		break;
		case 1:
			a->fb= -1;
			c->fb=0;
		break;
	}
	b->fb=0;
	*r=b;
}

int insere_AVL(TapontA *p, Navio x, int *cresceu) {
	int um = 1, zero =0;
	if ((*p)==NULL) {
		(*p) = (TapontA) malloc(sizeof(No));
		if ((*p) == NULL)
			return 0; // falha na inserção: não há espaço
		else {
			(*p)->navio = x;
			(*p)->fb =0;
			(*p)->esq = NULL;
			(*p)->dir = NULL;
			cresceu= &um;
			return 1; // inserção com sucesso
		}
		
	}
	else if (x.tempo_espera < (*p)->navio.tempo_espera) {
		if (insere_AVL(&(*p)->esq,x,cresceu)) {
			if (cresceu) { // inseriu esq: verificar balanceamento
				switch ((*p)->fb) {
					case -1: // BAL(p) = -2
						if ((*p)->esq->fb== -1) // sinais iguais – pendem para mesmo lado
							rot_dir(p); // p retorna balanceado
						// sinais trocados: rotação dupla
						else
							rot_dir_esq(p); // p retorna balanceado
						cresceu=&zero; //interrompe propagação
					break;
					case 0:
						(*p)->fb= -1; // ficou maior à esq.
						cresceu=&um; // propaga verificação
					break;
					case 1: // era maior à direita
						(*p)->fb=0; // balanceou com ins. esq
						cresceu=&zero; //interrompe propagação
					break;
				}
			}
			TapontA aux2 = (*p);
			if(aux2){
		        while(aux2){
		            aux2->fb = Altura(&aux2->dir) - Altura(&aux2->esq);
		            if(aux2->fb > 1 || aux2->fb < -1){
		                if((*p)->fb < -1){
					        if((*p)->esq->fb > 0){
					            rot_esq(&(*p)->esq);
					        }
					        rot_dir(&(*p));
					    }
					    else if((*p)->fb > 1){
					        if((*p)->dir->fb < 0){
					            rot_dir(&(*p)->dir);
					        }
					        rot_esq(&(*p));
					    }
		            }
		            aux2 = aux2->dir;
		        }
		    }
		return 1;
		}
	else return 0; 
	}
	else {
		if (insere_AVL(&(*p)->dir,x,cresceu)) {
			if (cresceu) { // inseriu à dir: verificar balanceamento}
				switch ((*p)->fb) {
					case -1: // era mais alto à esq.
						(*p)->fb=0; ; // balanceou com ins. dir
						cresceu=&zero; //interrompe propagação
					break;
					case 0: ; // direita fica maior
						(*p)->fb=1;
						cresceu=&um; // propaga verificação
					break;
					case 1: // BAL(p) = 2
						if ((*p)->dir->fb==1) // sinais iguais – pendem para mesmo lado
							rot_esq(p); // p retorna balanceado
						// sinais trocados: rotação dupla
						else
							rot_dir_esq(p); // p retorna balanceado
						cresceu=&zero; //interrompe propagação
					break;
				}
			}
			TapontA aux2 = (*p);
			if(aux2){
		        while(aux2){
		            aux2->fb = Altura(&aux2->dir) - Altura(&aux2->esq);
		            if(aux2->fb > 1 || aux2->fb < -1){
		                if((*p)->fb < -1){
					        if((*p)->esq->fb > 0){
					            rot_esq(&(*p)->esq);
					        }
					        rot_dir(&(*p));
					    }
					    else if((*p)->fb > 1){
					        if((*p)->dir->fb < 0){
					            rot_dir(&(*p)->dir);
					        }
					        rot_esq(&(*p));
					    }
		            }
		            aux2 = aux2->dir;
		        }
		    }
			
			
			if((*p)->fb < -1){
		        if((*p)->esq->fb > 0){
		            rot_esq(&(*p)->esq);
		        }
		        rot_dir(&(*p));
		    }
		    else if((*p)->fb > 1){
		        if((*p)->dir->fb < 0){
		            rot_dir(&(*p)->dir);
		        }
		        rot_esq(&(*p));
		    }
			return 1;
		}
		else return 0;
	}
}

void NivelAtual(TapontA arvore, int nivel){
	if(arvore != NULL){
		if(nivel == 1)
			printf("|%d|",arvore->navio.tempo_espera);
		else if(nivel > 1){
			NivelAtual(arvore->esq, nivel-1);
			NivelAtual(arvore->dir, nivel-1);
		}
	}
}

void InNivel(TapontA arvore){
	
	int altura = Altura(&arvore);
	int i;
	for(i = 1; i <= altura; i++){
		NivelAtual(arvore, i);
		printf("\n");
	}
}






void gera_navio(Fila *f1, Fila *f2, Fila *f3, Fila *f4, Porto porto){// Ira gerar novos navios e inseri-los no final das filas
	srand(time(NULL));
	
	int i, qtd,j,cont,t1,t2,t3,t4;
	qtd = rand()%4+1;//Quantidade de navios gerada
	Navio n1[qtd];
	printf("Quantidade de navios que chegaram: %d\n\n", qtd);
	for(i=0; i<qtd; i++){
		n1[i].ID = qtdID;
		n1[i].tempo_espera=0;
		n1[i].existe = 1;
		
		
		for(j=0;j<4;j++){
			FPVazia(&n1[i].pilha[j]);//inicia as pilhas dos navios
		}
		cont = rand()%13+4;//Quantidade de conteiners geradas por navio
		n1[i].conteiners = cont;
		j=0;
		do{
			empilha(1, &n1[i].pilha[j]);
			j++;
			if(j>3)
				j=0;
			cont--;
		}while(cont >0);
		
		
		t1 = f1->tamanho;
		t2 = f2->tamanho;
		t3 = f3->tamanho;
		t4 = f4->tamanho;
		
		//verifica se ja tem algum navio atracado
		if(porto.atracamento[0].ocupada ==1){
			t1++;	
		}
		if(porto.atracamento[1].ocupada ==1){
			t2++;	
		}
		if(porto.atracamento[2].ocupada ==1){
			t3++;	
		}
		if(porto.atracamento[3].ocupada ==1){
			t4++;	
		}
		
		//joga o navio em uma das filas
		if(t1<= t2 && t1 <= t3 && t1 <=t4){
			enfileira(n1[i],&(*f1));
			//(*f1).tamanho++;
		}else if(t2 < t1 && t2 <=t3 && t2 <=t4){
			enfileira(n1[i],&(*f2));
			//(*f2).tamanho++;
		}else if(t3 <t1 && t3 <t2 && t3 <= t4){
			enfileira(n1[i],&(*f3));
			//(*f3).tamanho++;
		}else{
			enfileira(n1[i],&(*f4));
			//(*f4).tamanho++;
		}
		qtdID++;
	}
} 


void atraca_navio(Fila *f, Atracamento *a){// ira remover um dos navios da fila para a area de atracamento para ser descarregado
	Navio n;
	desenfilera(&n, &(*f));

	a->navio_atual = n;
	a->ocupada = 1;
}

void descarrega(Porto *p,int a, TapontA *raiz, Fila *f5){// descarrega o navio na grua
	int i,emp = 0;
	
	//verifica se a pilha 0 do navio tem conteiners
	if(p->atracamento[a].navio_atual.pilha[0].tamanho>0){
		i=0;
		//verifica qual area de atracamento esta vazia
		while(i<4){
			if(p->atracamento[i].grua.carro ==0 && p->travessa[i].tamanho <5){
				desempilha(&(p->atracamento[a].navio_atual.pilha[0]));
				empilha(1,&p->travessa[i]);
				i=4;
			}
			i++;
		}
	}
	//verifica se a pilha 1 do navio tem conteiners
	else if(p->atracamento[a].navio_atual.pilha[1].tamanho>0){
		i=0;
		//verifica qual area de atracamento esta vazia
		while(i<4){
			if(p->atracamento[i].grua.carro ==0 && p->travessa[i].tamanho <5){
				desempilha(&(p->atracamento[a].navio_atual.pilha[1]));
				empilha(1,&p->travessa[i]);
				i=4;
			}
			i++;
		}
	}
	//verifica se a pilha 2 do navio tem conteiners
	else if(p->atracamento[a].navio_atual.pilha[2].tamanho>0){
		i=0;
		//verifica qual area de atracamento esta vazia
		while(i<4){
			if(p->atracamento[i].grua.carro ==0 && p->travessa[i].tamanho <5){
				desempilha(&(p->atracamento[a].navio_atual.pilha[2]));
				empilha(1,&p->travessa[i]);
				i=4;
			}
			i++;
		}
	}
	//verifica se a pilha 3 do navio tem conteiners
	else if(p->atracamento[a].navio_atual.pilha[3].tamanho>0){
		i=0;
		//verifica qual area de atracamento esta vazia
		while(i<4){
			if(p->atracamento[i].grua.carro ==0 && p->travessa[i].tamanho <5){
				desempilha(&(p->atracamento[a].navio_atual.pilha[3]));
				empilha(1,&p->travessa[i]);
				i=4;
			}
			i++;
		}
	}	
	//caso o navio ja esteja vazio, ira armazena-lo na fila que dara origem a arvore
	if(p->atracamento[a].navio_atual.pilha[3].tamanho==0){
		p->atracamento[a].ocupada=0;
		insere_AVL(&(*raiz), p->atracamento[a].navio_atual, 0);
		//insere_arvore(p->atracamento[a].navio_atual,&(*raiz));
		enfileira(p->atracamento[a].navio_atual,&(*f5));
		//insere_arvore(p->atracamento[a].navio_atual, &(*f));
	}
}

void esvazia_travessa_carrinho(Porto *p, int a, int t){// esvazia a travessa quando cheia
	p->atracamento[a].grua.carro = 3;
	while(p->travessa[t].tamanho >0){
		desempilha(&p->travessa[t]);
	}
}

int tempo=0;
void umtempo(Porto *porto, TapontA *raiz, Fila *f1, Fila *f2, Fila *f3, Fila *f4, Fila *f5){
	int i,j;
	
	tempo++;
	printf("\tTempo: %d\n",tempo);
	
	gera_navio(&(*f1),&(*f2),&(*f3),&(*f4), (*porto));
	//se a area de atracamento estiver ocupada, vai esvaziar, caso contrario vai atracar um navio
	if(porto->atracamento[0].ocupada == 1){
		descarrega(&(*porto),0,&(*raiz), &(*f5));
	}
	if(porto->atracamento[0].ocupada == 0){
		if(!FVazia(*f1)){
			atraca_navio(&(*f1), &(porto->atracamento[0]));
		}
	}
	
	//se a area de atracamento estiver ocupada, vai esvaziar, caso contrario vai atracar um navio
	if(porto->atracamento[1].ocupada == 1){
		descarrega(&(*porto),1,&(*raiz),&(*f5));
	}
	if(porto->atracamento[1].ocupada == 0){
		if(!FVazia(*f2)){
			atraca_navio(&(*f2), &porto->atracamento[1]);
		}
	}
	
	//se a area de atracamento estiver ocupada, vai esvaziar, caso contrario vai atracar um navio
	if(porto->atracamento[2].ocupada == 1){
		descarrega(&(*porto),2,&(*raiz),&(*f5));
	}
	if(porto->atracamento[2].ocupada == 0){
		if(!FVazia(*f3)){
			atraca_navio(&(*f3), &porto->atracamento[2]);
		}
	}
	
	//se a area de atracamento estiver ocupada, vai esvaziar, caso contrario vai atracar um navio
	if(porto->atracamento[3].ocupada == 1){
		descarrega(&(*porto),3,&(*raiz),&(*f5));
	}
	if(porto->atracamento[3].ocupada == 0){
		if(!FVazia(*f4)){
			atraca_navio(&(*f4), &porto->atracamento[3]);
		}
	}
	
	
	
	int cont;
	for(i=0;i<4;i++){//Mostra a situação das areas de atracamento
		if(porto->atracamento[i].navio_atual.existe ==1){
			printf("\tArea de atracamento %d\n",i+1);
			printf("\tNavio ID: %d\n",porto->atracamento[i].navio_atual.ID);
			cont = 0;
			for(j=0;j<4;j++){
				cont += porto->atracamento[i].navio_atual.pilha[j].tamanho;
			}
			printf("\tConteiners restantes no navio: %d\n", cont);
			printf("\n");
		}
	}
	printf("\n");
	for(i=0;i<4;i++){//mostra a situação das travessas
		printf("\tTravessa %d, conteiners: %d\n",i+1,porto->travessa[i].tamanho);
	}
	
	
	
	
	
	for(i=0;i<4;i++){//verificação responsavel por esvaziar o carrinho
		if(porto->travessa[i].tamanho>=5){
			j=0;
			while(j<5){
				if(porto->atracamento[j].grua.carro == 0){
					porto->atracamento[j].grua.viagens++;
					esvazia_travessa_carrinho(&(*porto),j,i);
					j=5;
				}
			j++;
			}
		}
	}
	
	
	for(i=0;i<4;i++){//mostra a situação dos carros
		if(porto->atracamento[i].grua.carro > 0){
			printf("Carro %d ocupado\t",i+1);
		}else{
			printf("Carro %d livre\t",i+1);
		}
		printf("Viagens %d\n",porto->atracamento[i].grua.viagens);
	}
	
	for(i=0;i<4;i++){//cuida do tempo em que os carros ficam indisponiveis
		if(porto->atracamento[i].grua.carro >0){
			porto->atracamento[i].grua.carro--;
		}
	}
	

	printf("\nFila 1\n");
	ImprimeFila(&(*f1));
	printf("\nFila 2\n");
	ImprimeFila(&(*f2));
	printf("\nFila 3\n");
	ImprimeFila(&(*f3));
	printf("\nFila 4\n");
	ImprimeFila(&(*f4));
	
	
	//Atualiza o tempo de espera dos navios em cada fila
	TapontF Aux;
	Aux = f1->frente;
	while(Aux != NULL){
		Aux->navio.tempo_espera++;
		Aux = Aux->prox;
	}
	Aux = f2->frente;
	while(Aux != NULL){
		Aux->navio.tempo_espera++;
		Aux = Aux->prox;
	}
	Aux = f3->frente;
	while(Aux != NULL){
		Aux->navio.tempo_espera++;
		Aux = Aux->prox;
	}
	Aux = f4->frente;
	while(Aux != NULL){
		Aux->navio.tempo_espera++;
		Aux = Aux->prox;
	}
}



float tempomedio(Fila f){
//tempo medio de espera
	float temp=0;
	TapontF Aux = f.frente;
	while(Aux!= NULL){
		temp = temp + Aux->navio.tempo_espera;
		Aux = Aux->prox;
	}
	temp = temp/f.tamanho;
	return temp;
}

void tempoEspera(Fila f){
	if(f.tamanho>1){//verificacao do maior e menor tempo de espera
		int tempMaior=0,tempMenor=999999;
		TapontF Aux = f.frente;
		TapontF aux2,aux3;
		while(Aux != NULL){
			if(Aux->navio.tempo_espera<tempMenor){
				aux2 = Aux;
				tempMenor = aux2->navio.tempo_espera;
			}
			if(Aux->navio.tempo_espera>tempMaior){
				aux3 = Aux;
				tempMaior = aux3->navio.tempo_espera;
			}
			Aux = Aux->prox;
		}
		printf("\t\tMaior Tempo de espera, ID: %d, tempo %d\n",aux3->navio.ID,aux3->navio.tempo_espera);
		printf("\t\tMenor Tempo de espera, ID: %d, tempo %d\n",aux2->navio.ID,aux2->navio.tempo_espera);
	}
}


