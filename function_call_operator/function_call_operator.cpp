// operator()()

/*
struct type-name{
    return-type operator()(arg-type1 arg1, arg-type2 arg2, ...)
    {
        Body of function-call operator
    }
}
*/

//  a counting example
#include <cstdio>
#include <cstdint>

struct CountIf{
    CountIf(char x) :  x{x}{}
    size_t operator()(const char* str) const {
        size_t index{}, result{};

        while (str[index])
        {
            if(str[index] == x) result++;
            index++;
        }
        return result;
        
    }


    private:
        const char x;
};