#include <bits/stdc++.h>  
using namespace std;  
#define INF 0x3f3f3f3f // The distance to other vertices is initialized as infinite  
// iPair ==> Integer Pair  
typedef pair<int, int> iPair;  
class Graph // Graph structure  
    {  
    int V; // No. of vertices in the graph  
    list<pair<int, int>>* adj; // the list of pair to store vertex and its weight  
public:  
    // Constructor that accept number of vertices in graph  
    Graph(int V) // allocate the vertex memory  
    {  
        this->V = V; // assign the vertex   
        adj = new list<iPair>[V]; // allocate space for vertices   
    }  
    void addEdge(int u, int v, int w); // add edges in the graph  
    // prints shortest path from s  
    void shortestPathingraph(int s); // pass source vertex  
};  
void Graph::addEdge(int u, int v, int w) // add an edge  
{  
    adj[u].push_back(make_pair(v, w)); // make a pair of vertex and weight and // add it to the list  
    adj[v].push_back(make_pair(u, w)); // add oppositely by making a pair of weight and vertex  
}  
// Calling function outside the Graph class  
void Graph::shortestPathingraph(int src) // src is the source vertex  
{  
    // Create a priority queue to store vertices that  
    // are being preprocessed.  
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;  
    vector<int> dist(V, INF); // All distance from source are infinite  
    pq.push(make_pair(0, src)); // push spurce node into the queue  
    dist[src] = 0; // distance of source will be always 0  
    while (!pq.empty()) { // While queue is not empty  
        // Extract the first minimum distance from the priority queue  
        // vertex label is stored in second of pair (it  
        // has to be done this way to keep the vertices  
        // sorted distance  
        int u = pq.top().second;  
        pq.pop();  
        // 'i' is used to get all adjacent vertices of a vertex  
        list<pair<int, int>>::iterator i;  
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {  
            // Get vertex label and weight of current adjacent  
            // of u.  
            int v = (*i).first;  
            int weight = (*i).second;  
  
            // If there is shorted path to v through u.  
            if (dist[v] > dist[u] + weight) {  
                // Updating distance of v  
                dist[v] = dist[u] + weight;  
                pq.push(make_pair(dist[v], v));  
            }  
        }  
    }  
    printf("Vertex \tDistance from Source\n"); // Print the result  
    for (int i = 0; i < V; ++i)  
        printf("%d \t\t %d\n", i, dist[i]); // The shortest distance from source  
}  
int main()  
{  
    int V = 9; // vertices in given graph are 9  
    Graph g(V); //  call Constructor by creating an object of graph  
    g.addEdge(0, 1, 4); // add root node with neighour vertex and weight  
    g.addEdge(0, 7, 8);  
    g.addEdge(1, 2, 8);  
    g.addEdge(1, 7, 11);  
    g.addEdge(2, 3, 7);  
    g.addEdge(2, 8, 2);  
    g.addEdge(2, 5, 4);  
    g.addEdge(3, 4, 9);  
    g.addEdge(3, 5, 14);  
    g.addEdge(4, 5, 10);  
    g.addEdge(5, 6, 2);  
    g.addEdge(6, 7, 1);  
    g.addEdge(6, 8, 6);  
    g.addEdge(7, 8, 7);  
    g.shortestPathingraph(0); // call the function to find shortest path of graph  
    return 0; // end of main function()  
}  

// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}

// driver's code
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	// Function call
	dijkstra(graph, 0);

	return 0;
}





#include <bits/stdc++.h>
using namespace std;
int N,M;
int ans = INT_MAX;
typedef pair<int,int> iPair;
class Graph
{
	int V;
	list<iPair> *adj;
public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<iPair>[V];
	}
	void addEdge(int u,int v,int w);
	void shortest(int s);
};

void Graph::addEdge(int u,int v,int w)
{
	adj[u].push_back({v,w});
	adj[v].push_back({u,w});
}
void Graph::shortest(int s)
{
	priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
	vector<int> d(N,INT_MAX);
	d[s] = 0;
	pq.push({0,s});
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		list<iPair>::iterator it;
		for(it = adj[u].begin(); it != adj[u].end();++it)
		{
			int v = (*it).first;
			int w = (*it).second;
			if(d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				pq.push({d[v],v});
			}
		}
	}
	int res = INT_MIN;
	for(int i=0;i<N;i++)
		if(d[i]>res) res = d[i];
	if(res < ans) ans = res;
}

int main() {
	cin>>N>>M;
	Graph g(N);
	int u,v,w;
	for(int i=0;i<M;i++)
	{
		cin>>u>>v>>w;
		g.addEdge(--u,--v,w);
	}
	//g.shortest(0);
	for(int i=0;i<N;i++)
	{
		g.shortest(i);
	}
	cout<<ans<<endl;
	return 0;
}
