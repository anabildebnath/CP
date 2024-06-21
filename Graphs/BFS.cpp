#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long vertices, edges;
    cin >> vertices >> edges;

    // Adjacency List
    vector<vector<int> > list(N);
    vector<bool> visited(N, false);

    // Read edges
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        list[x].push_back(y);
        list[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << endl;

        for (int i = 0; i < list[node].size(); i++)
        {
            int neighbor = list[node][i];
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
