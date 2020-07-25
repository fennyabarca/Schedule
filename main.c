// FERNANDA CAROLINA AGUILERA ABARCA
// Código Base para o Mini-Projeto Agenda de Amigos

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_CADASTRO 100

typedef struct ficha{
    char nome[40];
    char telefone[20];
    char endereco [80];
    char email [40];
    char nascimento [8];
    //int idade;
}tFicha;

int procurar(char [], struct ficha [], int);
char menu();

int main()
{   tFicha agenda[MAX_CADASTRO];
    int fichas_existentes = 0, proxima = 0, i;
    char opcao = '0', procurado[40];
    setlocale(LC_ALL, "Portuguese");

    while(opcao != '6') {
        opcao = menu();
        switch(opcao) {
            case '1': //inserir
                printf("\nEntre com um nome:");
                gets(agenda[proxima].nome);
                printf("\nEntre com um telefone:");
                gets(agenda[proxima].telefone);
                printf("\nEntre com um endereco:");
                gets(agenda[proxima].endereco);
                printf("\nEntre com um email:");
                gets(agenda[proxima].email);
                printf("\nEntre com um nascimento DD/MM/YY:");
                gets(agenda[proxima].nascimento);
                fichas_existentes++;
                proxima++;
                break;
    
            case '2': //procurar
                printf("\nEntre com o nome procurado:");
                gets(procurado);

                i = procurar(procurado, agenda, fichas_existentes);
                if(i >= 0)
                printf("\n\nOs dados de %s são %s\n", agenda[i].nome, agenda[i].telefone, agenda[i].endereco, agenda[i].email, agenda[i].nascimento);
                
                else printf("\n\nNome não encontrado\n");
                break;
   
            case '3': //listar tudo
                printf("\n\n");
                
                for(i=0; i<fichas_existentes; i++) {
                    printf("Os dados de %s são %s\n", agenda[i].nome, agenda[i].telefone, agenda[i].endereco, agenda[i].email, agenda[i].nascimento);
                }
                if(fichas_existentes == 0)
                    printf("A base de dados está vazia!\n");
                break;
                
            case '4': //excluir
                printf("\nEntre com o nome que sera excluído:");
                gets(procurado);
    
                i = procurar(procurado, agenda, fichas_existentes);
                if(i >= 0) {
                    printf("\n\nOs dados de %s, que são %s, serão removidos\n",agenda[i].nome, agenda[i].telefone, agenda[i].endereco, agenda[i].email, agenda[i].nascimento);

                    //RODA TODA A LISTA E TRANSFERE O PONTEIRO PRA CIMA
                    while (i>=0 && i<fichas_existentes ) {
                        agenda[i] = agenda[i+1];
                        i++;
                    }
                    fichas_existentes--;
                    proxima--;

                } else {
                    printf("\n\nNome não encontrado\n");
                }
                break;
                
            case '5':
                printf("\nEntre com o nome que será alterado:");
                gets(procurado);

                i = procurar(procurado, agenda, fichas_existentes);

                if(i < 0){
                    printf("\n\nNome não encontrado\n");
                } else {
                    printf("\nEntre com o nome:");
                    gets(agenda[i].nome);
                    printf("\nEntre com telefone:");
                    gets(agenda[i].telefone);
                    printf("\nEntre com endereco:");
                    gets(agenda[i].endereco);
                    printf("\nEntre com email:");
                    gets(agenda[i].email);
                    printf("\nEntre com nascimento DD/MM/YY:");
                    gets(agenda[i].nascimento);
                }
        }
    }
    return 0;
}

//Funcao para PROCURAR ignorar minusculas e MAIUSCULAS
int procurar(char procurado[], struct ficha vetor[], int num_fichas) {
    int i = 0;
    
    while (i<num_fichas) {
        if (strstr(vetor[i].nome,procurado) != NULL) {
            return i;
        }
        i++;
    }
    return -1;
}

char menu() {
    char opcao[10]="0";

    printf("\nEntre com a opção desejada:\n");
    printf("\n1) Inserir ficha:");
    printf("\n2) Procurar por nome:");
    printf("\n3) Listar toda a base:");
    printf("\n4) Excluir por nome:");
    printf("\n5) Alterar por nome:");
    printf("\n6) Sair\n\n");
    gets(opcao);
    return opcao[0];
}

/*
Reimplemente a função procurar de modo recursivo.
(particularmente não há nenhuma vantagem nesta alteração, é só para treinarmos recursividade).

FUNCAO PROCURAR RECURSIVA:
int procurarRecursivo(char procurado[], struct ficha vetor[], int inicio, int num_fichas)
{
   if(inicio >= num_fichas) return -1;
   if(strcmp(procurado, vetor[inicio].nome) == 0) return inicio;
   return procurarRecursivo(procurado, vetor, inicio+1, num_fichas);
}*/
