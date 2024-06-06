#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0));
    string choices[] = {"Rock", "Paper", "Scissors"};
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Enter your choice (Rock, Paper, or Scissors): ";
    string userChoice;
    cin >> userChoice;
    int randomIndex = rand() % 3; // 0 for Rock, 1 for Paper, 2 for Scissors
    string computerChoice = choices[randomIndex];
    cout << "You chose: " << userChoice << endl;
    cout << "Computer chose: " << computerChoice << endl;
    if (userChoice == computerChoice){
        cout << "It's a tie!" << endl;
    }
    else if ((userChoice == "Rock" && computerChoice == "Scissors") || (userChoice == "Paper" && computerChoice == "Rock") || (userChoice == "Scissors" && computerChoice == "Paper")){
        cout << "You win!" << endl;
    }
    else{
        cout << "Computer wins!" << endl;
    }
    return 0;
}