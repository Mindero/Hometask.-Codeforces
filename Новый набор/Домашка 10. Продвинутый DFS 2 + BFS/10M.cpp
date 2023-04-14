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
int add(int x, int y) {return (x + y) % mod;};
int mult(int x, int y){ return (x * 1ll * y) % mod;};

vector<pair<int,int>> mv = {{1,0},{-1,0},{0,1},{0,-1}};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n,vector<char>(m));
    forn(i,n)
        forn(j,m) cin >> g[i][j];
    int k;
    cin >> k;
    map<pair<int,int>,int> numb;
    vector<vector<int>> d(n,vector<int>(m,INF));
    vector<vector<vector<pair<int,int>>>> last(n, vector<vector<pair<int,int>>>(m));
    queue<pair<pair<int,int>,pair<int,int>>> q;
    forn(i,k)
    {
        int row, col;
        cin >> row >> col;
        --row, --col;
        q.push({{row,col}, {row,col}});
        d[row][col] = 0;
        numb[{row,col}] = i + 1;
    }
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        pair<int,int> now = t.first, pr = t.second;
        int row = now.first, col = now.second;
        if (g[row][col] == '*')
        {
            int mn = k;
            for (auto x : last[row][col])
            {
                mn = min(mn, numb[{x.first,x.second}]);
            }
            cout << mn << endl;
            return;
        }
        forn(i, 4)
        {
            int row1 = row + mv[i].first;
            int col1 = col + mv[i].second;
            if (row1 >= 0 && row1 < n && col1 >= 0 && col1 < m && g[row1][col1] != '1')
            {
                if(d[row1][col1] == d[row][col] + 1) last[row1][col1].pb(pr);
                else if(d[row1][col1] > d[row][col] + 1)
                {
                    last[row1][col1].clear();
                    last[row1][col1].pb(pr);
                    d[row1][col1] = d[row][col] + 1;
                    q.push({{row1,col1}, pr});
                }
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    //Okaay; letsGo;
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

