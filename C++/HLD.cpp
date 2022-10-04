// I also used my HLD to solve this problem (https://www.codechef.com/problems/CHEFTREE), which you can try as a challenge if you want. To my surprise, it ran rather quickly!

// You can use the above two problems as well as:

// Path Queries (CSES)
// QTREE (SPOJ): allows you to test modifications for edges
// GRASSPLA (SPOJ; original source is USACO but the judge doesn't work for that problem)
// GSS7 (SPOJ)
// QRYLAND (CodeChef)
// MONOPLOY (CodeChef)
// QUERY (CodeChef)
// BLWHTREE (CodeChef)
// Milk Visits (USACO)
// Max Flow (USACO)
// Exercise Route (USACO)

#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define vsz(x) ((long long) x.size())
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
 
// mt19937 rng(steady_clock::now().time_since_epoch().count());
mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

template<int size, int lg, typename seg_t = long long>
struct hld_max {
  vector<int> edges[size];
  int bigchild[size];
  int sz[size];
  int depth[size];
  int chain[size];
  int label[size], label_time;
  int par[size];

  int lca_lift[size][lg];

  seg_t seg_tree[4 * size];
  seg_t seg_lazy[4 * size];

  int N;

  /* ----------- segment tree ----------- */ 

  /* CHANGE THIS SECTION BY PROBLEM */
  inline seg_t seg_combine(seg_t a, seg_t b) {
    return max(a, b);
  }

  inline seg_t seg_lazy_apply(seg_t lazy_val, seg_t new_val) {
    return mp(lazy_val.f + new_val.f, new_val.s);
  }

  inline seg_t seg_lazy_func(seg_t cur_val, seg_t lazy_val, int l, int r) {
    if (cur_val.s == 222222) cur_val.s = lazy_val.s;
    return mp(cur_val.f + lazy_val.f, cur_val.s);
  }

  const seg_t seg_sentinel = mp(-923372036854775807LL, 77);
  const seg_t seg_lazy_sentinel = mp(0, 888);
  /* END SECTION */

  seg_t seg_query_header(int l, int r) {
    return seg_query_rec(0, 0, N - 1, l, r);
  }

  seg_t seg_query_rec(int i, int tl, int tr, int ql, int qr) {
    seg_eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return seg_tree[i];
    if (tl > tr || tr < ql || qr < tl) return seg_sentinel;

    int mid = (tl + tr) / 2;
    seg_t a = seg_query_rec(2 * i + 1, tl, mid, ql, qr);
    seg_t b = seg_query_rec(2 * i + 2, mid + 1, tr, ql, qr);
    return seg_combine(a, b);
  }

  void seg_update_header(int l, int r, seg_t v) {
    seg_update_rec(0, 0, N - 1, l, r, v);
  }

  seg_t seg_update_rec(int i, int tl, int tr, int ql, int qr, seg_t v) {
    seg_eval_lazy(i, tl, tr);
	
	  if (tl > tr || tr < ql || qr < tl) return seg_tree[i];
    if (ql <= tl && tr <= qr) {
      seg_lazy[i] = seg_lazy_apply(seg_lazy[i], v);
      seg_eval_lazy(i, tl, tr);
      return seg_tree[i];
    }
    if (tl == tr) return seg_tree[i];

    int mid = (tl + tr) / 2;
    seg_t a = seg_update_rec(2 * i + 1, tl, mid, ql, qr, v);
    seg_t b = seg_update_rec(2 * i + 2, mid + 1, tr, ql, qr, v);
    return seg_tree[i] = seg_combine(a, b);
  }

  void seg_eval_lazy(int i, int l, int r) {
    if (seg_lazy[i] == seg_lazy_sentinel) return;

    seg_tree[i] = seg_lazy_func(seg_tree[i], seg_lazy[i], l, r);

    if (l != r) {
      seg_lazy[i * 2 + 1] = seg_lazy_apply(seg_lazy[i * 2 + 1], seg_lazy[i]);
      seg_lazy[i * 2 + 2] = seg_lazy_apply(seg_lazy[i * 2 + 2], seg_lazy[i]);
    }

    seg_lazy[i] = seg_lazy_sentinel;
  }

  /* ----------- init phase 1 ----------- */
  /* initialize segtree, clear edges, etc. */

  void init_arrays(int n) {
    // everything not initialized doesn't need to be
    N = n;
    for (int i = 0; i < N; i++) {
      edges[i].clear();
      chain[i] = i;
    }

    for (int i = 0; i < 4 * N; i++) {
      seg_tree[i] = mp(0LL, 222222);
      seg_lazy[i] = seg_lazy_sentinel;
    }
  }

  /* ----------- init phase 2 ----------- */
  /* put edges in */

  void add_edge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  /* ----------- init phase 3 ----------- */
  /* build the lca and hld stuff */

  void init_tree(seg_t* arr, int root = 0) {
    // lca
    lca_dfs(root, -1);

    // size, compute biggest children
    dfs_size(root, -1, 0);

    // compute chains
    dfs_chains(root, -1);

    // label nodes
    label_time = 0;
    dfs_labels(arr, root, -1);
  }

  void lca_dfs(int v, int par) {
    lca_lift[v][0] = par;

    for (int i = 1; i < lg; i++) {
      if (lca_lift[v][i - 1] == -1) lca_lift[v][i] = -1;
      else lca_lift[v][i] = lca_lift[lca_lift[v][i - 1]][i - 1];
    }

    for (int x: edges[v]) {
      if (x != par) {
        lca_dfs(x, v);
      }
    }
  }

  void dfs_size(int v, int p, int d) {
    sz[v] = 1;
    depth[v] = d;
    par[v] = p;
    int bigc = -1, bigv = -1;

    for (int x: edges[v]) {
      if (x != p) {
        dfs_size(x, v, d + 1);
        sz[v] += sz[x];
        if (sz[x] > bigv) {
          bigc = x;
          bigv = sz[x];
        }
      }
    }

    bigchild[v] = bigc;
  }

  void dfs_chains(int v, int p) {
    if (bigchild[v] != -1) {
      chain[bigchild[v]] = chain[v];
    }

    for (int x: edges[v]) {
      if (x != p) {
        dfs_chains(x, v);
      }
    }
  }

  void dfs_labels(seg_t* arr, int v, int p) {
    label[v] = label_time++;
    seg_update_header(label[v], label[v], mp(arr[v].f, v));

    if (bigchild[v] != -1) {
      dfs_labels(arr, bigchild[v], v);
    }

    for (int x: edges[v]) {
      if (x != p && x != bigchild[v]) {
        dfs_labels(arr, x, v);
      }
    }
  }

  /* ----------- init phase 4 ----------- */
  /* usage */

  int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    int v = get_kth_ancestor(a, d);
    if (v == b) {
      return v;
    } else {
      for (int i = lg - 1; i >= 0; i--) {
        if (lca_lift[v][i] != lca_lift[b][i]) {
          v = lca_lift[v][i];
          b = lca_lift[b][i];
        }
      }
      return lca_lift[b][0];
    }
  }

  int get_kth_ancestor(int v, int k) {
    for (int i = lg - 1; i >= 0; i--) {
	    if (v == -1) return v;
      if ((1 << i) <= k) {
        v = lca_lift[v][i];
        k -= (1 << i);
      }
    }
    return v;
  }

  /* excludes p */
  seg_t query_chain(int v, int p) {
    seg_t val = seg_sentinel;
    while (depth[p] < depth[v]) {
      int top = chain[v];
      if (depth[top] <= depth[p]) {
        int diff = depth[v] - depth[p];
        top = get_kth_ancestor(v, diff - 1);
      }
      val = seg_combine(val, seg_query_header(label[top], label[v]));
      v = par[top];
    }
    return val;
  }

  seg_t query(int u, int v) {
    int lc = lca(u, v);
    seg_t val = seg_combine(query_chain(u, lc), query_chain(v, lc));
    return seg_combine(val, seg_query_header(label[lc], label[lc]));
  }

  /* excludes p */
  void update_chain(int v, int p, seg_t val) {
    while (depth[p] < depth[v]) {
      int top = chain[v];
      if (depth[top] <= depth[p]) {
        int diff = depth[v] - depth[p];
        top = get_kth_ancestor(v, diff - 1);
      }
      seg_update_header(label[top], label[v], val);
      v = par[top];
    }
  }

  void update(int u, int v, seg_t val) {
    int lc = lca(u, v);
    update_chain(u, lc, val); 
    update_chain(v, lc, val);
    seg_update_header(label[lc], label[lc], val);
  }
};

template<int size, int lg, typename seg_t = long long>
struct hld_sum {
  vector<int> edges[size];
  int bigchild[size];
  int sz[size];
  int depth[size];
  int chain[size];
  int label[size], label_time;
  int par[size];

  int lca_lift[size][lg];

  seg_t seg_tree[4 * size];
  seg_t seg_lazy[4 * size];

  int N;

  /* ----------- segment tree ----------- */ 

  /* CHANGE THIS SECTION BY PROBLEM */
  inline seg_t seg_combine(seg_t a, seg_t b) {
    return a + b;
  }

  inline seg_t seg_lazy_apply(seg_t lazy_val, seg_t new_val) {
    return lazy_val + new_val;
  }

  inline seg_t seg_lazy_func(seg_t cur_val, seg_t lazy_val, int l, int r) {
    return cur_val + lazy_val * (r - l + 1);
  }

  const seg_t seg_sentinel = 0;
  const seg_t seg_lazy_sentinel = 0;
  /* END SECTION */

  seg_t seg_query_header(int l, int r) {
    return seg_query_rec(0, 0, N - 1, l, r);
  }

  seg_t seg_query_rec(int i, int tl, int tr, int ql, int qr) {
    seg_eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return seg_tree[i];
    if (tl > tr || tr < ql || qr < tl) return seg_sentinel;

    seg_t mid = (tl + tr) / 2;
    seg_t a = seg_query_rec(2 * i + 1, tl, mid, ql, qr);
    seg_t b = seg_query_rec(2 * i + 2, mid + 1, tr, ql, qr);
    return seg_combine(a, b);
  }

  void seg_update_header(int l, int r, seg_t v) {
    seg_update_rec(0, 0, N - 1, l, r, v);
  }

  seg_t seg_update_rec(int i, int tl, int tr, int ql, int qr, seg_t v) {
    seg_eval_lazy(i, tl, tr);
	
	  if (tl > tr || tr < ql || qr < tl) return seg_tree[i];
    if (ql <= tl && tr <= qr) {
      seg_lazy[i] = seg_lazy_apply(seg_lazy[i], v);
      seg_eval_lazy(i, tl, tr);
      return seg_tree[i];
    }
    if (tl == tr) return seg_tree[i];

    int mid = (tl + tr) / 2;
    seg_t a = seg_update_rec(2 * i + 1, tl, mid, ql, qr, v);
    seg_t b = seg_update_rec(2 * i + 2, mid + 1, tr, ql, qr, v);
    return seg_tree[i] = seg_combine(a, b);
  }

  void seg_eval_lazy(int i, int l, int r) {
    if (seg_lazy[i] == seg_lazy_sentinel) return;

    seg_tree[i] = seg_lazy_func(seg_tree[i], seg_lazy[i], l, r);

    if (l != r) {
      seg_lazy[i * 2 + 1] = seg_lazy_apply(seg_lazy[i * 2 + 1], seg_lazy[i]);
      seg_lazy[i * 2 + 2] = seg_lazy_apply(seg_lazy[i * 2 + 2], seg_lazy[i]);
    }

    seg_lazy[i] = seg_lazy_sentinel;
  }

  /* ----------- init phase 1 ----------- */
  /* initialize segtree, clear edges, etc. */

  void init_arrays(int n) {
    // everything not initialized doesn't need to be
    N = n;
    for (int i = 0; i < N; i++) {
      edges[i].clear();
      chain[i] = i;
    }

    for (int i = 0; i < 4 * N; i++) {
      seg_tree[i] = seg_sentinel;
      seg_lazy[i] = seg_lazy_sentinel;
    }
  }

  /* ----------- init phase 2 ----------- */
  /* put edges in */

  void add_edge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  /* ----------- init phase 3 ----------- */
  /* build the lca and hld stuff */

  void init_tree(seg_t* arr, int root = 0) {
    // lca
    lca_dfs(root, -1);

    // size, compute biggest children
    dfs_size(root, -1, 0);

    // compute chains
    dfs_chains(root, -1);

    // label nodes
    label_time = 0;
    dfs_labels(arr, root, -1);
  }

  void lca_dfs(int v, int par) {
    lca_lift[v][0] = par;

    for (int i = 1; i < lg; i++) {
      if (lca_lift[v][i - 1] == -1) lca_lift[v][i] = -1;
      else lca_lift[v][i] = lca_lift[lca_lift[v][i - 1]][i - 1];
    }

    for (int x: edges[v]) {
      if (x != par) {
        lca_dfs(x, v);
      }
    }
  }

  void dfs_size(int v, int p, int d) {
    sz[v] = 1;
    depth[v] = d;
    par[v] = p;
    int bigc = -1, bigv = -1;

    for (int x: edges[v]) {
      if (x != p) {
        dfs_size(x, v, d + 1);
        sz[v] += sz[x];
        if (sz[x] > bigv) {
          bigc = x;
          bigv = sz[x];
        }
      }
    }

    bigchild[v] = bigc;
  }

  void dfs_chains(int v, int p) {
    if (bigchild[v] != -1) {
      chain[bigchild[v]] = chain[v];
    }

    for (int x: edges[v]) {
      if (x != p) {
        dfs_chains(x, v);
      }
    }
  }

  void dfs_labels(seg_t* arr, int v, int p) {
    label[v] = label_time++;
    seg_update_header(label[v], label[v], arr[v]);

    if (bigchild[v] != -1) {
      dfs_labels(arr, bigchild[v], v);
    }

    for (int x: edges[v]) {
      if (x != p && x != bigchild[v]) {
        dfs_labels(arr, x, v);
      }
    }
  }

  /* ----------- init phase 4 ----------- */
  /* usage */

  int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    int v = get_kth_ancestor(a, d);
    if (v == b) {
      return v;
    } else {
      for (int i = lg - 1; i >= 0; i--) {
        if (lca_lift[v][i] != lca_lift[b][i]) {
          v = lca_lift[v][i];
          b = lca_lift[b][i];
        }
      }
      return lca_lift[b][0];
    }
  }

  int get_kth_ancestor(int v, int k) {
    for (int i = lg - 1; i >= 0; i--) {
	    if (v == -1) return v;
      if ((1 << i) <= k) {
        v = lca_lift[v][i];
        k -= (1 << i);
      }
    }
    return v;
  }

  /* excludes p */
  seg_t query_chain(int v, int p) {
    seg_t val = 0;
    while (depth[p] < depth[v]) {
      int top = chain[v];
      if (depth[top] <= depth[p]) {
        int diff = depth[v] - depth[p];
        top = get_kth_ancestor(v, diff - 1);
      }
      val = seg_combine(val, seg_query_header(label[top], label[v]));
      v = par[top];
    }
    return val;
  }

  seg_t query(int u, int v) {
    int lc = lca(u, v);
    seg_t val = seg_combine(query_chain(u, lc), query_chain(v, lc));
    return seg_combine(val, seg_query_header(label[lc], label[lc]));
  }

  /* excludes p */
  void update_chain(int v, int p, seg_t val) {
    while (depth[p] < depth[v]) {
      int top = chain[v];
      if (depth[top] <= depth[p]) {
        int diff = depth[v] - depth[p];
        top = get_kth_ancestor(v, diff - 1);
      }
      seg_update_header(label[top], label[v], val);
      v = par[top];
    }
  }

  void update(int u, int v, seg_t val) {
    int lc = lca(u, v);
    update_chain(u, lc, val); 
    update_chain(v, lc, val);
    seg_update_header(label[lc], label[lc], val);
  }
};
 
ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

hld_max<100005, 20, pll> vals;
hld_sum<100005, 20, int> on;

void solve(int tc) {
  cin >> n >> q;

  cin >> x >> y;
  ai(a, n);

  pll vv[n];
  f0r(i, n) {
    vv[i] = mp(x * a[i] + y, i);
  }
  int aa[n];
  
  f0r(i, n) {
    aa[i] = (vv[i].f >= 0);
    if (vv[i].f >= 0) {
      vv[i].f = -2222337236854775807LL;
    }
  }

  vals.init_arrays(n);
  on.init_arrays(n);

  f0r(i, n - 1) {
    ll u, v; cin >> u >> v; --u; --v;
    vals.add_edge(u, v);
    on.add_edge(u, v);
  }

  // ao(vv, n); ao(aa, n);

  vals.init_tree(vv);
  on.init_tree(aa);
  
  f0r(i, q) {
    int t; cin >> t;
    if (t == 1) {
      ll a, b, c; cin >> a >> b >> c; --a; --b;
      vals.update(a, b, mp(x * c, 9999));
      // f0r(i, n) cout << vals.query(i, i) << " ";
      // cout << endl;
      pll v;
      do {
        v = vals.query(a, b);
        if (v.f >= 0) {
          on.update(v.s, v.s, 1);
          vals.update(v.s, v.s, mp(-222337236854775807LL, v.s));
        }
      } while (v.f >= 0);
    } else {
      ll a, b; cin >> a >> b; --a; --b;
      cout << on.query(a, b) << '\n';
    }
  }
}
 
int main() {
  send help
 
  // usaco("cowland");

  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
} 
