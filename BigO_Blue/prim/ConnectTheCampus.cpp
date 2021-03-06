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

/* B???n s??? t??nh kho???ng c??ch c???a t???t c??? c??c c???p t??a nh??, tr??? nh???ng t??a nh?? n??o ???? c?? k???t n???i r???i th?? b???n ?????t chi ph?? k???t n???i l?? 00.

Sau khi ???? t??nh xong th?? b???n b??? to??n b??? c??c c???p k???t n???i v?? chi ph?? ???? v??o graph r???i ch???y thu???t to??n Prim.

C??y khung nh??? nh???t l?? k???t qu??? t??m ???????c.

????? ph???c t???p: O(T * N^2 * logN)O(T???N
???2
?????? ???logN) v???i TT l?? s??? l?????ng b??? test v?? O(N^2 * logN)O(N
???2
?????? ???logN) l?? ????? ph???c t???p c???a thu???t to??n Prim v?? trong b??i n??y ta d??ng t???t c??? c???nh n???i gi???a c??c t??a nh?? n??n s??? l?????ng c???nh l?? N^2N
???2
?????? . */