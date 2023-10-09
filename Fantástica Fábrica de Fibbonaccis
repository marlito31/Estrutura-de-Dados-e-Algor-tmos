#include <stdio.h>
#include <stdlib.h>

int fibonacci(long long int *p, int n)
{
    int i;
    long long int b = 1;
    p[0] = b;
    long long int f = 1;
    p[1] = 1;
    // printf("%lld\n%lld\n",b,f);
    for ( i = 0; p[i] <= 1e18 ; i++)
    {
        p[2 + i] = b + f;
        // printf("%lld\n",p[2 + i]);
        b = f;
        f = p[i + 2];
    }
    return i;
}

int fabrica(long long int *v,long long int k,int max)
{
    int count = 0, i = max;
    while (k > 0)
    {
        if(v[i] <= k){
            k -= v[i];
            count++;
        }
        i--;
    }
    return count;
}

int main()
{
    int n;
    long long k;
    scanf("%d", &n);
    long long int *v = malloc( 100* sizeof(long long int));
    int max = fibonacci(v, n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &k);
        printf("%d\n", fabrica(v, k,max));
    }
    free(v);
    return 0;
}
