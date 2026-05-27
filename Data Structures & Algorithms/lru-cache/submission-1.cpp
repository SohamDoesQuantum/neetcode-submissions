class LRUCache {
   public:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    };
    int cap;
    Node* head;
    Node* tail;
    int size;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        deleteNode(node);
        addNode(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            addNode(node);
            return;
        }
        if (size == cap) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
            size--;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        addNode(node);
        size++;
    }
    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void addNode(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
    }
};
