#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

class Ranking
{
public:
    float avarageRating;
    string id, nameOfMovie;

    Ranking *transferToArray(int amountOfDataToSort);
    void transferToFile(Ranking *tab, int amountOfDataToSort);
    void addFilm(Ranking *obiekt, string id, float avarageRating, string nameOfMovie);
    int fileLines(string name);
    string *transferNamesToArray();
    int searchMovieInformations(string *namesTab, int size, string id, int PreviousId);
};
