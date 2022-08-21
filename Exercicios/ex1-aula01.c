/*
Faça um programa que receba do usuário N pares de valores, onde cada PAR representa uma aresta
bidirecional entre cada valor do par.
Mostre uma matriz de adjacência que represente esse grafo
Mostre uma lista de adjacência que represente esse grafo.
1 2
1 4
2 5
3 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Link{
    int numero;
    struct Link *prox;
} link;

typedef struct Lista{
    int numero;
    link *par;
    struct Lista *prox;
} lista;

void *aloca(size_t sz){
    void *memoria = malloc(sz);
    if(memoria == NULL){
        printf("Sem memória suficiente!");
        exit(1);
    }
    return memoria;
}

void addLink(lista *Lista, int num, int nam){
    while(Lista != NULL){
        if(Lista->numero == nam){
            link *novo = aloca(sizeof(*novo));
            novo->numero = num;
            novo->prox = Lista->par;
            Lista->par = novo;
        }
        Lista = Lista->prox;
    }
}

void addLista(lista **LISTA,lista *Lista, int num){
    while(Lista != NULL){
        if(Lista->numero == num){
            return;
        }
        Lista = Lista->prox;
    }
    lista *nova = aloca(sizeof(*nova));
    nova->numero = num;
    nova->prox = *LISTA;
    *LISTA = nova;
}

void exibe(lista *LISTA){
    printf("\n");
    while(LISTA != NULL){
        printf("Coluna: %d - Ligada com: ", LISTA->numero);

        link *LINK = LISTA->par;
        while(LINK != NULL){
            printf("%d ", LINK->numero);
            LINK = LINK->prox;
        }
        LISTA = LISTA->prox;
        printf("\n");
    }
}

int main(void){
    lista *nova = NULL;
    int n,i,j,a,b;
    printf("Digite a quantidade de pares: ");
    scanf("%d",&n);
    printf("\n");
    for (i = 1; i <= n ; i++){
        printf("Par %d\n", i);
        printf("Digite o primeiro valor: ");
        scanf("%d",&a);
        printf("Digite o segundo valor: ");
        scanf("%d",&b);
        addLista(&nova,nova,a);
        addLink(nova,b,a);
        addLista(&nova,nova,b);
        addLink(nova,a,b);
    }
    exibe(nova);
    return 0;

}