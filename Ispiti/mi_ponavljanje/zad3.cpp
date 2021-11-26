#include <iostream>

template <typename T>

class List
{
private:
    struct ListElement
    {
        T data;
        ListElement *next;
    };

    ListElement *head = nullptr;

public:
    void removeGreaterThan(T item)
    {
        ListElement **p = &head;
        //p je 2pok
        //*p je head / next (pokazivač na neki LE)
        //**p je LE

        while (*p != nullptr)
        {
            // std::cout << (*p)->data << " ";
            if ((*p)->data > item)
            {
                ListElement *tbd = *p;
                *p = (*p)->next;
                delete tbd;
            }
            else
            {
                p = &((*p)->next);
            }
        }
    }
};