#ifndef DEFERCLASS_HPP
#define DEFERCLASS_HPP
#include <functional>
#include <stack>
class Defer {
private:
    std::stack<std::function<void()>> seq;
    std::function<void()> func;
public:
    Defer(std::function<void()> f) {
        seq.push(f);
    }
    ~Defer() {
        while (!seq.empty()) {
            seq.top()();
            seq.pop();
        } 
    }
    void operator()(std::function<void()> f) {
        seq.push(f);
    }
};
#endif