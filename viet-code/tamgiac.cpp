#include <iostream>
using namespace std;

bool ktTamGiac(double a, double b, double c)
{
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
        return false;
    return true;
}

double chuvi(double a, double b, double c)
{
    return a + b + c;
}

double tim(int n, int arr[])
{
    double res = 0;
    double tmp;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (ktTamGiac(arr[i], arr[j], arr[k]))
                {
                    tmp = chuvi(arr[i], arr[j], arr[k]);
                    if (tmp > res)
                        res = tmp;
                }
            }
        }
    }
    return res;
}

int main()
{
    int arr[101];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << tim(n, arr);

    return 0;
}