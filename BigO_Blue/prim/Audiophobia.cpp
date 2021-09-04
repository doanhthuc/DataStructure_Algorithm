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

/* Ứng với mỗi test case, đầu tiên ta sẽ tìm cây khung ngắn nhất trên đồ thị bằng thuật toán Prim, lưu ý rằng đồ thị có thể là một rừng, tức có nhiều đồ thị đơn lẻ, nên ta phải tìm từng cây khung ứng với từng đồ thị. Sau đó ta sẽ duyệt DFS để tìm đường đi từ c_1c
​1
​​  đến c_2c
​2
​​ . Kết quả sẽ là mức âm thanh của cạnh lớn nhất khi ta đi từ c_1c
​1
​​  đến c_2c
​2
​​ .

Độ phức tạp: O(SlogC + Q*(C-1))O(SlogC+Q∗(C−1)), chi phí Prim O(SlogC)O(SlogC) với SS là số cạnh, CC là số đỉnh và chi phí duyệt DFS với M truy vấn: O(Q*(C-1))O(Q∗(C−1)) với QQ là số truy vấn, CC là số đỉnh ban đầu.

 */
