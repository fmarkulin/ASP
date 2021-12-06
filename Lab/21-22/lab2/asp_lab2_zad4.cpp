#include <iostream>
#include <ctime>

class Stog
{
    struct StogElement
    {
        int data;
        StogElement *next;
    };

    StogElement *top = nullptr;

public:
    bool push(int data)
    {
        StogElement *newElement = new (std::nothrow) StogElement;
        if (!newElement)
            return false;
        newElement->data = data;
        newElement->next = top;
        top = newElement;
        return true;
    }

    void ispis()
    {
        StogElement **p = &top;
        while(*p)
        {
            std::cout << (*p)->data << std::endl;
            p = &((*p)->next);
        }
        return;
    }
};

int main(void)
{
    Stog *stog = new Stog;
    srand(time(NULL));

    for(int i = 0; i < 101; i++)
    {
        int element = rand();
        stog->push(element);
    }

    //for testing stack behaviour
    // for(int i = 0; i < 101; i++)
    // {
    //     stog->push(i);
    // }

    stog->ispis();

    delete stog;

    return 0;
}