#include <cstdlib>

template <class T>
class Queue
{
private:
    static const int MAX = 100;

    T queue[MAX];
    int write =
        0;
    int read =
        0;

public:
    bool enqueue(T item)
    {
        if ((write +
             1) %
                MAX ==
            read)
            return false;
        queue[write] = item;
        write = (write +
                 1) %
                MAX;
        return true;
    }
    bool dequeue(T
                     &item)
    {
        if (write == read)
            return false;
        item = queue[read];
        read = (read +
                1) %
               MAX;
        return true;
    }
    int count()
    {
        if (write >= read)
        {
            return (write - read);
        }
        else
        {
            return (write - read + MAX);
        }
    }
};

template <class T>
Queue<T> *selectMultiples(Queue<T> *q, int number)
{
    Queue<T> tmp;
    Queue<T> *result = new Queue<T>;
    T tmpEl;
    while(q->dequeue(tmpEl))
    {
        if(tmpEl % number == 0)
        {
            result->enqueue(tmpEl);
            continue;
        }
        tmp.enqueue(tmpEl);        
    }

    while(tmp.dequeue(tmpEl))
    {
        q->enqueue(tmpEl);
    }

    return result;
}

int main(void)
{
    Queue<int> glavni;
    glavni.enqueue(3);
    glavni.enqueue(8);
    glavni.enqueue(2);
    glavni.enqueue(5);
    glavni.enqueue(35);
    glavni.enqueue(2);
    glavni.enqueue(24);
    glavni.enqueue(15);

    Queue<int> *visekratnici;
    visekratnici = selectMultiples(&glavni, 3);

    return 0;
}