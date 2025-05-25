#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2296 lang=cpp
 *
 * [2296] 设计一个文本编辑器
 */

// @lc code=start
class TextEditor {
    string left, right;  // 光标左侧和右侧的字符，尾对尾

    string text() {
        // 获取光标左侧最多 10 个字符
        return left.substr(max((int)left.length() - 10, 0));
    }
public:
    TextEditor() {
    }
    
    void addText(string text) {
        left += text;
    }
    
    int deleteText(int k) {
        k = min((int)left.length(), k);
        left.resize(left.length() - k);
        return k;
    }
    
    string cursorLeft(int k) {
        while (k && !left.empty()) {
            right += left.back();
            left.pop_back();
            --k;
        }
        return text();
    }
    
    string cursorRight(int k) {
        while (k && !right.empty()) {
            left += right.back();
            right.pop_back();
            --k;
        }
        return text();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
// @lc code=end

