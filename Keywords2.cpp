// Keywords2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <iostream>
#include <string>

using namespace std;
string name;//Name of the person

string allText[10] = { "apple", "banana", "orange", "strawberry", "blueberry", "dragonfruit", "watermelon", "cherry", "mango", "coconut" }; //10 words for the game
string currWords[3];//All three current words chosen for simuation

string hangmanWord;//The letters the player has guessed successfully displayed
int currWord = 0;//The word currently on

bool isRunning = true;
bool CheckGuess(string guess) { //Checks the players current letter guess if it is in the word
	bool FoundLetter = false;//Becomes true if it found the letter at least once
	for (int i = 0; i < currWords[currWord].length(); ++i) {
		if (currWords[currWord][i] == guess[0]) {
			FoundLetter = true;
			hangmanWord[i] = guess[0];
		}
	}
	return FoundLetter;
}
void GenerateWords() {//Generates 3 words that are unique from allText
	for (int i = 0; i < 3; i++) {
		currWords[i] = allText[rand() % 10];
		
		for (int o = 0; o < i; o++) { //Avoids choosing same words
			if (currWords[o] == currWords[i])//Checks if current word is any other word already chosen
				i--;//Restarts that current word and finds new one
		}
	}
}
void makeHangmanWord() { //makes the hangman word
	hangmanWord = "";//resets the hangman word
	for (int i = 0; i < currWords[currWord].length(); ++i) {//Turns letters into _ with hangmanword
		hangmanWord = hangmanWord + "_";
	}
}
void Simulation() {
	GenerateWords();

	cout << "The program is sensitive with your guesses and will only take the first character in each guess!\n" << endl;

	/*for (int i = 0; i < 3; i++) { //Debug for the developer
		cout << currWords[i] << endl;
	} */ 
	makeHangmanWord();
	int lives = 5;//Lives player has on each guess
	while (true) {
		
		cout << "Current Guess: " << hangmanWord << endl;
		cout << "Lives left: " << lives << endl;

		string letterGuess;

		cout << "Please enter a letter: " << endl;
		getline(cin, letterGuess);

		if (CheckGuess(letterGuess)) {//Checks the guess and takes away lives if incorrect and if out of lives ends current run
			cout << name << " is correct\n" << endl;
		}
		else {//Incorrect guess
			cout << name << " guessed incorrectly \n" << endl;
			lives--;
			if (lives < 1) {
				cout << name << " is out of lives and has lost the current run\n" << endl;
				break;
			}
		}

		if (hangmanWord == currWords[currWord]) {//if all letters have been guessed it goes onto the next word and if all words have been guess then the player ends simulation
			cout << name <<" guessed the word correctly" << endl;
			currWord++;
			lives = 5;
			makeHangmanWord();

			if (currWord > 2) {
				cout << name << " guessed all three words correctly. Great Job!" << endl;
				break;
			}
		}
	}
}
int main()
{
	srand(time(NULL));

	int simNum = 0;//The current simulation being run

	cout << "Welcome to the CIA KeyWords2 Program!" << endl;

	cout << "Please enter your name: " << endl;//Gets and displays the recruits name
	getline(cin, name);
    cout << "Your name is " << name <<"\n" << endl;

	cout << "This program is focused on a hangman type game where you have 3 different keywords to solve.\nYou have 5 mistakes for each word and you guess a letter each time til you finish the word.\n" << endl;
	while (isRunning) {
		simNum++;
		cout << "Recruit " << name << " is on simulation #" << simNum << endl;

		currWord = 0;//resets all the current runs data

		Simulation();
		string goAgain;
		cout << "Would " << name << " like to go again?(enter Y to go again)" << endl;
		getline(cin, goAgain);
		if (!(goAgain[0] == 'y' || goAgain[0] == 'Y')) {//Stops running if the player doesnt type y or Y
			isRunning = false;
		}
	}
}


// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 



// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word

//     Tell recruit how many incorrect guesses he or she has left

//     Show recruit the letters he or she has guessed

//     Show player how much of the secret word he or she has guessed

//     Get recruit's next guess

//     While recruit has entered a letter that he or she has already guessed

//          Get recruit ’s guess

//     Add the new guess to the group of used letters

//     If the guess is in the secret word

//          Tell the recruit the guess is correct

//          Update the word guessed so far with the new letter

//     Otherwise

//          Tell the recruit the guess is incorrect

//          Increment the number of incorrect guesses the recruit has made

// If the recruit has made too many incorrect guesses

//     Tell the recruit that he or she has failed the Keywords II course.

// Otherwise

//     Congratulate the recruit on guessing the secret words

// Ask the recruit if they would like to run the simulation again

// If the recruit wants to run the simulation again

//     Increment the number of simulations ran counter

//     Move program execution back up to // Display the simulation # is starting to the recruit. 

// Otherwise 

//     Display End of Simulations to the recruit

//     Pause the Simulation with press any key to continue
