#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;

const int maxn = 10000;

int n, m, s, t;
vector<pair<int, int>> adj[maxn];

void Nhap()
{
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++)
	{
		int x, y;//canh
		int w;//trong so
		cin >> x >> y >> w;
		adj[x].push_back({ y, w });
		//adj[y].push_back({ x, w }); khi vo huong
	}
}

int pre[maxn];
int const INF = 1e9;
void dijkstra(int s, int t)
{
	//mang luu khoang cach
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	pre[s] = s;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;//in ra min
	//{khoang cach, dinh}
	Q.push({ 0, s });
	while (!Q.empty())
	{
		//chon ra dinh co khoang cach s nho nhat
		pair<int, int>top  = Q.top();
		Q.pop();
		int u = top.second;
		int khoangcach = top.first;
		if (khoangcach > d[u]) continue;
		//relaxation : cap nhat khoang cach tu s den moi dinh ke u
		for (auto it : adj[u])
		{
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w)
				d[v] = d[u] + w;
			Q.push({ d[v], v });
			pre[v] = u;
		}
	}
	cout << d[t] << endl;
	vector<int> path;
	while (1)
	{
		path.push_back(t);
		if (t == s) break;
		t = pre[t];
	}
	reverse(path.begin(), path.end());
	for (int x : path)
	{
		cout << x << " ";
	}
}

int main()
{
	Nhap();
	dijkstra(s, t);
	return 0;
}




