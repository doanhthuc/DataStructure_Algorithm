#include "bits/stdc++.h"
using namespace std;

/* Bài 3: https://vnoi.info/wiki/algo/data-structures/deque-min-max.md */
// -------- CHUA LAM XONG ---------
list<int> dq;
vector<vector<int>> G;
int n;
int height[1011], lowL[1011], lowR[1011], highL[1011], highR[1011];

// lowL[k]: Xa nhất về phía bên trái nhận height[k] là max
void buildLowL()
{
    dq.clear();
    for (int k = 1; k <= n; k++)
    {
        while (dq.size() && height[dq.front()] <= height[k])
            dq.pop_front();
        if (dq.size())
            lowL[k] = dq.front() + 1;
        else
            lowL[k] = k;
        dq.push_front(k);
    }
}

// lowR[k]: xa nhất về phía bên phải nhận height[k] là max
void buildLowR()
{
    dq.clear();
    for (int k = n; k >= 1; k--)
    {
        while (dq.size() && height[dq.front()] <= height[k])
            dq.pop_front();
        if (dq.size())
            lowR[k] = dq.front() - 1;
        else
            lowR[k] = k;
        dq.push_front(k);
    }
}

// heightL[k]: Xa nhất về phía bên trái nhận height[k] là min
void buildHighL()
{
    dq.clear();
    for (int k = 1; k <= n; k++)
    {
        while (dq.size() && height[dq.front()] >= height[k])
            dq.pop_front();
        if (dq.size())
            highL[k] = dq.front() + 1;
        else
            highL[k] = k;
        dq.push_front(k);
    }
}

//heightR[k]: Xa nhất về phía bên phải nhận height[k]
void buildHighR()
{
    dq.clear();
    for (int k = n; k >= 1; k--)
    {
        while (dq.size() && height[dq.front()] >= height[k])
            dq.pop_front();
        if (dq.size())
            highR[k] = dq.front() - 1;
        else
            highR[k] = k;
        dq.push_front(k);
    }
}

int main()
{
    // Xay dung do thi
    G[0].push_back(0);
    for (int i = 1; i <= n; i++)
        G[i].push_back(i + 1);
    for (int k = 1; k <= n; k++)
    {
        if (height[k] < min(height[lowL[k] - 1], height[lowR[k] + 1]))
        {
            G[lowL[k] - 1].push_back(lowR[k] + 1);
        }
    }
    for (int k = 1; k <= n; k++)
    {
        if (height[k] > max(highL[k] - 1, highR[k] + 1))
        {
            G[highL[k] - 1].push_back(highR[k] + 1);
        }
    }
    bool visitted[n + 1];
    memset(visitted, false, sizeof(visitted));
    list<int> queue;
    int s = 1;
    visitted[1] = true;
    queue.push_back(1);

    list<int>::iterator i;
    while (!queue.empty())
    {
        s = queue.front();
    }
    return 0;
}
