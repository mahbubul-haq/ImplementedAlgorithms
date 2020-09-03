#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <set>
#include <complex>
#include <map>
#include <unordered_map>
#include <climits>
#include <bitset>
#include <queue>
#include <chrono>
#include <random>
#include <typeinfo>
#include <stack>
#include <list>
using namespace std;

#define all(v)                      v.begin(), v.end()
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define eb                          emplace_back
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt", "r", stdin)
#define FO                          freopen("out.txt", "w", stdout)
#define ff                          first
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x, y, sizeof x)
#define mp                          make_pair
#define msi                         map<string, int>
#define mii                         map<int, int>
#define mis                         map<int, string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int, bool>
#define pii                         pair<int, int>
#define pll                         pair<ll, ll>
#define present(c, x)               ((c).find(x) != (c).end())
#define sfi(x)                      scanf("%d", &x)
#define sfii(x,y)                   scanf("%d %d", &x, &y)
#define sfiii(x,y,z)                scanf("%d %d %d", &x, &y, &z)
#define siz(x)                      (int)x.size()
#define ss                          second
#define sRand                       srand(chrono::steady_clock::now().time_since_epoch().count())
#define timeTaken                   endd = clock(); cout << (double) (endd - beginn) / CLOCKS_PER_SEC * 1000 << endl
#define timeInit                    clock_t beginn = clock(), endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string, int>
#define umii                        unordered_map<int, int>
#define umis                        unordered_map<int, string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vvll                        vector<vll>
#define vpll                        vector<pll>
#define bug(...)                    cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << " : (" << #__VA_ARGS__ << ") = ("; _Print(__VA_ARGS__);
template<class T> void _Print(T &&x) { cerr << x << ")" << endl; }
template<class T, class ...S> void _Print(T &&x, S &&...y) { cerr << x << ", "; _Print(y...); }

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k - 1): returns kth smallest element's iterator
*/

template<class T> class compare {
public:
    bool operator() (pair<T, T> &x, pair<T, T> &y) {
        if (x.first == y.first) {
            return x.ss > y.ss;
        }
        return x.ff > y.ff;
    }
};

template<class T> ostream &operator<<(ostream &os, const pair<T, T> &a) { return os << a.ff << " " << a.ss; }
ll power(ll a, int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}

template<class T> pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff + b.ff, a.ss + b.ss}; }
template<class T> pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff - b.ff, a.ss - b.ss}; }
template<class T> pair<T, T> operator*(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff * b.ff, a.ss * b.ss}; }
template<class T> pair<T, T> operator%(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff % b.ff, a.ss % b.ss}; }
template<class T, class U> pair<T, T> operator+(const pair<T, T> &a, const U &b) { return {a.ff + b, a.ss + b}; }
template<class T, class U> pair<T, T> operator*(const pair<T, T> &a, const U &b) { return {a.ff * b, a.ss * b}; }

int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(int N, int pos){ return (bool) (N & (1 << pos)); }

///=======================================template=======================================///

const int inf = 1000000000;
vvii g;
vvi dist;
vi dst;
int n, m;

bool BellmanFord() {
    dst.assign(n + 1, inf);
    dst[0] = 0;

    for (int i = 1; i <= n; i++) {
        bool flag = false;

        for (int j = 0; j <= n; j++) {
            for (auto &v : g[j]) {
                if (dst[j] != inf and dst[v.ff] > dst[j] + v.ss) {
                    flag = true;
                    dst[v.ff] = dst[j] + v.ss;
                }
            }
        }
        if (!flag)
            return true;
    }

    for (int j = 0; j <= n; j++) {
        for (auto &v : g[j]) {
            if (dst[j] != inf and dst[v.ff] > dst[j] + v.ss) {
                bug(j, v.ff, dst[j], v.ss);
                return false;
            }
        }
    }

    return true;
}

void Dijkstra(int s) {
    PQ<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});///{distance, vertex}

    while(!pq.empty()) {
        auto u = pq.top(); pq.pop();
        if (dist[s][u.ss] == u.ff) {
            for (auto &v : g[u.ss]) {
                if (dist[s][u.ss] + v.ss < dist[s][v.ff]) {
                    dist[s][v.ff] = dist[s][u.ss] + v.ss;
                    pq.push({dist[s][v.ff], v.ff});
                }
            }
        }
    }
}

void JohnsonAPSP() {
    for (int i = 1; i <= n; i++) {
        g[0].eb(i, 0);
    }

    if (BellmanFord()) {
        for (int i = 1; i <= n; i++) {
            for (auto &v : g[i]) {
                v.ss = v.ss + dst[i] - dst[v.ff];
            }
        }

        for (int i = 1; i <= n; i++) {
            Dijkstra(i);
            for (int j = 1; j <= n; j++) {
                dist[i][j] = dist[i][j] + dst[j] - dst[i];///this is the final distance from i to j
            }
        }
    }
    else cout <<"Negative Cycle" << endl;
}

int main() {
    FastIO;
    FI;

    cin >> n >> m;

    g.assign(n + 1, vii());
    dist.assign(n + 1, vi(n + 1, inf));
    for (int i = 0; i <= n;  i++)
        dist[i][i] = 0;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    JohnsonAPSP();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
