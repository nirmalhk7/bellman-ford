// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <bits/stdc++.h>
using namespace std;
// a structure to represent a weighted edge in graph
struct Edge
{
  int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph
{
  // V-> Number of vertices, E-> Number of edges
  int V, E;

  // graph is represented as an array of edges.
  struct Edge *edge;
};

// Creates a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
  struct Graph *graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int n)
{
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < n; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle
void BellmanFord(struct Graph *graph, int src)
{
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  // Step 1: Initialize distances from src to all other vertices
  // as INFINITE
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;
  dist[src] = 0;

  // Step 2: Relax all edges |V| - 1 times. A simple shortest
  // path from src to any other vertex can have at-most |V| - 1
  // edges
  for (int i = 1; i <= V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        dist[v] = dist[u] + weight;
    }
  }

  // Step 3: check for negative-weight cycles.  The above step
  // guarantees shortest distances if graph doesn't contain
  // negative weight cycle.  If we get a shorter path, then there
  // is a cycle.
  for (int i = 0; i < E; i++)
  {
    int u = graph->edge[i].src;
    int v = graph->edge[i].dest;
    int weight = graph->edge[i].weight;
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
    {
      printf("Graph contains negative weight cycle");
      return; // If negative cycle is detected, simply return
    }
  }

  printArr(dist, V);

  return;
}
Graph* insertGraph(Graph *graph,int ns,int nd,int nw,int g)
{
  graph->edge[g].src = ns;
  graph->edge[g].dest = nd;
  graph->edge[g].weight = nw;
  return graph;
}
// Driver program to test above functions
int main()
{
  /* Let us create the graph given in above example */
  int V = 5; // Number of vertices in graph
  int E = 8; // Number of edges in graph
  struct Graph *graph = createGraph(V, E);
  int graphCount=0;
  int kill;
  do{
    cout << "\nEnter";
    cout << "\n1\tto add router";
    cout << "\n2\tto emulate router failure";
    cout << "\n3\tto emulate link failure";
    cout << "\n4\tto display Routing Table for any node";
    cout << "\n5\tto quit program\n-";
    cin >> kill;
    switch (kill)
    {
      case 1:
      {
        int ns, nd, nw;
        cout << "\nInserting Node. Enter node source, node destination (node number) and node weight : ";
        cin >> ns >> nd >> nw;
        graph=insertGraph(graph, ns, nd, nw, graphCount);
        graphCount++;
      }
      case 2:
      {

      }
      case 3:
      {
        
      }
      case 4:
      {
        int rtrop;
        cout<<"\nEnter the node whose table you wish to see :";
        cin>>rtrop;
        BellmanFord(graph,rtrop);
      }
    }
  }while(kill!=4);

  return 0;
}