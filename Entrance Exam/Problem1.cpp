#include <iostream>
#include <math.h>

using namespace std;

int main(){
    signed int xCenter;
    signed int yCenter;
    int radius;
    int numCoords;
    
    signed int xCoord;
    signed int yCoord;
    cin >> xCenter >> yCenter >> radius >> numCoords;
    
    for(int i = 0; i < numCoords; i++){
        cin >> xCoord >> yCoord;
        if(sqrt(pow((xCoord - xCenter), 2) + pow((yCoord - yCenter), 2)) > radius){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}