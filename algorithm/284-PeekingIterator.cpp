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
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
    bool hasPeeked;
    int peekedValue;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasPeeked = false;
        peekedValue = 0;
	}

	int peek() {
        if (!hasPeeked) {
            hasPeeked = true;
            peekedValue = Iterator::next();
        }
        return peekedValue;
	}

	int next() {
	    if (hasPeeked) {
            hasPeeked = false;
            int result = peekedValue;
            return result;
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
