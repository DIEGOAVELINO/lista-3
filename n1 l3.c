
#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct banda{
	char nome[40];
	char genero[40];
	int integrantes;
	int ranking;
}tbanda;

int qtd=0; 


int addBanda(tbanda b[]){
if(qtd==MAX)
return 0;
printf("Dados para banda\n");
printf("Nome:");
fflush(stdin); 
gets(b[qtd].nome);
printf("Genero:");
fflush(stdin); 
gets(b[qtd].genero);
printf("Integrantes:");
scanf("%d",&b[qtd].integrantes);
printf("Ranking:");
scanf("%d",&b[qtd].ranking);
qtd++;
return 1;  
}


void mostraBandas(tbanda b[]){
int i;
printf("\n ***** Bandas cadastradas *****\n");
for(i=0;i<qtd;i++){
printf("Banda %d\n",i+1);
printf("Nome:%s\n",b[i].nome);
printf("Genero:%s\n",b[i].genero);
printf("Integrantes:%d\n",b[i].integrantes);
printf("Ranking:%d\n",b[i].ranking);
	}
}

void buscaBanda(tbanda b[], char nomeBusca[40]){
int i, existe=0;
char aux[40];	
for(i=0;i<qtd;i++){
strcpy(aux,b[i].nome); 
if(strcmp( strupr(aux)   ,  strupr(nomeBusca)    )==0){ 
printf("*** Banda *** %d\n",i+1);
printf("Nome:%s\n",b[i].nome);
printf("Genero:%s\n",b[i].genero);
printf("Integrantes:%d\n",b[i].integrantes);
printf("Ranking:%d\n",b[i].ranking);
existe = 1;
	  }
	}
	if(!existe) 
	   printf("Banda nao encontrada :(\n");   
}

void buscaGenero(tbanda b[], char generoBusca[40]){
int i, existe=0;
char aux[40];	
for(i=0;i<qtd;i++){
strcpy(aux,b[i].genero);
if(strcmp( strupr(aux)   ,  strupr(generoBusca)    )==0){ 
printf("\n *** Banda *** %d\n",i+1);
printf("Nome:%s\n",b[i].nome);
printf("Genero:%s\n",b[i].genero);
printf("Integrantes:%d\n",b[i].integrantes);
printf("Ranking:%d\n",b[i].ranking);
existe = 1;
	  }
	}
	if(!existe) 
printf("Genero nao encontrado :(\n");   
}

void alteraBanda(tbanda b[], char nomeBusca[40]){
int i, existe=0;
char aux[40];	
for(i=0;i<qtd;i++){
strcpy(aux,b[i].nome); 
if(strcmp( strupr(aux)   ,  strupr(nomeBusca)    )==0){
printf("Novos dados para banda %s\n",b[i].nome);
printf("Novo nome:");
fflush(stdin); 
gets(b[i].nome);
printf("Novo genero:");
fflush(stdin); 
gets(b[i].genero);
printf("Integrantes:");
scanf("%d",&b[i].integrantes);
printf("Ranking:");
scanf("%d",&b[i].ranking);
existe = 1;
	  }
	}
	if(!existe) 
printf("Banda nao encontrada :(\n");   
}

void removerBanda(tbanda b[], char nomeBusca[40]){
int i, existe=0;
char aux[40];	
for(i=0;i<qtd;i++){
strcpy(aux,b[i].nome); 
if(strcmp( strupr(aux)   ,  strupr(nomeBusca)    )==0){ 
qtd--;
existe = 1;
	  }
	}
if(!existe)
printf("Banda nao encontrada :(\n");  
	else
printf("Banda removida com sucesso!\n");    
}

void salvarBandas(tbanda b[]){
int i;
FILE *arq;
arq = fopen("bandas.txt","w"); 
fprintf(arq,"%d\n",qtd); 
for(i=0;i<qtd;i++){
fprintf(arq,"%s\n",b[i].nome);
fprintf(arq,"%s\n",b[i].genero);
fprintf(arq,"%d\n",b[i].integrantes);
fprintf(arq,"%d\n",b[i].ranking);
	}
	printf("Dados salvos com sucesso :)\n");
	fclose(arq);
}

void carregaBandas(tbanda b[]){
FILE *arq;
int i;
arq = fopen("bandas.txt","r"); 
if(arq==NULL){
printf("Arquivo nao foi encontrado :(\n");
return;
	}
fscanf(arq,"%d",&qtd);
printf("Carregando dados");
for(i=0;i<qtd;i++){
fscanf(arq,"%s",&b[i].nome);
fscanf(arq,"%s",&b[i].genero);
fscanf(arq,"%d",&b[i].integrantes);
fscanf(arq,"%d",&b[i].ranking);
printf("...");
_sleep(500);
	}
fclose(arq);
system("cls"); 
}

int menu(){
int op;
printf("***** Sistema de Cadastro de Bandas *****\n");
printf("1- Adiciona Banda\n");
printf("2- Mostra Bandas\n");
printf("3- Busca Banda\n");
printf("4- Remove Banda\n");
printf("5- Altera Banda\n");
printf("6- Busca por Genero\n");
printf("0- Sair\n");
scanf("%d",&op);
return op;
}

int main(){
tbanda b[MAX];
char busca[40];
int op;
carregaBandas(b);
do{
op = menu();
switch(op){
	case 1: if(addBanda(b)==1)
			printf("Banda adicionada :)\n");
			 		else
			printf("Limite de bandas atingido :(\n");
break;
	case 2: mostraBandas(b);
	
break;
	case 3: printf("Nome da banda para buscar:");
			fflush(stdin); gets(busca);
			buscaBanda(b,busca);
					
break;
	case 4: printf("Nome da banda para remover:");
			fflush(stdin); gets(busca);
			removerBanda(b,busca);
					
break;

	case 5: printf("Nome da banda para alterar:");
			fflush(stdin); gets(busca);
			alteraBanda(b,busca);
			
break;	
	case 6: printf("Genero da banda para buscar:");
			fflush(stdin); gets(busca);
			buscaGenero(b,busca);
			

break;				
		
	case 0: salvarBandas(b);
			printf("Saindo... \n");
			
				break;
			default: printf("Opcao invalida\n");			 	
		}
		getch(); 
		system("cls");
	}while(op!=0);	

	return 0;
}
