#include <bits/stdc++.h>

using namespace std;

//Generate a vector of n randomly generated unique digits (0-9)
vector<int> randomVec(int n){
    vector<int> result;

    vector<int> pool;
    for(int i = 0; i <= 9; i++) pool.emplace_back(i);

    while(result.size() != n){
        int idx = rand() % pool.size();
        result.push_back(pool[idx]);
        pool.erase(pool.begin() + idx);
    }

    return result;
}

//Function to process user guesses
void countBullsAndCows(vector<int>& guessVec, vector<int>& secretVec){
    int bulls = 0;
    for(int i = 0; i < (int)guessVec.size(); i++){
        if(guessVec[i] == secretVec[i]) bulls++;
    }
    cout << "There are " << bulls << " bulls and ";

    int cows = 0;
    set<int> guessSet(guessVec.begin(), guessVec.end());
    for(int digit : secretVec){
        if(guessSet.count(digit)) cows++;
    }
    cows -= bulls;
    cout << cows << " cows\n";
}

// Controls the game flow
void initialise(){
    int numberOfDigits;
    cout << "Choose the number of digits(1-9):";
    cin >> numberOfDigits;
    if(numberOfDigits >= 1 && numberOfDigits <= 9){
        vector<int> secretVec = randomVec(numberOfDigits);

        int attemptCount = 0;
        bool won = false;

        while(!won){
            cout << "Give your guess\n";
            string guess;
            cin >> guess;

            if((int)guess.size() != numberOfDigits){
                cout << "Invalid Input: Please give a " << numberOfDigits << " digit number.\n";
                continue;
            }

            bool allDigits = true;
            for(char c : guess){
                if(!isdigit(c)){ allDigits = false; break; }
            }
            if(!allDigits){
                cout << "Invalid Input: Please enter digits only.\n";
                continue;
            }

            vector<int> guessVec;
            for(char c : guess) guessVec.push_back(c - '0');

            set<int> guessSet(guessVec.begin(), guessVec.end());
            if((int)guessSet.size() != numberOfDigits){
                cout << "Invalid Input: Please give a guess with all unique digits\n";
                continue;
            }

            countBullsAndCows(guessVec, secretVec);
            attemptCount++;

            if(guessVec == secretVec) won = true;
        }

        cout << "You have successfully guessed the number in";
        cout << " " << attemptCount << " attempts\n";
    }
    else{
        cout << "Please choose a valid number of digits.\n";
        initialise();
    }
}

int main(){
    srand(time(0));
    initialise();
}
