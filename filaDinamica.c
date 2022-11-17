#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct t_aluno
{
	int ra,faltas;
	float nota1,nota2;
};

typedef struct No{
	t_aluno dado;
	struct No *prox;
}No;

typedef struct Fila{
	No *inicio;
	No *fim;
}Fila;

void iniciaFila( Fila *f){
	f->inicio = NULL;
	f->fim = NULL;
}

void inseriFila( t_aluno dado, Fila *f){
	No *aux = (No*) malloc(sizeof(No));
	if(aux == NULL){
		printf("Erro de alocação.\n");
		return;
	} else {
		aux->dado = dado;
		aux->prox = NULL;
		if(f->inicio == NULL){
			f->inicio = aux;
		} else {
			f->fim->prox = aux;
		}
		f->fim = aux;
		return;
	}
}

t_aluno removeElemento(Fila *f){
	No *aux = f->inicio;
	t_aluno dado;
	if(aux != NULL){
		f->inicio = aux->prox;
		aux->prox = NULL;
		dado = aux->dado;
		free(aux);
		if(f->inicio == NULL){
			f->fim = NULL;
		}
		return dado;
	} else {
		printf("\tERRO: Fila vazia");
		return dado;	
	}
}

void mostraFila(Fila *f){
	No *aux = f->inicio;
	if( aux != NULL){
		while( aux != NULL){
			printf(" RA: %d", aux->dado.ra);
			printf(" NOTA1: %d", aux->dado.nota1);
			printf(" NOTA2: %d", aux->dado.nota2);
			printf(" FALTAS: %d", aux->dado.faltas);
			printf("\n");
			aux = aux->prox;
		}
	} else {
		printf("\tERRO: Fila vazia");
		return;
	}
}


t_aluno recebe_dados() //insercao dos dados
{
	t_aluno a;
	printf ("RA    :");
	scanf ("%d",&a.ra);
	printf ("NOTA1 :");
	scanf ("%f",&a.nota1);
	printf ("NOTA2 :");
	scanf ("%f",&a.nota2);
	printf ("FALTAS:");
	scanf ("%d",&a.faltas);
	return a;
}


int main(){
	Fila *algoritimos = (Fila*) malloc(sizeof(Fila));
	iniciaFila(algoritimos);
	char tecla;
	t_aluno aluno;
	
	
	while (tecla!='S' && tecla!='s')
	{
	  printf("[I]nserir [M]ostrar [R]emover [S]air\n");
	  tecla=getch(); 
	  if (tecla=='i' || tecla=='I')     
	  {
		aluno=recebe_dados();
		inseriFila(aluno, algoritimos);		
	  } 
	  else if (tecla=='m' || tecla=='M')
	  {
	  	mostraFila(algoritimos);
	  } 
	  else if (tecla=='r' || tecla=='R')
	  {
	  	removeElemento(algoritimos);
	  }
	  
	  else if (tecla=='s' || tecla=='S')
	  {
	   printf("Saindo\n");
	  } 
	  else
	  {
		printf("Opcao invalida\n");
	  }
	}
	return 0;
}