#include "bits/stdc++.h"

using namespace std;
//src: Hackerearth
typedef pair<int, int> ii;
typedef vector<ii> Vii;
const int MAX = 1e5 + 10;
const int INF = 1e9 + 5;
vector<Vii> graph(MAX, Vii());
vector<int> dist(MAX, INF);
vector<bool> visited(MAX, false);
vector<int> path(MAX, -1);

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

int main()
{
    int n, m, q;
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    prims(1);
    priority_queue<int> mstCables;
    for (int i = 2; i <= n; i++)
    {
        mstCables.push(dist[i]);
    }
    priority_queue<int, vector<int>, greater<int>> newCables;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> w;
        newCables.push(w);
    }
    long long res = 0;
    while (!mstCables.empty())
    {
        int usedCables = mstCables.top();
        mstCables.pop();
        if (!newCables.empty() && newCables.top() < usedCables)
        {
            usedCables = newCables.top();
            newCables.pop();
        }
        res += usedCables;
    }
    cout << res << endl;
    return 0;
}

/* Đầu tiên bạn sẽ tìm cây khung nhỏ nhất của đồ thị đề bài cho, sau đó lần lượt thay các cạnh có độ trễ lớn bằng cách cạnh có độ trễ nhỏ hơn trong QQ sợi cáp được cho.

Sau khi tìm được cây khung nhỏ nhất tạo thành từ các sợi cáp sẵn có, bạn sẽ thay các sợi cáp lớn nhất bằng những sợi cáp mới có độ trễ nhỏ nhất có thể để giảm chi phí xuống. Có thể sử dụng 2 heap (1 heap max cho các sợi cáp trong cây khung để ưu tiên thay những sợi lớn nhất và 1 heap min cho các sợi cáp mới để ưu tiên chọn những sợi cáp nhỏ nhất). Hoặc sắp xếp lại giảm dần theo các sợi cáp trong cây khung và tăng dần theo các sợi cáp mới (tương tự như 2 heap) và sau đó sử dụng kỹ thuật two pointer.

Độ phức tạp: O(MlogN + NlogN + QlogQ)O(MlogN+NlogN+QlogQ) trong đó MlogNMlogN là độ phức tạp Prim, NlogN + QlogQNlogN+QlogQ là độ phức tạp quá trình thay các cáp cũ bằng cáp mới. */