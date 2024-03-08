#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
 
typedef struct processos
{
    char nome[31];
    int pid;
    int time;
} processos;
 
typedef struct queue_t
{
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
    processos *queue;
} queue_t;
 
void queue_initialize(queue_t **q)
{
    (*q) = malloc(sizeof(queue_t));
    (*q)->front = 0;
    (*q)->back = 3;
    (*q)->size = 0;
    (*q)->capacity = 4;
    (*q)->queue = malloc(sizeof(processos) * 4);
}
 
void queue_push(queue_t *q, processos data) {
    if (q->size == q->capacity) {
        size_t old_capacity = q->capacity;
        q->capacity *= 2;
        q->queue = realloc(q->queue, sizeof(processos) * q->capacity);
        if (q->front > q->back) {
            for (size_t i = q->front; i < old_capacity; i++) {
                q->queue[i + old_capacity] = q->queue[i];
            }
            q->front = q->front + old_capacity;
        }
    }
    q->back++;
    if (q->back == q->capacity)
        q->back = 0;
    q->queue[q->back] = data;
    q->size++;
}
 
void queue_pop(queue_t *q) {
    assert(q->size > 0);
    if (q->size == q->capacity / 4 && q->capacity > 4) {
        size_t new_capacity = q->capacity / 2;
        if (q->front <= q->back) {
            for (size_t i = q->front, j = 0; i <= q->back; i++, j++) {
                q->queue[j] = q->queue[i];
            }
        } else {
            size_t front_len = q->capacity - q->front;
            for (int i = q->back; i >= 0; i--) {
                q->queue[i + front_len] = q->queue[i];
            }
            for (size_t i = q->front, j = 0; i < q->capacity; i++, j++) {
                q->queue[j] = q->queue[i];
            }
        }
        q->front = 0;
        q->back = q->size - 1;
        q->capacity = new_capacity;
        q->queue = realloc(q->queue, q->capacity * sizeof(processos));
    }
    q->front++;
    q->size--;
    if (q->front == q->capacity)
        q->front = 0;
}
 
processos queue_front(queue_t *q) {
    assert(q->front < q->capacity);
    return q->queue[q->front];
}
 
size_t queue_size(queue_t *q)
{
    return q->size;
}
 
bool queue_empty(queue_t *q)
{
    return queue_size(q) == 0;
}
 
int main(){
    int n,q;
    queue_t *f;
    queue_initialize(&f);
    scanf("%d %d",&n,&q);
    for (int i = 0; i < n; i++)
    {
        processos v;
        scanf("%s %d %d",v.nome,&v.pid,&v.time);
        queue_push(f,v);
        // printf("%s %d %d\n",v.nome,v.pid,v.time);
    }
    // printf("%s\n", f->queue->nome);
    processos aux;
    int temp_total=0;
    while(f->size > 0)
    {
        aux = queue_front(f);
        queue_pop(f);
        if(aux.time > q)
        {
            aux.time -= q;
            temp_total += q;
            queue_push(f,aux);
        }else{
            temp_total += aux.time;
            printf("%s %d %d ms\n",aux.nome,aux.pid,temp_total);
        }


    }
    
    return 0;
}
