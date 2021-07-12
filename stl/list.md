### Unique

  method 1
  ```
    n = unique(a.begin(), a.end()) - a.begin();
    a.resize(n);
  ```
  method 2
  ```
    a.erase(unique(a.begin(), a.end()), a.end());
  ```

  method 3
  ```
    pr.resize(unique(pr.begin(), pr.end()) - pr.begin());

  ```
