#include "bits/stdc++.h"

using namespace std;

const int MAX = 1011;
const int INF = 1e9 + 5;
typedef pair<int, double> ii;
typedef vector<pair<int, double>> Vii;
vector<Vii> graph(MAX, Vii(MAX));
vector<double> dist(MAX);
vector<bool> visited(MAX);
vector<int> path(MAX);
int x[MAX], y[MAX];
int N, M;

// src: UVA

struct options
{
    bool operator()(const ii &a, const ii &b)
    {
        return a.second > b.second;
    }
};

double distance(int i, int j)
{
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

void prims(int s)
{
    priority_queue<ii, Vii, options> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;
        for (auto &neighbour : graph[u])
        {
            int v = neighbour.first;
            double w = neighbour.second;

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
    while (cin >> N)
    {
        int a, b;
        for (int i = 1; i <= N; i++)
        {
            dist[i] = INF;
            visited[i] = false;
            path[i] = -1;
            graph[i].clear();
            cin >> a >> b;
            x[i] = a;
            y[i] = b;
        }

        cin >> M;
        vector<vector<bool>> edges(N + 1, vector<bool>(N + 1, false));
        for (int i = 0; i < M; i++)
        {
            cin >> a >> b;
            edges[a][b] = true;
            edges[b][a] = true;
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                if (edges[i][j] == false)
                {
                    double w = distance(i, j);
                    graph[i].push_back({j, w});
                    graph[j].push_back({i, w});
                }
                else
                {
                    graph[i].push_back({j, 0});
                    graph[j].push_back({i, 0});
                }
            }
        }
        prims(1);
        double res = 0;
        for (int i = 1; i <= N; i++)
        {
            res += dist[i];
            if (res >= INF)
            {
                res = -1;
                break;
            }
        }
        printf("%.2f\n", res);
    }
    return 0;
}

/* Bạn sẽ tính khoảng cách của tất cả các cặp tòa nhà, trừ những tòa nhà nào đã có kết nối rồi thì bạn đặt chi phí kết nối là 00.

Sau khi đã tính xong thì bạn bỏ toàn bộ các cặp kết nối và chi phí đó vào graph rồi chạy thuật toán Prim.

Cây khung nhỏ nhất là kết quả tìm được.

Độ phức tạp: O(T * N^2 * logN)O(T∗N
​2
​​ ∗logN) với TT là số lượng bộ test và O(N^2 * logN)O(N
​2
​​ ∗logN) là độ phức tạp của thuật toán Prim vì trong bài này ta dùng tất cả cạnh nối giữa các tòa nhà nên số lượng cạnh là N^2N
​2
​​ . */