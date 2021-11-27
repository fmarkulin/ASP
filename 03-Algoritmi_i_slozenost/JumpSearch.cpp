#include <cmath>
#include <algorithm>

int blockSearch(int A[], int n, int x)
{
    int index = -1;
    int blockStart = 0;
    int blockSize = sqrt(n);
    int nextBlockStart = blockStart + blockSize;
    int next = std::min(nextBlockStart, n - 1);

    //find containing block
    while(next < n - 1 && A[next] <= x)
    {
        nextBlockStart += blockSize;
        blockStart += blockSize;
        next = std::min(nextBlockStart, n - 1);
    }

    if(next == n - 1)
    {
        next++;
    }

    for(int i = blockStart; i < next; i++)
    {
        if(A[i] == x)
        {
            index = i;
            break;
        }
    }

    return index;
}