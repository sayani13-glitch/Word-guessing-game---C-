#include "Game.h"


#include <iostream>
#include <fstream>
#include<ctime>
#include <string>


using namespace std;


int letterFill(char, string, string&);



 //we can make this program better by adding a hint for each word that is given. Plus, lets  change it to something people from NOrth america are more familiar with. 
int main()
{
	Game obj1;
	
	obj1.repeat();
	
	// Initialize the secret word with the * character.
  	string unknown(obj1.word.length(), ('_')); //takes each letter of the word and displays it with -. 
	
	
  	// welcome the user
  	cout << "\n\nWelcome to the guessing game...Guess a country Name"; //starts a new line and prints the quoted text. 
  	cout << "\n\nEach letter is represented by a star."; //starts a new line and prints the quoted text. 
  	cout << "\n\nYou have to type only one letter in one try";  //starts a new line and prints the quoted text. 
  	cout << "\n\nYou have " << obj1.MAX_TRIES << " tries to try and guess the word.";  //Starts a new line. prints the quoted text and max number of tries. 
    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl<<endl<<endl;  //starts a new line and prints the quoted text. 
  
  	// Loop until the guesses are used up
  while (obj1.num_of_wrong_guesses < obj1.MAX_TRIES)
  {
  	
  	cout << "*************************************************"<< endl<<endl<< endl<<endl; //starts a new line and prints the quoted text. 
    cout << endl <<"\t"<< obj1.hint << endl;
    cout << "\n\n" << unknown;         //new line  and the displays the word in a hidden way. 
    cout << "\n\nGuess a letter: "<< endl<<endl;    //prints the quoted text with a new line. 
    cin >> obj1.letter;  //user enters the guessed letter.
    cout<<"\n\n*************************************************";
	                   

    // Fill secret word with letter if the guess is correct,
    // otherwise increment the number of wrong guesses.
    if (letterFill(obj1.letter, obj1.word, unknown) == 0)  //returns the letter the user entered.  the current word selected and how much of the word the user has guessed. 
    {
      cout << endl << "Whoops! That letter isn't in there!" << endl;   //prints the quoted text and ends line.
      obj1.num_of_wrong_guesses++;   //increase the number of guesses by one. 
    }
    else
    {
      cout << endl << "You found a letter! Isn't that exciting!" << endl; // print the text and ends the line. 
    }
    // Tell user how many guesses has left.
    cout << "\nYou have " << obj1.MAX_TRIES - obj1.num_of_wrong_guesses; //prints the number of guesses left. This is done by subtracting the number of guesses from the number of max tries. 
    cout << " guesses left." << endl; //Prints the quoted text. 
    // Check if user guessed the word.
    if (obj1.word == unknown)
    {
      cout << obj1.word << endl; //prints the word selected for the user to guess. 
      cout << "\n\n\n\n\tYeah! You got it!" << endl;
      cout << "\nWould like to play another round of guessing ?" << endl;
      cout << "\n\nEnter yes or no" << endl; 

      cin >> obj1.yes_or_no;

      if (obj1.yes_or_no == "yes") // if user says yes, then start the game again. 
      {
         
        main();
      }


      if (obj1.yes_or_no == "no") // if user says no, then end the game. 
      {
        cout << "Closing program" << endl;
        return 0; //returns 0 to close the program.
        
      }
      break;
    }
  }
  if (obj1.num_of_wrong_guesses == obj1.MAX_TRIES) //to execute when the number of wrong guesses equals the number of max tries. 
  {
    cout << "\n\tSorry, you lose." << endl;
    cout << "\nThe word was " << obj1.word << endl;
    cout << "\nWould like to play another round of guessing ?" << endl;
    cout << "\n\\Enter yes or no : " << endl;

    cin >> obj1.yes_or_no;

    if (obj1.yes_or_no == "yes") // if user says yes, then start the game again. 
    {
      main();
    }

    if (obj1.yes_or_no == "no") // if user says no, then end the game. 
    {
      cout << "Closing program" << endl;
        return 0; //returns 0 to close the program.
       
    }

  }
  return 0; //ensures the program exits better. 
  	//cin.ignore(); not needed. Causes issues with exiting. 
  	//cin.get();  not needed. Causes issues with exiting. 
}

/* Take a one character guess and the secret word, and fill in the
 	unfinished guess word. Returns number of characters matched.
 	Also, returns zero if the character is already guessed. */

int letterFill(char guess, string secretword, string& guessword)
{
  	int i;
  	int matches = 0;
  	int len = secretword.length();
  	for (i = 0; i < len; i++)
  	{
    	// Did we already match this letter in a previous guess?
    	if (guess == guessword[i])
      	return 0;
    	// Is the guess in the secret word?
    	if (guess == secretword[i])
    	{
      		guessword[i] = guess;
      		matches++;
    	}
  	}
  	return matches;
}
 
