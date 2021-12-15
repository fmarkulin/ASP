#include <iostream>
#include <ctime>

class Stog
{
    static const int MAX = 10;
    int stog[MAX];
    int top = -1;

public:
    bool push(int element)
    {
        if (top == MAX - 1)
            return false; // stog je pun
        stog[++top] = element;
        return true;
    }

    bool pop(int &element)
    {
        if (top < 0)
            return false; // stog je prazan
        element = stog[top--];
        return true;
    }

    void ispis()
    {
        std::cout << "Ispisujem stog..." << std::endl;
        for (int i = top; i >= 0; i--)
        {
            std::cout << i << ".|" << stog[i] << std::endl;
        }
    }
};

int main(void)
{
    Stog *stog = new Stog;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int element = rand() % (10 + 1 - 1) + 1; // rand() & (max_number + 1 - min_number) + min_number
        stog->push(element);
    }

    stog->ispis();
    
    Stog *stogReversed = new Stog;
    int element;
    while (stog->pop(element))
    {
        stogReversed->push(element);
    }

    std::cout << std::endl;
    stogReversed->ispis();

    delete stog;
    delete stogReversed;

    return 0;
}