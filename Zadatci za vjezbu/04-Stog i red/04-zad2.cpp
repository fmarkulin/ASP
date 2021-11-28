#include "04-zad1.cpp"

template <class T>
bool peek(Stack<T> s, T &item)
{
    if(s.pop(item))
    {
        s.push(item);
        return true;
    }
    return false;
}