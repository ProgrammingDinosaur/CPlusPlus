#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int points[10] = {10,10,8,6,5,5,7,8,10,9};
    int sum = 0;
    for (int i = 0; i < (sizeof(points)/sizeof(points[0]));i++){
        sum = sum + points[i];
        if ( i == 9) {
            cout << "Media es: " << to_string(float(sum)/float(i+1));
        }
        else{
            ;
        }
    }

    return 0;
}
