#include <iostream> 
#include <fstream> 
#include <sstream> 
using namespace std;

int main() {
  ifstream fin("in", ios::in);
  string s;
  while (!getline(fin, s).eof()) {
    cout << s << endl;
    cout << "tellg: " << fin.tellg() << endl;
  }

  fin.clear();
  fin.seekg(0);

  while (fin >> s) {
    cout << s << endl;
    cout << "tellg: " << fin.tellg() << endl;
  }
  fin.close();
  

  ofstream fout("out", ios::trunc);
  fout << "hello world" << endl;
  fout << " world" << endl;
  fout.close();
}
