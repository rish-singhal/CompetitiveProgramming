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
  int k; cin>>k;
  queue <LL> q;
  for1(i,9) q.push(i);
  while(--k){
    LL x(q.front());
    q.pop();
    if(x%10) q.push(x*10 + x%10 - 1);
    q.push(x*10 + x%10);
    if(x%10<9) q.push(x*10 + x%10 + 1);
  }
  cout<<q.front()<<endl;
   return 0;
}

