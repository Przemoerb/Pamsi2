#include "../inc/Ranking.hh"
#include <assert.h>

int Ranking::fileLines(string name)
{
    string line;
    int count = 0;
    ifstream f;
    f.open(name, ios::in);
    while (getline(f, line))
        count++;
    f.close();
    return count;
}

void Ranking::addFilm(Ranking *obiekt, string id, float avarageRating, string nameOfMovie)
{
    obiekt->id = id;
    obiekt->avarageRating = avarageRating;
    obiekt->nameOfMovie = nameOfMovie;
}

Ranking *Ranking::transferToArray(int amountOfDataToSort)
{
    int numberOfLinesInFile = fileLines("../plik_ranking.tsv");
    if (amountOfDataToSort > numberOfLinesInFile)
        amountOfDataToSort = numberOfLinesInFile;
    Ranking *tab = new Ranking[amountOfDataToSort];

    ifstream ranking;
    string id, line, tmp, x{"0"}, s, data[2];
    char separator='0';
    float avarageRating;
    int movieInfo, previousIdPlace = 0, k=0;
    ranking.open("../plik_ranking.tsv", ios::in);
    if (!ranking.is_open())
    {
        cout << "Nie wczytano pliku, błąd" << endl;
    }
    else
    {
        string *tabOfNames = transferNamesToArray();
        int sizeOftabOfName = fileLines("../plik_nazwy.txt");
        getline(ranking, tmp);
        while (getline(ranking, line) && k < amountOfDataToSort)
        {
            istringstream iss(line);
            iss >> id >> avarageRating;
            movieInfo = searchMovieInformations(tabOfNames, sizeOftabOfName, id, previousIdPlace);
            previousIdPlace = movieInfo;
            addFilm(&tab[k], id, avarageRating, tabOfNames[movieInfo]);
            k++;
        }
        delete[] tabOfNames;
        ranking.close();
        return tab;
    }

    assert(1&&"cos");
    return new Ranking;
}

void Ranking::transferToFile(Ranking *tab, int amountOfDataToSort)
{
    ofstream sortedFile;
    sortedFile.open("../plik_posortowany.txt", ios::out);
    if (!sortedFile.is_open())
    {
        cout << "Nie wczytano pliku, blad" << endl;
    }
    else
    {
        int numberOfLinesInFile = fileLines("../plik_ranking.tsv");
        if (amountOfDataToSort > numberOfLinesInFile)
            amountOfDataToSort = numberOfLinesInFile;
        for (int i = 0; i < amountOfDataToSort; i++)
        {
            sortedFile << tab[i].id << " " << tab[i].avarageRating << " " << tab[i].nameOfMovie << endl;
        }
        sortedFile.close();
    }
}

string *Ranking::transferNamesToArray()
{
    int numberOfLinesInFile = fileLines("../plik_nazwy.txt");
    string *tab = new string[numberOfLinesInFile];

    ifstream names;
    string id, line, tmp, x{"0"};
    int i = 0;

    names.open("../plik_nazwy.txt", ios::in);
    if (!names.is_open())
    {
        cout << "Nie wczytano pliku, błąd" << endl;
    }
    else
    {
        getline(names, tmp);
        while (!names.eof())
        {
            getline(names, line);
            tab[i] = line;
            i++;
        }
        names.close();
        return tab;
    }
    assert(1&&"cos2");
    string *red=&x;
    return red;
}

int Ranking::searchMovieInformations(string *namesTab, int size, string id, int previousIdPlace)
{
    string idN, s, data;
    int i=0, j=0;
    id[0] = '0';
    id[1] = '0';
    int l = previousIdPlace, r = stoi(id), idNi, idi = stoi(id);
    if(r>size)
    {
        r=size;
    }
    if(l>r)
    {
        l=l/20;
    }

    while (l <= r)
    {
        int m = l + (r - l) / 2;


        istringstream iss(namesTab[m]);
        iss >> idN;

        idN[0] = '0';
        idN[1] = '0';
        idNi = stoi(idN);

        if (idNi == idi)
        {
            return m;
        }

        if (idNi < idi)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return 0;
}