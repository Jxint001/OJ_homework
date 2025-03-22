#include <iostream>
#include <string.h>
const int maxn1 = 2e7 + 5;
const int maxn2 = 1e6 + 5;
char s1[maxn1], s2[maxn2];
int next[maxn2];  // next[i]是第0~i个字符构成的字串的最长相同前后缀长度（也就是最长border长度）
inline void getNext() {
    next[0] = 0;
    int i = 1, j = 0; // j是最长相同前后缀的长度，也是前缀末尾，i是后缀末尾
    int SN = strlen(s2);
    for (; i < SN; ++i) {
        while (j > 0 && s2[j] != s2[i])  j = next[j - 1];
        if (s2[j] == s2[i])  ++j;
        next[i] = j;
    }
}
int main() {
    std::cin >> s1 >> s2;
    getNext();
    int j = 0, SN1 = strlen(s1), SN2 = strlen(s2);
    for (int i = 0; i < SN1; ++i) {
        while (j > 0 && s1[i] != s2[j]) j = next[j - 1];
        if (s1[i] == s2[j]) ++j;
        if (j == SN2) {
            std::cout << i - j + 2 << std::endl;
            j = next[j - 1];
        }
    }
    for (int i = 0; i < SN2; ++i)  std::cout << next[i] << " ";
    std::cout << std::endl;
}