/*[REDACTED], Assignment 3.
This program is meant to create and deal with judge scoring in a contest that has specific rules for judging.
These rules include the use of fractional scores represented as decimals such
as 8.3. Scores may range from 0 to 10 and the final score is determined by dropping the highest and lowest scores.
Intended as a project for [REDACTED]'s C++ Programming course.*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void getJudgeData(string, double &score);
double getAverage(double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);
double findHighest(double score1, double score2, double score3, double score4, double score5);

int main()
{
    double score1, score2, score3, score4, score5, average_sc, lowest_sc, highest_sc;

    getJudgeData("Judge 1", score1);
    getJudgeData("Judge 2", score2);
    getJudgeData("Judge 3", score3);
    getJudgeData("Judge 4", score4);
    getJudgeData("Judge 5", score5);

    average_sc = getAverage(score1, score2, score3, score4, score5);
    lowest_sc = findLowest(score1, score2, score3, score4, score5);
    highest_sc = findHighest(score1, score2, score3, score4, score5);

    cout << "____________________________________________" << endl
         << "Score 1 Score 2 Score 3 Score 4 Score 5" << endl << score1 << '\t' << score2 << '\t' <<
         score3 << '\t' << score4 << '\t' << score5 << '\t' << endl << "Average score: " << average_sc
         << endl << "Lowest score: " << lowest_sc << endl << "Highest score: " << highest_sc << endl;

    system("pause");
    return 0;
}

void getJudgeData(string _jname, double &score)
{
    do
    {
        cout << "" << _jname << """ score entry, entry should be 0-10: ";
        cin >> score;
        if (cin.fail())
        {
            cout << "Score must be numeric!" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            score = -100;
        }
        else if (score < 0 || score > 10)
            cout << "Score must be between 0 and 10!" << endl;
    }
    while (cin.fail() || score < 0 || score > 10);
}

double getAverage(double _score1, double _score2, double _score3, double _score4, double _score5)
{
    double ret_avg, _lowest_sc, _highest_sc;

    _lowest_sc = findLowest(_score1, _score2, _score3, _score4, _score5);
    _highest_sc = findHighest(_score1, _score2, _score3, _score4, _score5);

    ret_avg = (_score1 + _score2 + _score3 + _score4 + _score5 - _lowest_sc - _highest_sc) / 3;
    return ret_avg;
}

double findLowest(double __score1, double __score2, double __score3, double __score4, double __score5)
{
    double ret_low;
    ret_low = __score1;

    if (__score2 < ret_low)
        ret_low = __score2;
    if (__score3 < ret_low)
        ret_low = __score3;
    if (__score4 < ret_low)
        ret_low = __score4;
    if (__score5 < ret_low)
        ret_low = __score5;
    else
        ret_low = __score1;

    return ret_low;
}

double findHighest(double ___score1, double ___score2, double ___score3, double ___score4, double ___score5)
{
    double ret_high;
    ret_high = ___score1;

    if (___score2 > ret_high)
        ret_high = ___score2;
    if (___score3 > ret_high)
        ret_high = ___score3;
    if (___score4 > ret_high)
        ret_high = ___score4;
    if (___score5 > ret_high)
        ret_high = ___score5;
    else
        ret_high = ___score1;

    return ret_high;
}
