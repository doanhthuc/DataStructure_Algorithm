#include "bits/stdc++.h"

using namespace std;

const int MAX = 111;
const int INF = 1e9 + 5;
typedef pair<int, int> ii;
typedef vector<ii> Vii;
vector<Vii> graph(MAX, Vii());
vector<Vii> MSTgraph(MAX, Vii());
bool visited[MAX];
vector<int> path(MAX);
vector<int> dist(MAX, INF);
int N, M, Q;

// src: UVa

struct options
{
    bool operator()(const ii &a, const ii &b)
    {
        return a.second > b.second;
    }
};

void prims(int s)
{
    priority_queue<ii, Vii, options> pq;
    pq.push({s, 0});
    dist[s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;
        for (auto &neighbour : graph[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if (!visited[v] && w < dist[v])
            {
                dist[v] = w;
                path[v] = u;
                pq.push({v, w});
            }
        }
    }
}

void buildMSTgraph()
{
    for (int u = 1; u <= N; u++)
    {
        if (path[u] != -1)
        {
            int v = path[u];
            int w = dist[u];
            MSTgraph[u].push_back({v, w});
            MSTgraph[v].push_back({u, w});
        }
    }
}

int dfs(int src, int dst, int level)
{
    if (src == dst)
    {
        return level;
    }
    visited[src] = true;
    for (auto &neighbour : MSTgraph[src])
    {
        int v = neighbour.first;
        int w = neighbour.second;
        if (!visited[v])
        {
            int tmpLevel = dfs(v, dst, max(level, w));
            if (tmpLevel != INF)
            {
                return tmpLevel;
            }
        }
    }
    return INF;
}

int main()
{
    int u, v, w;
    int tc = 1;
    while (cin >> N >> M >> Q, N != 0)
    {
        for (int i = 1; i <= N; i++)
        {
            MSTgraph[i].clear();
            graph[i].clear();
            visited[i] = false;
            path[i] = -1;
            dist[i] = INF;
        }

        for (int i = 0; i < M; i++)
        {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                prims(i);
            }
        }

        buildMSTgraph();

        if (tc != 1)
            cout << endl;
        cout << "Case #" << tc++ << endl;
        for (int i = 0; i < Q; i++)
        {
            cin >> u >> v;
            memset(visited, false, sizeof(visited));
            int level = dfs(u, v, 0);
            if (level != INF)
                cout << level;
            else
                cout << "no path";
            cout << "\n";
        }
    }
    return 0;
}

/* ???ng v???i m???i test case, ?????u ti??n ta s??? t??m c??y khung ng???n nh???t tr??n ????? th??? b???ng thu???t to??n Prim, l??u ?? r???ng ????? th??? c?? th??? l?? m???t r???ng, t???c c?? nhi???u ????? th??? ????n l???, n??n ta ph???i t??m t???ng c??y khung ???ng v???i t???ng ????? th???. Sau ???? ta s??? duy???t DFS ????? t??m ???????ng ??i t??? c_1c
???1
??????  ?????n c_2c
???2
?????? . K???t qu??? s??? l?? m???c ??m thanh c???a c???nh l???n nh???t khi ta ??i t??? c_1c
???1
??????  ?????n c_2c
???2
?????? .

????? ph???c t???p: O(SlogC + Q*(C-1))O(SlogC+Q???(C???1)), chi ph?? Prim O(SlogC)O(SlogC) v???i SS l?? s??? c???nh, CC l?? s??? ?????nh v?? chi ph?? duy???t DFS v???i M truy v???n: O(Q*(C-1))O(Q???(C???1)) v???i QQ l?? s??? truy v???n, CC l?? s??? ?????nh ban ?????u.

 */
