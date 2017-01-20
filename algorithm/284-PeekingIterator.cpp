#include <iostream>
#include <vector>
using namespace std;

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	int next();
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
    bool hasPeeked;
    int nextVal;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    hasPeeked = false;
	}

	int peek() {
        if (!hasPeeked)
            nextVal = Iterator::next();
        hasPeeked = true;
        return nextVal;
	}

	int next() {
	    if (hasPeeked) {
	        hasPeeked = false;
	        return nextVal;
	    }
	    return Iterator::next();
	}

	bool hasNext() const {
	    return Iterator::hasNext() || hasPeeked;
	}
};


int main() {
    return 0;
}
