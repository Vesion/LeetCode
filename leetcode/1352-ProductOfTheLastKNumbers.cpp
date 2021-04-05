#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Prefix products, be careful of zeros
class ProductOfNumbers {
public:
    vector<int> prods;

    ProductOfNumbers() {
        prods = {1};
    }

    void add(int num) {
        if (num) prods.push_back(prods.back() * num);
        else prods = {1};
    }

    int getProduct(int k) {
        return k < prods.size() ? prods.back() / prods[prods.size()-k-1] : 0;
    }
};

int main() {

}
