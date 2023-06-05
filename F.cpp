#include <bits/stdc++.h>
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

ll dfs(string &a, string &b, ll i, ll j, vvi &dp)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
    {
        return dp[i][j]= 1+dfs(a,b, i-1, j-1, dp);
    }
    return dp[i][j]=max(dfs(a, b, i-1, j, dp), dfs(a, b, i, j-1, dp));
}

void solve()
{
    string a, b;
    cin>>a>>b;
    ll n=sz(a), m=sz(b);
    // vvi dp(n, vi(m, -1));
    // ll ans = dfs(a, b, n-1, m-1, dp);

    // cout<<ans<<line;

    vvi dp(n+1, vi(m+1, 0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // cout<<dp[n][m];

    ll len = dp[n][m];

    string ans="";
    ll i=n, j=m;

    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans+=a[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else{
                j--;
            }
        }
    }

    reverse(all(ans));
    cout<<ans<<line;


}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("error.txt", "w", stderr);
    //     freopen("output.txt", "w", stdout);
    // #endif

    fio;
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
