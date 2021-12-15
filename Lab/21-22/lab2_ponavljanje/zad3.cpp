#include <iostream>
#include <ctime>

class Stog
{
    static const int MAX = 100;
    int stog[MAX];
    int i = -1;

public:
    bool push(int element)
    {
        if(i == MAX - 1)
            return false; // stog je pun
        stog[++i] = element;
        return true;
    }
};

int main(void)
{
    Stog *stog = new Stog;
    srand(time(NULL));
    for(int i = 0; i < 101; i++)
    {
        int element = rand();
        if(!stog->push(element))
            std::cout << "Nisam uspio dodati element: " << element << std::endl;
    }

    delete stog;

    return 0;
}