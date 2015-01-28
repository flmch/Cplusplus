#include<iostream>
#include<math.h>

using namespace std;

char** NextGeneration(char a[5][5]);
void PrintForest(char **a);
void PrintForest(char a[5][5]);
void AssignForest(char a[5][5],char **p);


int main(){
    
    char Forest[5][5]={{'G','G','I','G','D'},
                       {'G','G','G','G','G'},
                       {'G','I','G','G','G'},
                       {'G','G','G','I','G'},
                       {'G','D','G','G','G'}};
    int Generation = 10;
    cout << "Original Condition is " << endl;
    PrintForest(Forest);

    for(int g=0;g<Generation;g++){
        char **p;
        p=NextGeneration(Forest);
        AssignForest(Forest, p);
        cout << "Number " << g+1 << " Generation is:" << endl;
        PrintForest(Forest);
    }
    
    return 0;
}



char** NextGeneration(char a[5][5]){
    char** table;
    table = new char*[5];
    for(int i=0;i<5;i++){
        table[i]=new char[5];
        for(int j=0;j<5;j++){
            //initializing
            table[i][j]='G';
        }
    }//end of initializaing
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(a[i][j]=='I'){
                    table[i][j]='D';
                    if((i-1)>=0&&a[i-1][j]=='G'){table[i-1][j]='I';}
                    if((i+1)<5&&a[i+1][j]=='G'){table[i+1][j]='I';}
                    if((j-1)>=0&&a[i][j-1]=='G'){table[i][j-1]='I';}
                    if((j+1)<5&&a[i][j+1]=='G'){table[i][j+1]='I';}
            }else if(a[i][j]=='D'){
                table[i][j]='G';
            }
        }
    }//end of loop
    
    return table;
}

void PrintForest(char **a){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void PrintForest(char a[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void AssignForest(char a[5][5],char **p){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            a[i][j]=p[i][j];
        }
    }
}
