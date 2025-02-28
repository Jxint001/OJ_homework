#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include <iostream>

#define USE_OS

// Don't delete the error class below.
// 不要删除下面的错误类
class error : public std::exception {
private:
    std::string msg;

public:
    explicit error(const char *_msg_) : msg(_msg_) {}

    const char *toString() {
        return msg.c_str();
    }
};

template <typename T>
class ArrayList {
private:
    T* arr = nullptr;
    int length = 0;
public:
    // todo
    // constructor with a given array (T* arr, int length) 从已有的数组构造
    ArrayList(T* a, int len):length(len) {
        if (length < 0) {
            throw error("invalid length");
        }
        arr = new T[length];
        for (int i = 0; i < length; ++i) { arr[i] = *(a + i); }
    }
    // constructor with fixed length (int length) 构造一个固定长度的数组
    ArrayList(int len):length(len) {
        if (length < 0) {
            throw error("invalid length");
        }
        arr = new T[length];
        for (int i = 0; i < length; ++i) { arr[i] = T(); }
    }
    // copy constructor 拷贝构造函数ArrayList& 
    ArrayList(const ArrayList& oth):length(oth.length) {
        if (length < 0) {
            throw error("invalid length");
        }
        arr = new T[length];
        for (int i = 0; i < length; ++i) { arr[i] = oth[i]; }
    }
    // size()
    int size() const {
        return length;
    }
    // operator[]
    T& operator[](int& id) {
        if (id < 0 || id >= length) {
            throw error("index out of bound");
        }
        return arr[id];
    }
    T& operator[](int&& id) {
        if (id < 0 || id >= length) {
            throw error("index out of bound");
        }
        return arr[id];
    }
    const T& operator[](int& id) const {
        if (id < 0 || id >= length) {
            throw error("index out of bound");
        }
        return arr[id];
    }
    const T& operator[](int&& id) const {
        if (id < 0 || id >= length) {
            throw error("index out of bound");
        }
        return arr[id];
    }
    // operator+ 
    ArrayList operator+(const ArrayList& rhs) const {
        ArrayList<T> temp(length + rhs.length);
        for (int i = 0; i < length; ++i) { temp[i] = arr[i]; }
        for (int i = length; i < length + rhs.length; ++i) { temp[i] = rhs[i - length]; }
        return temp;
    }
    // operator=
    ArrayList operator=(const ArrayList& oth) {
        if (&oth != this) {
            delete[] arr;
            length = oth.length;
            arr = new T[length];
            for (int i = 0; i < length; ++i) { arr[i] = oth[i]; }
        }
        return *this;
    }
    // operator==
    bool operator==(const ArrayList& oth) const {
        if (length != oth.length) { return false; }
        for (int i = 0; i < length; ++i) {
            if (arr[i] != oth[i]) { return false; }
        }
        return true;
    }
    // operator!=
    bool operator!=(const ArrayList& oth) const {
        if (*this == oth) {
            return false;
        }
        return true;
    }
#ifdef USE_OS
    friend std::ostream& operator<<(std::ostream& out, const ArrayList& now) {
        for (int i = 0; i < now.length; ++i) {
            out << now[i] << " ";
        }
        return out;
    }
#else
    // Notice: if you don't know how to implement operator<<,
    // you can use the following two print() functions AND COMMENT
    // "#define USE_OS" IN LINE 6 to enable your print functions.
    // 如果你不知道如何重载 operator<< ，请并注释掉
    // 第六行的 "#define USE_OS" 使得你的 print() 函数能够正常使用。
    void print() {
        for (int i = 0; i < length; i++)
            std::cout << arr[i] << " ";
    }
    void print() const {
        for (int i = 0; i < length; i++)
            std::cout << arr[i] << " ";
    }

#endif

    //destructor 析构函数
    ~ArrayList() {
        delete[] arr;
        arr = nullptr;
    }
};

#endif // ARRAY_LIST_HPP