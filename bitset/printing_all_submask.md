## visualization 

take 25 for example, binary form `11001` <br>
consider it as photoshoped image composed of various layer over `00000` <br>
time to sepearate them out then. 
```js
- 11001
- 11000
- 10001
- 10000
- 01001
- 01000
- 00001
```


```cpp
void printBinary(int n) {
  for (int i = 10; i >= 0; i--) {
    printf("%d", ((n >> i) & 1));
  }
  printf("\n");
}

void SubMasks(int n) {
  for (int s = n; s; s = (s - 1) & n) {
  cout << s << ": ";
    printBinary(s);
  }
}

int main() {
  int n = 25;
  cin >> n;
  SubMasks(n);

  return 0;
}
```

