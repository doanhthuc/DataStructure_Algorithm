#include "bits/stdc++.h"
using namespace std;

struct obj
{
    int cost;
    int time;
};

void output(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

bool check(int k, vector<int> &kq)
{
    for (int i = k; i > 0; i--)
        if (kq[i] == -1)
        {
            kq[i] = k;
            return 1;
        }
    return 0;
}

bool cmp(obj a, obj b)
{
    return a.cost < b.cost;
}

void in(vector<obj> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i].cost << "   " << a[i].time << endl;
    }
}

int orderConsignment(vector<int> a, vector<int> t)
{

    int asize = a.size();
    obj tmp;
    vector<obj> v;

    for (int i = 0; i < asize; i++)
    {
        tmp.cost = a[i];
        tmp.time = t[i];
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);

    vector<int> kp(a.size() + 1, -1);
    // output(kp);

    int dem = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (check(v[i].time, kp) == true)
            dem += v[i].cost;
        output(kp);
    }

    return dem;
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
    obj tmp;
    vector<obj> v;

    for (int i = 0; i < n; i++)
    {
        tmp.cost = a[i];
        tmp.time = t[i];
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    in(v);
    cout << endl;
    cout << orderConsignment(a, t) << endl;
    return 0;
}