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
 
    unordered_map<string, int> subs;
    unordered_set<string> curr;
    int n;
    string nums[70001], num, sub;
    cin >> n;
    rep(i, 0, n) {
        cin >> nums[i];
        num = nums[i];
        rep(i, 1, 10) rep(j, 0, 9 - i + 1) {
            sub = num.substr(j, i);
            if (!curr.count(sub)) {
                ++subs[sub];
                curr.insert(sub);
            }
        }
        curr.clear();
    }
    rep(i, 0, n) {
        num = nums[i];
        bool found = false;
        rep(i, 1, 10) {
            rep(j, 0, 9 - i + 1) {
                sub = num.substr(j, i);
                if (subs[sub] == 1) {
                    cout << sub << endl;
                    found=true;
                    break;
                }
            }
            if(found)break;
        }
    }
    return 0;
}