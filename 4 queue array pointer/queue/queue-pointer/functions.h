
#include <iostream>
using namespace std;
/*
First InFirst Out 
Түрүүлж орсон нь түрүүлж гарна
*/

struct Node{
    int content;
    Node *next;
};

bool isEmpty(Node **head);
void enqueue(Node **head, int &newData);
int dequeue(Node **head);

int front(Node **head);
int rear(Node **head);
void displayQueue(Node **head);