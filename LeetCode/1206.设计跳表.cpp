#include <cstdlib>
#include <ctime>
/*
 * @lc app=leetcode.cn id=1206 lang=cpp
 *
 * [1206] 设计跳表
 */

// @lc code=start
class Skiplist {
    struct Node{
        int val;
        Node* forward[33];
        Node(int value = 0): val(value) {
            for (int i = 0; i < 33; ++i)  forward[i] = nullptr;
        }
        ~Node() = default;
    };
    
    static constexpr int MAXL = 32;
    static constexpr int MASK = 0xFFFF;
    static constexpr int BOUND = MASK  >> 1;

    Node *head = nullptr;
    int level = 0;

    int randomLevel() {
        int lv = 1;
        while ((rand() & MASK) < BOUND && lv < MAXL)  ++lv;
        return lv;
    }
public:
    Skiplist() {
        head = new Node();
        srand(time(nullptr));
    }

    ~Skiplist() {
        Node *p = head;
        while (p) {
            Node *next = p->forward[0];
            delete p;
            p = next;
        }
    }
    
    bool search(int target) {
        Node *p = head;
        if (!p)  return false;
        for (int i = level; i >= 0; --i) {
            while (p->forward[i] && (p->forward[i]->val) < target)  p = p->forward[i];
        }
        p = p->forward[0];
        if (!p)  return false;
        return p->val == target;
    }
    
    void add(int num) {
        Node *p = head;
        Node* update[MAXL + 1];
        for (int i = 0; i <= MAXL; ++i)  update[i] = nullptr;
        for (int i = level; i >= 0; --i) {
            while (p->forward[i] && (p->forward[i]->val) < num)  p = p->forward[i];
            update[i] = p;
        }
        p = p->forward[0];

        // if (p && num == p->val)  return;
        
        int lv = randomLevel();
        Node *newnode = new Node(num);
        if (lv > level) {
            lv = ++level;
            update[lv] = head;
        }

        for (int i = lv; i >= 0; --i) {
            p = update[i];
            newnode->forward[i] = p->forward[i];
            p->forward[i] = newnode;
        }
    }
    
    bool erase(int num) {
        Node* p = head;
        Node* before[MAXL + 1];
        for (int i = 0; i <= MAXL; ++i) {before[i] = nullptr; }
        for (int i = level; i >= 0; --i) {
            while (p->forward[i] && (p->forward[i]->val) < num)  p = p->forward[i];
            before[i] = p;
        }
        p = p->forward[0];

        if (!p || num != p->val) {return false; }

        for (int i = 0; i <= level; ++i) {
            if (before[i]->forward[i] != p) {break; }
            before[i]->forward[i] = p->forward[i];
        }
        delete p;
        // remove "empty" level: only head->tail(nullptr)
        while (level > 0 && head->forward[level] == nullptr) {--level; }
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end

