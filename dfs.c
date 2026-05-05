#include <iostream> 
#define MAX 10
using namespace std;
int adjacency[MAX][MAX];
int visited[MAX]={0};

void dfs(int start, int n)
{
    visited[start]=1;
    cout<<start<<" ";
    for (int neighbour=0; neighbour<n;neighbour++)
    {
        if (adjacency[start][neighbour]!=0 and visited[neighbour]!=1)
        {
            dfs(neighbour, n);
        }
    }

}

int main()
{
    // enter adjacency matrix using nested for loops. n is the size of the adjacency matrix
    // dfs(0,n);
    return 0;
}
