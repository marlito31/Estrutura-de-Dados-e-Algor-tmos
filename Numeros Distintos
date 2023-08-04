#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void heapify(int *v, int i, int size) {
    int left;
    int right;
    int largest;
    while (i < size) {
        left = (i * 2) + 1;
        right = (i * 2) + 2;
        largest = i;
        if (left < size && v[left] > v[largest]) {
            largest = left;
        }
        if (right < size && v[right] > v[largest]) {
            largest = right;
        }
        if (i == largest) {
            break;
        }
        int swp = v[i];
        v[i] = v[largest];
        v[largest] = swp;
        i = largest;
    }
}

static void make_heap(int *v, int size) {
    int i;
    for (i = size / 2; i >= 0; i--) {
        heapify(v, i, size);
    }
}

void heap_sort(int *v, int size) {
    int i;
    make_heap(v, size);
    for (i = size - 1; i > 0; i--) {
        int swp = v[i];
        v[i] = v[0];
        v[0] = swp;
        heapify(v, 0, i);
    }
}

int counter(int *v,int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] != v[i+1]){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    int* v = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&v[i]);
    }
    heap_sort(v,n);
    printf("%d\n",counter(v,n));
    return 0;
}
