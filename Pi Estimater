#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int main () {
   
    int count=0;
    int N = 100000;

    for(int i = 0;i<N;i++){
        double coorx =  double(rand())/double(RAND_MAX);
        double coory =  double(rand())/double(RAND_MAX);
        double location;
        location = coorx*coorx+coory*coory;
        if(location < 1){
            count++;
        }
    }
    
    cout << "The pi value is " << 4*double(count)/double(N) << endl;

    return 0;
}
