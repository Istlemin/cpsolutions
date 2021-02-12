#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a - 1; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
 
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
 
#define umap unordered_map
#define uset unordered_set
#define INF 1000000007
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    vector<ll> powers;
    int n, mult=1,num;
    ll ans =0 ;
    powers.pb(mult);
    while (mult<=INF){
        mult*=2;
        powers.pb(mult);
    }
 
    umap<int,ll> nums;
    cin>>n;
    while(n--){
        cin>>num;
        trav(power,powers){
            if(num>=power)continue;
            if (nums.count(power-num))ans+=nums[power-num];
        }
        ++nums[num];
    }
    cout<<ans<<endl;
    return 0;
}