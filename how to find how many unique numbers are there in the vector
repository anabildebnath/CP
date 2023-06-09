#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {

        long long n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long uniq = 0;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            while (i < n - 1 && v[i] == v[i + 1])
            {
                i++;
                flag = true;
            }
            if (flag)
            {
                flag = false;
                continue;
            }
            uniq++;
        }
        cout << uniq << endl;
    }
}
