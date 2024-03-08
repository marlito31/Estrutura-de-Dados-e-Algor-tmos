#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int number;
    int index;
} num;

typedef struct
{
    num *v;          // vetor din^amico
    size_t capacity; // capacidade do vetor din~amico
    size_t size;     // tamanho do vetor din^amico
} dynamic_array_t;

void dynamic_array_initialize(dynamic_array_t **arr)
{
    /*** Utilizamos uma capacidade de 4 por padrão na criação
     * do vetor dinâmico
     */
    (*arr) = malloc(sizeof(dynamic_array_t));
    (*arr)->capacity = 4;
    (*arr)->size = 0;
    (*arr)->v = malloc(sizeof(num) * 4);
}

void dynamic_array_double_capacity(dynamic_array_t *arr)
{
    arr->capacity *= 2;
    arr->v = realloc(arr->v, sizeof(num) * arr->capacity);
}

void dynamic_array_halve_capacity(dynamic_array_t *arr)
{
    arr->capacity /= 2;
    arr->v = realloc(arr->v, sizeof(num) * arr->capacity);
}

void dynamic_array_push_back(dynamic_array_t *arr, num x)
{
    /*** o tamanho do vetor dinâmico seja igual a sua capaciade,
     * duplicamos a capacidade e realocamos o tamanho do vetor.
     ***/
    if (arr->size == arr->capacity)
    {
        dynamic_array_double_capacity(arr);
    }
    /***
     * O elemento é inserido ao final.
     */
    arr->v[arr->size] = x;
    arr->size++;
}

void dynamic_array_pop_back(dynamic_array_t *arr)
{
    /*** Removemos o último elemento do vetor. Para isto só é necessário
     * decrementar o seu tamanho.
     * Caso o tamanho atual esteja à 1/4 da capacidade máxima do vetor,
     * o vetor é redimensionado para metade do seu tamanho.
     * Nunca redimensionamos a capacidade  para abaixo de 4.
     */
    if (arr->size == arr->capacity / 4 && arr->capacity > 4)
    {
        dynamic_array_halve_capacity(arr);
    }
    arr->size--;
}

void dynamic_array_delete(dynamic_array_t **arr)
{
    /***
     * Para deletar completamente o vetor dinãmico, basta remover
     * a área apontada por v e a área apontada pelo próprio vetor dinâmico
     */
    free((*arr)->v);
    free(*arr);
    *arr = NULL;
}

num dynamic_array_back(dynamic_array_t *arr)
{
    return arr->v[arr->size - 1];
}

num dynamic_array_front(dynamic_array_t *arr)
{
    return arr->v[0];
}

size_t dynamic_array_size(dynamic_array_t *arr)
{
    return arr->size;
}

size_t dynamic_array_capacity(dynamic_array_t *arr)
{
    return arr->capacity;
}

int main()
{
    int n;
    scanf("%d", &n);
    dynamic_array_t *v;
    dynamic_array_initialize(&v);
    num aux;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &aux.number);
        aux.index = i;
        
        while (v->size > 0 && v->v[v->size - 1].number >= aux.number)
        {
            dynamic_array_pop_back(v);
        }
        
        if(v->v[v->size - 1].number < aux.number && v->size > 0){
            printf("%d ",v->v[v->size - 1].index);
        }else{
            printf("0 ");
        }
        
        dynamic_array_push_back(v,aux);
    }
    printf("\n");
    return 0;
}
