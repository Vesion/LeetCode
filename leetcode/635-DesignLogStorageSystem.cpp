#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class LogSystem {
private:
  struct Log {
    int id;
    string t;
    Log(int id, string timestamp) : id(id), t(timestamp){ }
  };
  vector<Log> logs;
  unordered_map<string, int> index = {
    {"Year", 4},
    {"Month", 7},
    {"Day", 10},
    {"Hour", 13},
    {"Minute", 16},
    {"Second", 19},
  };

public:
  LogSystem() { }

  void put(int id, string timestamp) {
    logs.push_back(Log(id, timestamp));
  }

  vector<int> retrieve(string s, string e, string gra) {
    vector<int> res;
    for (Log& l : logs) {
      if (s.substr(0, index[gra]) <= l.t.substr(0, index[gra]) && l.t.substr(0, index[gra]) <= e.substr(0, index[gra]))
        res.push_back(l.id);
    }
    return res;
  }
};


int main() {
  LogSystem l;
  l.put(1, "2017:01:01:23:59:59");
  l.put(2, "2017:01:01:22:59:59");
  l.put(3, "2016:01:01:00:00:00");
  vector<int> r;
  r = l.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year");
  for (auto& e : r) cout << e << " "; cout << endl; 
  r = l.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour");
  for (auto& e : r) cout << e << " "; cout << endl; 
  return 0;
}
