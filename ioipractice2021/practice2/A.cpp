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
 
vi p;
ll n;
 
ll getAns(ll a){
	ll v = a;
	vector<bool> seen(n);
 
	while(true){
		if(seen[v]) return v;
		seen[v] = true;
		v = p[v];
	}
}
//test
int main(){
	cin.sync_with_stdio(false); cin.tie(0);
	cin>>n;
	p.resize(n);
	rep(i,0,n) {
		cin>>p[i];
		p[i]--;
	}
	rep(i,0,n) cout<<getAns(i)+1<<" ";
	cout<<endl;
}
