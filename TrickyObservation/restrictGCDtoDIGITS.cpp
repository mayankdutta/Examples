/*
 * we are supposed to find two integer having
 * digits 'a' and digits 'b'
 * such that their GCD's will be of digits 'c'
 * https://codeforces.com/contest/1511/problem/B
 * HOW TO restrict digits of GCD
 * Must read: https://codeforces.com/blog/entry/89634
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    c --;
    string one, two;
    for (int i = 0; i < a - 1; i++)
      one.push_back('0');
    one = "1" + one;

    for (int i = 0; i < b; i++)
      two.push_back('1');

    for (int i = 0; i < c; i++)
      two[i] = '0';

    reverse(two.begin(), two.end());

    cout << one << ' ' << two << '\n';
  }
}

