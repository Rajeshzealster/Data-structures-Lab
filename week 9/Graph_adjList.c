#include <stdio.h>
#include<stdlib.h>
#define SIZE 20
//structure for node of adjacency list
typedef struct node
{
    int vertex_no;
    struct node* next;
}Node;

//structure for entire graph represented using adjacency list
typedef struct graph
{
    int number_vertices;
    struct node** adj_lists;//similar to 2D array creation
    int* visited;//an array to keep track of visited vertices while traversing...
}Graph;

//structure for creating a queue
typedef struct queue
{
    int arr[SIZE];
    int rear,front;
}Queue;

//Creating a graph
Graph* create_Graph(int n)
{
    Graph* g=(Graph*)malloc(sizeof(Graph));
    g->number_vertices=n;
    g->adj_lists=(Node**)malloc(n*sizeof(Node*));
    g->visited=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        g->adj_lists[i]=NULL;
        g->visited[i]=0;//all vertices are not visited initially..
    }
    return g;
}

//Creating a node
Node* create_Node(int v)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->vertex_no=v;
    newnode->next=NULL;
    return newnode;
}
// Create a queue
Queue* create_Queue() {
  Queue* q = malloc(sizeof(Queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int is_Empty(Queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(Queue* q, int ele) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front=0;
    q->rear++;
    q->arr[q->rear] =ele;
  }
}

// Removing elements from queue
int dequeue(Queue* q) {
  int ele;
  if(is_Empty(q))
  {
    printf("Queue is empty");
    ele=-1;
  }
  else{
    ele=q->arr[q->front];
    q->front++;
    //when front exceeds rear...queue is empty
    if(q->front>q->rear)
    {
        q->front=q->rear=-1;
    }
  }
  return ele;
}
// Print the queue
void print_Queue(Queue* q) {
  int i = q->front;

  if(is_Empty(q))
  {
    printf("Queue is empty");
  }
  else{
    printf("\nQueue:");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->arr[i]);
    }
  }
}

//Breadth First search of a graph
void BFS(Graph* g,int start_vertex)
{
    //visited[]={0} so that we can apply BFS any number of times with varying starting vertex
    for(int i=0;i<g->number_vertices;i++)
        g->visited[i]=0;
    Queue* q = create_Queue();
    g->visited[start_vertex] = 1;
    enqueue(q, start_vertex);

  while (!is_Empty(q)){
    print_Queue(q);
    int v= dequeue(q);
    printf("Visited-%d\n", v);
    Node* t = g->adj_lists[v];

    while (t) {

      if (g->visited[t->vertex_no] == 0)
      {
        g->visited[t->vertex_no] = 1;
        enqueue(q, t->vertex_no);
      }
      t = t->next;
    }
  }
}
//Depth First search of the graph
void DFS(Graph* g,int v)
{
    Node* t=g->adj_lists[v];
    g->visited[v]=1;
    printf("Visited-%d ",v);

    while(t)
    {
        if(g->visited[t->vertex_no]==0)
            DFS(g,t->vertex_no);
        t=t->next;
    }
}
//Depth First Traversal of graph(if the graph is not connected)...


//checking the presence of edge in the graph
int check_Edge(Graph* g,int source,int dest)
{
    Node* t=g->adj_lists[source];
    while(t)
    {
        if(t->vertex_no==dest)
            return 1;//vertex already present in the adj list
        t=t->next;
    }
    return 0;
}

//Adding an edge to the graph
void add_Edge(Graph* g,int source,int dest,int ch)
{
    if(!check_Edge(g,source,dest)){
        //Edge from source->dest
        Node* newnode=create_Node(dest);
        newnode->next=g->adj_lists[source];
        g->adj_lists[source]=newnode;

        //Edge from dest->source if undirected graph
        if(ch==2){
            newnode=create_Node(source);
            newnode->next=g->adj_lists[dest];
            g->adj_lists[dest]=newnode;
        }
        printf("The edge is successfully added to the graph");
    }
    else
        printf("This edge is already added to the graph");
}

//Printing graph in adjacency list representation
void print_Graph(Graph* g)
{
    for(int v=0;v<g->number_vertices;v++)
    {
        Node* t=g->adj_lists[v];
        printf("Vertex: %d-->",v);
        while(t)
        {
            printf("%d ",t->vertex_no);
            t=t->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice,nv,ch1,ch2,s,d;
    Graph* g;

    do
    {
        printf("\n1.Create a graph\n2.BFS traversal of the graph\n3.DFS traversal of the graph\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter the number of nodes in the graph:");
            scanf("%d",&nv);
            //create graph with nv vertices
            g=create_Graph(nv);

            do{
                printf("\n\n1.Directed Graph\n2.Undirected Graph\n3.Return to main menu\n");
                printf("Enter your choice:");
                scanf("%1d",&ch1);
                if(ch1==1 || ch1==2)
                {
                    do{
                        printf("\n\n1.Add edge to the graph(Vertices from 0 to n-1)\n2.Print the graph(adjacency list representation)\n3.Return(after the graph is created fully)\n");
                        printf("Enter your choice:");
                        scanf("%1d",&ch2);
                        if(ch2==1){
                            printf("Enter the edge(souce Destination):");
                            scanf("%d%d",&s,&d);
                            add_Edge(g,s,d,ch1);
                        }
                        else if(ch2==2)
                        {
                            print_Graph(g);
                        }
                        else if(ch2>3)
                            printf("Enter a valid choice..");
                    }while(ch2!=3);

                }
                else if(ch1>3)
                    printf("Enter a valid choice..");

            }while(ch1!=3);
        }
        else if(choice==2)
        {
            printf("\nEnter the starting vertex for traversal:");
            scanf("%d",&s);
            //visited[]={0} so that we can apply BFS any number of times with varying starting vertex
            for(int i=0;i<g->number_vertices;i++)
                g->visited[i]=0;
            BFS(g,s);
        }
        else if(choice==3)
        {
            printf("\nEnter the starting vertex for traversal:");
            scanf("%d",&s);
            //visited[]={0} so that we can apply DFS any number of times with varying starting vertex
            for(int i=0;i<g->number_vertices;i++)
                g->visited[i]=0;
            DFS(g,s);
        }
        else if(choice>4)
        {
            printf("Enter a valid choice...");
        }
    }while(choice!=4);

    return 0;
}
