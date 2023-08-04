#include <stdio.h>
#include <stdlib.h>

typedef struct soma{
    int indice;
    int num;
}soma;
 
static void heapify(soma *v, int i, int size) {
    int left;
    int right;
    int largest;
    while (i < size) {
        left = (i * 2) + 1;
        right = (i * 2) + 2;
        largest = i;
        if (left < size && v[left].num > v[largest].num) {
            largest = left;
        }
        if (right < size && v[right].num > v[largest].num) {
            largest = right;
        }
        if (i == largest) {
            break;
        }
        soma swp = v[i];
        v[i] = v[largest];
        v[largest] = swp;
        i = largest;
    }
}
 
static void make_heap(soma *v, int size) {
    int i;
    for (i = size / 2; i >= 0; i--) {
        heapify(v, i, size);
    }
}
 
void heap_sort(soma *v, int size) {
    int i;
    make_heap(v, size);
    for (i = size - 1; i > 0; i--) {
        soma swp = v[i];
        v[i] = v[0];
        v[0] = swp;
        heapify(v, 0, i);
    }
}
 
int busca_binaria(soma* v,int n,int chave){
    int l,r,m;
    l = 0;
    r = n-1;
    while(l<=r){
        m = (l+r)/2;
        if(chave<v[m].num){
            r = m-1;
        }
        else if(chave>v[m].num){
            l = m+1;
        }
        else{
            return m;
        }
    }
    return -1;
}
 
int main()
{
    int n;
    int c,chave,aux,count;
    scanf("%d %d", &n, &c);
    soma *h = malloc(n*sizeof(soma));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i].num);
        h[i].indice = i;

    }
    heap_sort(h,n);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d %d\n",h[i].num,h[i].indice);
    // }
    
    for (int i = 0; i < n; i++)
    {
        count = 0;
        chave = c - h[i].num;
        aux = busca_binaria(h,n,chave);
        if(i == aux){
            count = 1;
        }
        else if(aux != -1)
        {
            printf("%d %d\n",h[i].indice + 1,h[aux].indice+1);
            break;
        }else{
            count = 1;
        }
    }
    if(count){
        printf("-1\n");
    }
    return 0;
}
