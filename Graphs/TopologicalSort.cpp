#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int> > list(vertices + 1);
    vector<int> indegree(vertices + 1, 0);

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        list[x].push_back(y);
        indegree[y]++;
    }
    queue<int> q;
    for(int i=1;i<=vertices;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<< node <<" ";
        for(int i=0;i<list[node].size();i++)
        {
            indegree[list[node][i]]--;
            if(indegree[list[node][i]]==0)
            {
                q.push(list[node][i]);
            }
        }
    }
}