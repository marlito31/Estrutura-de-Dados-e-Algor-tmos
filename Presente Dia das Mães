#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *v, int n,int m)
{
    int l, r, count, chute = 0,aux = 0;
    l = 1;
    r = 1e9;
    while (l <= r)
    {
        chute = (l + r) / 2;
        count = 0;
        if (chute == 0) 
            break;
        for (int i = 0; i < n; i++)
        {
            count += v[i] / chute;
        }
        if (count >= m)
        {
            aux = chute;
            l = chute + 1;
        }
        else
        {
            r = chute - 1;
        }

    }

    return aux;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *v = malloc(n * sizeof(int));
    int count = 0;
    int maior = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    printf("%d\n", busca_binaria(v, n, m));
    return 0;
}
