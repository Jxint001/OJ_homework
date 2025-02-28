#ifndef SKIP_LIST_HPP
#define SKIP_LIST_HPP

#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <optional>

using std::vector;
template<typename T>
class SkipList {
private:
    //add whatever you want here
    template<typename Y = T>
    class Node {
        public:
            std::optional<Y> val;
            vector <Node*> forward;
            Node(Y value, int level) : val(value), forward(level + 1, nullptr) {}
            Node(int level) : forward(level + 1, nullptr) {}
            ~Node() = default;
    };

    static constexpr int MAXL = 32;
    static constexpr int MASK = 0xFFFF;
    static constexpr int BOUND = MASK / 4;
    //Node<T>* h_forward[MAXL + 1] = {nullptr};
    Node<T>* head = nullptr;
    int level = 0;

    int randomLevel() {
        int lv = 1;
        while ((rand() & MASK) < BOUND && lv < MAXL) { ++lv; }
        return lv;
    }

public:
    SkipList () {
        head = new Node<T>(MAXL);
        srand(time(nullptr));
    };

    ~SkipList () {
        Node<T>* p = head;
        while (p) {
            Node<T>* next = p->forward[0];
            delete p;
            p = next;
        }
        //delete head;
    };

    // Insert a value into the skip list. If the value already exists, do nothing.
    void insert(const T & item) {
        //search and determine the node to insert_after
        Node<T>* p = head;
        Node<T>* update[MAXL + 1];
        for (int i = 0; i <= MAXL; ++i) {update[i] = nullptr; }
        for (int i = level; i >= 0; --i) {
            while (p->forward[i] && (p->forward[i]->val) < item) {
                p = p->forward[i];
            }
            update[i] = p;
        }
         p = p->forward[0];
        // if value exists
        if (p && !(item < (p->val))) {return; }
        // get max_length of new_node
        int lv = randomLevel();
        // bool newlevel = 0;
        Node<T>* newNode = new Node<T>(item, lv);
        if (lv > level) {
            lv = ++level;
            update[lv] = head;

        }
        // insert new_node into each level
        for (int i = lv; i >= 0; --i) {

            p = update[i];
            newNode->forward[i] = p->forward[i];
            p->forward[i] = newNode;
        }
    }

    // Search for a value in the skip list
    bool search (const T & item) {
        Node<T>* p = head;
        if (!p) {return false; }
        for (int i = level; i >=0; --i) {
            while (p->forward[i] && (p->forward[i]->val) < item) {
                p = p->forward[i];
            }
        }
        //if (p && !(p->val < item) && !(item < p->val)) {return true; }  //search head
        p = p->forward[0];
        if (!p) {return false; }
        return !((p->val) < item) && !(item < (p->val));
    }

    // Delete a value from the skip list. If the value does not exist in the skip list, do nothing.
    void deleteItem(const T & item){
        //search and determine the node before the to_be_delete node
        Node<T>* p = head;
        //if (!p) {return; }
        Node<T>* before[MAXL + 1];
        for (int i = 0; i <= MAXL; ++i) {before[i] = nullptr; }
        for (int i = level; i >= 0; --i) {
            while (p->forward[i] && (p->forward[i]->val) < item) {
                p = p->forward[i];
            }
            before[i] = p;
        }
        p = p->forward[0];
        if (!p || item < (p->val)) {return; }
        for (int i = 0; i <= level; ++i) {
            if (before[i]->forward[i] != p) {break; }
            before[i]->forward[i] = p->forward[i];
        }
        delete p;
        // remove "empty" level: only head->tail(nullptr)
        while (level > 0 && head->forward[level] == nullptr) {--level; }

    };
};

#endif