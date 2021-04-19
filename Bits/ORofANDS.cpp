/*
 * Motivation Problem: https://www.codechef.com/problems/OROFAND
 * Topics to learn: bit masking and all, (I solved usins seg tree though)
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n], bitsCount[32] = {};

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 31; j++) {

          /*
           * Do note that, we have broken a[i] into bits,
           * and then respectively checked according to the digit at jth place.
           *
           * a[i] >> j: means to remove last j digits from the a[i]:
           * Take S = 34
           * s >> 4 will mean dividing by 4 OR removing last 4 digits
           * and then & is taken to see if that digit is 1 or not.
           * and then finally added to our bitset count
           */

            if ((a[i] >> j) & 1) {
                bitsCount[j]++;
            }
        }
    }

    int answer = 0;
    for (int j = 0; j < 31; j++) {
      /*
       * consider, j = 3 then 1 << j, would mean adding j digits in the end of 1,
       * This will become 1000, 3 digits being added.
       */
        answer += (1 << j) * (bitsCount[j] >= 1);
    }
    cout << answer << '\n';

    while (q--) {
        int index, value;
        cin >> index >> value;
        --index;

        // remove old value.
        for (int j = 0; j < 31; j++) {
            if ((a[index] >> j) & 1) {
                bitsCount[j]--;
            }
        }

        a[index] = value;

        // add new value.
        for (int j = 0; j < 31; j++) {
            if ((a[index] >> j) & 1) {
                bitsCount[j]++;
            }
        }

        answer = 0;
        for (int j = 0; j < 31; j++)
            answer += (1 << j) * (bitsCount[j] >= 1);
        cout << answer << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}

