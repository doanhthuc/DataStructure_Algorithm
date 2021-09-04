#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> Vii;
const int MAX = 100;
const int INF = 1e9;
vector<Vii> graph(MAX, Vii());
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;

void printMST()
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (path[i] == -1)
            continue;
        ans += dist[i];
        cout << path[i] << " - " << i << ": " << dist[i] << endl;
    }
    cout << "Weight of MST: " << ans << endl;
}

struct option
{
    bool operator()(const ii &a, const ii &b)
    {
        return a.second > b.second;
    }
};

void prims(int src)
{
    priority_queue<ii, Vii, option> pq;
    pq.push(make_pair(src, 0));
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;
        // if (dist[u] != pq.top().second)
        // {
        //     continue;
        // }
        for (auto &neighbour : graph[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if (!visited[v] && dist[v] > w)
            {
                dist[v] = w;
                pq.push(make_pair(v, w));
                path[v] = u;
            }
        }
    }
}

int main()
{
    int u, v, w;
    cin >> N >> M;
    memset(path, -1, sizeof(path));
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    int s = 1;
    prims(s);
    printMST();
    return 0;
}