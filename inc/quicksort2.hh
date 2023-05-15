int partition(Ranking *arr, int left, int right)
{
    Ranking temp; 
    float pivot = arr[(left + right) / 2].avarageRating;
    int l = left, r = right;
    while (1)
    {
        while (arr[l].avarageRating < pivot)
            l++;
        while (arr[r].avarageRating > pivot)
            r--;

        if (l >= r)
            return r;

        temp = arr[l];
        arr[l++] = arr[r];
        arr[r--] = temp;
    }
}

void quickSort(Ranking *arr, int left, int right)
{
    if (left >= 0 && left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot);
        quickSort(arr, pivot + 1, right);
    }
}