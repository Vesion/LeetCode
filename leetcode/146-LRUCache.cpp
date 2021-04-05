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
    using Cache = list<pair<int,int>>;
    Cache cache;
    unordered_map<int, Cache::iterator> table;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = table.find(key);
        if (it == table.end()) return -1;
        auto cit = it->second;
        int val = cit->second;
        cache.splice(cache.begin(), cache, cit);
        table[key] = cache.begin();
        return val;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            table[key]->second = value;
        } else {
            if (cache.size() == cap) {
                int k = cache.back().first;
                table.erase(k);
                cache.pop_back();
            }
            cache.push_front({key, value});
            table[key] = cache.begin();
        }
    }
};


int main() {
    return 0;
}
