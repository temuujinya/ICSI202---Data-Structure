
#include <iostream>
using namespace std;
struct Node{
    int content;
    Node *next;
};

bool isEmpty(Node **head);
void push(Node **head, int &newData);
int pop(Node **head);

int TOP(Node **head);
void displayStack(Node **head);