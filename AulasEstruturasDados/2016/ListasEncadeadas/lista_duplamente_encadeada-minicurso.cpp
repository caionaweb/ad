/* Fun��o : Listas duplamente encadeadas
/ Autor : Edkallenn
/ Data : 06/04/2012
/ Observa��es:
*/
#include <stdio.h>
#include <stdlib.h>
#define QL printf("\n")

//definicao
struct lista2 {
    int info;
    struct lista2* ant;
    struct lista2* prox;
};
//sin�nimo
typedef struct lista2 Lista2;

//prot�tipos
Lista2* lst2_cria(void);
Lista2* lst2_insere (Lista2* l, int v);
Lista2* lst2_busca (Lista2* l, int v);
Lista2* lst2_retira (Lista2* l, int v);
void lst2_imprime(Lista2* l);
int lst2_vazia(Lista2* l);
void lst2_libera (Lista2* l);

/* inser��o no in�cio: retorna a lista atualizada */
Lista2* lst2_insere (Lista2* l, int v){
    Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
    /* verifica se lista n�o estava vazia */
    if (l != NULL)
        l->ant = novo;
    return novo;
}

/* fun��o busca: busca um elemento na lista */
Lista2* lst2_busca (Lista2* l, int v){
    Lista2* p;
    for (p=l; p!=NULL; p=p->prox)
        if (p->info == v)
            return p;
    return NULL; /* n�o achou o elemento */
}

/* fun��o retira: remove elemento da lista */
Lista2* lst2_retira (Lista2* l, int v) {

    Lista2* p = lst2_busca(l,v);

    if (p == NULL)
        return l; /* n�o achou o elemento: retorna lista inalterada */

    /* retira elemento do encadeamento */
    if (l == p) /* testa se � o primeiro elemento */
        l = p->prox;
    else
        p->ant->prox = p->prox;

    if (p->prox != NULL) /* testa se � o �ltimo elemento */
    p->prox->ant = p->ant;

    free(p);

    return l;
}

//Funcao de Criacao - retorna uma lista vazia
Lista2* lst2_cria(void){
    return NULL;
}

//funcao imprime: imprime valores dos elementos
void lst2_imprime(Lista2* l){
    Lista2* p;   //variavel auxiliar para percorrer a lista
    for(p = l; p !=NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

//funcao vazia: retorna 1 se vazia ou 0 se nao vazia
int lst2_vazia(Lista2* l){
    return (l == NULL);
}

void lst2_libera (Lista2* l){
    Lista2* p = l;
    while(p!=NULL){
        Lista2* t = p->prox; //guarda referencia ao proximo elemento
        free(p);            //libera a memoria apontada por p
        p = t;              //faz p apontar para o proximo
    }
}
int main(void){
    Lista2* lista2;               //declara uma lista nao atualizada
    lista2 = lst2_cria();         //cria e inicializa lista como vazia
    lista2 = lst2_insere(lista2, 23);  //insere na lista o elemento 23
    lista2 = lst2_insere(lista2, 45);  //insere na lista o elemento 45
    lista2 = lst2_insere(lista2, 32);  //insere na lista o elemento 32
    lista2 = lst2_insere(lista2, 48);  //insere na lista o elemento 32

    lst2_imprime(lista2);
    QL;
    lista2 = lst2_retira(lista2, 32);
    QL;
    lst2_imprime(lista2);
    lst2_libera(lista2);
    return 0;
}

