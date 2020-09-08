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


template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  template <typename U>
  friend const Modular<U>& abs(const Modular<U>& v) { return v; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}
 
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 
constexpr int md = (int) 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;


template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}


void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


void takeinput(vector<LL> &v, int n, int k){
  forn(i,k) cin>>v[i];
  LL a, b, c, d; cin>>a>>b>>c>>d;
  a %= d, b%= d, c%=d;
  for(int i = k; i < n; i++){
    v[i] = c;
    v[i] = (v[i] + (b*(v[i-1])%d)%d)%d;
    v[i] = (v[i] + (a*(v[i-2])%d)%d)%d;
    v[i]++;
  } 
}

set <pair<LL,pair<LL,LL>>> s;
Mint P = 0;

void add(LL l, LL w, LL h){
  if((int)s.size() == 0){
    P += 2LL*(h + w);
    s.insert({l, {l+w, h}});
    return;
  }
  LL r = l + w;
  auto it = s.upper_bound({l,{0, 0}});
  auto it2 = s.upper_bound({r,{0, 0}});

  if(it!=s.begin()){
    auto x = it;
    it --;
    LL ll = (*it).fi;
    LL rr = (*it).se.fi;
    LL l2 = (*x).fi;
    LL r2 = (*x).se.fi;
    if((ll<=l && l<=rr)|| (ll<=r && r<=rr) || (l <= ll && rr <= r) || (ll<=l && r<=rr)){
        // do nothing
    }
    else if((l2<=l && l<=r2)|| (l2<=r && r<=r2) || (l <= l2 && r2 <= r) || (l2<=l && r<=r2)){
      it = x;
    }
    else{
      P += 2LL*(h + w);
      s.insert({l, {l+w, h}});
      return;
    }
  }
  LL ll = (*it).fi;
  LL rr = (*it).se.fi;
  if((ll<=l && l<=rr)|| (ll<=r && r<=rr) || (l <= ll && rr <= r) || (ll<=l && r<=rr)){
    if(it2!=s.begin()){
      it2--;
      LL l2 = (*it2).fi;
      LL r2 = (*it2).se.fi;
      if((l2<=l && l<=r2)|| (l2<=r && r<=r2) || (l <= l2 && r2 <= r) || (l2<=l && r<=r2)){
        LL le = l;
        Mint len = 0;
        Mint exhi = 0;
        auto zz = it2;
        it2++;
        auto temp = it2;
        it2 = zz;
        zz = temp;
        bool bb = 0;
       // to edit
        LL pph = 0;
       
        for(auto x = it; x != zz; x++){
          LL kkk = max(0LL, (*x).fi - le);
          len += kkk;
          le = (*x).se.fi;
          if(kkk != 0 && bb!=0) {
            exhi -= (Mint)((Mint)pph + (Mint)(*x).se.se);
          }
          else if(bb!=0){
            exhi -= (Mint) abs(pph - (*x).se.se);
          }
          pph = (*x).se.se;
          bb = 1;
        }

        auto lef = *it;
        auto rig = *it2;

        exhi += abs(lef.se.se - h);
        exhi += abs(rig.se.se - h);
        len += max(0LL, r - (*it2).se.fi);
        LL pl = (*it).fi;
        LL pr = (*it2).se.fi;
        s.erase(it, zz);
        if((lef.fi < l && h!=lef.se.se) && (rig.se.fi > r && h!=rig.se.se)){
          s.insert({lef.fi,{l,lef.se.se}});
          s.insert({l, {r,h}});
          s.insert({r, {rig.se.fi, rig.se.se}});
        }
        else if((lef.fi < l && h!=lef.se.se)){
          s.insert({lef.fi,{l,lef.se.se}});
          s.insert({l, {max(r,rig.se.fi),h}});
        }
        else if((rig.se.fi > r && h!=rig.se.se)){
          s.insert({min(l,lef.fi), {r,h}});
          s.insert({r, {rig.se.fi, rig.se.se}});
        }
        else{
          s.insert({min(l,lef.fi), {max(r,rig.se.fi),h}});
        }
        P += (2LL*len);
        P += exhi;
        return;
      }
      else{
        P += 2LL*(h + w);
        s.insert({l, {l+w, h}});
        return;
      }
    }
    else{
      P += 2LL*(h + w);
      s.insert({l, {l+w, h}});
      return;
    }
  }
  else{
    P += 2LL*(h + w);
    s.insert({l, {l+w, h}});
    return;
  }
}

void solve(){
  s.clear();
  P = 0;
  LL n,k; cin>>n>>k;
  //cout<<"yes"<<endl;
  vector<LL> L(n), H(n), W(n);
  takeinput(L, n, k);
  takeinput(W, n, k);
  takeinput(H, n, k);
  //debug(L, W, H);
  Mint an = 1;
  LL nxt = 0;
  forn(i,n){
   add(L[i], W[i], H[i]);
   debug(s);
   debug(P);
   an *= P;    
  }
  cout<<an<<endl;
}

int main(){
  fio();
  int T; cin>>T;
  for1(i,T){
    cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}