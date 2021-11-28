template <class T>
void remove(Stack<T> *s)
{
    Stack <T> s1, s2;
    T el, x;
    while(s->pop(el))
    {
        s1.push(el);
        while(s->pop(x))
        {
            if(x != el)
            {
                s2.push(x);
            }
        }
        while(s2.pop(x))
        {
            s->push(x);
        }
    }
    while(s1.pop(el))
    {
        s->push(el);
    }
}