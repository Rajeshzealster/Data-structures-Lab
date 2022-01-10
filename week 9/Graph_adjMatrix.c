#include <stdio.h>
#define M_SIZE 20

int visited[20],nv,q[20],r=-1,f=0;
//Depth First Search of the graph
void DFS(int adj[M_SIZE][M_SIZE],int u)
{
    visited[u]=1;
    printf("%d ",u);
    for (int v=0;v <nv;v++) {
        if (!visited[v] && adj[u][v]) {
            DFS(adj, v);
        }
    }
}
//Breadth First Search of the graph
void BFS(int adj[M_SIZE][M_SIZE],int v) {
    printf("%d ",v);
	for (int i=0;i<nv;i++)
	  if(adj[v][i] && !visited[i])
	    q[++r]=i;
	if(f<=r) {
		visited[q[f]]=1;
		BFS(adj,q[f++]);
	}
}
int main()
{
    int choice,s;
    int adj[M_SIZE][M_SIZE];
    printf("1.Create a graph\n2.DFS traversal of the graph\n3.BFS traversal of the graph\n4.Exit\n");

    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter the number of nodes in the graph:");
            scanf("%d",&nv);
            for(int i=0;i<nv;i++)
            {
                printf("Enter the adjacency list for node%d:",i+1);
                for(int j=0;j<nv;j++)
                    scanf("%d",&adj[i][j]);
            }
            printf("\nThe adjacency matrix of the graph is:\n");
            for(int i=0;i<nv;i++){
                for(int j=0;j<nv;j++){
                    printf("%d ",adj[i][j]);
                }
                printf("\n");
            }
        }
        else if(choice==2)
        {
            for(int i=0;i<nv;i++)
            {
                visited[i]=0;
            }
            printf("\nEnter the starting vertex:");
            scanf("%d",&s);
            printf("\nDFS traversal is:\n");
            DFS(adj,s);
        }
        else if(choice==3)
        {
            for(int i=0;i<nv;i++)
            {
                visited[i]=0;
            }
            printf("\nEnter the starting vertex:");
            scanf("%d",&s);
            visited[s]=1;
            printf("\nBFS traversal is:\n");
            BFS(adj,s);
        }
    }while(choice!=4);

    return 0;
}

