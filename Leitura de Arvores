#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>



typedef struct tree_node_t
{
    struct tree_node_t *left;
    struct tree_node_t *right;
    int data;
} tree_node_t;

typedef struct queue_t
{
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
    tree_node_t *queue;
} queue_t;

void queue_initialize(queue_t **q)
{
    (*q) = malloc(sizeof(queue_t));
    (*q)->front = 0;
    (*q)->back = 3;
    (*q)->size = 0;
    (*q)->capacity = 4;
    (*q)->queue = malloc(sizeof(tree_node_t) * 4);
}

tree_node_t *queue_front(queue_t *q) {
    assert(q->front < q->capacity);
    return &q->queue[q->front];
}

size_t queue_size(queue_t *q) {
    return q->size;
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
        q->queue = realloc(q->queue, q->capacity * sizeof(tree_node_t));
    }
    q->front++;
    q->size--;
    if (q->front == q->capacity)
        q->front = 0;
}


void queue_delete(queue_t **q) {
    free((*q)->queue);
    free(*q);
    *q = NULL;
}

bool queue_empty(queue_t *q)
{
    return queue_size(q) == 0;
}

void queue_push(queue_t *q, tree_node_t data)
{
    if (q->size == q->capacity)
    {
        size_t old_capacity = q->capacity;
        q->capacity *= 2;
        q->queue = realloc(q->queue, sizeof(tree_node_t) * q->capacity);
        if (q->front > q->back)
        {
            for (size_t i = q->front; i < old_capacity; i++)
            {
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

void bfs(tree_node_t *node)
{
    queue_t *queue;
    queue_initialize(&queue);
    if (node != NULL)
    {
        queue_push(queue, *node);
    }
    while (!queue_empty(queue))
    {
        tree_node_t* u = queue_front(queue);
        printf("%d ",u->data);
        if (u->left != NULL)
        {
            queue_push(queue, *u->left);
        }
        if (u->right != NULL)
        {
            queue_push(queue, *u->right);
        }
        queue_pop(queue);
    }

    queue_delete(&queue);
}

tree_node_t *constroi(char p[], int *i)
{
    if (p[*i] == '.')
    {
        (*i)++;
        return NULL;
    }
    tree_node_t *node = malloc(sizeof(tree_node_t));
    scanf("%d", &node->data);
    (*i)++;
    node->left = constroi(p, i);
    node->right = constroi(p, i);
    (*i)++;
    return node;
}

int main()
{
    int n;
    int i = 0;
    scanf("%d", &n);
    int aux = (3 * n) + 2;
    char *p = malloc(aux * sizeof(char));
    scanf("%s", p);
    bfs(constroi(p, &i));
    printf("\n");
    return 0;
}
