#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// A prefix code is a type of code system which requires that there is NO whole code word is a prefix of any other code word.
// Huffman coding is a typical Prefix Code

typedef pair<int, int> CharFreq;
typedef vector<bool> HuffCode;
typedef unordered_map<int, HuffCode> HuffMap;

struct HuffNode {
    int val;
    int freq;
    HuffNode* left;
    HuffNode* right;
    HuffNode(int x, int f) : val(x), freq(f), left(NULL), right(NULL) {}
    HuffNode(HuffNode* n1, HuffNode* n2) : val(0) , freq(n1->freq + n2->freq), left(n1), right(n2) {}
};

struct Cmp {
    bool operator()(const HuffNode* n1, const HuffNode* n2) {
        return n1->freq > n2->freq; // min heap
    }
};

// build tree using priority_queue
HuffNode* BuildHuffTree(vector<CharFreq>& data) {
    priority_queue<HuffNode*, vector<HuffNode*>, Cmp> Q;
    for (auto & n : data) Q.push(new HuffNode(n.first, n.second));
    while (Q.size() > 1) {
        HuffNode* ln = Q.top(); Q.pop();
        HuffNode* rn = Q.top(); Q.pop();
        HuffNode* pn = new HuffNode(ln, rn);
        Q.push(pn);
    }
    return Q.top(); 
}

// generate coding using dfs
void generateHuffCoding(HuffNode* root, HuffCode& path, HuffMap& result) {
    if (!root->left && !root->right) {
        result[root->val] = path;
        return;
    }
    path.push_back(0);
    generateHuffCoding(root->left, path, result);
    path.pop_back();

    path.push_back(1);
    generateHuffCoding(root->right, path, result);
    path.pop_back();
}

HuffMap getHuffCoding(vector<CharFreq>& data) {
    auto root = BuildHuffTree(data);
    HuffMap result;
    HuffCode path;
    generateHuffCoding(root, path, result);
    return result;
}

int main() {
    vector<CharFreq> v = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    auto result = getHuffCoding(v);
    for (auto & m : result) {
        cout << m.first << " : ";
        for (auto i : m.second) cout << i;
        cout << endl;
    }
    
    return 0;
}
