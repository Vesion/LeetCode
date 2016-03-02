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

class LRUCache{
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v) : key(k), value(v) {}
    };

    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cacheMap.count(key) == 0) return -1;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }

    void set(int key, int value) {
        if (cacheMap.count(key) == 0) {
            if (cacheList.size() == this->capacity) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
        else {
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }
};


int main() {
    LRUCache lru(3);
    cout << lru.get(1) << endl;

    lru.set(1, 1);
    lru.set(2, 2);
    lru.set(3, 3);
    cout << lru.get(1) << endl;

    lru.set(4, 4);
    cout << lru.get(2) << endl;

    return 0;
}
