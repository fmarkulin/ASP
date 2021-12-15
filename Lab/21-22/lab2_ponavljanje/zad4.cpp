#include <iostream>
#include <ctime>

template <class T>
class Stog
{
    template <class X>
    struct StogElement
    {
        X data;
        StogElement<X> *next;
    };

    StogElement<T> *top = nullptr;

public:
    bool push(T element)
    {
        StogElement<T> *newElement = new (std::nothrow) StogElement<T>;
        if(!newElement)
            return false; // neuspjelo stvaranje novog elementa
        newElement->data = element;
        newElement->next = top;
        top = newElement;
        return true;
    }

    void ispis()
    {
        StogElement<T> **p = &top;
        int i = 1;
        while(*p)
        {
            std::cout << i++ << ".|" << (*p)->data << std::endl;
            p = &((*p)->next);
        }
    }
};

int main(void)
{
    Stog<int> *stog = new Stog<int>;
    srand(time(NULL));
    for(int i = 0; i < 101; i++)
    {
        int element = rand();
        if(!stog->push(element))
            std::cout << "Nisam uspio ubaciti " << i << ". element: " << element << std::endl;
    }
    stog->ispis();

    delete stog;

    return 0;
}