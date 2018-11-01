
#include <iostream>
using namespace std;
/*
First InFirst Out 
Түрүүлж орсон нь түрүүлж гарна
*/

bool isFull(int &max, int &length);
bool isEmpty(int &length);
void enqueue(int *queue,int &max,int &length,int &newData);
int dequeue(int *queue, int &length);
int front(int *queue);
int rear(int *queue, int &length);
void displayQueue(int *queue, int &length);

