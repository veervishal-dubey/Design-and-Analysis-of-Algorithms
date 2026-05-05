#include <iostream>
#define MAX 10
using namespace std;

int adjacency[MAX][MAX];
int visited[MAX]={0};
int queue[MAX];
int front = -1, rear=-1;

void enqueue(int element)
{
    if (rear==MAX-1)
        return;
    if (front==-1)
        front=0;
    queue[++rear]=element;
}

int dequeue()
{
    if (front==-1)
        return -1;
    int value=queue[front];
    if (front==rear)
        front=rear=-1;
    front++;
    return value;
}

int isEmpty()
{
    if (front==-1)
        return 1;
    else
        return 0;
}

void bfs (int start, int n)
{
    enqueue(start);
    visited[start]=1;
    while (!isEmpty())
    {
        int current=dequeue();
        cout<<current << " ";
        for (int i=0; i<n;i++)
        {
            if (adjacency[current][i]!=0 && visited[i]!=1)
            {
                enqueue[i];
                visited[i]=1;
            }
        }
    }
    
}
