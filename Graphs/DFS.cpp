#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5 + 1;
vector<vector<int> > list(N);
vector<bool> visited(N, false);

void dfs(int node)
{
    // preorder
    visited[node] = true;
    cout << node << " ";

    // inorder
    for (int i = 0; i < list[node].size(); i++)
    {
        int neighbor = list[node][i];
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }

    // postorder
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vertices, edges;
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        list[x].push_back(y);
        list[y].push_back(x);
    }

    // Start DFS from node 1
    dfs(1);

    return 0;
}
