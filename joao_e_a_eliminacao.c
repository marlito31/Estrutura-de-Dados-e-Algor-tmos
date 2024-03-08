#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct dlist_node_t
{
    char data[31];
    struct dlist_node_t *next;
    struct dlist_node_t *prev;
} dlist_node_t;

typedef struct dlist_t
{
    dlist_node_t *head; /*Cabe¸ca da Lista*/
    dlist_node_t *tail; /*Cauda da Lista*/
    size_t size;        /*tamanho da lista*/
} dlist_t;

void dlist_insert(dlist_t *l, char data[31], size_t i);
void dlist_append(dlist_t *l, char data[31]);
bool dlist_empty(dlist_t *l);
size_t dlist_size(dlist_t *l);
void dlist_remove(dlist_t *l, size_t i);
// void dlist_delete(dlist_t **l);
static void dlist_delete_node(dlist_node_t *node);
void dlist_remove_head(dlist_t *l);
void dlist_remove_tail(dlist_t *l);

static dlist_node_t *dlist_new_node(char data[31])
{
    dlist_node_t *new_node = malloc(sizeof(dlist_node_t));
    // new_node->data = data;
    strcpy(new_node->data, data);
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

/**Insere um elemento na cauda da dlista **/
void dlist_append(dlist_t *l, char data[31])
{
    dlist_node_t *new_node = dlist_new_node(data);
    if (dlist_empty(l))
    {
        l->head = new_node;
    }
    else
    {
        l->tail->next = new_node;
    }
    new_node->next = l->head;
    new_node->prev = l->tail;
    l->tail = new_node;
    l->size++;
}

/**Remove o elemento da posição i da dlista**/
void dlist_remove(dlist_t *l, size_t i)
{
    assert(!dlist_empty(l) && i < dlist_size(l));
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
    assert(!dlist_empty(l));
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
    assert(!dlist_empty(l));
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

// /**Retorna o tamanho da dlista**/
size_t dlist_size(dlist_t *l)
{
    return l->size;
}

/**Retorna verdadeiro se a dlista está vazia, e falso caso contrário**/
bool dlist_empty(dlist_t *l)
{
    return dlist_size(l) == 0 ? true : false;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    dlist_t *l;
    dlist_initialize(&l);
    for (int i = 0; i < n; i++)
    {
        char aux[31];
        scanf("%s", aux);
        dlist_append(l, aux);
    }
    x -= 1;

    for (int i = x;; i += x)
    {
        if (dlist_size(l) == 1)
            break;
        else if (i >= dlist_size(l))
        {
            while (i >= dlist_size(l))
            {
                i -= dlist_size(l);
            }
        }
        dlist_remove(l, i);
    }

    printf("%s\n",l->head->data);
    // dlist_node_t *aux, *aux1;
    // aux = l->head;
    // aux1 = aux;
    // // printf("%s\n", aux->data);
    // while (aux != NULL)
    // {
    //     printf("%s\n", aux->data);
    //     aux = aux->next;
    //     if (aux == aux1)
    //         break;
    // }

    return 0;
}
