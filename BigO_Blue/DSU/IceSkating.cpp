#include "bits/stdc++.h"

using namespace std;
//src: Codeforces
typedef pair<int, int> ii;
const int MAX = 111 * 111;
vector<int> parent(MAX), ranks(MAX);

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int find(int u)
{
    if (u != parent[u])
    {
        parent[u] = find(u);
    }
    return parent[u];
}

void unionSet(int u, int v)
{
    int up = find(u);
    int vp = find(v);
    if (up != vp)
    {
        if (ranks[vp] > ranks[up])
        {
            parent[up] = vp;
        }
        else
        {
            parent[vp] = up;
            if (ranks[up] == ranks[vp])
            {
                ranks[up]++;
            }
        }
    }
}

bool isSameSet(const ii &p1, const ii &p2)
{
    return p1.first == p2.first || p1.second == p2.second;
}

int main()
{
    int n;
    cin >> n;
    vector<ii> points(n);
    makeSet(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
        for (int j = 0; j < i; j++)
        {
            if (isSameSet(points[i], points[j]))
            {
                unionSet(i, j);
            }
        }
    }

    int nGroups = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
        {
            nGroups++;
        }
    }
    cout << nGroups - 1 << endl;
    return 0;
}

/* Ta thấy rằng nếu hai snow drift A và B có cùng tọa độ x hoặc y thì Bajtek có thể trượt trực tiếp mà không cần đắp thêm drift phụ nào. Và nếu từ A đến được B và B đến được C theo cách như trên thì từ A ta cũng có thể đến C mà không cần thêm drift.

Như vậy nếu ta xem mỗi nhóm là tập hợp các snow drift mà ta có thể trượt trực tiếp đến nhau, thì số snow drift phụ mà ta cần đắp chính bằng số nhóm trừ 1. Lúc này ta có thể sử dụng DSU để giải quyết bài toán.

Độ phức tạp: O(N*M)O(N∗M) trong trường hợp sử dụng DSU cơ bản, nếu sử dụng DSU nâng cao (update by rank, path compression, by size) thì sẽ là O(M*logN)O(M∗logN) với NN là số điểm trong dữ liệu đầu vào và MM là số các kết nối tạo được giữa các điểm (tức tối đa M = N*(N - 1)/2M=N∗(N−1)/2). */