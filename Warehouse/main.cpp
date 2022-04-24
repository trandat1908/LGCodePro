#include <bits/stdc++.h>

// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
using namespace std;
#include <limits.h>
 
// Number of vertices in the graph
//#define V 9
int V,M;
const int MAX  = 105;
vector<int> mV;
int graph[MAX][MAX];
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 1; v <= V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int dist[])
{
    int minV = INT_MIN;
    for (int i = 1; i <= V; i++)
    {
        if(dist[i] > minV)
        {
            minV = dist[i];
        }
    }
    mV.push_back(minV);
}
 
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[MAX][MAX], int src)
{
    int dist[MAX]; // The output array.  dist[i] will hold the shortest distance from src to i
 
    bool sptSet[MAX]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 1; i <= V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 1; count < V; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 1; v <= V; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSolution(dist);
}

void InPut(int N, int M)
{
    int u,v,c;
    for(int j =1; j<=N;j++)
    {
        for(int k =1;k<=N;k++)
        {
            graph[j][k] = 0;
        }
    }
    for(int i = 0; i < M; i++)
    {
        cin>> u >> v >> c;
        graph[u][v] = graph[v][u] = c;
    }
}
 
// driver program to test above function
int main()
{
   
    /* Let us create the example graph discussed above */
    // int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //                     { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //                     { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //                     { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //                     { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //                     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //                     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //                     { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    freopen("in.txt","r",stdin);
    cin >> V >>M;

    InPut(V, M);
 
    for(int i=1;i<=V;i++)
    {
        dijkstra(graph, i);
    }
    int res = *min_element(mV.begin(), mV.end());
    cout << res<< endl;
    return 0;
}
 