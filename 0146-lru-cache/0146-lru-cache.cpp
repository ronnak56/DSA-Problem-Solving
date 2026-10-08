class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };

    int limit;
    unordered_map<int, Node*> m;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        limit = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void delNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {

        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;
        delNode(ansNode);
        addNode(ansNode);

        return ans;
    }

    void put(int key, int val) {

        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
            delete oldNode;
        }

        if (m.size() == limit) {
            Node* lruNode = tail->prev;
            m.erase(lruNode->key);
            delNode(lruNode);
            delete lruNode;
        }

        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
};