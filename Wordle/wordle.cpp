#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

/* Function prototypes */
void gameloop();
int randInt(int a, int b);
string getWord();
void displayOpeningMessage();

/* Wordle class definition */
class Wordle { 
private:
	string word;

	// Returns a string code as per the game rules explained in the opening message
	// This function working currently depends heavily on the word and guess strings being the same length; will break otherwise
	string validateGuess(string guess) {
		string code = "";
		for (int i = 0; i < word.length(); i++) {
			if (guess[i] == word[i]) { // Do the letters in the same place of both words match?
				code.append("!");
			}
			else {					   // Does this letter of our guess exist anywhere in the target word?
				bool foundAny = false;
				for (int j = 0; j < word.length(); j++) { 
					if (guess[i] == word[j]) {
						foundAny = true;
					}
				}
				if (foundAny) {
					code.append("*");
				}
			}
			if (code.length() <= i) { // If at this point we have found no matches, the letter does not exist
				code.append("-"); 
			}
		}
		return code;
	}
public:
	// Default constructor; just gives it a word from the getWord word list.
	Wordle() {
		this->word = getWord();
	}
	// Alternate constructor for fun and testing; could put in nonstandard words, but the same warning for validateWord applies.
	Wordle(string word) {
		this->word = word;
	}

	// A loop of one game of Wordle, with an early quit option
	void play() {
		cout << "Enter your guess, or press q to quit early: "; //give the user a way to exit without finishing
		string guess = "a";
		while (guess != "q") {
			cin >> guess;
			if (guess == "q") {
				return;
			}

			//currently, if guess is not the same length as word, this might explode from referencing past an array.
			string code = validateGuess(guess);
			for (int i = 0; i < guess.length(); i++) {
				cout << code[i] << guess[i] << " ";
			}
			cout << endl << endl;

			if (guess == word) {
				cout << "Nice! You did it!" << endl;
				return;
			}
		}
	}
};

/* Generates a random integer between a and b, b noninclusive */
int randInt(int a, int b) {
	int c = b - a;
	srand(time(NULL));
	return rand() % c + a;
}

/* Returns a random word from a small word list currently defined within the function */
string getWord() {
	int randomIndex = randInt(0, 5);
	vector<string> words { "rocks", "stick", "blade", "laser", "mango" };
	return words[randomIndex];
}

/* General menu loop; lets a user to play games of Wordle until they exit */
void gameloop() {
	char choice = 'p';
	while (choice != 'q' && choice != 'Q') { // While we don't quit...
		cout << "Press p to play or q to quit: ";
		cin >> choice;
		if (choice == 'p' || choice == 'P') { // ...make a new Wordle and play
			cout << endl;
			Wordle session;
			session.play();
		}
	}
	return;
}

/* Welcome the user to the game and explain the rules, if they are unfamiliar with Wordle */ 
void displayOpeningMessage() {
	cout << "Welcome to Wordle!" << endl;
	cout << "How to play: \n"
		<< "When prompted, guess a 5-letter word until you get it correct.\n"
		<< "Each guess will be displayed back to you with feedback. If you guess a letter...\n"
		<< "   - correctly and in the right position, a ! will be next to it.\n"
		<< "   - correctly but in the wrong position, a * will be next to it.\n"
		<< "   - entirely incorrectly, a - will be next to it.\n"
		<< "Please keep all of your inputs lowercase!" << endl;
		// This particular clause is because we lack super great user input checking and handling. 
}

/* Run the whole thing */
int main()
{
	displayOpeningMessage();
	gameloop();
	return 0;
}