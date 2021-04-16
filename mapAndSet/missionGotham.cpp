/*
 * Motivation problem: https://www.codechef.com/problems/GOTHAM
 * approach: solution lucrates the idea of indices, see how they are inserted,
 * that's maintain the order in the indices way, which was later used in lower_bound
 */
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;

int main() {
    int n;
    cin >> n;

    set<pair<ll, ll>> st;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        st.insert({i + 1, num}); /* Really nice approach */
    }

    int queries;
    cin >> queries;

    while (queries --) {
        ll index, value;
        cin >> index >> value;

        auto it = st.lower_bound({index, 0});
        ll ans = 0;

        while (it != st.end() and value > 0) {
           /* Pick up copy and pen, and make cases */

            if (value < it -> second) {
                ans += (value) * (it -> first - index);
                st.insert({it -> first, it -> second- value});
                st.erase(it);
                value = 0;
            }
            else {
                ans += (it -> second) * (it -> first - index);
                auto it_temp = it;
                value -= it -> second;
                it ++;
                st.erase(it_temp);
            }
        }
        cout << ans << '\n';
    }
}

