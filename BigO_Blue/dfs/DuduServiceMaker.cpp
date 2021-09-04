#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int N, M;
int visited[MAX];
vector<int> graph[MAX];

bool DFS(int u)
{
    visited[u] = 1;

    for (int &v : graph[u])
    {
        if (visited[v] == 1)
        {
            return true;
        }
        else if (visited[v] == 0)
        {
            if (DFS(v))
            {
                return true;
            }
        }
    }

    visited[u] = 2;
    return false;
}

int main()
{
    int T, u, v;
    cin >> T;

    while (T--)
    {
        cin >> N >> M;

        for (int i = 1; i <= N; i++)
        {
            graph[i].clear();
            visited[i] = 0;
        }

        for (int i = 0; i < M; i++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
        }

        bool isCyclic = false;

        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0)
            {
                isCyclic = DFS(i);
                if (isCyclic)
                {
                    break;
                }
            }
        }

        cout << (isCyclic ? "YES" : "NO") << endl;
    }
    return 0;
}