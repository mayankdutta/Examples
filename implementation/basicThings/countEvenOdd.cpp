// not much but looks cleaner
int32_t main() {
  int tc;
  cin >> tc;
  while(tc--){
    string s;
    cin >> s;
    int even =0 ;
    int odd = 0;
    map<char,int> cnt;
    for(auto node : s) cnt[node]++;
    for(auto node : cnt){
      odd += (node.ss)%2;  // remainder will always be 1 if node.ss is odd
      even += (node.ss)/2; // will always be 1 if node.ss is even
    }
    if(odd <=even) cout << "YES" << endl;
    else cout <<"NO" << endl;
  }
}
