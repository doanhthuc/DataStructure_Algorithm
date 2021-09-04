#include "bits/stdc++.h"

using namespace std;

typedef vector<int> Vi;
const int MAX = 105;
const int INF = 1e9;

vector<Vi> graph;
vector<Vi> dist;
vector<Vi> path;
int V;

void printPath(vector<Vi> &path, int s, int f)
{
    if (s == f)
    {
        cout << f << " ";
        return;
    }
    if (path[s][f] == -1)
    {
        cout << "No path found";
        return;
    }
    printPath(path, s, path[s][f]);
    cout << f << " ";
}

void printSolution(vector<Vi> &path, vector<Vi> &dist)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j)
            {
                cout << i << "-> " << j << ": ";
                printPath(path, i, j);
                cout << endl;

                if (path[i][j] != -1)
                {
                    cout << "Total length: " << dist[i][j] << endl;
                }
            }
        }
    }
}

bool floydWarshall(vector<Vi> &graph, vector<Vi> &dist)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
            if (dist[i][j] != INF)
            {
                path[i][j] = i;
            }
            else
            {
                path[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            if (dist[i][k] == INF)
                continue;
            for (int j = 0; j < V; j++)
            {
                if (dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (dist[i][i] < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, temp;
    cin >> V;
    graph = vector<Vi>(V, Vi(V));
    dist = vector<Vi>(V, Vi(V));
    path = vector<Vi>(V, Vi(V));

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> temp;
            if (temp == 0 && i != j)
            {
                graph[i][j] = INF;
            }
            else
            {
                graph[i][j] = temp;
            }
        }
    }

    if (floydWarshall(graph, dist) == true)
    {
        printSolution(path, dist);
    }
    else
    {
        cout << "Graph contains negative weight cycle" << endl;
    }

    return 0;
}