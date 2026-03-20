#include <bits/stdc++.h>

using namespace std;

// This function generates a random number between 1-9
int randomDigit(){
    return (rand()%9+1);
}

// Returns an unordered set with 4 unique digits
unordered_set<int> randomNumber(){
    unordered_set<int> randomSet = {};

    while(randomSet.size()!=4){
        randomSet.insert(randomDigit());
    }
    return randomSet;
}

// Initialises the game
void initialise(){
    unordered_set<int> random_set = randomNumber();
    //converts the unordered set into a vector for no reason
    vector<int> random_vector(random_set.begin(), random_set.end());
    int random_number = 0;
    // This converts the set into an actual integer for easier comparison?
    for(int i : random_vector){
        random_number*=10;
        random_number+=i;
    }
    cout << random_number;


}

int main(){
    srand(time(0));
    initialise();
}
