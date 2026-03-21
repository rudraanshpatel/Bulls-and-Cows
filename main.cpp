#include <bits/stdc++.h>

using namespace std;
//Converts vector into integer
int integer(vector<int> vec){
    int result = 0;
    for(int i: vec){
        result*=10;
        result+=i;
    }
    return result;
}
//Converts integer into vector
vector<int> convertToVector(int n){
    vector<int> vec;
    while(n>0){
        auto it = vec.begin();
        vec.insert(it,n%10);
        n/=10;
    }
    return vec;
}

//Generate a vector of 4 randomly generated digits
vector<int> randomVec(int n){
    vector<int> result;
    
    // A vector of integers from 1-9
    vector<int> integers;
    for(int i = 1; i<=9; i++){
        integers.emplace_back(i);
    }

   // Generates the random n sized vector
   while(result.size()!=n){
       // We create a random index from 0-8
       int randomIndex = rand()%integers.size();
       int randomDigit = integers.at(randomIndex);
       result.push_back(randomDigit);
       auto it = integers.begin()+randomIndex;
       integers.erase(it);

   }
   return result;


}
//Function to process user guesses
void countBullsAndCows(int guess, int choice){
    vector<int> guessVector = convertToVector(guess);
    vector<int> choiceVector = convertToVector(choice);
    //Count bulls
    int bulls = 0;
    for(int i =0; i<guessVector.size(); i++){
        if(guessVector[i]==choiceVector[i]){
            bulls+=1;
            
        }
    }
    cout << "There are "<< bulls<<" bulls and ";
    //Count cows
    int cows = 0;
    set<int> guessSet(guessVector.begin(),guessVector.end());
    for(int i =0; i<guessSet.size();i++){
        auto it = guessSet.find(choiceVector[i]);
        if(it != guessSet.end()){
            cows+=1;
        }
    }
    cows = cows-bulls;
    cout<<cows<<" cows\n";
}

// Controls the game flow
void initialise(){
    int numberOfDigits;
    cout << "Choose the number of digits(1-9):";
    cin >> numberOfDigits;
    if(numberOfDigits>=1 && numberOfDigits<=9){
    int random_number = integer(randomVec(numberOfDigits));
    //cout << random_number << endl;
    int guess = 0000;
    while(random_number != guess){
        cout << "Give your guess\n";
        cin >> guess;
        std::string s = std::to_string(guess);
        int length = s.size();
        vector<int> guessVector = convertToVector(guess);
        set<int> guessSet(guessVector.begin(), guessVector.end()); 
        if(length!=numberOfDigits){
            cout << "Invalid Input: Please give a "<<numberOfDigits<<" digit number.\n";
        }
        else if(guessSet.size()!=numberOfDigits){
            cout << "Invalid Input: Please give a guess with all unique digits\n";
        }
        else{
            countBullsAndCows(guess,random_number);
        }
    }
    cout << "You have successfully guessed the number\n";}
    else{
        cout << "Please choose a valid number of digits.\n";
        initialise();
    }
}

int main(){
    srand(time(0));
    initialise();
}
