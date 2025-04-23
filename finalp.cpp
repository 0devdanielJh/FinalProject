#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>
#include <unistd.h>

using namespace std;

class brainGames
{
  public:
  brainGames();
  void unScramble();
  void introduction();
  void typingChallenge();
  void oddOneOut();
 

  private:
  string wordScrambler(string word) /* Helper function to scramble words */
  {
    srand(time(0));
    for(int i = 0; i < word.length();i++) 
    {
      int j = rand() % word.length();
      swap(word[i], word[j]);
    }
    return word;
  } 
  bool hardMode;
  bool easyMode;   /* sets difficulty for the entire game */
  int answer;

};
void brainGames::introduction()             /* provides introductions to each game */
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
brainGames::brainGames()
{
  introduction();
  cout << "Please choose a difficutly" << endl;
  sleep(2);
  cout << "Type 1 for hard mode, Type 2 for easy mode" << endl;
  bool done = false;
  hardMode = false;
  easyMode = false;
  while (!done)
  {
    cin >> answer;
    cin.clear();                      
    cin.ignore(1000,'\n');
    if (cin.fail() || answer != 1 && answer != 2)
    {
      cout << "please enter a 1 or a 2" << endl;
    }
    if(answer == 1)
    {
      sleep(1);
      cout << "You chose hard mode" << endl;
      done = true;
      hardMode = true;
      answer = 0;
    }
    if(answer == 2)
    {
      sleep(1);
      cout << "you chose easy mode" << endl;
      cout << endl;
      done = true;
      easyMode = true;
      answer = 0;
    }
  }
  sleep(2);
  cout << "please choose which game you would like to start with" << endl;
  sleep(2);
  cout << "Type 1 for: Unscramble " << endl;
  sleep(2);
  cout << "Type 2 for: Typing challenge  " << endl;
  sleep(2);
  cout << "Type 3 for: Odd One Out " << endl;
  bool go = false;
  while(!go)                            
  {
    cin >> answer;
    if (cin.fail() ||answer != 1 && answer != 2 && answer != 3)
    {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "choose a 1 , 2 , or 3" << endl;  
      cin >> answer;
    }
    if (answer == 1)
    {
      answer = 0;
      go = true;
      cout << "You've chosen unscramble , the game will start shortly" << endl;
      sleep(1);
      cout << "loading..." << endl;
      sleep(1);
      unScramble();   /* recalls specific function */
    }
    if( answer == 2)
    {
      answer = 0;
      go = true;
      cout << "You've chosen typing challenge, the game will begin shortly" << endl;
      sleep(1);
      cout << "loading..." << endl;
      typingChallenge();
    }
    if (answer == 3)
    {
      answer = 0;
      go = true;
      cout << "you've chose Odd One Out, the game will begin sortly" << endl;
      sleep(1);
      cout << "loading..." << endl;
      oddOneOut();
    }

  }
}
void brainGames::unScramble()
{
  int score = 0;
  list<string> easyWords;
  easyWords.push_back("maybe");
  easyWords.push_back("again");         
  easyWords.push_back("niche");
  easyWords.push_back("young");           /* storage for each possible word*/
  easyWords.push_back("hope");

  list<string> hardWords;
  hardWords.push_back("indifferent");
  hardWords.push_back("discovery");
  hardWords.push_back("believe");
  hardWords.push_back("radiance");
  hardWords.push_back("wanderer");

  list<string>::iterator easyPos = easyWords.begin();
  list<string>::iterator hardPos = hardWords.begin();
  
  if (easyMode == true)
  {
    while(easyPos != easyWords.end())
    {
      string answer;
      string currentWord = *easyPos;
      cout << "Unscramble the following word:" << endl;
      sleep(1);
      cout << wordScrambler(currentWord) << endl;
      sleep(1);
      cin >> answer;
      if (answer != currentWord)
      {
        cout << "Incorrect word," << endl;
        sleep(2);
      }
      if (answer == currentWord)
      {
        score++;
        sleep(1);
        cout << "Great job!! you've unscrabled the word!" << endl;
        sleep(1);
      }
      easyPos++;
    }
    cout << "You've completed the game, here is your score" << endl;
    sleep(1);
    cout << score <<  "/" << easyWords.size() << endl;
  }
  if (hardMode == true)
  {
    while(hardPos != hardWords.end())
    {
      string answer;
      string currentWord = *hardPos;
      cout << "Unscramble the following word:" << endl;
      sleep(1);
      cout << wordScrambler(currentWord) << endl;
      sleep(1);
      cin >> answer;
      if (answer != currentWord)
      {
        cout << "Incorrect word," << endl;
        sleep(2);
      }
      if (answer == currentWord && hardPos != hardWords.end())
      {
        score++;
        cout << "Great job!! you've unscrambled the word!" << endl;
        sleep(1);
      }
      hardPos++;
    }
    cout << "You've completed the game! Here is your score" << endl;
    sleep(1);
    cout << score <<  "/" << hardWords.size() << endl;
  }
  cout << "press 1 to play again, press 2 to choose another game, press 3 to quit Brain games" << endl;
  bool play = false;
  while (!play)
  {
    cin >> answer;
    if (cin.fail() || answer != 1 && answer != 2 && answer != 3)
    {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "please type either a 1 , 2 , or 3" << endl;
    }
    if(answer == 1)
    {
      answer = 0;
      play = true;
      cout << "Scramble will start shortly" << endl;
      sleep(1);
      cout << "loading..." << endl;
      sleep(1);
      unScramble();
    }
    if(answer == 2)
    {
      answer = 0;
      play = true;
      sleep(1);
      cout << "Which game would you like to play?" << endl;
      sleep(1);
      cout << "Type a 1 for typing challenge, type 2 for Odd One Out " << endl; 
      bool playAgain = false;
      while (!playAgain)
      {
        cin >> answer;
        if (cin.fail() || answer != 1 && answer != 2)
        {
          cin.clear();
          cin.ignore(1000,'\n');
          cout << "please type a 1 or a 2" << endl;
        }
        if (answer == 1)
        {
          answer = 0;
          playAgain = true;
          cout << "Typing challenge will start soon" << endl;
          sleep(1);
          cout << "loading..." << endl;
          sleep(1);
          typingChallenge();
        }
        if (answer == 2)
        {
          answer = 0;
          playAgain = true;
          cout << "Odd One Out will begin soon" << endl;
          sleep(1);
          cout << "loading..." << endl;
          sleep(1);
          oddOneOut(); 
        }
      }
    }
    if (answer == 3)
    {
      answer = 0;
      play = true;
      cout << "Thank you for playing!" << endl;
      sleep(1);
      cout << "Please play again soon!" << endl;
    }
  }
} 
void brainGames::typingChallenge()
{
  int score = 0;
  string a;
  string sentences[] = {"the quick brown fox jumps over the lazy dog","the cat is sleeping on the soft couch near the window"
  , "ice cream is good because it tastes sweet and soft" , "the dog runs around the yard and barks at birds"};
  string *h = sentences;
  if (hardMode == true)
  { 
    sleep(2);
    cout << "loading..." << endl;
    sleep(1);
    cout << "You will have 10 seconds to type the following sentence" << endl;
    sleep(1);
    cout << "Ready..." << endl;
    sleep(1);
    cout << "go!" << endl;
    for (int i = 0; i < 4;i++)
    {
      cin.clear();
      cin.ignore(100,'\n');
      sleep(2);
      cout << *(h+i) << endl;     
      int now = time(0);      /* tracks time passed between viewing and user input */
      getline(cin,a);
      int later = time(0);
      int timePassed = later - now;
      
      if (timePassed > 10 || a != *(h+i))
      {
        sleep(2);
        cout << "You failed!" << endl;
        if (a != *(h+i))
        {
          sleep(1);
          cout << "You misspelled 1 or more word" << endl;
        }
        sleep(1);
        cout << "you took " << timePassed << " seconds" << endl;
        sleep(1);
        cout << "press enter to continue" << endl;
      }
      else
      {
        score++;
        sleep(2);
        cout << "Congrats you passed" << endl;
        sleep(1);
        cout << "you took " << timePassed << " seconds" << endl;
        sleep(1);
        cout << "press enter to continue" << endl;
      }
    }
    cout << "you've completed the game!" << endl;
    cout << "heres your score " << score << "/" << "4" << endl;
  } 
  if (easyMode == true)
  {
    sleep(2);
    cout << "loading..." << endl;
    sleep(1);
    cout << "You will have 14 seconds to type the following sentence" << endl;
    sleep(1);
    cout << "ready..." << endl;
    sleep(1);
    cout << "go!" << endl; 
    for (int i = 0; i < 4;i++)
    {
      cin.clear();
      cin.ignore(100,'\n');
      sleep(2);
      cout << *(h+i) << endl;
      int now = time(0);
      getline(cin,a);
      int later = time(0);
      int timePassed = later - now;
      
      if (timePassed > 14 || a != *(h+i))
      {
        sleep(2);
        cout << "You failed!" << endl;
        if (a != *(h+i))
        {
          sleep(1);
          cout << "You misspelled 1 or more word" << endl;
        }
        sleep(1);
        cout << "you took " << timePassed << " seconds" << endl;
        sleep(1);
        cout << "press enter to continue" << endl;
      }
      else
      {
        score++;
        sleep(2);
        cout << "Congrats you passed" << endl;
        sleep(1);
        cout << "you took " << timePassed << " seconds" << endl;
        sleep(1);
        cout << "press enter to continue" << endl;
      }
    }
    cout << "you've completed the game!" << endl;
    cout << "heres your score " << score << "/" << "4" << endl;
  }
  sleep(2);
  cout << "press 1 to play again, press 2 to choose another game, press 3 to quit Brain games" << endl;
  bool play = false;
  while (!play)
  {
    cin >> answer;
    if (cin.fail() || answer != 1 && answer != 2 && answer != 3)
    {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "please type either a 1 , 2 , or 3" << endl;
    }
    if(answer == 1)
    {
      answer = 0;
      play = true;
      cout << "Typing challenge will start shortly" << endl;
      sleep(1);
      cout << "loading..." << endl;
      sleep(1);
      typingChallenge();
    }
    if(answer == 2)
    {
      answer = 0;
      play = true;
      sleep(1);
      cout << "Which game would you like to play?" << endl;
      sleep(1);
      cout << "Type a 1 for unscramble, type 2 for Odd One Out" << endl; 
      bool playAgain = false;
      while (!playAgain)
      {
        cin >> answer;
        if (cin.fail() || answer != 1 && answer != 2)
        {
          cin.clear();
          cin.ignore(1000,'\n');
          cout << "please type a 1 or a 2" << endl;
        }
        if (answer == 1)
        {
          answer = 0;
          playAgain = true;
          cout << "unscramble will start soon" << endl;
          sleep(1);
          cout << "loading..." << endl;
          sleep(1);
          unScramble(); 
        }
        if (answer == 2)
        {
          answer = 0;
          playAgain = true;
          cout << "Odd One Out will begin soon " << endl;
          sleep(1);
          cout << "loading..." << endl;
          sleep(1);
          oddOneOut();
        }
      }

    }
    if (answer == 3)
    {
      answer = 0;
      play = true;
      cout << "Thank you for playing!" << endl;
      sleep(1);
      cout << "Please play again soon!" << endl;
    }
  }
}
void brainGames::oddOneOut()
{
  string easyOptions[] = {"onion , lettcue , tomato , carrot" , "circle , square , triangle , rectangle " , "100 , 200 , 600 , 950 " , 
  "tiktok , snapchat , twitter , duolingo" , "2 , 4 , 6 , 9"};
  string hardOptions[] = {"justice , honesty , courage , cowardice" , "energy , time, book , space " , "electron , neutron , proton , photon " ,
  "einstien , newton , darwin , da-vinci" , "ios , androd , windows , safari"};
  string easyAnswer[] = {"tomato" , "circle" , "950" , "duolingo" , "9"};
  string hardAnswer[] = {"cowardice" , "book" , "photon" , "da-vinci" , "safari"};
  string *e = easyOptions;
  string *h = hardOptions;
  int score = 0;
  if (hardMode == true)
  {
    sleep(1);
    cout << "loading..." << endl;
    sleep(1);
    string response;
    for (int i = 0;i < 5;i++)
    {
      cin.clear();
      cin.ignore(1000,'\n');
      sleep(2);
      cout << *(h + i) << endl;
      sleep(1);
      cout << "Choose the odd one out " << endl;
      cin >> response;
      if (cin.fail() || response != hardAnswer[i])
      {
        sleep(1);
        cout << "Incorrect!!" << endl;
        sleep(2);
      }
      if(response == hardAnswer[i])
      {
        sleep(1);
        cout << "Correct" << endl;
        score++;
      }
    }
  }
  if (easyMode == true)
  {
    sleep(1);
    cout << "loading..." << endl;
    sleep(1);
    string response;
    for (int i = 0;i < 5;i++)
    {
      cin.clear();
      cin.ignore(1000,'\n');
      sleep(2);
      cout << *(e + i) << endl;
      sleep(1);
      cout << "Choose the odd one out " << endl;
      cin >> response;
      if (cin.fail() || response != easyAnswer[i])
      {
        sleep(1);
        cout << "Incorrect!!" << endl;
        sleep(2);
      }
      if(response == easyAnswer[i])
      {
        sleep(1);
        cout << "Correct" << endl;
        score++;
      }
    }
  }
  sleep(2);
  cout << "Youve finished the game!!" << endl;
  sleep(2);
  cout << "Your score is " << score << "/5" << endl;
  sleep(1);
  cout << "press 1 to play again, press 2 to choose another game, press 3 to quit Brain games" << endl;
  bool play = false;
  while (!play)
  {
    cin >> answer;
    if (cin.fail() || answer != 1 && answer != 2 && answer != 3)
    {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "please type either a 1 , 2 , or 3" << endl;
    }
    if(answer == 1)
    {
      answer = 0;
      play = true;
      cout << "Odd One Out will start shortly" << endl;
      sleep(1);
      cout << "loading..." << endl;
      sleep(1);
      oddOneOut();
    }
    if(answer == 2)
    {
      answer = 0;
      play = true;
      sleep(1);
      cout << "Which game would you like to play?" << endl;
      sleep(1);
      cout << "Type a 1 for unscramble, type 2 for typing challenge  " << endl; 
      bool playAgain = false;
      while (!playAgain)
      {
        cin >> answer;
        if (cin.fail() || answer != 1 && answer != 2)
        {
          cin.clear();
          cin.ignore(1000,'\n');
          cout << "please type a 1 or a 2" << endl;
        }
        if (answer == 1)
        {
          answer = 0;
          playAgain = true;
          cout << "unscramble will start soon" << endl;
          sleep(1);
          cout << "loading..." << endl;
          sleep(1);
          unScramble(); 
        }
        if (answer == 2)
        {
          answer = 0;
          playAgain = true;
          cout << " typing challenge will start soon" << endl; 
          sleep(1);
          cout << "loading..." << endl;
          sleep(1);
          typingChallenge();
        }
      }

    }
    if (answer == 3)
    {
      answer = 0;
      play = true;
      cout << "Thank you for playing!" << endl;
      sleep(1);
      cout << "Please play again soon!" << endl;
    }
  }

}
int main ()
{

  brainGames();

  return 0;
}
