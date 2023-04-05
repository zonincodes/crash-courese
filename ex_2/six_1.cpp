// Exercise one
/*
The mode of a series of values is the value that appears most commonly.
Implement a mode function using the following signature: int mode(const
int* values, size_t length). If you encounter an error condition, such as
input having multiple modes and no values, return zero.*/

#include <cstdio>

int mode(const int *values, size_t length)
{
    if(!values || !length) return 0;
}

template<int T, size_t length>
int mode(T *values, size_t length)
{
    return 0;
};