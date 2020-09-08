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
const int MAXN = 1e6 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL cou[MAXN];
LL mm[MAXN];
int main(){
  fio();
  int n; cin>>n;
  vector<LL> v(n);
  forn(i,n){
   cin>>v[i];
   cou[v[i]]++;
   }

   for1(i,MAXN){
   	if(cou[i]>1) {
   		cou[i]=0;
   		mm[i] = 1;
   	}
   }
   LL an =0;
   for1(i,MAXN){
   		if(mm[i] || cou[i]) {
   			if(!mm[i]) an++;
   		for(int j = i; j<=MAXN; j+=i)
   			cou[j] = 0;
   	}
   }
   cout<<an<<endl;
  return 0;
}