#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct autor
{
    char nome[31];
    int publi;
    int *cit;
    int indice;
} autor;

static void merge(autor *v, autor *v1, autor *v2, int size)
{

    int size_v1 = size / 2;
    int size_v2 = size - size_v1;
    int i = 0;
    int j = 0;
    int k = 0;

    /** Enquanto não chegar ao fim da primeira
     *  e da segunda metade **/
    for (i = 0; j < size_v1 && k < size_v2; i++)
    {
        /* Se o elemento da primeira metade
         * é menor ou igual ao da segunda metade,
         * insira-o no vetor resultado
         */
        if (v1[j].indice >= v2[k].indice)
        {
            // v[i] = v1[j++];
            strcpy(v[i].nome, v1[j].nome);
            v[i].indice = v1[j].indice;
            j++;
        }
        /* Caso contrário, insira o elemento da
         * segunda metade no vetor resultado */
        else
        {
            // v[i] = v2[k++];
            strcpy(v[i].nome, v2[k].nome);
            v[i].indice = v2[k].indice;
            k++;
        }
    }

    /** Se ainda  restam elementos na primeira partição **/
    while (j < size_v1)
    {
        /* Copiamos os elementos para o vetor resultado */
        // v[i++] = v1[j++];
        strcpy(v[i].nome, v1[j].nome);
        v[i].indice = v1[j].indice;
        j++;
        i++;
    }
    /** Se ainda  restam elementos na segunda partição **/
    while (k < size_v2)
    {
        /* Copiamos os elementos para o vetor resultado */
        // v[i++] = v2[k++];
        strcpy(v[i].nome, v2[k].nome);
        v[i].indice = v2[k].indice;
        k++;
        i++;
    }
}

void merge_sort(autor *v, int size)
{
    int mid;
    if (size > 1)
    {
        mid = size / 2;
        /* aloca espaço para os subvetores */
        autor *v1 = malloc(sizeof(autor) * mid);
        autor *v2 = malloc(sizeof(autor) * size - mid);
        /* Copia os elementos de v para os subvetores */
        int i;
        for (i = 0; i < mid; i++)
        {
            // v1[i] = v[i];
            strcpy(v1[i].nome, v[i].nome);
            v1[i].indice = v[i].indice;
        }
        for (i = mid; i < size; i++)
        {
            // v2[i - mid] = v[i];
            strcpy(v2[i - mid].nome, v[i].nome);
            v2[i - mid].indice = v[i].indice;
        }
        /* Ordena recursivamente a primeira metade */
        merge_sort(v1, mid);
        /* Ordena recursivamente a segunda metade */
        merge_sort(v2, size - mid);
        /* Faz a junção das duas metades */
        merge(v, v1, v2, size);
        /* Libera o espaço alocado */
        free(v1);
        free(v2);
    }
}

static void merge1(int *v, int *v1, int *v2, int size)
{

    int size_v1 = size / 2;
    int size_v2 = size - size_v1;
    int i = 0;
    int j = 0;
    int k = 0;

    /** Enquanto não chegar ao fim da primeira
     *  e da segunda metade **/
    for (i = 0; j < size_v1 && k < size_v2; i++)
    {
        /* Se o elemento da primeira metade
         * é menor ou igual ao da segunda metade,
         * insira-o no vetor resultado
         */
        if (v1[j] >= v2[k])
        {
            v[i] = v1[j++];
        }
        /* Caso contrário, insira o elemento da
         * segunda metade no vetor resultado */
        else
        {
            v[i] = v2[k++];
        }
    }

    /** Se ainda  restam elementos na primeira partição **/
    while (j < size_v1)
    {
        /* Copiamos os elementos para o vetor resultado */
        v[i++] = v1[j++];
    }
    /** Se ainda  restam elementos na segunda partição **/
    while (k < size_v2)
    {
        /* Copiamos os elementos para o vetor resultado */
        v[i++] = v2[k++];
    }
}

void merge_sort1(int *v, int size)
{
    int mid;
    if (size > 1)
    {
        mid = size / 2;
        /* aloca espaço para os subvetores */
        int *v1 = malloc(sizeof(int) * mid);
        int *v2 = malloc(sizeof(int) * size - mid);
        /* Copia os elementos de v para os subvetores */
        int i;
        for (i = 0; i < mid; i++)
        {
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++)
        {
            v2[i - mid] = v[i];
        }
        /* Ordena recursivamente a primeira metade */
        merge_sort1(v1, mid);
        /* Ordena recursivamente a segunda metade */
        merge_sort1(v2, size - mid);
        /* Faz a junção das duas metades */
        merge1(v, v1, v2, size);
        /* Libera o espaço alocado */
        free(v1);
        free(v2);
    }
}

void swap(int i, int j, autor *v)
{
    autor aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}


void indice_h(int n, autor *v)
{
    int *h;
    for (int i = 0; i < n; i++)
    {
        v[i].indice = 0;
        h = malloc(v[i].publi * sizeof(int));
        for (int k = 0; k < v[i].publi; k++)
        {
            h[k] = v[i].cit[k];
        }
        merge_sort1(h, v[i].publi);
        for (int k = 0; k < v[i].publi; k++)
        {
            v[i].cit[k] = h[k];
        }
        for (int j = 0; j < v[i].publi; j++)
        {
            if (v[i].cit[j] >= j + 1)
            {
                v[i].indice = j + 1;
            }
        }
        free(h);
        free(v[i].cit);
    }
    merge_sort(v, n);
    int swapped = 1;
    for (int i = 0; i < n - 1 && swapped; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j].indice == v[j+1].indice)
            {
                if (strcmp(v[j].nome, v[j+1].nome) > 0)
                {
                    swap(j, j+1, v);
                    swapped = 1;
                }
                // else if(strcmp(v[i].nome, v[i + 1].nome) < 0)
                // {
                //     swap(i+1, i, v);
                //     swapped = 1;
                // }
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    autor *v = malloc(n * sizeof(autor));
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", v[i].nome, &v[i].publi);

        v[i].cit = malloc(v[i].publi * sizeof(int));

        for (int j = 0; j < v[i].publi; j++)
        {
            scanf("%d", &v[i].cit[j]);
        }
    }

    indice_h(n, v);

    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", v[i].nome, v[i].indice);
    }
    free(v);
    return 0;
}
