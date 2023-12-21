#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class disjoint
{
    int *parent;
    int *rank;

public:
    disjoint(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 0;
        }
    }

    int ult_par(int x)
    {
        if (parent[x] == -1)
        {
            return x;
        }
        return ult_par(parent[x]);
    }

    // void join(int v, int u)
    // {
    //     int par_v = ult_par(v);
    //     int par_u = ult_par(u);
    //     if (par_u != par_v)
    //     {
    //         if (rank[par_v] < rank[par_u])
    //         {
    //             parent[par_v] = par_u;
    //         }
    //         else if (rank[par_v] > rank[par_u])
    //         {
    //             parent[par_u] = par_v;
    //         }
    //         else
    //         {
    //             parent[par_u] = par_v;
    //             rank[par_v]++;
    //         }
    //     }
    // }
};

class graph
{
    vector<vector<int>> edgelist;
    int v;

public:
    graph(int v)
    {
        this->v = v;
    }
    void addEdge(int v, int u, int cost)
    {
        edgelist.push_back({cost, v, u});
    }

    void mst(int v)
    {
        sort(edgelist.begin(), edgelist.end());
        disjoint D(v);
        int total = 0;

        for (auto edge : edgelist)
        {
            int v = edge[1];
            int u = edge[2];
            int cost = edge[0];

            if (D.ult_par(v) != D.ult_par(u))
            {
                // D.join(v, u);
                total += cost;
                cout << "\n"
                     << v << "----->" << u << " === " << cost;
            }
        }
        cout << "\nTotal cost = " << total;
    }
};

int main()
{
    graph g(5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(1, 4, 10);
    g.addEdge(1, 5, 5);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 4);
    g.addEdge(4, 5, 2);

    // Function call
    g.mst(5);

    return 0;
}