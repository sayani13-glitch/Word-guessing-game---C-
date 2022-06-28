#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include<ctime>
#include <string>

using namespace std;

class Game
{
	public:
		
		const int MAX_TRIES = 5;
  		string yes_or_no;
  		char letter;
  		int num_of_wrong_guesses = 0;
  		string hint;
		int i=0;
		string wordarray[100]={};
		string word, t, q, filename;

		
		int repeat()	
		{
			i=0;
		
			ofstream MyFile("words_to_guess.txt");  // Create and open a text file
			MyFile << "mexico france italy southafrica japan australia egypt singapore china turkey";   // Write to the file
			MyFile.close();   // Close the file
	
    		// filestream variable file	fstream file;
   	
  			fstream file;
    		// filename of the file
			filename = "words_to_guess.txt";
  
   		 	// opening file
    		file.open(filename.c_str());
  
    		// extracting words from the file
    		while (file >> word)
    		{
      			// displaying content
       			wordarray[i++]=word;
    		}
			srand(time(NULL));
  			int n = rand() % (i-1); //range from to 0 and i. so it will basically choose randomly any of these words. 
			word = wordarray[n]; // word is equal to one of the country names in the array.

 	 		switch (n) // a switch statement that will execute based on which word is chosen.  Range is from zero to 10. 
  			{
  				case 0: //if Mexico is chosen as the word to guess. Then give the player this hint. 
   					hint = "Hint: This country shares a border with the USA";
   					break;

 	 			case 1: //if  France  is chosen as the word to guess. Then give the player this hint. 
  	  				hint = "Hint: This country has the Eiffel tower";
  	  				break;

 	 			case 2: //if  Italy  is chosen as the word to guess. Then give the player this hint. 
   	 				hint = "Hint: This country has the city called Rome";
    				break;

 	 			case 3: //if  South Africa  is chosen as the word to guess. Then give the player this hint. 
   					hint = "Hint: The country in which nelson Mandela was born (Do not enter a space for this one)";
   	 				break;


 	 			case 4: //if  Japan  is chosen as the word to guess. Then give the player this hint. 
   	 				hint = "Hint: The country in which anime was created";
    				break;


  				case 5: //if  Australia  is chosen as the word to guess. Then give the player this hint. 
    				hint = "Hint: This country has kangaroos";
      				break;

  				case 6:   //if  Egypt  is chosen as the word to guess. Then give the player this hint. 
  					hint = "Hint: This country has giant pyramids";
    				break;


  				case 7: //if  Singapore  is chosen as the word to guess. Then give the player this hint. 
    				hint = "Hint: This country has a amazing airport called  Changi Airport";
    				break;

  				case 8: //if china  is chosen as the word to guess. Then give the player this hint. 
    				hint = "Hint: This country has a place called Beijing.";
    				break;

  				case 9: //if Turkey  is chosen as the word to guess. Then give the player this hint. 
    				hint = "Hint: This country has a place called Istanbul.";
    				break;
			
				}
			
			return 0;
		}
	
	
};

#endif