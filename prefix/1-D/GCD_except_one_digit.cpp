/*
 * https://atcoder.jp/contests/abc125/tasks/abc125_c
 * Problem was to get the maximum gcd if we exclude one no.
 * Below is the optimize implementation of the same.
 */

#include <bits/stdc++.h>
#define what_is(x) cout << "value of " << #x << " :: " << x << "\n"

using namespace std;
using ll=long long int;
using lld=long double;


int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main () {

    int n;
    cin >> n;

    vector <int> arr (n + 2, 0);
    vector <int> prefix (n + 2, 0);
    vector <int> suffix (n + 2, 0);

    for (int i=1; i<=n; i++) cin >> arr[i];

    for (int i=1; i<=n; i++) {
        prefix [i] = gcd (prefix[i-1], arr[i]);
    }

    for (int i=n; i>=1; i--) {
        suffix [i] = gcd (suffix[i+1], arr[i]);
    }

    int mx = 0;
    for (int i=0; i<=n; i++) {
        mx = max (gcd(prefix[i-1] ,suffix [i+1]), mx );
    }

    cout << mx << "\n";
}


