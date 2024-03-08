#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
    char *str;
    int len;
} string;

static void merge(string *v, string *v1, string *v2, int size)
{
    int size_v1 = size / 2;
    int size_v2 = size - size_v1;
    int i = 0; 
    int j = 0;
    int k = 0;
    for (i = 0; j < size_v1 && k < size_v2; i++)
    {
        if (v1[j].len <= v2[k].len)
        {
            strcpy(v[i].str, v1[j].str);
            v[i].len = v1[j].len;
            j++;
        }
        else
        {
            strcpy(v[i].str, v2[k].str);
            v[i].len = v2[k].len;
            k++;          
        }
    }
    while (j < size_v1)
    {
        strcpy(v[i].str, v1[j].str);
        v[i].len = v1[j].len;
        i++;
        j++;
    }
    while (k < size_v2)
    {
        strcpy(v[i].str, v2[k].str);
        v[i].len = v2[k].len;
        i++;
        k++;
    }
}

void merge_sort(string *v, int size)
{
    if (size > 1)
    {
        int mid = size / 2;
        string *v1 = malloc(mid * sizeof(string));
        string *v2 = malloc((size - mid) * sizeof(string));
        for (int i = 0; i < mid; i++)
        {
            v1[i].str = malloc(11 * sizeof(char));
            strcpy(v1[i].str, v[i].str);
            v1[i].len = v[i].len;
        }
        for (int i = mid; i < size; i++)
        {
            v2[i - mid].str = malloc(11 * sizeof(char));
            strcpy(v2[i - mid].str, v[i].str);
            v2[i - mid].len = v[i].len;
        }
        merge_sort(v1, mid);
        merge_sort(v2, size - mid);
        merge(v, v1, v2, size);

        // for (int i = 0; i < size; i++)
        // {
        //     free(v1[i].str);
        //     free(v2[i].str);
        // }
        // free(v1);
        // free(v2);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    string *v = malloc(n * sizeof(string));
    for (int i = 0; i < n; i++)
    {
        v[i].str = malloc(11 * sizeof(char));
        scanf("%s", v[i].str);
        v[i].len = strlen(v[i].str);
    }
    merge_sort(v, n);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", v[i].str);
        //  free(v[i].str);
    }
    // free(v);
    return 0;
}
