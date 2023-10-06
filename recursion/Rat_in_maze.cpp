#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }

    return false;
}

void findPath(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // 4 choices - D L R U;

    // down
    int newx = x + 1;
    int newy = y;

    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('D');
        findPath(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y - 1;

    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('L');
        findPath(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // right
    newx = x;
    newy = y + 1;

    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('R');
        findPath(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // up
    newx = x - 1;
    newy = y;

    if (isSafe(newx, newy, n, visited, m))
    {
        path.push_back('U');
        findPath(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

void print(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    vector<string> ans;
    vector<vector<int>> visited = m;

    int n = 4;
    int x = 0;
    int y = 0;

    // initialise with zero
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string path = "";
    findPath(m, n, ans, x, y, visited, path);
    sort(ans.begin(), ans.end());
    print(ans);
    return 0;
}