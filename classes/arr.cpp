#include <iostream>
class X {
    public:
        X (std::initializer_list<int> list) {
        for (auto i = list.begin(); i != list.end(); i++) {
                std::cout << *i << std::endl;
            }
        }
};


int main () {
    X x = {1,2,3,4,5};
}


