struct bucket
{
    int count;
    Ranking *value;
};

void bucketSort(Ranking *array, int size)
{
    bucket buckets[5];
    int i, j, k;
    for (i = 0; i < 5; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = new Ranking[size];
    }

    for (i = 0; i < size; i++)
    {
        if (array[i].avarageRating < 2)
        {
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i].avarageRating >= 2 && array[i].avarageRating < 4)
        {
            buckets[1].value[buckets[1].count++] = array[i];
        }
        else if (array[i].avarageRating >= 4 && array[i].avarageRating < 6)
        {
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else if (array[i].avarageRating >= 6 && array[i].avarageRating < 8)
        {
            buckets[3].value[buckets[3].count++] = array[i];
        }
        else if (array[i].avarageRating >= 8 && array[i].avarageRating < 10)
        {
            buckets[4].value[buckets[4].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 5; i++)
    {
        // now using quicksort to sort the elements of buckets
        quickSort(buckets[i].value, 0, buckets[i].count);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].value[j+1];
        }
        k += buckets[i].count;
        delete[] buckets[i].value;
    }
}