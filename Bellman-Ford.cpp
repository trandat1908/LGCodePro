#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 101;

int n, m, src, mark[MAXN];
ll dist[MAXN];

class Edge
{
public:
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<Edge> edges;

void BellmanFord()
{
    fill(dist + 1, dist + n + 1, LONG_MAX);
    dist[src] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (Edge e : edges)
        {
            if (dist[e.u] + e.w < dist[e.v])
            {
                if (i == n)
                    mark[e.v] = 1;
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
}

int main()
{
    freopen("D:\\Code\\SPCT\\in.txt", "r", stdin);
    cin >> n >> m >> src;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back(Edge(u, v, w));
    }
    BellmanFord();
    for (int i = 1; i <= n; ++i)
    {
        if (!mark[n])
        {
            if (dist[i] == LONG_MAX)
                cout << "-1" << endl;
            else
                cout << dist[i] << endl;
        }
        else
            cout << "-2" << endl;
    }

    return 0;
}
