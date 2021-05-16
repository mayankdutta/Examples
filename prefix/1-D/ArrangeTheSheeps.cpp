status: NOT_SOLVED.
problem: https://codeforces.com/contest/1520/problem/E
solutions: https://codeforces.com/submissions/JustNik77/page/2
           https://codeforces.com/contest/1520/submission/115315773
similar problem: https://atcoder.jp/contests/abc102/tasks/arc100_a

text that may help: 
My DP solution for E: we can find all pref[i] values where pref[i] shows how many moves we need to move all sheep to the left from i to i. 
           If a sheep doesn't stay at i position, then pref[i] = pref[i — 1] + was ( was is an amount of sheep to the left from i), 
           else pref[i] = pref[i — 1]. Same operations we can do for suff (we go from n to 1). 
Then we can simply check for every i: ans = min(ans, pref[i] + suff[i + 1]).
