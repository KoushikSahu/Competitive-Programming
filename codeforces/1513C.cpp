#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ipair;
typedef pair<ll, ll> llpair;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int nxm = 2e5+5;
string n;
int m;
int cnt[10], dp[nxm];

void solve(){
  cin>>n>>m;
  int ans = 0;
  for(char c: n){
    int d = c - '0';
    int diff = 9 - d;
    if(diff >= m){
      ans++;
    }else{
      int tmp = m - diff - 1;
      ans += dp[tmp];
      ans %= MOD;
    }
  }
  cout<<ans<<'\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fill(cnt, cnt+10, 0);
  fill(dp, dp+nxm, 0);
  dp[0] = 2;
  cnt[0]++, cnt[1]++;
  for(int i=1; i<nxm; i++){
    int tmp = cnt[9];
    for(int j=9; j>=1; j--){
      cnt[j] = cnt[j-1];
    }
    cnt[0] = tmp;
    cnt[1] += tmp;
    cnt[1] %= MOD;
    for(int j=0; j<=9; j++){
      dp[i] += cnt[j];
      dp[i] %= MOD;
    }
  }
  int T=1;
  cin>>T;
  while(T--){
    solve();
  }
  return 0;
}

