#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<long long, long long>> p;

    for (int i = 0; i < 10; i++)
    {
        long long x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    
    //you can take input in a more efficient way
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first;
        p[i].second=i;
    }
    
    //for printing 
    for(int i=0;i<n;i++)
    {
       cout<<p[i].first<<" "<<p[i].second;
    }

    sort(p.begin(), p.end()); // this sorts the pair in increasing order with the prespective of the first element

    
}
