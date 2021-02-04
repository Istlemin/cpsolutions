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
	ll n,m;
	cin>>n>>m;
	vector<string> g(n);
	rep(i,0,n) cin>>g[i];
 
	vector<vector<vector<vi>>> seen(n,vector<vector<vi>>(m,vector<vi>(4,vi(3))));
 
	queue<tuple<ll,ll,ll,ll>> q;
	rep(i,0,n) rep(j,0,m){
		if(g[i][j]=='T'){
			q.emplace(i,j,0,0);
			q.emplace(i,j,1,0);
			q.emplace(i,j,2,0);
			q.emplace(i,j,3,0);
		}
	}
	while(q.size()){
		ll r,c,dir,dist;
		tie(r,c,dir,dist) = q.front();
		q.pop();
		if(dist>2||r<0||r>=n||c<0||c>=m||seen[r][c][dir][dist]||g[r][c]=='*') continue;
		seen[r][c][dir][dist] = true;
		//cout<<r<<" "<<c<<" "<<dir<<" "<<dist<<endl;
		if(g[r][c]=='S'){
			cout<<"YES"<<endl;
			return 0;
		}
		q.emplace(r+1,c,1,dist+(dir!=1));
		q.emplace(r,c+1,2,dist+(dir!=2));
		q.emplace(r-1,c,3,dist+(dir!=3));
		q.emplace(r,c-1,0,dist+(dir!=0));
	}
	cout<<"NO"<<endl;
}
