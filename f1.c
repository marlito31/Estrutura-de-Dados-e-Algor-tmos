#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct pilotos
{
    char str[31];
    double t;
} pilotos;
 
static void merge(pilotos *v, pilotos *v1, pilotos *v2, int size)
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
        if (v1[j].t <= v2[k].t)
        {
            // v[i] = v1[j++];
            v[i] = v1[j];
            j++;
        }
        /* Caso contrário, insira o elemento da
         * segunda metade no vetor resultado */
        else
        {
            // v[i] = v2[k++];
            v[i] = v2[k];
            k++;
        }
    }
 
    /** Se ainda  restam elementos na primeira partição **/
    while (j < size_v1)
    {
        /* Copiamos os elementos para o vetor resultado */
        // v[i++] = v1[j++];
        v[i] = v1[j];
        j++;
        i++;
    }
    /** Se ainda  restam elementos na segunda partição **/
    while (k < size_v2)
    {
        /* Copiamos os elementos para o vetor resultado */
        // v[i++] = v2[k++];
        v[i] = v2[k];
        k++;
        i++;
        //fjhdsgfhjsdf
    }
}
 
void merge_sort(pilotos *v, int size)
{
    int mid;
    if (size > 1)
    {
        mid = size / 2;
        /* aloca espaço para os subvetores */
        pilotos *v1 = malloc(sizeof(pilotos) * mid);
        pilotos *v2 = malloc(sizeof(pilotos) * size - mid);
        /* Copia os elementos de v para os subvetores */
        int i;
        for (i = 0; i < mid; i++)
        {
            // v1[i] = v[i];
            v1[i] = v[i];
        }
        for (i = mid; i < size; i++)
        {
            // v2[i - mid] = v[i];
            v2[i-mid] = v[i];
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
 
void print(pilotos *v, int n)
{
 
    for (int i = 0; i < n; i++)
    {
        int t = v[i].t;
        int m = t / 60000;
        int r = t % 60000;
        int ss = r / 1000;
        int ms = r % 1000;
 
        printf("%d. %s - %d:%02d.%03d\n", i + 1, v[i].str, m, ss, ms);
    }
}
 
int main()
{
    int n;
    double x;
    double inp;
    char str[20];
    scanf("%d", &n);
    pilotos *v = malloc(n * sizeof(pilotos));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", v[i].str);
        double temp = 0;
        for (int j = 0; j < 3; j++)
        {
            // scanf("%s", str);
            // x = strtod(str, NULL);
            scanf("%lf", &inp);
            temp += inp * 1000;
        }
        v[i].t = temp;
    }
    merge_sort(v, n);
    print(v, n);

    free(v);

    return 0;
}
