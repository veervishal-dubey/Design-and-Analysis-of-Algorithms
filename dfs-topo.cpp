#include <iostream>
#define MAX 10 
using namespace std;

int adjacency[MAX][MAX];
int visited[MAX]={0};
int stack[MAX];
int top=-1; 

void push(int element)
{
    if (top==MAX-1)
        return;
    stack[++top]=element;
}

int pop()
{
    if (top==-1)
        return -1;
    int val=stack[top];
    top--;
    return val;
}

void dfstopo(int start, int n)
{
    visited[start]=1;
    for (int i=0; i<n; i++)
    {
        if (adjacency[start][i]==1 && visited[i]!=1)
            dfstopo(i, n);
    }
    push(start);
}

void printtopo()
{
    while (top!=-1)
        cout<<pop()<<" ";
}
