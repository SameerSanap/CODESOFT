#include <bits/stdc++.h>
using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(0)));

    const int minNumber = 1;
    const int maxNumber = 50;
    const int maxAttempts = 10; 

    char playAgain;

    do {
        int randomNumber = rand()% (maxNumber- minNumber + 1) + minNumber;
        int guess;
        int attempts = 0;

        cout <<"Welcome to the Number Guessing Game!" <<endl;
        cout <<"Guess a number between "<<minNumber <<" and "<<maxNumber<< "." << endl;

        do {
            cout << "Attempts remaining: "<<maxAttempts - attempts<<endl;
            cout << "Enter your guess: ";
            cin >> guess;
            cout<<endl;
            attempts++;

            if (guess > randomNumber) {
                cout << "Too high! Try a lower number." <<endl;
            } else if (guess < randomNumber) {
                cout << "Too low! Try a higher number." <<endl;
            } else {
                cout << "Congratulations!! You guessed the number "<<randomNumber<<" in " <<attempts <<" attempts!!"<<endl;
                break;
            }
        } while (guess != randomNumber && attempts < maxAttempts);

        if (attempts == maxAttempts && guess != randomNumber) {
            cout<<"Sorry, you've exhausted all attempts. The correct number was "<<randomNumber<< "."<<endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while(playAgain == 'y' || playAgain == 'Y');

    cout<<"Thank you for playing the Number Guessing Game! Goodbye!"<<endl;

    return 0;
}
