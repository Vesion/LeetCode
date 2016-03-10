#include <iostream>
#include <vector>
#include <set>
using namespace std;


// Based on 079-WordSearch.
//
// We would need to optimize our backtracking to pass the larger test, so that we should stop backtracking earlier.
// If the current candidate does not exist in all words' prefix, we could stop backtracking immediately.
// That is, use Trie.


class TrieNode{
public:
    bool is_end;
    TrieNode* children[26];
    TrieNode(){
        is_end=false;
        fill_n(children, 26, nullptr);
    }   
};

class Trie{
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>& words){
        root=new TrieNode();
        for(int i=0; i<words.size(); ++i)
            addWord(words[i]);
    }
    void addWord(const string& word){
        TrieNode* cur=root;
        for(int i=0; i<word.size(); ++i){
            int index=word[i]-'a';
            if(cur->children[index]==NULL)   
                cur->children[index]=new TrieNode();
            cur=cur->children[index];    
        }
        cur->is_end=true;
    }
private:
    TrieNode* root;
};



void dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result){
    if(x<0||x>=board.size()||y<0||y>=board[0].size() || board[x][y]==' ') return;
    if(root->children[board[x][y]-'a'] != NULL){
        word=word+board[x][y];
        root=root->children[board[x][y]-'a']; 
        if(root->is_end) result.insert(word);
        char c=board[x][y];
        board[x][y]=' ';
        dfs(board, x+1, y, root, word, result);
        dfs(board, x-1, y, root, word, result);
        dfs(board, x, y+1, root, word, result);
        dfs(board, x, y-1, root, word, result);
        board[x][y]=c;        
    }
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie* trie = new Trie(words);
    TrieNode* root=trie->getRoot();
    set<string> result_set;
    for(int x=0; x<board.size(); ++x)
        for(int y=0; y<board[0].size(); ++y)
            dfs(board, x, y, root, "", result_set);

    vector<string> result;
    for(auto it:result_set)    result.push_back(it);
    return result;        
}

int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    auto result = findWords(board, words);
    for (auto w:result) cout << w << endl;
    return 0;
}
