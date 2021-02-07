/*
* Problem : https://atcoder.jp/contests/abc157/tasks/abc157_e
* solution referred : https://atcoder.jp/contests/abc157/submissions/10441072
* mine is below(only approach) 
*
*
 * Gist :: certain string was given, and we were supposed to 
 * replace character if 1 is entered by given character 
 * if 2 is entered then we are given a L and a R and supposed to find distinct characters b/w the same 
 * 
 * One approach was clearly SegTree, BIT etc..... 
 * This appproach hash the INDEX value of STRING at the CHARACTER value of STRING
 */
 
 #include <bits/stdc++.h>
 using namespace std; 
 using ll = long long int; 
 
 void solve { 
    ll n; 
    cin >> n;
    string s;
    cin >> s;

    set<ll> st[26];
    for (ll i = 0; i < n; i++) { 
        st[s[i] - 'a'].insert(i);
    }

    ll queries; 
    cin >> queries;

    while (queries--) { 
        ll type; 
        cin >> type; 

        if (type == 1) { 
            ll index; 
            char ch; 
            cin >> index >> ch; 

            index --;
            if (s[index] != ch) { 
                st[s[index] - 'a'].erase(index); //to learn 
                s[index] = ch; 
                st[ch - 'a'].insert(index); 
            }
        }
        else { 
            ll l, r;
            cin >> l >> r;

            l --; 
            r --;
            ll ans = 0;
            for (int i = 0; i < 26; i++) { 
                auto it = st[i].lower_bound(l); //found the location of L and then counted the same. 
                if (it != st[i].end() and *it <= r) { 
                    ans ++; 
                }
            }
            cout << ans << '\n';
        }
    }
    }
