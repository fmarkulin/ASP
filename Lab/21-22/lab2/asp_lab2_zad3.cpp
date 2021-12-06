#include <iostream>
#include <ctime>

class Stog
{
private:
    static const int MAX = 100;
    int stack[MAX];
    int top = -1;

public:
    bool push(int element)
    {
        top++;
        if(top > 99)
        {
            top--;
            return false;
        }
        stack[top] = element;
        return true;
    }

    void ispis()
    {
        for(int i = 0; i <= top; i++)
        {
            std::cout << stack[i] << " ";
        }
    }
};

int main(void)
{
    Stog *stog = new Stog;
    srand(time(NULL));

    for(int i = 0; i < 101; i++)
    {
        stog->push(i);
    }

    stog->ispis();

    delete stog;

    return 0;
}