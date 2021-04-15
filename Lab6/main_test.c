#include <stdio.h>
#include "main.h"
#include <assert.h>

Node *nullNode = NULL;

void Test1qEmpty()
{
    Queue q;

    qInit(&q);
    assert(qEmpty(&q) == 1);
}

void Test2qEmpty()
{
    Queue q;

    qInit(&q);
    qAdd(&q, 19, 4, 'A');
    assert(qEmpty(&q) == 0);
}

void Test1SearchNode()
{
    Node *root;

    root = NULL;
    AddNode(12, &root, &nullNode);
    AddNode(34,&root, &nullNode);
    AddNode(23, &root, &nullNode);
    AddNode(67, &root, &nullNode);
    AddNode(21, &root, &nullNode);
    assert(SearchNode(&root, 67)->data = 67);
}

void Test2SearchNode()
{
    Node *root;

    root = NULL;
    AddNode(12, &root, &nullNode);
    AddNode(34, &root, &nullNode);
    AddNode(23, &root, &nullNode);
    AddNode(67, &root, &nullNode);
    AddNode(21, &root, &nullNode);
    assert(SearchNode(&root, 89) == NULL);
}

void Test1MinRightNode()
{
    Node *root;

    root = NULL;
    AddNode(54, &root, &nullNode);
    AddNode(33, &root, &nullNode);
    AddNode(78, &root, &nullNode);
    AddNode(92, &root, &nullNode);
    AddNode(67, &root, &nullNode);
    assert(MinRightNode(&root)->data == 67);
}

void Test2MinRightNode()
{
    Node *root;

    root = NULL;
    AddNode(2, &root, &nullNode);
    AddNode(66, &root, &nullNode);
    AddNode(44, &root, &nullNode);
    AddNode(33, &root, &nullNode);
    AddNode(77, &root, &nullNode);
    assert(MinRightNode(&root)->data == 33);
}

int main()
{
    Test1qEmpty();
    Test2qEmpty();
    Test1SearchNode();
    Test2SearchNode();
    Test1MinRightNode();
    Test2MinRightNode();
    printf("Tests passed!");
    return 0;
}
