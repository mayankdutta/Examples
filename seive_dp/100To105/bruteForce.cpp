#include <bits/stdc++.h>
using ll = long long int;
#define rep(i, a, n) for (ll i = a; i < n; i++) 
using namespace std; 

ll check(ll a, ll b, ll c, ll d, ll e, ll f) { 
  return (100 * a + 101 * b + 102 * c + 103 * d + 104 * e + 105 * f);
}

int main () { 
  ll x;
  cin >> x; 


  rep(a, 0, x / 100 + 1) { 
    rep(b, 0, x / 101 + 1) { 
      rep(c, 0, x / 102 + 1) { 
        rep(d, 0, x / 103 + 1) { 
          rep(e, 0, x / 104 + 1) { 
            rep(f, 0, x / 105 + 1) { 
              //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
              if (check(a, b, c, d, e, f) == x) { 
                cout << 1 << '\n'; 
                exit(0); 
              }
            }
          }
        }
      }
    }
  }
  cout << 0 << '\n';
}
