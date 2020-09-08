#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, q, p[MX], rk[MX];
set<ii> st[MX];

int parent (int a) {
	while (a != p[a]) a = p[a];
	return a;
}

void insert (set<ii> &st, const ii &k) {
	st.insert(k);

	auto it = st.find(k);
	auto jt = it;

	jt++;
	if (jt != st.end()) {
		if (it->se + 1 == jt->fi) {
			st.emplace(it->fi, jt->se);
			st.erase(it);
			st.erase(jt);
		}
	}

	it = st.lower_bound(k);
	jt = it;

	if (jt != st.begin()) {
		jt--;
		if (jt->se + 1 == it->fi) {
			st.emplace(jt->fi, it->se);
			st.erase(jt);
			st.erase(it);
		}
	}
}

int join (int a, int b) {
	int _a = a, _b = b;
	a = parent(a), b = parent(b);
	
	if (a == b) {
		auto it = st[a].upper_bound(ii(_a, MX)); it--;
		auto jt = st[b].upper_bound(ii(_b, MX)); jt--;

		return min(it->se - _a, _b - jt->fi) + 1;
	} else {
		if (rk[a] < rk[b]) swap(a, b);
		if (rk[a] == rk[b]) rk[a]++;

		p[b] = a;

		if (st[a].size() < st[b].size())
			swap(st[a], st[b]);

		for (const auto &k : st[b])
			insert(st[a], k);

		st[b].clear();
		return 0;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;

	forn (i, n) {
		p[i] = i;
		st[i].emplace(i, i);
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		while (l < r) {
			int d = join(l, r);
			if (d == 0) {
				n--;
				l++, r--;
			} else{
				if(d==1) break;
				l += d;
				r -= d;
			}
		}

		cout << n << endl;
	}

	return 0;
}
