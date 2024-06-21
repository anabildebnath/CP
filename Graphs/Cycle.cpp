#include <iostream>
#include <vector>
using namespace std;

int vertices, edges;
vector<vector<int> > list;
vector<bool> visited;
vector<bool> stack;

// undirected
bool undirecteCycle(int index, int parent)
{
    visited[index] = true;
    for (int i = 0; i < list[index].size(); i++)
    {
        int neighbor = list[index][i];
        if (!visited[neighbor])
        {
            if (undirecteCycle(neighbor, index))
            {
                return true;
            }
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }
    return false;
}

// directed
bool directedCycle(int node)
{
    if (!visited[node])
    {
        visited[node] = true;
        stack[node] = true;

        for (int i = 0; i < list[node].size(); i++)
        {
            int neighbor = list[node][i];
            if (!visited[neighbor] && directedCycle(neighbor))
            {
                return true;
            }
            else if (stack[neighbor])
            {
                return true;
            }
        }
    }
    stack[node] = false;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vertices >> edges;

    list.resize(vertices + 1);
    visited.resize(vertices + 1, false);
    stack.resize(vertices + 1, false);

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        list[x].push_back(y);
        // list[y].push_back(x);
    }

    bool isCycle = false;

    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i] && directedCycle(i))
        {
            isCycle = true;
            break;
        }
    }

    if (isCycle)
    {
        cout << "cycle exists" << endl;
    }
    else
    {
        cout << "cycle doesn't exist" << endl;
    }

    return 0;
}
