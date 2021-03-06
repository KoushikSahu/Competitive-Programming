#include <bits/stdc++.h>
using namespace std;
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

string s, a;
int k;
int g[26][26];
const int INF = 1e9+5;

void testcase(){
	cin>>s>>k;
	fill_n(g[0], 26*26, INF);
	for(int i=0; i<26; i++) g[i][i] = 0;
	for(int i=0; i<k; i++){
		cin>>a;
		g[a[0]-'A'][a[1]-'A'] = 1;
	}
	for(int l=0; l<26; l++){
		for(int i=0; i<26; i++){
			for(int j=0; j<26; j++){
				g[i][j] = min(g[i][j], g[i][l]+g[l][j]);
			}
		}
	}
	int ans = INF;
	for(int i=0; i<26; i++){
		bool pos = true;
		int tm = 0;
		for(char c: s){
			if(g[c-'A'][i] < INF){
				tm += g[c-'A'][i];
			}else{
				pos = false;
			}
		}
		if(pos) ans = min(ans, tm);
	}
	if(ans < INF) cout<<ans<<'\n';
	else cout<<-1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		cout<<"Case #"<<i<<": ";
		testcase();
	}
    return 0;
}

