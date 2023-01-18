#include <map>
#include <iostream>

using namespace std;

int main(){
    int numCards;
    int cardID;
    map<int, int> cards;
    cin >> numCards;

    for(int i = 0; i < numCards; i++){
        cin >> cardID;
        if(cards.count(cardID) == 0){
            cards.insert(pair<int, int>(cardID, 1));
        }else{
            cards[cardID] += 1;
        }
    }

    for(auto& elements : cards){
        cout << elements.first << " " << elements.second << endl;
    }
    return 0;
}