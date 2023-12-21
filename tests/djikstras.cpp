#include <iostream>
#include <climits>

using namespace std;

int minDistance(int dist[], bool visit[], int v)
{
    int min = INT_MAX, min_idx;
    for (int i = 0; i < v; i++)
    {
        if (!visit[i] && dist[i] <= min)
        {
            min = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void djikstra(int **graph, int src, int v)
{
    int dist[v];
    bool visit[v];

    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        visit[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int u = minDistance(dist, visit, v);
        visit[u] = true;

        for (int j = 0; j < v; j++)
        {
            if (!visit[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    cout << "Vertex and distance from source;";
    for (int i = 0; i < v; i++)
    {
        cout << "\n"
             << i << "---->" << dist[i];
    }
}

int main()
{
    int n;
    cout << "Enter no of vertices : ";
    cin >> n;

    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
    }

    cout << "Enter the adjacency matrix for the graph (0 for no edge):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    djikstra(graph, source, n);
    return 0;
}