// "Wrapper": src.hpp
#ifndef Wrapper_CPP_Wrapper_HPP
#define Wrapper_CPP_Wrapper_HPP

#include <string>
using std::string;
struct Wrapper {
    // todo: add definitions here
    void (*func)(string);
    void (*before)();
    void (*after)();
    Wrapper* next;
    Wrapper(void (*f)(string), void (*b)(), void (*af)()) 
        : func(f), before(b), after(af), next(nullptr) {}
};
// todo: add definition for link list
Wrapper *head = nullptr;
Wrapper *end = nullptr;

// todo: create()
Wrapper* create(void (*func)(string), void (*before)(), void (*after)()) {
    Wrapper* newfunc = new Wrapper(func, before, after);
    if (end == nullptr) {
        head = newfunc;
        end = newfunc;
    } else {
        end->next = newfunc;
        end = newfunc;
    }
    return newfunc;
}

// todo: remove()
void remove(Wrapper *todelete) {
    if (head == nullptr || todelete == nullptr)  return;
    if (todelete == head) {
        head = head->next;
        if (head == nullptr)  end = nullptr;
        delete todelete;
        return;
    }
    Wrapper* current = head;
    while (current->next != nullptr) {
        if (current->next == todelete) {
            //找到了要删除结点的上一个结点
            current->next = todelete->next;
            if (todelete == end)  end = current;
            delete todelete;
            return;
        }
        current = current->next;
    }
}

// todo: run()
void run(Wrapper *current, string id) {
   current->before();
   current->func(id);
   current->after();
   return;
}

// todo: destroy()
void destroy() {
    Wrapper *current = head;
    while (current != nullptr) {
        Wrapper *nextfunc = current->next;
        delete current;
        current = nextfunc;
    }
    head = nullptr;
    end = nullptr;
    return;
}


#endif //Wrapper_CPP_Wrapper_HPP