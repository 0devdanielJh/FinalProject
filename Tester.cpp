#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>
#include <unistd.h>

using namespace std;

string wordScrambler(string word) 
{
    srand(time(0));
    for(int i = 0; i < word.length();i++) 
    {
      int j = rand() % word.length();
      swap(word[i], word[j]);
    }
    return word;
} 
void introduction()
{
  cout << "Rules of the Brain Games:" << endl;
  sleep(1);
  cout << "Game 1: Unscrambler! " << endl;
  sleep(1);
  cout << "In this game you will be given a pre-scrambled word, your job is to unscrable the word." << endl;
  sleep(4);
  cout << "you will be given one attempt at each word" << endl;
  sleep(3);
  cout << "A score will be kept and increased for every word correctly unscrablmed" << endl;
  sleep(3);
  cout << "Depending on your choice of easy mode or hard mode the words will be between 4-5 characters or 6-11 characers" << endl;
  sleep(4);
  cout << "Game 2: Typing Challenge " << endl;
  sleep(3);
  cout << "In this game you will be given a sentences to type within a specific time frame" << endl;
  sleep(2);
  cout << "Easy mode allows for 14 seconds, while hard mode only grants 10" << endl;
  sleep(3);
  cout << "Success will grant you a point, failure will give nothing" << endl;
  sleep(2);
  cout << "Game 3: Odd One Out" << endl;
  sleep(2);
  cout << "In this game you will be given a list of 4 things" << endl;
  sleep(2);
  cout << "One of which wont belong" << endl;
  sleep(1);
  cout << "A point will be given for each correct chioce" << endl;
  sleep(2);
}
int main ()
{
    string word = "elephant";

    cout << wordScrambler(word) << endl;
    introduction();

  

  return 0;
}