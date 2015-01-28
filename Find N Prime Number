#include <iostream>
using namespace std;


bool checkprime(int a)
{
    double check;
    if(a==1)
    {check = 1;}
    else if(a==2)
    {check = 1;}
    else
    {
        check = 1;
        for(int k=2;k<a-1;k++)
        {
            check = check * (a%k);
        }
    }
    if(check == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main () {
    int N, count=0,current=1;
    cout << "Input how many prime number you want." << endl;
    cin >> N;
    int prime[N];
    do{
            if(checkprime(current))
            {
                prime[count]=current;
                count++;
            }
        current++;
    }while(count < N);
    cout << "The prime numbers are: " << endl;
    for(int i=0;i<N;i++)
    {
        cout << prime[i] << endl;
    }
    cout << "There are total " << count << " of prime numbers."<< endl;
    return 0;
}
