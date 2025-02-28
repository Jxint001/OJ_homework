#ifndef ROLLING_HASH_HPP
#define ROLLING_HASH_HPP

// #include <iostream>
#include <vector>
#include <string>

class RollingHash {
private:
    long long p1, p2, B;
    // 在这里添加你需要的私有成员变量和函数
    std::vector<int> hash1;
    std::vector<int> hash2;
    std::vector<long long> power1;
    std::vector<long long> power2;
    int len;

public:
 RollingHash(){
     //初始化你的class
    p1 = 131, p2 = 1e7 + 9;
    //p1 = 3, p2 = 5;
    std::vector<int> ().swap(hash1);
    std::vector<int> ().swap(hash2);
    hash1.push_back(1);
    hash2.push_back(1);
    std::vector<long long>().swap(power2);
    std::vector<long long>().swap(power2);
    power1.push_back(1);
    power2.push_back(1);
    len = 1;
    B = 131;
 };

~RollingHash(){
    std::vector<int> ().swap(hash1);
    std::vector<int> ().swap(hash2);
    std::vector<long long>().swap(power2);
    std::vector<long long>().swap(power2);
    len = 1;
};
std::pair<long long, long long> getp(){
    return std::pair<long long, long long> (p1,p2);
};
// 将字符 c 追加到字符串末尾
void append(char c) {
    int val = c - 'a' + 1;
    hash1.push_back((hash1[len - 1] * B + val) % p1);
    hash2.push_back((hash2[len - 1] * B + val) % p2);
    power1.push_back((power1[len - 1] * B) % p1);
    power2.push_back((power2[len - 1] * B) % p2);
    ++len;
}

// 获取从位置 l 到位置 r 的子串的哈希值（1-based 索引）
// 返回一个包含两个 long long 的 pair，分别是两个模数下的哈希值
std::pair<long long, long long> getHash(int l, int r) {
    int length = r - l + 1;
    long long h1 = (hash1[r] - hash1[l - 1] * power1[length]) % p1;
    if (h1 < 0)  h1 += p1;
    long long h2 = (hash2[r] - hash2[l - 1] * power2[length]) % p2;
    if (h2 < 0)  h2 += p2;
    return std::pair<long long, long long> (h1, h2);
}

};

#endif