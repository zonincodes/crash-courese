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

int main()
{

    CountIf s_counter{'s'};
    auto sally = s_counter("Sally sells seashells at the seashore.");
    printf("Sally: %zd\n", sally);

    auto sailor  = s_counter("Sailor went to sea to see what he could see.");
    printf("Sailors: %zd\n", sailor);

    auto buffalo = CountIf{'f'}("Buffalo buffalo buffalo buffalo buffalo buffalo buffalo ");
    printf("Buffalo: %zd\n", buffalo);
    return 0;
}