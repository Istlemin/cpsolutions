#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
 
int main(){
	cin.sync_with_stdio(false); cin.tie(0);
 
	vector<bool> seen(4*1e4);
	ll n,m;
	cin>>n>>m;
	queue<pii> q;
	q.emplace(n,0);
	while(q.size()){
		ll v = q.front().first;
		ll d = q.front().second;
		q.pop();
		if(v>=seen.size()||v<0||seen[v]) continue;
		seen[v] = true;
		if(v==m){
			cout<<d<<endl;
			break;
		}
		q.emplace(2*v,d+1);
		q.emplace(v-1,d+1);
	}
}
