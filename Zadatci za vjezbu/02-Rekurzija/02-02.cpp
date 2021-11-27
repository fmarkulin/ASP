template <typename T>
class LinearSearch : public ISearch<T>
{
public:
    RetValSearch search(const T A[], const size_t n, const T &item) override 
    {
        if (n == 0)
        {
            bool found false;
            int index = -1;
            return RetValSearch(found, index);
        }
        
        if (A[n - 1] == item)
        {
            found = true;
            index = n - 1;
            return RetValSearch(found, index);
        }

        return search(A, n - 1, item);
    }
};