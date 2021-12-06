#include <iostream>
#include <ctime>

class Stog
{
private:
    static const int MAX = 10;
    int stack[MAX];
    int top = -1;

public:
    bool push(int element)
    {
        top++;
        if (top > MAX - 1)
        {
            top--;
            return false;
        }
        stack[top] = element;
        return true;
    }

    bool pop(int &element)
    {
        if (top < 0)
            return false;
        element = stack[top--];
        return true;
    }
};

int main(void)
{
    Stog *stog = new Stog;
    srand(time(NULL));

    //za testiranje stack behaviour
    // for(int i = 0; i < 12; i++)
    // {
    //     stog->push(i + 1);
    // }

    for(int i = 0; i < 10; i++)
    {
        int element = rand() % (10 + 1 - 1) + 1;
        stog->push(element);
    }

    Stog *stogZaIspis = new Stog;
    int popped;
    while(stog->pop(popped))
        stogZaIspis->push(popped);
    
    while(stogZaIspis->pop(popped))
        std::cout << popped << std::endl;

    delete stog;
    delete stogZaIspis;

    return 0;
}