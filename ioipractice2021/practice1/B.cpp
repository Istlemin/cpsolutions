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
	ll s,n;
	cin>>s>>n;
	vector<pii> d(n);
	rep(i,0,n) cin>>d[i].first>>d[i].second;
 
	sort(all(d));
 
	rep(i,0,n){
		if(s<=d[i].first){
			cout<<"NO"<<endl;
			return 0;
		}
		s += d[i].second;
	}
	cout<<"YES"<<endl;
}