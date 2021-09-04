#include <bits/stdc++.h>
using namespace std;

#define MAX 50
#define INF 1e9
typedef pair<int, int> pii;
typedef long long int lli;

int n;
int s, c, e;
int event[MAX][MAX];
int ans[MAX];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(event, 0, sizeof(event));
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; i++)
        {
            cin >> s >> e >> c;
            event[s][e] = max(event[s][e], c);
        }
        for (int k = 0; k <= 48; k++)
        {
            for (int i = 0; i < k; i++)
            {
                ans[k] = max(ans[k], event[i][k] + ans[i]);
            }
        }
        cout << ans[48] << endl;
    }
    return 0;
}