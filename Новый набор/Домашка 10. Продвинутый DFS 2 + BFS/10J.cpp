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
vector<vector<int>> d;
vector<vector<int>> p;
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    set<tuple<int,int,int>> bad;
    g.resize(n);
    d.resize(n,vector<int>(n,INF));
    p.resize(n,vector<int>(n,-1));
    forn(i,m)
    {
        int v, u;
        cin >> v >> u;
        --v,--u;
        g[v].pb(u);
        g[u].pb(v);
    }
    forn(i,k)
    {
        int f,s,t;
        cin >> f >> s >> t;
        --f,--s,--t;
        bad.insert({f,s,t});
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    d[0][0] = 0;
    pair<int,int>finish = {-1,-1};
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int v = t.first;
        int pr = t.second;
        //cout << v << ' ' << pr << endl;
        if (v == n - 1)
        {
            finish = t;
            break;
        }
        for (int u : g[v])
        {
            if (bad.count({pr,v,u})) continue;
            if (d[u][v] > d[v][pr] + 1)
            {
                d[u][v] = d[v][pr] + 1;
                p[u][v] = pr;
                q.push({u,v});
            }
        }
    }
    if (finish.first == -1)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> res;
    while (p[finish.first][finish.second] != -1)
    {
        res.pb(finish.first);
        finish ={finish.second, p[finish.first][finish.second]};
    }
    reverse(all(res));
    cout << res.size() << '\n';
    cout << 1 << ' ';
    for (int v : res) cout << v + 1 << ' ';
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

