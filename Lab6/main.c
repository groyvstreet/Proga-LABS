#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "main.h"

#ifndef TESTING

int main()
{
    char input[100], sym;
    int correct, i, data, num, j;
    Queue q;
    Node **trees;
    Node *nullNode;
    
    nullNode = NULL;

    do
    {
        correct = 1;
        printf("Enter: ");
        scanf("%s", input);

        if (input[0] == '0')
        {
            correct = 0;
        }

        for (i = 0; i < strlen(input); i++)
        {
            if (!isdigit(input[i]))
            {
                correct = 0;
            }
        }
    } while (!correct);

    qInit(&q);

    for (i = 0; i < atoi(input); i++)
    {
        data = rand() % 100;
        num = rand() % atoi(input);

        if (rand() % 2)
        {
            sym = 'A';
        }
        else
        {
            sym = 'D';
        }

        qAdd(&q, data, num, sym);
    }

    qPrint(&q);
    trees = (Node **)calloc(atoi(input), sizeof(Node *));

    if (trees == NULL)
    {
        printf("Not enough memory!");
        return 0;
    }

    for (i = 0; i < atoi(input); i++)
    {
        trees[i] = NULL;

        for (j = 0; j < atoi(input); j++)
        {
            if (q.num[j] == i)
            {
                if (q.sym[j] == 'A')
                {
                    AddNode(q.data[j], &trees[i], &nullNode);
                }
                else
                {
                    DeleteNode(&trees[i], q.data[j]);
                }
            }
        }
    }

    return 0;
}

#endif

void qInit(struct queue *q)
{
    q->first = 1;
    q->last = 0;
}

void qAdd(struct queue *q, int x, int y, char z)
{
    if (q->last < QMAX - 1)
    {
        q->last++;
        q->data[q->last] = x;
        q->num[q->last] = y;
        q->sym[q->last] = z;
    }
    else
    {
        printf("Очередь полна!\n");
    }
}

int qEmpty(struct queue *q)
{
    if (q->last < q->first)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void qRemove(struct queue *q)
{
    int i;

    if (qEmpty(q) == 1)
    {
        printf("Очередь пуста!\n");
        return;
    }

    for (i = q->first; i < q->last; i++)
    {
        q->data[i] = q->data[i + 1];
        q->num[i] = q->num[i + 1];
        q->sym[i] = q->sym[i + 1];
    }

    q->last--;
}

void qPrint(struct queue *q)
{
    int i;

    if (qEmpty(q) == 1)
    {
        printf("Очередь пуста!\n");
        return;
    }

    for (i = q->first; i <= q->last; i++)
    {
        printf("%d %d %c ", q->data[i], q->num[i], q->sym[i]);
    }

    printf("\n");
}

void AddNode(int data, Node **root, Node **parent)
{
    if (*root == NULL)
    {
        *root = (Node *)calloc(1, sizeof(Node));

        if(*root == NULL)
        {
            printf("Not enough memory!");
            exit(0);
        }

        (*root)->data = data;
        (*root)->left = (*root)->right = NULL;
        (*root)->parent = *parent;
    }
    else
    {
        if (data < (*root)->data)
        {
            AddNode(data, &(*root)->left, &(*root));
        }
        else if (data > (*root)->data)
        {
            AddNode(data, &(*root)->right, &(*root));
        }
        else
        {
            printf("There is such element in the tree");
        }
    }
}

Node *SearchNode(Node **root, int data)
{
    if (*root == NULL || (*root)->data == data)
    {
        return *root;
    }

    if (data < (*root)->data)
    {
        return SearchNode(&(*root)->left, data);
    }
    else
    {
        return SearchNode(&(*root)->right, data);
    }
}

Node *MinRightNode(Node **root)
{
    Node *l;

    l = *root;

    if (l->right != NULL)
    {
        l = l->right;
    }
    else
    {
        return NULL;
    }

    while (l->left != NULL)
    {
        l = l->left;
    }

    return l;
}

void DeleteNode(Node **root, int data)
{
    Node *l, *parent;

    l = NULL;
    parent = NULL;
    l = SearchNode(&(*root), data);

    if (l == NULL)
    {
        return;
    }

    if (l->left == NULL && l->right == NULL)
    {
        parent = l->parent;

        if (parent->left == l)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }

    if (l->left == NULL && l->right != NULL)
    {
        parent = l->parent;

        if (parent->left == l)
        {
            parent->left == l->right;
        }
        else
        {
            parent->right == l->right;
        }
    }

    if (l->left != NULL && l->right == NULL)
    {
        parent = l->parent;

        if (parent->left == l)
        {
            parent->left == l->left;
        }
        else
        {
            parent->right == l->left;
        }
    }

    if (l->left != NULL && l->right != NULL)
    {
        parent = MinRightNode(&l);
        l->data = parent->data;

        if (parent->right == NULL)
        {
            parent->parent->left = NULL;
        }
        else
        {
            parent->parent->left = parent->right;
        }
    }
}
