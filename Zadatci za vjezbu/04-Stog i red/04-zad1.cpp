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
    Stack(size_t size) : size(size) { stack stack = (T *)malloc(size * sizeof(T)); }

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
        stack[top] = item;
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