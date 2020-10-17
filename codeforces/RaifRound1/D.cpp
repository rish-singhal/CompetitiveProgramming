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
const int MAXN = 1e5 +5;
// check MAXN


void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n; cin>>n;
  vector<int> a(n);
  forn(i,n) cin>>a[i];
  reverse(all(a));
  int in = 0;
  vector<int> fr(2*n+5);
  int ccc = 0;
  int szx = 0;
  while(in < n && a[in] == 0){
  	  	in++;
  }
  if(in >= n){
  	cout<<0<<endl;
  	return 0;
  }
  if(a[in] > 1){
  	cout<< -1 <<endl;
  	return 0;
  }
  vector<pair<int,int>> ans;
  ans.push_back({n,  n - in});
  int row = n;
  in++;
  int cn = 2;
  int bb = 0;
  
  for(int i = in ; i < n; i++){
  	if(a[i] == 1){
  		if(!bb)row--;
  		bb =0;
  		 if(row < 1){
 			cout<<-1<<endl;
 			return 0;
 		}
 		ans.push_back({row,  n - i});
 		if(row < 1){
 			cout<<-1<<endl;
 			return 0;
 		}
 		fr[szx] = row;
  		szx++;
  	}
  	else if(a[i] == 2){
  		 if(row < 1){
 			cout<<-1<<endl;
 			return 0;
 		}
 		if(bb == 1 || bb == 2){
 			if(szx == ccc){
 				cout<<-1<<endl;
 				return 0;
 			}
 			ans.push_back({fr[ccc],  n - i});
 			ccc++;
 			continue;
 		}
  		ans.push_back({row,  n - i});
  		szx--;
  		row--;	bb = 1;
  	}
  	else if(a[i] == 3){
  		if(!bb)row--;
  		bb = 0;
  		 if(row < 1){
 			cout<<-1<<endl;
 			return 0;
 		}
  		ans.push_back({row,  n - i});
  		ans.push_back({row,  n - i + 1});
  		if(fr[szx] == (i - 1)) szx--;
  		if(row < 1 || n - in + 1 > n || n - in + 1 <= 0){
 			cout<<-1<<endl;
 			return 0;
 		}
 		row--;	bb = 1;
  	}
  	else{
  		bb = 2;
  	}
  }
  cout<<ans.size()<<endl;
  for(auto i:ans)
  	cout<<i.fi<<" "<<i.se<<endl;

  return 0;
}