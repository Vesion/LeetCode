#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Implement a simplified version of class string

class String {
private:
    char* m_data;
public:
    String(const char* str = NULL) {
        if (str == NULL) {
            m_data = new char[1];
            *m_data = '\0';
        } else {
            m_data = new char[strlen(str)+1];
            strcpy(m_data, str);
        }
    }

    String(const String& other) {
        m_data = new char[strlen(other.m_data)+1];
        strcpy(m_data, other.m_data);
    }

    ~String() {
        delete[] m_data;
    }

    String& operator=(const String& other) {
        if (this == &other) return *this;
        delete[] m_data;
        m_data = new char[strlen(other.m_data)+1];
        strcpy(m_data, other.m_data);
        return *this;
    }

    void print() {
        printf("%s\n", m_data);
    }
};


int main() {
    String s("abc");
    s.print();
    String s2(s);
    s2.print();
    String s3 = s2;
    s3.print();
    return 0;
}
