//
//  main.cpp
//  test_class_inheritance
//
//  Created by Evandro Liani on 6/13/26.
//

#include <iostream>
#include <thread>

class Parent {
public:
    Parent(){
        std::cout << "I am a parent" << std::endl;
    }
    
    virtual void print_nice_format(){
        std::cout << "Parents are expected to teach children how to behave" << std::endl;
    }
};

class Child : public Parent {
public:
    Child(){
        std::cout << "I am a child" << std::endl;
    }
    
    void print_nice_format() override{
        std::cout << "Children are expected to show good manners" << std::endl;
    }
};

void thread_func(){
    std::cout << "Printing inside the thread" << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Parent * my_parent = new Parent();
    Child * my_child = new Child();
    my_parent->print_nice_format();
    my_child->print_nice_format();
    Parent * my_relative = new Child();
    my_relative->print_nice_format();
    
#
    std::thread my_thread(thread_func);
    my_thread.detach();
    
    std::cout << "Finishing main program" << std::endl;
    return 0;
}
