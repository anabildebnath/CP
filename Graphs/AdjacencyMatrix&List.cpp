#include <vector>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;

    vector<vector<int> > matrix(n + 1, vector<int>(n + 1, 0));
    vector<vector<int> > list(n + 1);

    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
        list[x].push_back(y);
        list[y].push_back(x);
    }

    // Print adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Print adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < list[i].size(); j++)
        {
            cout << list[i][j] << " ";
        }
        cout << endl;
    }
}
