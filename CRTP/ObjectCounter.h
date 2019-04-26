/*
 * Header file demonstrating the use of CRTP to give a class functionality to
 * keep track of the number of current instances of itself.
 */
#include <cstddef>
#include <string>
#include <vector>
template <typename CountedType>
class ObjectCounter {
private:
    // use inline keyword to allow for static variable definition in interface
    inline static size_t count = 0;

protected:

    // default constructor
    ObjectCounter() {
        ++count;
    }

    // copy constructor
    ObjectCounter(ObjectCounter<CountedType> const&) {
        ++count;
    }

    // move constructor
    ObjectCounter(ObjectCounter<CountedType> &&) {
        ++count;
    }

    // destructor
    ~ObjectCounter() {
        --count;
    }

public:

    // return number of existing objects
    static size_t live() {
        return count;
    }
};

// example

class MyString : public ObjectCounter<MyString> {
private:
    std::string str;
public:
    MyString() : str("hello world") {}
};
