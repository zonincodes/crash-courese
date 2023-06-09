// lambda  expression usage
/*
captures: The member variables of the function object(i.e
    the partially applied parameters)
parameters: The arguments required to invoke the function object
body: The function object's code
specifiers: Elements like constexpr, mutable, noexcept, and [[noreturn]]
return type: The type returned by the function object
*/

// [captures] (parameters) modifiers -> return-type { body }

#include <cstdio>
#include <cstdint>

template <typename Fn>
void transform(Fn fn, const int* in, int* out, size_t length)
{
    for(size_t i{}; i < length; i++){
        out[i] = fn(in[i]);
    }
}

int main()
{
    const size_t len{3};
    int base[]{1, 2, 3}, a[len], b[len], c[len];
    transform([](int x)
              { return 1; },
              base, a, len);
    transform([](int x)
              { return x; },
              base, b, len);
    transform([](int x)
              { return 10*x+5; },
              base, c, len);
    
    for ( size_t i{}; i < len; i++)
    {
        printf("Element %zd: %d %d %d\n", i, a[i], b[i], c[i]);
    }
}