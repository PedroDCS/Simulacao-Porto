#include"TAD.c"

void main(){
	//Inicialização das estruturas
	Fila f1,f2,f3,f4,f5;
	int i,j,cont,insert;
	qtdID = 0;
	
	FFVazia(&f1);
	FFVazia(&f2);
	FFVazia(&f3);
	FFVazia(&f4);
	FFVazia(&f5);
	
	Porto p1;
	for(i=0;i<4;i++){
		FPVazia(&p1.travessa[i]);
		p1.atracamento[i].ocupada=0;
		p1.atracamento[i].grua.carro=0;
		p1.atracamento[i].grua.viagens=0;
	}
	
	TapontA raiz;
	FAVazia(&raiz);
	
	Navio n1;
	//menu
	int modulodesejado;
	char a;
	do{
		system("cls"); //limpa a tela
		printf("=====================================================================\n");
		printf("=====================================================================\n");
		printf("============================= Bem Vindo =============================\n");
		printf("==================== Qual Modulo Deseja Acessar? ====================\n");
		printf("===== 1. Gerar 1 tempo ==============================================\n");
		printf("===== 2. Gerar 10 tempos ============================================\n");
		printf("===== 3. Gerar tempos ate apertar n =================================\n");
		printf("===== 4. Exibir Fila 1 ==============================================\n");
		printf("===== 5. Exibir Fila 2 ==============================================\n");
		printf("===== 6. Exibir Fila 3 ==============================================\n");
		printf("===== 7. Exibir Fila 4 ==============================================\n");
		printf("===== 8. Exibir Fila 5 (navios que ja sairam do porto) ==============\n");
		printf("===== 9. Exibir Arvore (navios que ja sairam do porto) ==============\n");
		printf("===== 0. Sair =======================================================\n");
		printf("=====================================================================\n");
		scanf("%d",&modulodesejado);
		
		switch (modulodesejado){
			case 1:
				umtempo(&p1, &raiz, &f1,&f2,&f3,&f4,&f5);
				fflush(stdin);
				printf("Pressione para continuar");
				getchar();
			break;
			
			case 2:
				for(i=0;i<10;i++){
					umtempo(&p1, &raiz, &f1,&f2,&f3,&f4,&f5);
				}
				fflush(stdin);
				printf("\nPressione para continuar");
				getchar();
			break;
			
			case 3:
				do{
					umtempo(&p1, &raiz, &f1,&f2,&f3,&f4,&f5);
					fflush(stdin);
					printf("Pressione 'a' para parar a execucao\n");
					scanf("%c", &a);
				}while(a != 'a' && a != 'a');
				fflush(stdin);
				printf("\nPressione para continuar");
				getchar();
			break;
			
			case 4:
				printf("\nFila 1\n");
				ImprimeFila(&f1);
				fflush(stdin);
				printf("\nPressione para continuar");
				getchar();
			break;
			
			case 5:
				printf("\nFila 2\n");
				ImprimeFila(&(f2));
				fflush(stdin);
				printf("\nPressione para continuar");
				getchar();
			break;
			
			case 6:
				printf("\nFila 3\n");
				ImprimeFila(&(f3));
				fflush(stdin);
				printf("\nPressione para continuar");
				getchar();
			break;
			
			case 7:
				printf("\nFila 4\n");
				ImprimeFila(&(f4));
				fflush(stdin);
				printf("\nPressione para continuar");
				getchar();
			break;
			
			case 8:
				printf("\nFila 4\n");
				ImprimeFila(&(f5));
				fflush(stdin);
				printf("\nPressione para continuar");
				getchar();
			break;
			
			case 9:
				imprimeInOrdem(raiz);
				fflush(stdin);
				printf("\nPressione para continuar");
				getchar();
			break;			
		}
	}while(modulodesejado != 0);
	
	imprimeInOrdem(raiz);
	
	//quantidade de navios que passaram pelo porto
	int qtd = f5.tamanho;
	for(i=0;i<4;i++){
		if(p1.atracamento[i].ocupada != 0){
			qtd++;
		}
	}
	
	
	printf("\nRelatorio\n");
	printf("\tAltura da arvore: %d\n",Altura(&raiz));
	printf("\tQuantidade de navios que transitou pelo porto: %d\n",qtd);
	
	printf("\n\tO tempo medio de espera da Fila 1: %.2f\n",tempomedio(f1));
	printf("\tMaior e menor tempo de espera da fila 1\n");
	tempoEspera(f1);
	printf("\n\tO tempo medio de espera da Fila 2: %.2f\n",tempomedio(f2));
	printf("\tMaior e menor tempo de espera da fila 2\n");
	tempoEspera(f2);
	printf("\n\tO tempo medio de espera da Fila 3: %.2f\n",tempomedio(f3));
	printf("\tMaior e menor tempo de espera da fila 3\n");
	tempoEspera(f3);
	printf("\n\tO tempo medio de espera da Fila 4: %.2f\n",tempomedio(f4));
	printf("\tMaior e menor tempo de espera da fila 4\n");
	tempoEspera(f4);
	printf("\n\tO tempo medio de espera dos navios que ja sairam do porto: %.2f\n",tempomedio(f5));
	printf("\tMaior e menor tempo de espera dos navios que sairam do porto\n");
	tempoEspera(f5);
}
