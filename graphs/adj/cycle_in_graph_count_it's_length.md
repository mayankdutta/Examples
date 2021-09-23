[problem](https://codeforces.com/problemset/problem/1249/B2)
```cpp

  int n;
  cin >> n;
  vi arr(n);
  cin >> arr;
  for (auto &i : arr)
    i--;

  vi parent(n), ans(n);
  vb used(n, false);

  for (auto &i : arr)
    parent[i] = arr[i];

  for (const auto &i : arr) {
    if (!used[i]) {
      int start = i;
      int count = 1;
      vi temp;

      temp.push_back(start);

      while (parent[start] != i) {
        start = parent[start];
        count++;
        used[start] = true;
        temp.push_back(start);
      }

      for (const auto &i : temp)
        ans[i] = count;

      used[i] = true;
    }
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << '\n';


```
