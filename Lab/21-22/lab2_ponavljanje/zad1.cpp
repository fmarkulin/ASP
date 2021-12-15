#include <iostream>

template <class T>
class List
{
    template <class X>
    struct Cvor
    {
        X data;
        Cvor<X> *next;
    };

    Cvor<T> *head = nullptr;

public:
    bool upis(T data)
    {
        Cvor<T> *newElement = new (std::nothrow) Cvor<T>;
        if (!newElement)
            return false; // neuspjelo stvaranje novog elementa
        newElement->data = data;

        Cvor<T> **p = &head;
        while(*p)
        {
            if((*p)->data < data)
                p = &((*p)->next);
            else
                break;
        }
        newElement->next = *p;
        *p = newElement;
        return true;
    }

    void ispis()
    {
        Cvor<T> **p = &head;
        while(*p)
        {
            std::cout << (*p)->data << " ";
            p = &((*p)->next);
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    int n;
    std::cout << "n: ";
    std::cin >> n;

    List<int> *lista = new List<int>;
    int *A = new int[n];
    for(int i = 0; i < n; i++)
    {
        std::cout << i << ". :";
        std::cin >> A[i];
        lista->upis(A[i]);
    }

    lista->ispis();

    delete lista;

    return 0;
}