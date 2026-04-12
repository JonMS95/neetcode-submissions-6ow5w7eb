#include <unordered_map>
using namespace std;

class Node
{
public:
    int key;
    int val;
    Node* newer;
    Node* older;

    Node(int i_key, int i_val, Node* i_newer = nullptr, Node* i_older = nullptr)
        : key(i_key), val(i_val), newer(i_newer), older(i_older) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> hist;
    const int size;
    Node* oldest;
    Node* newest;

    void _removeNode(Node* node)
    {
        Node* newer = node->newer;
        Node* older = node->older;

        if (node == oldest)
            oldest = newer;

        if (node == newest)
            newest = older;

        if (older)
            older->newer = newer;

        if (newer)
            newer->older = older;

        node->older = nullptr;
        node->newer = nullptr;
    }

    void _insertNode(Node* node)
    {
        node->newer = nullptr;
        node->older = nullptr;

        if (!newest)
        {
            newest = oldest = node;
            return;
        }

        newest->newer = node;
        node->older = newest;
        newest = node;
    }

public:
    LRUCache(int capacity)
        : size(capacity), oldest(nullptr), newest(nullptr) {}

    int get(int key)
    {
        if (!hist.count(key))
            return -1;

        Node* cur = hist[key];

        _removeNode(cur);
        _insertNode(cur);

        return cur->val;
    }

    void put(int key, int value)
    {
        if (hist.count(key))
        {
            Node* cur = hist[key];
            cur->val = value;

            _removeNode(cur);
            _insertNode(cur);
            return;
        }

        if ((int)hist.size() == size)
        {
            Node* lru = oldest;

            hist.erase(lru->key);
            _removeNode(lru);
            delete lru;
        }

        Node* node = new Node(key, value);

        hist[key] = node;
        _insertNode(node);
    }
};