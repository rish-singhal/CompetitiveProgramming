#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
const int D = 170;
struct Query
{
    int l, r, idx;
    bool operator<(const Query& a) const
    {
        return (l-1)/D<(a.l-1)/D||(l-1)/D==(a.l-1)/D&&r<a.r;
    };
};
LL fr[1000005];
LL c = 0;

void add(LL x)
{
    fr[x]++;
    if (fr[x] == 1)
    {
        c++;
    }
}
void remove(LL x)
{
    fr[x]--;
    if (fr[x] == 0)
        c--;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) scanf("%d", &a[i]);
    int q;
        scanf("%d", &q);
    vector<Query> v(q);

    forn(i, q)
    {
        int l, r;
        scanf("%d%d",&v[i].l,&v[i].r);
        v[i].l--, v[i].r--;
        v[i].idx = i;
    }
    srt(v);
    vector<LL> an(q);
    int l = 0, r = -1;
    for (auto q : v)
    {
        while (l > q.l)
        {
            l--;
            add(a[l]);
        }
        while (r < q.r)
        {
            r++;
            add(a[r]);
        }
        while (l < q.l)
        {
            remove(a[l]);
            l++;
        }
        while (r > q.r)
        {
            remove(a[r]);
            r--;
        }
        an[q.idx] = c;
    }
    for (auto i : an)
        printf("%lld\n", i);
    return 0;
}

