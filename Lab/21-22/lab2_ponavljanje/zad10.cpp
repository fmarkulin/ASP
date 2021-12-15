void selection2Sort(int A[], int n, char smjer)
{
    int i, j;
    for(i = 0; i < n; i++, n--)
    {
        int min = i;
        int max = n -1;
        for(j = i + 1; j < n; j++)
        {
            if(A[j] < A[min])
                min = j;
            
            if(A[j] > A[max])
                max = j;
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;

        temp = A[n - 1];
        A[n - 1] = A[max];
        A[max] = temp;
    }
}