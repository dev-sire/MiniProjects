#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
int main(){ 
	std::vector < std::string > words = { "apple", "orange", "cat", "dog", "animal", "love", "money", "care", "gold", "paradise" }; 
	std::mt19937 gen(static_cast < unsigned int > (std::time(nullptr))); std::uniform_int_distribution < int > distribution(0, words.size() - 1);
	std::string selectedWord = words[distribution(gen)];
	int maxIncorrectGuesses = 6, incorrectGuesses = 0;
	std::vector < char > guessedLetters; 
	std::cout << "Welcome to Hangman!" << std::endl;
	while (incorrectGuesses < maxIncorrectGuesses){ 
		std::cout << "Guess the word: ";
		// Display the word with underscores for hidden letters
		for (char letter: selectedWord) {
		  if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
		    std::cout << letter << " ";
		  } else {
		    std::cout << "_ ";
		  }
		}
		std::cout << std::endl;
		// Check is the user has won
		if (std::all_of(selectedWord.begin(), selectedWord.end(),
		    [ & guessedLetters](char letter) {
		      return std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
		    })) {
		  std::cout << "Congratulations! You guessed the word: " << selectedWord << std::endl;
		  break;
		}
		// User Input
		char guess;
		std::cout << "Guess a letter: ";
		std::cin >> guess;	
		// Check if the letter has already been guessed
		if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
		  std::cout << "You've already guessed that letter." << std::endl;
		  continue;
		}	
		// Add the guessed letter to the list
		guessedLetters.push_back(guess);
		// Check if the guessed letter is in the word
		if (selectedWord.find(guess) == std::string::npos) {
		  std::cout << "Incorrect guess!" << std::endl;
		  incorrectGuesses++;
		}
	}
	if(incorrectGuesses >= maxIncorrectGuesses){ 
		std::cout << "You ran out of attempts. The correct word was: " << selectedWord << std::endl; 
	}
	return 0; 
}