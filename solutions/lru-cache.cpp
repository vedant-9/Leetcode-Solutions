// https://leetcode.com/problems/lru-cache

class LRUCache {
    // Two structures working together:
    //   items -> usage order (front = most recently used, back = least)
    //   pos   -> key to its exact node in `items`, so we never scan the list
    int capacity;
    list<pair<int,int>> items;                              // nodes of {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> pos;  // key -> node iterator

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;              // not cached

        // touching a key makes it most recently used -> move its node to front.
        // splice relinks pointers in O(1) and keeps the iterator valid,
        // so `pos` needs no update.
        items.splice(items.begin(), items, it->second);
        return it->second->second;                   // ->second (pair).second (value)
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {                       // already present: refresh it
            it->second->second = value;              // overwrite stored value
            items.splice(items.begin(), items, it->second);  // and mark most recent
            return;
        }

        if ((int)items.size() == capacity) {         // no room: evict LRU first
            pos.erase(items.back().first);           // back = least recently used
            items.pop_back();
        }

        // brand new key becomes the most recently used -> insert at front
        items.push_front({key, value});
        pos[key] = items.begin();                    // remember where it landed
    }
};
