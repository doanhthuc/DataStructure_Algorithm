#include "bits/stdc++.h"
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> Vii;
int f[10011][2011];

int solve(vector<int> &a, vector<int> &t)
{
    int n = a.size();
    Vii v(n + 1);
    v[0].first = 0;
    v[0].second = 0;
    for (int i = 1; i <= n; i++)
    {
        v[i].first = t[i - 1];  // first: thời gian đợi
        v[i].second = a[i - 1]; // second: Giá trị đơn hàng
    }
    sort(v.begin(), v.end()); // Sắp xếp theo thời gian đợi

    // Thời gian đợi của khách có thể chờ lâu nhất
    int timeMax = v[n].first;

    for (int i = 0; i <= timeMax; i++)
    {
        f[0][i] = 0; // Tạo viền
    }
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= timeMax; j++)
        {
            if (j <= v[i].first)
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + v[i].second);
            }
            else
                f[i][j] = f[i][j - 1];
        }
    }

    return f[n][timeMax];
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    cout << solve(a, t) << endl;
    return 0;
}

/* ---------------------------------------------------------------------------------------------------- */
int groupGraduating(std::vector<int> groups)
{
    vector<int> dem(5, 0);
    for (int i = 0; i < groups.size(); i++)
        dem[groups[i]]++;
    if (dem[1] == 0 && dem[2] == 0)
        return 0;
    int sum = dem[1] + dem[2] * 2 + dem[3] * 3 + dem[4] * 4;
    int ans = -1;
    for (int y = 0; y <= sum; y += 4)
    {
        if ((sum - y) % 3 == 0)
        {
            int g4 = y / 4;
            int g3 = (sum - y) / 3;
            vector<int> tmp = dem;
            int pos = 0;
            int neg = 0;

            for (int i = 4; i > 0; i--)
            {
                int curr = min(g4, tmp[i]);
                g4 -= curr;
                tmp[i] -= curr;
                neg += curr * (4 - i);
                pos += abs(curr * (4 - i));
            }
            for (int i = 4; i > 0; i--)
            {
                int curr = min(g3, tmp[i]);
                g3 -= curr;
                tmp[i] -= curr;
                neg += curr * (3 - i);
                pos += abs(curr * (3 - i));
            }
            for (int i = 1; i <= 4; i++)
            {
                if (tmp[i] > 0)
                    neg += tmp[i] * (-i);
                pos += tmp[i] * i;
            }
            neg += g3 * 3 + g4 * 4;
            if (neg == 0)
                if (ans == -1)
                    ans = pos / 2;
                else
                    ans = min(ans, pos / 2);
        }
    }
    return ans;
}