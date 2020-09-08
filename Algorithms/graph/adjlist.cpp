#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back


vector <vector <int> > adj(MAXN);
int n;
for(int i=0;i<n;i++){
    int u,v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}


