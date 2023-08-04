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

void dfs(tree_node_t *l, tree_node_t *r, int *p)
{
    if (l != NULL && r == NULL)
    {
        *p = 0;
        return;
    }
    else if (l == NULL && r != NULL)
    {
        *p = 0;
        return;
    }
    else if (l == NULL && r == NULL)
        return;

    if (l->data == r->data)
    {
        dfs(l->left, r->right, p);
        dfs(l->right, r->left, p);
    }
    else
    {
        *p = 0;
        return;
    }
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
    tree_node_t * root = constroi(p, &i);
    int f = 1;
    dfs(root->left,root->right,&f);
    if(f)
        printf("SIM\n");
    else
        printf("NAO\n");
    return 0;
}
