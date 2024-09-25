#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
using namespace std;


int n;
int e;
vector<char> s3;
set<char> s4;

bool compare(pair<char, int> a, pair<char, int> b) {
    return a.second < b.second;
}

bool KiemTraDiemCuoi(int n, vector<vector<int>>& DoThi, int i1) {
    for (int i = 0; i < n; i++) {
        if (DoThi[i1][i] != 0) {
            return true;
        }
    }
    return false;
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

void input1(int n, int e, map<char, int>& Dinh, vector<vector<int>>& DoThi) {
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

vector<int> bfs(vector<vector<int>>& DoThi, map<char, int>& Dinh, char s1, char s2, int n) {
    int i1 = Dinh[s1];
    int i2 = Dinh[s2];
    vector<int> path1;
    if (!KiemTraDiemCuoi(n, DoThi, i1)) {
        return {};
    }
    else {
        int count = 0;
        path1.push_back(i2);
        while (1) {
            count = TruyVet(DoThi, n, i2, i1);
            if (count == -1) {
                return {};
            }
            path1.push_back(count);
            if (count == i1) {
                break;
            }
            i2 = count;
        }
    }
    return path1;
}

void TimDuongDi(vector<vector<int>>& DoThi, map<char, int>& Dinh, int n, char s1, char s2) {
    vector<pair<char, int>> path(Dinh.begin(), Dinh.end());
    sort(path.begin(), path.end(), compare);
    cin >> s1 >> s2;
    vector<int> DuongDi = bfs(DoThi, Dinh, s1, s2, n);
    if (DuongDi.empty()) {
        cout << "no_path" << endl;
    }
    else {
        reverse(DuongDi.begin(), DuongDi.end());
        for (int i : DuongDi) {
            cout << path[i].first << " ";
        }
        cout << endl;
    }
}





int KiemTra(stack<char> test, char s) {
    while (test.size()) {
        if (test.top() == s)
        {
            return 1;
        }
        test.pop();
    }
    return 0;
}


void TimDuongDiBangDFS(vector<vector<int>> DoThi, map<char, int> Dinh, char s1, char s2, map<char, vector<char>>canh, const int n)
{
    stack<char> open;
    open.push(s1);
    bool close[n] = { false };
    if (s4.find(s1) != s4.end())
    {
        while (!open.empty())
        {
            char xet = open.top(); open.pop();
            cout << xet << " ";
            close[Dinh[xet]] = true;
            if (DoThi[Dinh[xet]][Dinh[s2]] != 0)
            {
                cout << s2 << " ";
                break;
            }
            for (auto i : canh[xet])
            {
                if ((close[Dinh[i]] == false) && (KiemTra(open, i)) == 0 && Dinh.find(i) != Dinh.end())
                {
                    open.push(i);
                }
            }
        }
    }
    else
    {
        cout << "no_path";
    }

}


int main() {
    srand(unsigned(time(NULL)));
    int z = rand() % 2 + 1;
    if (z == 1) {
        int n, e, m;
        cin >> n >> e;
        vector<vector<int>> DoThi(n, vector<int>(n, 0));
        map<char, int> Dinh;
        map<char, vector<char>> canh;
        for (int i = 0; i < n; i++) {
            char s;
            cin >> s;
            s3.push_back(s);
            Dinh[s] = i;
        }
        for (int i = 0; i < e; i++) {
            char s, t;
            cin >> s >> t;
            DoThi[Dinh[s]][Dinh[t]] = 1;
            s4.insert(s);
            canh[s].push_back(t);
        }
        cin >> m;

        for (int i = 0; i < m; i++) {
            char start, end;
            cin >> start >> end;
            TimDuongDiBangDFS(DoThi, Dinh, start, end, canh, n);
            cout << "\n";
        }
    }
    else {
        cin >> n;
        cin >> e;
        vector<vector<int>> DoThi(n, vector<int>(n, 0));
        map<char, int> Dinh;
        input1(n, e, Dinh, DoThi);
        int m;
        char s1, s2;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> s1 >> s2;
            TimDuongDi(DoThi, Dinh, n, s1, s2);
        }
    }
    return 0;
}