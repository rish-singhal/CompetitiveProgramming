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

string s;

struct Node{
	Node* a[26];
};

Node* root = new Node();

pair<LL,LL> dfs(Node *node){
	int f = 0;
	int w = 0, l = 0;
	forn(i,26){
		if(node->a[i]!=NULL){
			f = 1;
			auto x = dfs(node->a[i]);
			w |= (x.fi==0);
			l |= (x.se==0);
		}
	}
	if(f==0){
		return {0,1};
	}
	return {w,l};
}

int main(){
  fio();
  int n; cin>>n;
  LL k; cin>>k;
  forn(i,n){
  	cin>>s;
  	auto ro = root;
  	for(auto c:s){
  		int x = c - 'a';
  		if(ro->a[x]==NULL)
  			ro->a[x] = new Node();
  		ro = ro->a[x];
  	}
  }
  auto v = dfs(root);
  if(v.fi == 1 && v.se==1) {
  	cout<<"First"<<endl;
  	return 0;
  }
  if(v.fi == 0){
  	cout<<"Second"<<endl;
  	return 0;
  }
  cout<<(k&1?"First":"Second")<<endl;
  return 0;
}