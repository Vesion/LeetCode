#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// classical design problem, LRU
//
// LRU的典型实现是一个双向链表和一个哈希表，我们直接使用std::list和std::unordered_map。
//      双向链表插入和删除的效率高，而单向链表需要额外操作查找前驱节点；
//      哈希表保存每个节点的地址，可以保证在O(1)时间内访问到任意节点。
// 具体实现：
//      双向链表的大小就是LRUCache的大小，越靠近头部的节点表示距离上次访问时间越短，越靠近尾部表示离最近访问时间越长；
//      访问（get）节点时，若哈希表中有，直接根据哈希表中节点的地址访问，并把该节点移到链表头部，同时更新哈希表中该节点的地址；
//      插入（set）节点时，若链表的size达到了上限capacit，则删除尾部节点，同时删除哈希表中对应的项；再把新节点插到链表头部，并在哈希表中添加对应的项。

class LRUCache {
private:
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> pos;
    size_t capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!pos.count(key)) return -1;
        auto it = pos[key];
        cache.splice(cache.begin(), cache, it);
        pos[key] = cache.begin();
        return pos[key]->second;
    }
    
    void put(int key, int value) {
        if (!pos.count(key)) {
            if (cache.size() == capacity) {
                pos.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            pos[key] = cache.begin();
        } else {
            get(key);
            pos[key]->second = value;
        }
    }
};


int main() {
    return 0;
}
