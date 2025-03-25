// n-ary tree to binary tree: "transform.cpp"
#ifndef NAryTree_To_BinaryTree
#define NAryTree_To_BinaryTree

#include "tree.hpp"

BinaryTree* Transform(const NAryTree *node) {
    // @argu node(pointer to NAryTree): pointer to the root of the n-ary tree you want to transform
    if (!node) return nullptr;

    BinaryTree* bt_node = new BinaryTree(node->val);
    if (!node->children.empty()) {
        // 第一个子节点作为左儿子
        bt_node->lson = Transform(node->children[0]);
        BinaryTree* current = bt_node->lson;
        // 其余子节点作为右链
        for (size_t i = 1; i < node->children.size(); ++i) {
            current->rson = Transform(node->children[i]);
            current = current->rson;
        }
    }
    return bt_node;
}


#endif