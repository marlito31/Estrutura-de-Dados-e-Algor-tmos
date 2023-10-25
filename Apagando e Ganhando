#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char *v;         // vetor din^amico
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
    (*arr)->v = malloc(sizeof(char) * 4);
}

void dynamic_array_double_capacity(dynamic_array_t *arr)
{
    arr->capacity *= 2;
    arr->v = realloc(arr->v, sizeof(char) * arr->capacity);
}

void dynamic_array_halve_capacity(dynamic_array_t *arr)
{
    arr->capacity /= 2;
    arr->v = realloc(arr->v, sizeof(char) * arr->capacity);
}

void dynamic_array_push_back(dynamic_array_t *arr, char x)
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

int dynamic_array_back(dynamic_array_t *arr)
{
    return arr->v[arr->size - 1];
}

int dynamic_array_front(dynamic_array_t *arr)
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
    int n = 1, d = 1;

    dynamic_array_t *v;
    while (n != 0)
    {
        scanf("%d %d", &n, &d);
        if (n == 0)
            break;

        dynamic_array_initialize(&v);

        char aux;
        int x = d;

        getchar();
        for (int i = 0; i < n; i++)
        {
            scanf("%c", &aux);

            while(v->size > 0 && (dynamic_array_back(v)) < aux && d > 0)
            {
                dynamic_array_pop_back(v);
                d--;
            }

            dynamic_array_push_back(v, aux);

        }

        for (int i = 0; i < n - x; i++)
        {
            printf("%c", v->v[i]);
        }
        printf("\n");
        dynamic_array_delete(&v);
        
    }

    return 0;
}
