#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> Vii;
const int MAX = 28;
const int INF = 1e9;
struct Place;
vector<Place> res;
vector<Vii> graphY(MAX), graphM(MAX);
vector<int> distY(MAX), distM(MAX);

struct sortWay
{
    bool operator()(const ii &a, const ii &b)
    {
        return a.second > b.second;
    }
};

struct Place
{
    int id, cost;
    bool operator<(const Place &other) const
    {
        return cost < other.cost || (cost == other.cost && id < other.id);
    }
};

void dijkstra(int s, vector<int> &dist, vector<Vii> &graph)
{
    priority_queue<ii, Vii, sortWay> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        if (dist[u] != w)
        {
            continue;
        }
        for (auto &v : graph[u])
        {
            if (dist[v.first] > v.second + w)
            {
                dist[v.first] = v.second + w;
                pq.push(make_pair(v.first, dist[v.first]));
            }
        }
    }
}

int main()
{
    int n, c;
    char age, dir, x, y;
    while (cin >> n, n != 0)
    {
        for (int i = 0; i < MAX; i++)
        {
            distY[i] = INF;
            distM[i] = INF;
            graphY[i].clear();
            graphM[i].clear();
        }

        for (int i = 0; i < n; i++)
        {
            cin >> age >> dir >> x >> y >> c;
            int u = x - 'A';
            int v = y - 'A';
            if (age == 'Y')
            {
                graphY[u].push_back(make_pair(v, c));
                if (dir == 'B')
                {
                    graphY[v].push_back(make_pair(u, c));
                }
            }
            else
            {
                graphM[u].push_back(make_pair(v, c));
                if (dir == 'B')
                {
                    graphM[v].push_back(make_pair(u, c));
                }
            }
        }

        cin >> x >> y;
        int s = x - 'A';
        int d = y - 'A';
        dijkstra(s, distY, graphY);
        dijkstra(d, distM, graphM);

        res.clear();
        int minDist = INF;

        for (int i = 0; i < MAX; i++)
        {
            int dist1 = distY[i];
            int dist2 = distM[i];

            if (dist1 != INF && dist2 != INF && dist1 + dist2 <= minDist)
            {
                res.push_back({i, dist1 + dist2});
                minDist = dist1 + dist2;
            }
        }

        if (res.empty())
        {
            cout << "You will never meet.";
        }
        else
        {
            sort(res.begin(), res.end());
            cout << minDist;
            for (Place &place : res)
            {
                if (place.cost != minDist)
                {
                    break;
                }
                cout << " " << char(place.id + 'A');
            }
        }
        cout << endl;
    }
    return 0;
}