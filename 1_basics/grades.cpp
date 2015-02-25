//By Peter G. Marczis for wikibooks.
//Absolutely free to use anyhow.
#include <iostream>
#include <string>
#include <sstream>
 
using namespace std; //Sorry, I'm lazy, this is not a good practice
 
bool isNumber(string &inp)
//Function to check if a string consist only numbers.
{
    int i;
    if (inp[0] == '-') { //Handle "-" sign
        i = 1;
    } else {
        i = 0;
    }
    for( i ; i < inp.length() ; i++) { //Along the string
        for (int z = 0x30 ; z < 0x3A ; z++) { //With every numbers in the ASCII table.
            if (inp[i] == (char)z) break; //If we find a number go to the next char
            if (z == 0x39) return false; //if we reached number "9" and no hit, return false.
        } 
    }
    return true; //All char. were numbers, happy !
}
 
char getGrade(int &score)
//Convert score into grades.
{
    if ( score >= 90 ) return 'A';
    if ( score >= 80 ) return 'B';
    if ( score >= 70 ) return 'C';
    if ( score >= 60 ) return 'D';
    return 'F';
}
 
int main(int argc, const char* argv[])
{
    int    score;
    string score_str;
 
    cout << "Please provide your score:" << endl;
    while ( 1 ) {
        getline(cin, score_str);
        if (isNumber(score_str)) {
            stringstream(score_str) >> score; //Convert the string into number.
            if ( score > -1 && score < 101 ) { //Check limits break if we inside.
                break;
            }
        }
        cout << "!!! Score should be a number in 0-100 !!!" << endl; //Print error message if not.
    }
    cout << "Your grade: " << getGrade(score) << endl; //Put the result on the screen
    if ( score == 100 ) {
        cout << "Perfect score !" << endl; //And do the extra "tap" if the student is great.
    }
}