#include <cstdlib>

template <class T>
class Stack
{
private:
    static const size_t increment = 100;
    size_t size = 100;
    T *stack;
    int top = -1;

public:
    //a
    Stack() { stack = (T *)malloc(size * sizeof(T)); }
    Stack(size_t size) : size(size) { stack = (T *)malloc(size * sizeof(T)); }

    //b
    bool push(T element)
    {
        if (top >= (int)(size - 1))
        {
            T *tmp = (T *)realloc(stack, (size + increment) * sizeof(T));
            if (!tmp)
                return false;
            stack = tmp;
            size += increment;
        }
        top++;
        stack[top] = element;
        return true;
    }

    bool pop(T &item)
    {
        if (top < 0)
            return false;
        item = stack[top];
        top--;
        if (top > -1 && top < (int)(size - increment))
        {
            T *tmp = (T *)realloc(stack, (size - increment) * sizeof(T));
            if (!tmp)
                return false;
            stack = tmp;
            size -= increment;
        }
        return true;
    }
};

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
bool transfer(Stack<T> *s, Queue<T> *q)
{
    T element;
    bool status;
    status = s->pop(element);
    if (status == false)
        return true;
    status = q->enqueue(element);
    if (status == false)
        return false;
    return transfer(s, q);
}
int main(void)
{
    Queue<int> q1;
    Stack<int> s1;
    int i;
    for (i = 0; i <= 10; i++)
        s1.push(i);
    transfer(&s1, &q1);
    return 0;
}