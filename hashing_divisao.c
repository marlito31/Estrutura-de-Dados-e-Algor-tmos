#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct dlist_node_t
{
    long long data;            /*Dado*/
    struct dlist_node_t *next; /*ponteiro para o próximo elemento*/
    struct dlist_node_t *prev; /*Ponteiro para o elemento anterior*/
} dlist_node_t;

typedef struct dlist_t
{
    dlist_node_t *head; /*Cabeça da dlista*/
    dlist_node_t *tail; /*Cauda da dlista*/
    size_t size;        /*tamanho da dlista*/
} dlist_t;

void dlist_initialize(dlist_t **l);
void dlist_delete(dlist_t **l);
void dlist_insert(dlist_t *l, long long data, size_t i);
void dlist_append(dlist_t *l, long long data);
void dlist_remove(dlist_t *l, size_t i);
void dlist_remove_head(dlist_t *l);
void dlist_remove_tail(dlist_t *l);
int dlist_access(dlist_t *l, size_t i);
long long dlist_access_head(dlist_t *l);
int dlist_access_tail(dlist_t *l);
size_t dlist_size(dlist_t *l);
int isEmpty(dlist_t *l);

static dlist_node_t *dlist_new_node(long long data)
{
    dlist_node_t *new_node = malloc(sizeof(dlist_node_t));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

static void dlist_delete_node(dlist_node_t *node)
{
    free(node);
}

/**Inicializa a lista duplamente encadeada e seus membros**/
void dlist_initialize(dlist_t **l)
{
    (*l) = malloc(sizeof(dlist_t));
    (*l)->head = NULL;
    (*l)->tail = NULL;
    (*l)->size = 0;
}
/** Deleta a lista por inteiro e libera espaço em memória **/
void dlist_delete(dlist_t **l)
{
    while (!isEmpty(*l))
    {
        dlist_remove_head(*l);
    }
    free(*l);
    *l = NULL;
}




/**Insere um elemento na cauda da dlista **/
void dlist_append(dlist_t *l, long long data) {
    dlist_node_t *new_node = dlist_new_node(data);
    if (isEmpty(l)) {
        l->head = new_node;
    }else{
        l->tail->next = new_node;
    }
    new_node->prev = l->tail;
    new_node->next = l->head;
    l->tail = new_node;
    l->size++;
}

/**Remove o elemento da posição i da dlista**/
void dlist_remove(dlist_t *l, size_t i)
{
    assert(!isEmpty(l) && i < dlist_size(l));
    dlist_node_t *node;
    if (dlist_size(l) == 1 || i == 0)
    {
        dlist_remove_head(l);
    }
    else if (i == dlist_size(l) - 1)
    {
        dlist_remove_tail(l);
    }
    else
    {
        dlist_node_t *aux = l->head;
        size_t k;
        for (k = 0; k < i; k++)
        {
            aux = aux->next;
        }
        node = aux;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        dlist_delete_node(node);
        l->size--;
    }
}

void dlist_remove_head(dlist_t *l)
{
    assert(!isEmpty(l));
    dlist_node_t *node = l->head;
    l->head = l->head->next;
    if (dlist_size(l) == 1)
    {
        l->tail = NULL;
    }
    else
    {
        l->head->prev = NULL;
    }
    dlist_delete_node(node);
    l->size--;
}

void dlist_remove_tail(dlist_t *l)
{
    assert(!isEmpty(l));
    dlist_node_t *node = l->tail;
    l->tail = l->tail->prev;
    if (dlist_size(l) == 1)
    {
        l->head = NULL;
    }
    else
    {
        l->tail->next = NULL;
    }
    dlist_delete_node(node);
    l->size--;
}

int dlist_access(dlist_t *l, size_t i)
{
    assert(!isEmpty(l) && i < dlist_size(l));
    dlist_node_t *aux = l->head;
    int j;
    for (j = 0; j < i; j++)
    {
        aux = aux->next;
    }
    return (aux->data);
}

long long dlist_access_head(dlist_t *l)
{
    return (l->head->data);
}

int dlist_access_tail(dlist_t *l)
{
    assert(!isEmpty(l));
    return (l->tail->data);
}

/**Retorna o tamanho da dlista**/
size_t dlist_size(dlist_t *l)
{
    return l->size;
}

/**Retorna verdadeiro se a dlista está vazia, e falso caso contrário**/
int isEmpty(dlist_t *l) {
    return dlist_size(l) == 0 ? 1 : 0;
}

long long peek(dlist_t *l) {
    return l->head->data;
}


typedef struct t_hash
{
    long long m;
    dlist_t **v;
} t_hash;

t_hash *criar_hash(long long m)
{
    t_hash *tabela = (t_hash *)malloc(sizeof(t_hash));
    tabela->m = m;
    tabela->v = malloc(m * sizeof(dlist_t));
    for (int i = 0; i < m; i++)
    {
        dlist_initialize(&(tabela->v[i]));
    }
    return tabela;
}

void inserir_hash(t_hash *tabela, long long key)
{
    long long i = key % tabela->m;
    if (i < 0)
        i *= -1;
    dlist_append(tabela->v[i], key);
}

void printhash( t_hash* map) {
    for(int i = 0; i < map->m; i++){
        (void) printf("T[%d]->",i);
        while(!isEmpty(map->v[i])){
            (void) printf("%lld->",peek(map->v[i]));
            dlist_remove_head(map->v[i]);
        }
        (void) printf("NULL\n");
    }
}

int main()
{
    int n, m;
    long long aux;
    scanf("%d %d", &n, &m);
    t_hash *tabela = criar_hash(m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &aux);
        inserir_hash(tabela, aux);
    }

    printhash(tabela);
    return 0;
}
