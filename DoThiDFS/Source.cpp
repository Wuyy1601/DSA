#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int n;//so dinh
int e;//so canh
bool visited[100];
vector<int> parent;


bool compare(pair<char, int> a, pair<char, int> b) {
    return a.second < b.second;
}

void input(int n, int e, map<char, int>& Dinh, vector<vector<int>>& DoThi) {
    char temp;
    int i = 0;
    while (n--) {
        cin >> temp;
        Dinh[temp] = i;
        i++;
    }
    char s1, s2;
    int i1, i2;
    for (int i = 0; i < e; i++) {
        cin >> s1 >> s2;
        i1 = Dinh[s1];
        i2 = Dinh[s2];
        DoThi[i1][i2] = 1;
    }
}
int TruyVet(vector<vector<int>>& DoThi, int n, int i1, int i2) {
    if (DoThi[i2][i1]) {
        return i2;
    }
    for (int i = n - 1; i > -1; i--) {
        if (DoThi[i][i1]) {
            DoThi[i][i1] = 0;
            return i;
        }
    }
    return -1;
}

void dfs(int n, map<char, int>& Dinh, vector<vector<int>>& DoThi, char s1)
{
    int i1 = Dinh[s1];
    visited[i1] = true;
    map<char, int> it;
    for (const auto& it : DoThi[i1])
    {
        if (!visited[it])
        {
            parent[it] = i1;
            char s3 = Dinh[it];
            dfs(n,Dinh,DoThi,s3);
        }
    }
}

void TimDuongDi(int n, map<char, int>& Dinh, vector<vector<int>>& DoThi, char s1, char s2)
{
    int i1 = Dinh[s1];
    int i2 = Dinh[s2];
    memset(visited, false, sizeof(visited));
    dfs(n, Dinh, DoThi, s1);
    if (!visited[s2])
    {
        cout << "no_path" << endl;
    }
    else
    {
        //truy vet
        vector<int>path;
        while (i2 != i1)
        {
            path.push_back(i2);
            i2 = parent[i2];
        }
        path.push_back(i1);
        reverse(path.begin(), path.end());
        vector<pair<char, int>> path1(Dinh.begin(), Dinh.end());
        sort(path1.begin(), path1.end(), compare);
        for (int x : path)
        {
            cout << path1[x].first << " ";
        }
        cout << endl;
    }

}

int main()
{
    cin >> n;
    cin >> e;
    vector<vector<int>> DoThi(n, vector<int>(n, 0));
    map<char, int> Dinh;
    input(n, e, Dinh, DoThi);
    int m;
    char s1, s2;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s1 >> s2;
        TimDuongDi(n, Dinh, DoThi, s1, s2);
    }
	return 0;
}