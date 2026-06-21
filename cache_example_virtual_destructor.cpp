//
//  main.cpp
//  caching_example
//
//  Created by Evandro Liani on 6/20/26.
//

#include <iostream>
#include <vector>

static std::vector<std::string> db_vec({"Evandro","Sara","Lisa","Anna"});

class MyCacheExample
{
public:
    // cctor and destructor
    MyCacheExample(void){};
    ~MyCacheExample(void){};

    // Caching structures
    std::vector<std::string> firstNameVec;
    std::vector<std::string>::iterator itr;

    void CacheSomeData()
    {
        // Setup DB related stuff which is required to create session and connect to a DB
        // Setup the iterator to start caching your data

        // Get data from the result set stored in rcrdSet object
        for (auto tmp : db_vec)
        {
            // insert the data into the vector i.e. "cache" the data for quick look up
            firstNameVec.push_back(tmp);
        }
    }
};


// Use of virtual destructor in base class allows to destroy object of derived class using pointer to base class.
// Without virtual destructor, the derived class object leaks.
class A {
public:
    A(){std::cout << "A" << std::endl;}
    virtual ~A(){std::cout << "a" << std::endl;}
};

class B: public A {
public:
    B(){std::cout << "B" << std::endl;}
    ~B(){std::cout << "b" << std::endl;}
};



int main(int argc, const char * argv[]) {
    // insert code here...
    MyCacheExample persistent_cache;
    persistent_cache.CacheSomeData();
    for (auto tmp: persistent_cache.firstNameVec){
        std::cout << tmp << std::endl;
    }
    // Instance object of derived class using pointer to base
    A * obj = new B();
    delete obj;
    // Output will be A B b a, so it shows the derived destructor is called.
    return 0;
}
