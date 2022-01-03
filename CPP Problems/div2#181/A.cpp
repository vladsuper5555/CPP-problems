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
void solve ()
{
    vector <int> v1, v2, v3;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 0)
            v3.push_back(a);
        else if (a > 0)
            v1.push_back(a);
        else
            v2.push_back(a);
    }
    if (v1.size() == 0)
    {
        v1.push_back(v2.back());
        v2.pop_back();
        v1.push_back(v2.back());
        v2.pop_back();
    }
    if (v2.size() % 2 == 0)
    {
        v3.push_back(v2.back());
        v2.pop_back();
    }
    cout << v2.size() << ' ';
    for (auto i : v2)
        cout << i << ' ';
    cout << '\n';
    cout << v1.size() << ' ';
    for (auto i:v1)
        cout << i << ' ';
    cout << '\n';
    cout << v3.size() << ' ';
    for (auto i:v3)
        cout << i << ' ';
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
