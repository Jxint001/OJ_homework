// "Wrapper": example.cpp
#include <iostream>
#include <string>

#include "func_wrapper.hpp"

void foo(std::string id) { std::cout << id << std::endl; }
void before() { std::cout << "before foo" << std::endl; }
void after() { std::cout << "after foo" << std::endl; }

int main(){
    Wrapper *f = create(foo, before, after);
    run(f, "Hello");
    Wrapper *g = create(foo, after, before);
    run(g, "World!");
    remove(g);
    destroy();
    return 0;
}