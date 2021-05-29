/*
 * Question-1 of the list
 * base on pq, can also be done via mutliset, but pq better
 * Collecting sum while sum + arr[i] >= 0 won't work like in this TC: 3 3 -2 -1 0 -1 -1 -1 -1, no intelligence in the code
 * pq after inserting and then deletion in another loop will also not work.
 * pq should be in the same loop, else there will be chance that -ve element inserted first
 */

#include <bits/stdc++.h>

using namespace std;
using ll=long long int;
using lld=long double;


#define fast std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);

void solve() {
    int n; cin >> n;
    priority_queue<int> pq;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(-num);

        sum += num;
        while (sum < 0) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << '\n';
}

int main() {
    fast;
    int t = 1;
    while (t--)
        solve();
}

