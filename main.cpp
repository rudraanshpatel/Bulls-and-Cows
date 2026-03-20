#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int randomDigit(){
    return (rand()%9+1);
}

unordered_set<int> randomNumber(){
    unordered_set<int> randomSet = {};

    while(randomSet.size()!=4){
        randomSet.insert(randomDigit());
    }
    return randomSet;
}

void initialise(){
    unordered_set<int> random_set = randomNumber();
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
