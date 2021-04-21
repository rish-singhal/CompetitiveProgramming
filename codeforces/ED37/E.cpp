#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vi> vii;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
const int MAXN = 2e5 +5;

set <int> s;
vector <int> v[MAXN];
int cnt = 0;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
 
void dfs(int u){
  cnt++;
  s.erase(u);
  sort(all(v[u]));
  for(int i=1;;){
    auto it = s.lower_bound(i);
    if(it == s.end())
      return;
    i = *it;
    if(!binary_search(all(v[u]), i)){
      dfs(i);
    }
    i++;
  }
}

int main(){
  fio();
  int n, m;
  cin >> n >> m;
  forn(i, m){
    int u, vv;
    cin >> u >> vv;
    v[u].push_back(vv);
    v[vv].push_back(u);
  }
  for1(i,n) s.insert(i);
  vector <int> ans;
  for1(i,n) {
    if(s.count(i))
    {
      cnt = 0;
      dfs(i);
      ans.push_back(cnt);
    }
  }
  sort(all(ans));
  cout << ans.size() << "\n";
  for(auto i: ans){
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
