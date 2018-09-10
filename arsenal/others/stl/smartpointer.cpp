#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Implement a smart pointer class with template to provide functions like pointer and garbage collections.
// We can use a reference counter to count references, and delete them when counter becomes 0.

template <class T>
class smart_ptr {
private:
    T* ref;
    int* ref_count; // must be pointer to track reference

    void remove() {
        --*ref_count;
        if (*ref_count == 0) {
            delete ref;
            delete ref_count;
            ref = ref_count = nullptr;
        }
    }

public:
    smart_ptr(T* obj) {
        ref = obj;
        ref_count = new int(1);
    }

    smart_ptr(smart_ptr<T>& sptr) {
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++(*ref_count);
    }

    smart_ptr<T>& operator=(smart_ptr<T>& sptr) {
        if (this == &sptr) return *this; // if they are the same obj, return
        if (*ref_count > 0) remove(); // remove old reference

        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++(*ref_count);
        return *this;
    }

    T operator*() {
        return *ref;
    }

    ~smart_ptr() {
        remove();
    }

    int getCounter() { return *ref_count; }
};


int main() {
    smart_ptr<int> sp1(new int(100));    
    cout << *sp1 << endl;
    cout << sp1.getCounter() << endl;

    sp1 = sp1;
    cout << sp1.getCounter() << endl;

    smart_ptr<int> sp2(sp1);
    cout << *sp2 << endl;
    cout << sp2.getCounter() << endl;

    {
        smart_ptr<int> sp3 = sp2;
        cout << *sp3 << endl;
        cout << sp3.getCounter() << endl;
    }

    cout << sp1.getCounter() << endl;
    return 0;
}
