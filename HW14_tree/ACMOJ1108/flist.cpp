#include <cstdio>
#include <string.h>
#include <unordered_map>
#include <list>
char middle[1010], level[1010], first[1010];
std::unordered_map<char, int> char_to_idx;  // ch 在 middle 中的下标
std::list<char> flist;

struct node{
    char ch;
    node *lson = nullptr, *rson = nullptr;
    node(char s) :ch(s) {}
};

void Build(char* inorder, char* levelorder) {
    if (!levelorder || !inorder || !strlen(levelorder) || !strlen(inorder))  return;
    char root = levelorder[0];
    flist.push_back(root);
    int rootidx = char_to_idx[root], len = strlen(levelorder);
    char left[1000], right[1000];
    int l = 0, r = 0;
    for (int i = 1; i < len; ++i) {
        if (char_to_idx[levelorder[i]] < rootidx) {
            left[l++] = levelorder[i];
        }
        if (char_to_idx[levelorder[i]] > rootidx) {
            right[r++] = levelorder[i];
        }
    }
    left[l] = right[r] = '\0';
    l = r = 0;
    char leftinorder[1000], rightorder[1000];
    len = strlen(inorder);
    for (int i = 0; i < len; ++i) {
        if (inorder[i] == root)  rootidx = i;
    }
    for (int i = 0; i < rootidx; ++i)  leftinorder[l++] = inorder[i];
    for (int i = rootidx + 1; i < len; ++i)  rightorder[r++] = inorder[i];
    leftinorder[l] = rightorder[r] = '\0';
    
    Build(leftinorder, left);
    Build(rightorder, right);
}

int main() {
    scanf("%s", middle);  scanf("%s", level);
    int len = strlen(middle);
    for (int i = 0; i < len; ++i)  char_to_idx[middle[i]] = i;
    Build(middle, level);
    for (auto ch : flist)  printf("%c", ch);
    printf("\n");
    return 0;
}
// 给中序和按层遍历，输出先序遍历的结果
// 二叉树