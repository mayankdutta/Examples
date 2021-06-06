/*
 * I think there is need for clarification.
 * I see two heaps as:
 * 1) build two sets (size of k / 2 and k — k / 2) for a[1..k]. Elements of first set will be not greater than elements of second.
 * 2) for shifting window by 1 to the right, we need to hold sets of that size.
 * 3) Then for each step answer is biggest element of first set.
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class Multiset {
  long N, M;
  vector<int> arr;
  multiset<long> up, low;

  public:

  void Insert(long val) { // insert val into sets
    if(*low.rbegin() < val){
      up.insert(val);
      if(up.size() > M/2){
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
      }
    }
    else{
      low.insert(val);
      if(low.size() > (M + 1)/2){
        up.insert(*low.rbegin());
        low.erase(low.find(*low.rbegin()));
      }
    }
  }

  void Erase(long val){ // erase from sets
    if(up.find(val) != up.end()) up.erase(up.find(val));
    else low.erase(low.find(val));
    if(low.empty()){
      low.insert(*up.begin());
      up.erase(up.find(*up.begin()));
    }
  }
  void Main() {
    cin >> N >> M;
    arr.resize(N);
    for(int i = 0; i < N; i++) cin >> arr[i];

    low.insert(arr[0]);
    for(int i = 1; i < M; i++) Insert(arr[i]);
    cout << *low.rbegin() << " ";

    for(long i = M; i < N; i++){
      if(M == 1){
        Insert(arr[i]);
        Erase(arr[i - M]); // or can use two pointers.
      }
      else{
        Erase(arr[i - M]);
        Insert(arr[i]);
      }
      cout << *low.rbegin() << " ";
    }
  }
};

int main() {
  Multiset st;
  st.Main();
}

