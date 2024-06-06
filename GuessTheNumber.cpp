#include <iostream> 
#include <random> 
#include <ctime>
int main(){ 
	std::cout << "Welcome to Guess-the-number Game" << std::endl;
	std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
	std::uniform_int_distribution<int> distribution(0, 100);
	int guessed_num = distribution(gen);
	int num;
	bool gameNotFinished = true;
		while (gameNotFinished){
	    	do{
	        std::cout << "Enter the number(1-100): ";
	        std::cin >> num;
	    } while (num < 0 || num > 100);
	    if (guessed_num < num)
	        std::cout << "your option is greater than guess number" << std::endl;
	    else if (guessed_num > num )
	        std::cout << "your option is lesser than guess number" << std::endl;
	    else{
	        std::cout << "Your Guess Number is Correct" << std::endl;
	        gameNotFinished = false;
	    }
	}
}