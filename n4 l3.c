
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct {
	
char nome[40];
float potencia, horas;
	
}teletro;
int qnt=0;
 
 void inserir(teletro e[]){
if(qnt==MAX){
printf("\n Sistema cheio, impossivel cadastrar novo eletrodomestico!");
}
printf("\n ***** CADASTRO DE ELETRODOMESTICO *****");
printf("\n Nome do eletrodomestico: ");
fflush(stdin);
gets(e[qnt].nome);
printf("\n Potencia: ");
scanf("%f",&e[qnt].potencia);
printf("\n Tempo médio diario em atividade (por horas): ");
scanf("%f",&e[qnt].horas);

qnt++;


 }

 
 void mostrarE(teletro e[]){
int i;
for( i=0;i<qnt; i++){
printf("\n** eletrodomestico %d**",i+1);
printf("\n Nome do eletrodomestico: %s ", e[i].nome);
printf("\n Potencia: %.2f KW ",e[i].potencia);
printf("\n Tempo médio diario em atividade (por horas): %.2f hrs ",e[i].horas);
}
 }


 
void BuscarE(teletro e[], char BuscarNome[]){
   int i;
   char nome[40];
   int existe=0;
   for (i=0; i<qnt; i++){
	strcpy(nome, e[i].nome);
if(strcpm(strupr(nome), strupr(BuscarNome))==0){
printf("\n *** Eletrodomestico %d ***",i+1);
printf("\n Nome: %s",e[i].nome);
printf("\n Potencia: %.2f KW ",e[i].potencia);
printf("\n Tempo médio diario em atividade por horas: %.2f hrs ",e[i].horas);

existe=1;
break;

}
}
   if(!existe)
   printf("\n não foi possivel encontrar");

} 


void BuscarMaior(teletro e[], float valor){
int i;
int existe=0;
int cont=0;
for (i=0; i<qnt; i++){
if(valor <e[i].potencia){
printf("\n *** Eletrodomestico %d ***",i+1);
printf("\n Nome: %s",e[i].nome);
printf("\n Potencia: %.2f KW ",e[i].potencia);
printf("\n Tempo médio diario em atividade (por horas): %.2f hrs ",e[i].horas);
 existe=1;
 cont++;
 

}
}
if(existe==0){
printf("\n Nao existe superior a este valor!");
}
}


void consumo(teletro e[]){
int i;
float total=0;
float totalm, cm, cd;
for(i=0;i<qnt;i++){
total+=e[i].potencia;
total=total;
totalm= total*30;
}
printf("\n Consumo diario em Kw: %.2f",total);
printf("\n Consumo mensal em Kw: %.2f",totalm);

}



void salvarArquivoB(teletro e[]){
FILE*arq;
arq=fopen("Eletro.txt","wb");
fwrite(&e[0],sizeof(teletro),qnt,arq);
printf("\n Salvo com sucesso!");
fclose(arq);
}



void carregarArquivoB(teletro e[]){
FILE*arq;
arq=fopen("Eletro.txt","rb");
if(arq==NULL){
printf("\n Arquivo não encontrado");
return;
}
while(fread(&e[qnt],sizeof(teletro),1,arq) >0)
qnt++;
fclose(arq);
}


int menu()
{
int op;
printf("\n ***** CADASTRO DE ELETROS *****");
printf("\n 1- Cadastrar eletrodomestico\n");
printf("\n 2- Mostrar eletrodomestico\n");
printf("\n 3- Buscar pelo nome\n");
printf("\n 4- Consumo\n");
printf("\n 0- Sair\n");
scanf("%d",&op);
return op;
}



int main()
{
int op;
teletro e[MAX];
char BuscarNome[30];
float valor, total;

do{

op* menu();
switch(op){
	
	 case 1:inserir (e);
break;  

     case 2:mostrarE (e);
     	
break;
	
	 case 3: printf("\nDigite o nome para a busca:");
	         fflush(stdin);
	         gets(BuscarNome);
	         BuscarE(e,BuscarNome );
	         
	 
break;
	
	 case 4:consumo(e);
	 	
break;

     case 5: printf(" \n Buscar por eletrodomestico que consuma mais que um valor x:");
	         printf("\nDigite o valor da busca:");
			 scanf("%f",&valor);
			 BuscarMaior(e,valor);
			 
break;

    case 6: carregarArquivoB (e);
    printf("\n Os dados foram carregados!");
    
break;

   case 7: salvarArquivoB (e);
   
break;

   case 0: printf("\n sair!");
   
break;
			 	 	
}
getch();
system("cls");
}
while(op!=0);
return 0;
}
