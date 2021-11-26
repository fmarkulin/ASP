#include <iostream>

template <class T>
class List
{
private:
    struct Atom
    {
        T data;
        Atom *next;
    };
    Atom *head = nullptr;

public:
    bool insert(T data)
    { // umetanje na početak liste
        Atom *newElement = new (std::nothrow) Atom;
        if (newElement == nullptr)
            return false;
        newElement->data = data;
        newElement->next = head;
        head = newElement;
        return true;
    }
    void kopirajParne(List<T> &dstList)
    {
        Atom **p = &head;
        while ((*p) != nullptr)
        {
            if ((**p).data % 2 == 0)
            {
                dstList.insert((**p).data);
            }

            p = &((**p).next);
        }
    }

    void ispis()
    {
        Atom **p = &head;
        while((*p) != nullptr)
        {
            std::cout << (**p).data << " ";
            p = &((**p).next);
        }
        std::cout << std::endl;
        return;
    }
};

int main(void)
{
    List<int> *srcList = new List<int>();
    List<int> *dstList = new List<int>();
    List<int> *GEJ = new List<int>();

    (*srcList).insert(3);
    (*srcList).insert(2);
    (*srcList).insert(8);
    (*srcList).insert(6);
    (*srcList).insert(1);
    (*srcList).insert(7);
    (*srcList).insert(4);
    (*srcList).insert(5);

    (*srcList).kopirajParne(*dstList);
    (*dstList).kopirajParne(*GEJ);
    (*srcList).ispis();
    (*GEJ).ispis();

    delete srcList;
    delete dstList;

    return 0;
}