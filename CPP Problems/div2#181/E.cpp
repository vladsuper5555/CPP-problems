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
