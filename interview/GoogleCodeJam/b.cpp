#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int t; cin>>t;
  int x = 1;
  while(x<=t){
    string s; cin>>s;
    cout<<"Case #"<<x<<": ";

    stack <char> ss;
    for(auto i:s){
      int k = i -'0';
      forn(j,k){
        if(!ss.empty() &&ss.top()==')') {
          ss.pop(); continue;
        }
        ss.push('(');
      }
      ss.push(i);
      forn(j,k)ss.push(')');
    }
    string an;
    while(!ss.empty()){
      an+=ss.top();
      ss.pop();
    }
    reverse(an.begin(),an.end());
    cout<<an<<endl;
    x++;
  }
      return 0;
}

