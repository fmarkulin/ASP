#include <iostream>

template <typename T>
struct ListElement
{
    T data;
    ListElement<T> *next;
};

template <typename T>
class List
{
    ListElement<T> *head = nullptr;

public:
    void removeGreaterThan(T item)
    {
        ListElement<T> **p;
        p = &head;
        while((*p) != nullptr)
        {
            if((**p).data > item)
            {
                ListElement<T> *tmp;
                tmp = (*p);
                (*p) = (**p).next;
                delete tmp;
            }

            p = &((**p).next);
        }
        return;
    }
};
