#include <bits/stdc++.h>
#define mod 1000000007
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
int pd[1000006][65];
bool ok(int n, int a, int b)
{
    bool good = true;
    while (n && good)
    {
        if (n % 10 != a && n % 10 != b)
            good = false;
        n /= 10;
    }
    return good;
} 
void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    pd[1][a] = 1;
    pd[1][b] = 1;
    for (int i = 1; i <= n;++i)
        for (int suma = min(a, b); suma <= 64;++suma)
            if (suma < b)
                pd[i][suma] = (pd[i][suma] + pd[i - 1][suma - a]) % mod;
            else
                pd[i][suma] = (pd[i][suma] + pd[i - 1][suma - a] + pd[i - 1][suma - b]) % mod;
    int ans = 0;
    for (int i = 1; i <= 64;++i)
        if (ok(i, a, b))
            ans = (ans + pd[n][i]) % mod;
    cout << ans;
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