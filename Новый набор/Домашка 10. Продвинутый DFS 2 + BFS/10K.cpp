#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include <queue>
#include <array>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int i = 0; i < (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i < (int)r; ++i
#define forit(it,a) for(auto it = a.begin(); it != a.end(); it++)
#define endl '\n'
#define Okaay ios_base::sync_with_stdio(0)
#define letsGo cin.tie(NULL)
#define pb push_back

typedef long long ll;
typedef long double ld;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> nRandom(1, 10);
uniform_int_distribution<int> mRandom(1000, 10000);

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int mod = 998244353;
const int INF = 2 * 1e9 + 1;
const ld eps = 1e-9;
const ld PI = acos(-1.0);

vector<vector<char>> g;
vector<vector<int>> d;
void solve()
{
    int n, m, r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;
    --r, --c;
    g.resize(n, vector<char>(m));
    d.resize(n, vector<int>(m, INF));
    forn(i, n)
    {
        forn(j, m)
        {
            cin >> g[i][j];
        }
    }
    d[r][c] = 0;
    deque<array<int, 4>> q;
    q.push_front({ r,c,0,0 });
    int ans = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop_front();
        int i = t[0], j = t[1], lf = t[2], rg = t[3];
        if (g[i][j] == '.') ++ans;
        g[i][j] = '+';
        if (i + 1 < n && d[i + 1][j] > d[i][j] && g[i + 1][j] != '*')
        {
            q.push_front({ i + 1, j, lf, rg });
            d[i + 1][j] = d[i][j];
        }
        if (i - 1 >= 0 && d[i - 1][j] > d[i][j] && g[i - 1][j] != '*')
        {
            q.push_front({ i - 1, j, lf, rg });
            d[i - 1][j] = d[i][j];
        }
        if (j + 1 < m && d[i][j + 1] > d[i][j] + 1 && rg + 1 <= y && g[i][j + 1] != '*')
        {
            q.push_back({ i, j + 1, lf, rg + 1 });
            d[i][j + 1] = d[i][j] + 1;
        }
        if (j - 1 >= 0 && d[i][j - 1] > d[i][j] + 1 && lf + 1 <= x && g[i][j - 1] != '*')
        {
            q.push_back({ i, j - 1, lf + 1, rg });
            d[i][j - 1] = d[i][j] + 1;
        }
    }
    cout << ans << endl;

    /*forn(i,n)
    {
        forn(j,m) cout << g[i][j];
        cout << endl;
    }*/

}


int main()
{
    Okaay; letsGo;
    startTime = clock();
    cout.tie(NULL);
    int T;
    T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
}

