#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
// https://www.youtube.com/watch?v=t5GDacP_2pQ
using namespace std;
ifstream in ("film.in");
ofstream out ("film.out");
int pow (int a, int b)
{
    int rez = 1;
    while (b)
    {
        if (b&1)
            rez = (rez * a) % mod;
        a = (a * a) % mod;
        b>>=1;
    }
    return rez;
}
vector<int> v[1000];
int viz[1001];
vector<int> dfs (int start)
{
    vector<int> ans;
    queue<int> q;
    q.push(start);
    viz[start] = 1;
    ans.push_back(start);
    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        for (auto vecin:v[nod])
            if (viz[vecin] == 0)
            {
                viz[vecin] = 1;
                q.push(vecin);
                ans.push_back(vecin);
            }
    }
    return ans;
}
void solve ()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m;++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    map <int, vector<vector<int> > > fr;
    bool ok = 1;
    for (int i = 1; i <= n;++i)
        if (!viz[i])
        {
            vector<int> k = dfs(i);
            if (k.size() > 3)
                ok = 0;
            else
                fr[k.size()].push_back(k);
        }
    if (ok == 0 || fr[1].size() < fr[2].size() || (fr[1].size() - fr[2].size()) % 3 != 0)
        cout << -1;
    else
    {
        for (int i = 0; i < fr[2].size();++i)
        {
            for (auto val: fr[1][i])
                cout << val << ' ';
            for (auto val: fr[2][i])
                cout << val << ' ';
            cout << '\n';
        }
        for (int i = fr[2].size();i<fr[1].size(); i += 3)
            cout << fr[1][i][0] << ' ' << fr[1][i + 1][0] << ' ' << fr[1][i + 2][0] << '\n';
        for (auto vv : fr[3])
            for (auto val : vv)
                cout << val << ' ';
        cout << '\n';
    }
    for (int i = 1; i <= 1000;++i)
        viz[i] = 1;
    for (int i = 1; i <= 1000;++i)
        v[i].clear();
    return;
}
main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}
