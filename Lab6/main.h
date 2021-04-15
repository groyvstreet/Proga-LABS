#ifndef MAIN_H
#define MAIN_H

#define QMAX 100

typedef struct queue
{
    int data[QMAX];
    int num[QMAX];
    char sym[QMAX];
    int last, first;
} Queue;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
} Node;

void qInit(struct queue *q);
void qAdd(struct queue *q, int x, int y, char z);
int qEmpty(struct queue *q);
void qRemove(struct queue *q);
void qPrint(struct queue *q);
void AddNode(int data, Node **root, Node **parent);
Node *SearchNode(Node **root, int data);
Node *MinRightNode(Node **root);
void DeleteNode(Node **root, int data);

#endif
