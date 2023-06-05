#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(a) a.begin(), a.end()
#define f(i, a, b) for (int i = a; i < b; i++)
#define ff(i, a, b) for (int i = a; i <= b; i++)
#define bloop(i, a, b) for (int i = a; i >= b; i--)
// #define deb(x) cout << #x << "=" << x <<'\n'
#define ll long long
#define pb emplace_back
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define inf (int)(1e18)
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umii;
typedef map<ll, ll> mii;
typedef vector<vi> vvi;
#define fi first
#define se second
#define line "\n"
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)
const ll mod = 1e9 + 7;

/****************************************DEBUG************************************************************************************************************************************************************/
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define deb(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define deb(x...)
#endif
/*********************************************************************************************************************************************************************************************************/

template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

template <typename T>
void print(T &&t) { cout << t << "\n"; }
void printarr(ll arr[], ll n)
{
    f(i, 0, n) cout << arr[i] << " ";
    cout << "\n";
}
template <typename T>
void printvec(vector<T> v)
{
    ll n = v.size();
    f(i, 0, n) cout << v[i] << " ";
    cout << "\n";
}
template <typename T>

ll getSum(vector<T> v)
{
    ll n = v.size();
    ll s = 0;
    f(i, 0, n) s += v[i];
    return s;
}

/*******************************************************************************************************************************************************************************************************/

ll dfs(vi &a, vi&b, vi&c, ll idx, ll prev, vvi &dp)
{

    if(idx<0) return 0;
    if( dp[idx][prev]!=-1) return dp[idx][prev]; 
    ll ans=-inf;
    if(prev!=0)
    {
        ans=max(ans, a[idx]+dfs(a, b, c, idx-1, 0, dp));
    }
    if(prev!=1){
        ans=max(ans, b[idx]+dfs(a, b, c, idx-1, 1, dp));
    }

    if(prev!=2)
    {
        ans=max(ans, c[idx]+dfs(a, b, c, idx-1, 2, dp));
    }

    return dp[idx][prev] =ans;
}

void solve()
{
    ll n;
    cin>>n;
    vi a(n), b(n), c(n);

    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    vvi dp(n, vi(4, -1));
    ll ans = dfs(a, b, c, n-1, 3, dp);

    cout<<ans<<line;


    //dp[i][j]= MAX SCORE I CAN GET IF I CHOOSE JTH ACTIVITY ON ITH DAY
    // vvi dp(n, vi(3, 0));

    // dp[0][0]=a[0];
    // dp[0][1]=b[0];
    // dp[0][2]=c[0];

    // for(int i=1;i<n;i++)
    // {
    //     dp[i][0]=a[i]+max(dp[i-1][1], dp[i-1][2]);
    //     dp[i][1]=b[i]+max(dp[i-1][0], dp[i-1][2]);
    //     dp[i][2]=c[i]+max(dp[i-1][0], dp[i-1][1]);
    // }

    // ll ans = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    // cout<<ans<<line;

}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("error.txt", "w", stderr);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // srand(time(NULL));

    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

    return 0;
}
