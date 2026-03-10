#include <stdio.h>
int count = 1;

int stack[100];

int graph[10][10];

int visited[100];

void dfs(int start, int n)
{

        visited[start]=count++;
        printf("%d ", start);
        for (int i =0; i<n;i++)
        {
                if(graph[start][i]!=0 && !visited[i])
                        dfs(i,n);
        }
}

int main()
{

int n;

printf("Enter the number of vertex: ");
scanf("%d",&n);
printf("Enter the adjacenecy matrix\n");
for (int i=0; i<n;i++)
{
        for (int j = 0 ; j<n ; j++)
                scanf("%d", &graph[i][j]);
}

dfs(0,n);


return 0;
}
