#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list> 
#include <map> 
using namespace std;

// list + ordered map
class MaxStack {
private:
  using lit = list<int>::iterator;
  list<int> st;
  map<int, vector<lit>> m;

public:
  MaxStack() {}
  
  void push(int x) { // O(logn)
    st.push_back(x);
    m[x].push_back(--st.end());
  }
  
  int pop() { // O(logn)
    int x = st.back();
    st.pop_back();
    m[x].pop_back();
    if (m[x].empty()) m.erase(x);
    return x;
  }
  
  int top() { // O(1)
    return st.back();
  }
  
  int peekMax() { // O(logn)
    return (--m.end())->first;
  }
  
  int popMax() { // O(logn)
    auto t = --m.end();
    st.erase(t->second.back());
    t->second.pop_back();
    if (t->second.empty()) m.erase(t->first);
    return t->first;
  }
};


int main() {
  MaxStack m;
  m.push(5);
  m.push(1);
  m.push(-5);
  cout << m.popMax() << endl;
  cout << m.popMax() << endl;
  cout << m.top() << endl;
  return 0;
}
