/*
Exercício aula 02 - 26/08/2022

Link da questão https://www.hackerearth.com/pt-br/problem/algorithm/connected-components-in-a-graph/

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Link{
    int numero;
    struct Link *prox;
} link;

typedef struct Lista{
    int visited;
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
            link *LINK = Lista->par;
            int f = 0;
            while(LINK != NULL){
                if(LINK->numero == num){
                    f++;
                }
                LINK = LINK->prox;
            }
            if(f == 0){
                link *novo = aloca(sizeof(*novo));
                novo->numero = num;
                novo->prox = Lista->par;
                Lista->par = novo;
            } else {
                return;
            }
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

void procura(int numeroPesquisa, lista *Lista){
    lista *listaAux = Lista;
    if (listaAux->visited == 1){
        return;
    } else {
        // printf("entrou");
        Lista->visited = 1;
        while(listaAux != NULL){
            if(listaAux->numero == numeroPesquisa){
                while(listaAux->par != NULL){
                    procura(listaAux->par->numero, Lista);
                    listaAux->par = listaAux->par->prox;
                }
            }
            listaAux = listaAux->prox;
        }
    }
}

void contaLinks(lista *LISTA){
    int cont = 0;
    while(LISTA != NULL){
        link *Link = LISTA->par;
        // printf("\n Num Lista: %d Visited: %d", LISTA->numero, LISTA->visited);
        while(Link != NULL){
            procura(Link->numero, LISTA);
            // printf("\n Num Link: %d", Link->numero);
            Link = Link->prox;
        }
        if(LISTA->visited == 0){
            // printf("entrou");
            cont++;
        }
        LISTA = LISTA->prox;
    }
    printf("\nQuantidade de componentes conectados no grafo: %i\n", cont);
}

int main(void){
    lista *nova = NULL;
    int n,i,j,a,b;
    int contador;
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
    contaLinks(nova);

    return 0;

}