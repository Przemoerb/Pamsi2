#include "../inc/Ranking.hh"
#include "../inc/quicksort2.hh"
#include "../inc/mergesort.hh"
#include "../inc/bucketsort.hh"
#include <time.h>

int main()
{
    int start, stop;
    Ranking RANKING;
    Ranking *test = new Ranking;
menu:
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "     Program sortuje Ranking wykorzystując algorytmy:" << endl;
    cout << "           Quick sort Merge sort Bucket sort         " << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;

        cout << "Wybierz metode sortowania:" << endl;
        cout << "1-> quickSort , 2-> mergeSort , 3-> bucketSort , 4->Wszystkie" << endl;
        char number;
        cin >> number;
        int n;
        switch (number)
        {
        case '1':
        {
            cout<<"Podaj ilosc danych do posortowania: ";
            cin>>n;
            cout<<"Przydzielenie pamieci - ";
            Ranking *test_quick = new Ranking[n];
            cout<<"Koniec"<<endl;
            cout<<"transport ratingu z nazwami do pliku - ";
            test_quick = RANKING.transferToArray(n);
            cout<<"Koniec"<<endl;
            start = clock();
            quickSort(test_quick, 0, n - 1);
            stop = clock();
            RANKING.transferToFile(test_quick, n);
            double time = (double)(stop - start) / CLOCKS_PER_SEC;
            cout << "Czas sortowania algorytmem quick sort : " << time << "[s]" << endl
                 << endl;
            // RANKING.average(test_quick, n);
            delete[] test_quick;

            goto menu;
        }
        case '2':
        {
            cout<<"Podaj ilosc danych do posortowania: ";
            cin>>n;
            Ranking *test_merge = new Ranking[n];
            test_merge = RANKING.transferToArray(n);
            start = clock();
            mergeSort(test_merge, 0, n - 1);
            stop = clock();
            RANKING.transferToFile(test_merge, n);
            double time = (double)(stop - start) / CLOCKS_PER_SEC;
            cout << "Czas sortowania algorytmem merge sort : " << time << "[s]" << endl
                 << endl;
            // RANKING.average(test_merge, n);
            delete[] test_merge;

            goto menu;
        }
        case '3':
        {
            cout<<"Podaj ilosc danych do posortowania: ";
            cin>>n;
            Ranking *test_bucket = new Ranking[n];
            test_bucket = RANKING.transferToArray(n);
            start = clock();
            bucketSort(test_bucket, n);
            stop = clock();
            RANKING.transferToFile(test_bucket, n);
            double time = (double)(stop - start) / CLOCKS_PER_SEC;
            cout << "Czas sortowania algorytmem bucket sort : " << time << "[s]" << endl
                 << endl;
            // RANKING.average(test_bucket, n);
            delete[] test_bucket;

            goto menu;
        }

        case '4':
        {
            cout<<"Podaj ilosc danych do posortowania: ";
            cin>>n;
            Ranking *test = new Ranking[n];
            test = RANKING.transferToArray(n);
            start = clock();
            quickSort(test, 0, n - 1);
            stop = clock();
            double time = (double)(stop - start) / CLOCKS_PER_SEC;
            cout << "Czas sortowania algorytmem quick sort : " << time << "[s]" << endl;
            start = clock();
            mergeSort(test, 0, n - 1);
            stop = clock();
            time = (double)(stop - start) / CLOCKS_PER_SEC;
            cout << "Czas sortowania algorytmem merge sort : " << time << "[s]" << endl;
            start = clock();
            bucketSort(test, n);
            stop = clock();
            time = (double)(stop - start) / CLOCKS_PER_SEC;
            cout << "Czas sortowania algorytmem bucket sort : " << time << "[s]" << endl
                 << endl;
            RANKING.transferToFile(test, n);
            // RANKING.average(test, n);
            delete[] test;

            goto menu;
        }
    }
};