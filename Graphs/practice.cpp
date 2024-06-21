// #include <vector>
// #include <iostream>
// using namespace std;

// const int N = 1e5 + 1;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     long long vertices, edges;
//     cin >> vertices >> edges;
//     vector<pair<int, int>> connections;
//     int mx = 0;
//     for (int i = 0; i < edges; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         connections.push_back(make_pair(x, y));
//         mx = max(mx, max(x, y));
//     }

//     vector<vector<int>> matrix(mx + 1, vector<int>(mx + 1, 0));
//     vector<vector<int>> list(mx + 1);

//     for (int i = 0; i < edges; i++)
//     {
//         int x = connections[i].first;
//         int y = connections[i].second;

//         matrix[x][y] = 1;
//         matrix[y][x] = 1;
//         list[x].push_back(y);
//         list[y].push_back(x);
//     }

//     for (int i = 1; i <= mx; i++)
//     {
//         for (int j = 1; j <= mx; j++)
//         {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
//     for (int i = 1; i <= mx; i++)
//     {
//         if (list[i].size())
//         {
//             cout << i << ":-> ";
//             for (int j = 0; j < list[i].size(); j++)
//             {
//                 cout << list[i][j] << " ";
//             }
//         }

//         cout << endl;
//     }
// }

// #include <vector>
// #include <iostream>
// using namespace std;
// vector<vector<int> > list(7 + 1);
// vector<bool> visited(7 + 1, false);

// void dfs(int node)
// {

//     // preorder
//     visited[node] = true;
//     cout << node << " ";

//     // inorder
//     for (int i = 0; i < list[node].size(); i++)
//     {
//         if (!visited[list[node][i]])
//         {
//             visited[list[node][i]] = true;

//             dfs(list[node][i]);
//         }
//     }

//     // postorder
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int vertices, edges;
//     cin >> vertices >> edges;

//     for (int i = 0; i < edges; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         list[x].push_back(y);
//         list[y].push_back(x);
//     }
//     dfs(1);
// }

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
    vector<bool> visited(vertices + 1, false);

    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        list[x].push_back(y);
        list[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    visited[1]=true;


    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
     
            for (int i = 0; i<list[node].size(); i++)
            {

                int neighbor = list[node][i];
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;  
            }
            }
     
      
    }
}