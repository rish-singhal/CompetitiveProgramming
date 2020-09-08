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

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


void solve(){
	int n; cin>>n;
	vector<LL> v(n);
	forn(i,n) cin>>v[i];

	vector<int> lma(n), rma(n), lmi(n), rmi(n);
	stack <int> s;
	forn(i,n){
		while(!s.empty() && v[s.top()]<=v[i])
			s.pop();
		if(s.empty()) lma[i] = -1;
		else lma[i] = s.top();
		s.push(i);
	}

	while(!s.empty()) s.pop();

	for(int i=n-1;i>=0;i--){
		while(!s.empty() && v[s.top()]>=v[i])
			s.pop();
		if(s.empty()) rmi[i] = n;
		else rmi[i] = s.top();
		s.push(i);
	}

	reverse(all(v));

	while(!s.empty()) s.pop();

	forn(i,n){
		while(!s.empty() && v[s.top()]<=v[i])
			s.pop();
		if(s.empty()) rma[n - 1 -i] = n;
		else rma[n - 1 - i] =  n - 1 - s.top();
		s.push(i);
	}

	while(!s.empty()) s.pop();

	for(int i=n-1;i>=0;i--){
		while(!s.empty() && v[s.top()]>=v[i])
			s.pop();
		if(s.empty()) lmi[n - 1 - i] = -1 ;
		else lmi[n - 1 - i] =  n - 1 - s.top();
		s.push(i);
	}
	reverse(all(v));
	LL an = 0;
	for(int i = 0; i < n; i++){
		rmi[i]--, rma[i]--;
		cout<<v[i]<<" : "<<lmi[i]<<" "<<rmi[i]<<" , "<<lma[i]<<" "<<rma[i]<<endl;
		
		an += max({0,min(rma[i] - (i-1), i - lma[i])});
		an += max({0,min(rmi[i] - (i-1), i - lmi[i])});
		an -= 2;
		
		if(lmi[i] + 1 == rmi[i]){
			LL win = (rma[i] - lma[i]);
			LL a = max({0,lma[i]});
			LL b = n - 1 - rma[i];

			an += min(a, win) + min(b, win);
			if(a + b >= win){
				a-=1; b-=1;
				win-=2;
				an += min({win,a,b});
			}
		}	
		else if(rma[i] - 1 == lma[i]){
			LL win = (rmi[i] - lmi[i]);
			LL a = max({0,lmi[i]});
			LL b = n - 1 - rmi[i];
			
			an += min(a, win) + min(b, win);
			if(a + b >= win){
				a-=1; b-=1;
				win-=2;
				an += max({0LL,min({win,a,b})});
			}
		}
		else{
			LL win = rma[i] - lma[i];
			LL win2 = rmi[i] - lmi[i];
			LL a = (lmi[i] <= lmi[i]? lmi[i]: lmi[i]) + 1;
			LL b = n - 1 - (rmi[i] <= rma[i]? rma[i]: rma[i]);
			b = n - 1 - b;
			// an += min({win-1, win2}) + min({win, win2-1});
			// for minii
			if(lmi[i] <= lma[i]){
				LL aa = win2 - 1;
				LL bb = b;
				LL ww = win;
				an += min(aa, ww) + min(bb, ww);
				if(aa + bb >= ww){
					aa-=1; bb-=1;
					ww-=2;
					aa += max({0LL,min({ww,aa,bb})});
				}

				aa = a;
				bb = win - 1;
				ww = win2;
				an += min(aa, ww) + min(bb, ww);
				if(aa + bb >= ww){
					aa-=1; bb-=1;
					ww-=2;
					an += max({0LL,min({ww,aa,bb})});
				}
			}
			else{
				LL aa = win - 1;
				LL bb = b;
				LL ww = win2;
				an += min(aa, ww) + min(bb, ww);
				if(aa + bb >= ww){
					aa-=1; bb-=1;
					ww-=2;
					an += max({0LL,min({ww,aa,bb})});
				}

				aa = a;
				bb = win2 - 1;
				ww = win;
				an += min(aa, ww) + min(bb, ww);
				if(aa + bb >= ww){
					aa-=1; bb-=1;
					ww-=2;
					an += max({0LL,min({ww,aa,bb})});
				}
			}

		}
		cout<<an<<" "<<endl;
	}
	cout<<"ans: "<<(an/2)<<endl;
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}