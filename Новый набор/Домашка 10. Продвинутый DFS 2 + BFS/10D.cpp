#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int i = 0; i < (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i < (int)r; ++i
#define forit(it,a) for(auto it = a.begin(); it != a.end(); it++)
#define endl '\n'
#define Okaay ios_base::sync_with_stdio(0)
#define letsGo cin.tie(NULL)
#define pb push_back

typedef unsigned long long ll;
typedef long double ld;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> nRandom(1,10);
uniform_int_distribution<int> mRandom(1000,10000);

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int mod = 1e9 + 7;
const int INF = 1e9 + 1;
const ld eps = 1e-9;
const ld PI = acos(-1.0);

vector<vector<int>> g;
map<pair<int,int>, int> edg;
vector<ll> d;
vector<int> res;
vector<int> used;
ll curr = 1;
ll k;
void ans(int v, ll p = 1)
{
    //cout << "v " << v + 1 << endl;
    //cout << "path: \n";
    //for (int x : res) cout << x + 1<< ' ';
    //cout << endl;
    for (int u : g[v])
    {
        //cout << "second. u " << u + 1 << " cur " << curr << endl;
        int cnt = edg[{v,u}];
        if (curr < k && curr + p * cnt * d[u] >= k)
        {
            res.pb(u);
            if (curr + p * cnt >= k) return;
            curr += p * cnt;
            ans(u, p * cnt);
            return;
        }
        curr += p * cnt * d[u];
    }
}
void dfs(int v)
{
    used[v] = 1;
    d[v] = 1;
    for (int u: g[v])
    {
        if (!used[u]) dfs(u);
        d[v] += edg[{v,u}] * d[u];
    }

}
void solve()
{
    int n, m;
    cin >> n >> m >> k;
    g.clear(); d.clear(); used.clear();
    curr = 1; edg.clear(); res.clear();
    g.resize(n); d.resize(n,0); used.resize(n,0);
    forn(i, m)
    {
        int v, u;
        cin >> v >> u;
        --v, --u;
        edg[{v,u}]++;
        if(edg[{v,u}] == 1)
            g[v].pb(u);
    }
    forn(i,n) sort(all(g[i]));
    dfs(0);
    //forn(i,n) cout << "i : " << i + 1 << " d[i]: " << d[i] << '\n';
    res.pb(0);
    ans(0);
    for (int v : res) cout << v + 1 << ' ';
    cout << endl;
    //cout << "cur " << curr << endl;
}

int main()
{
    Okaay; letsGo;
    startTime = clock();
    cout.tie(NULL);
    cout << setprecision(20) << fixed;
    int T;
    T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
}

