#include<string>
#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

//print current situation of playboard
void PrintTable(vector<vector<char> > board);

//check if the player win after one move
bool CheckWin(vector<vector<char> > board);

//check if a input is valid or not.
//cell labels like A1, B3 are acceptable. quit button Q is acceptable.
bool checkValidInput(string &input,vector<vector<char> > board);

//game for two players
void twoplayers(vector<vector<char> > &board);

//game for one player
void oneplayer(vector<vector<char> > &board);


int main ()
{
    //initialize 3X3 play board
    vector<vector<char> > board(3,vector<char>(3,' '));

    char gametype;
    char replaygame='Y';
    cout << "*Tic-Tac-Toe Game Start. Above is the 3X3 playing board." << endl << endl;
    
    while(replaygame=='Y'||replaygame=='y'){
        
        //clear the play board
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                board[i][j]=' ';
            }
        }
        
        //print empty play board
        cout << endl;
        PrintTable(board);
        cout << endl;
        
        cout << endl << "*Please select number of player:"<< endl;
        cout << "1. One Player"<< endl;
        cout << "2. Two Players"<< endl;
        cout << "Select: ";
        cin >> gametype;
    
        while(gametype!='1'&&gametype!='2'){
            cout << "Invalid input, please select again: ";
            cin >> gametype;
        }
    
        if(gametype=='1'){
            cout << endl << "One player game start!" << endl;
            oneplayer(board);
        }else if(gametype=='2'){
            cout << endl << "Two players game start!" << endl;
            twoplayers(board);
        }
        
        cout << endl << "Play again? Y/N" << endl;
        cin >> replaygame;
    
    }
    
    return 0;
}

void PrintTable(vector<vector<char> > board){
    
    cout << "    1   2   3  " << endl ;
    cout << "   --- --- ---" << endl;
    cout << " A  " << board[0][0]<< " | " <<board[0][1]<< " | " <<board[0][2]<< " " << endl;
    cout << "   --- --- ---" << endl;
    cout << " B  " << board[1][0]<< " | " <<board[1][1]<< " | " <<board[1][2]<< " " << endl;
    cout << "   --- --- ---" << endl;
    cout << " C  " << board[2][0]<< " | " <<board[2][1]<< " | " <<board[2][2]<< " " << endl;
    cout << "   --- --- ---" << endl;
    
    return ;
}

bool CheckWin(vector<vector<char> > board){
    bool result=false;
    
    for(int i=0;i<board.size();i++){
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]&&board[i][0]!=' '){
            result=true;
        }
        if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]&&board[0][i]!=' '){
            result=true;
        }
    }
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]!=' '){
        result=true;
    }
    if(board[2][0]==board[1][1]&&board[2][0]==board[0][2]&&board[2][0]!=' '){
        result=true;
    }
    return result;
}

bool checkValidInput(string &input,vector<vector<char> > board){
    bool result=true;
    if(input[0]!='A'&&input[0]!='a'&&input[0]!='B'&&input[0]!='b'&&input[0]!='C'&&input[0]!='c'){
        result=false;
    }
    if(input[1]!='1'&&input[1]!='2'&&input[1]!='3'){
        result=false;
    }
    if(input[0]=='a'){input[0]='A';}
    if(input[0]=='b'){input[0]='B';}
    if(input[0]=='c'){input[0]='C';}
    
    if(result&&board[input[0]-'A'+0][input[1]-'1'+0]!=' '){
        return false;
    }
    
    return result;
}

void twoplayers(vector<vector<char> > &board){
    int step=0;          //keep track on how many symbols are inputted, it can't be larger than 9
    string currentInput; //instore input value
    char row,column;     //instore row and column of input
    string currentplayer="Player1";  //define who is current player
    
    //start game until one player win or the board is filled
    while(!CheckWin(board)&&step<9){
        //print out guidance messages, if it's first input, print differently
        if(step==0){
            
            cout << "*Input cell's label to place cross or circle on the board. i.e A2." << endl;
            cout << "*Press Enter when finish input." << endl;
            cout << "*To quit game, input Q." << endl;
        }
        
        //ask player to input location
        currentplayer = step%2==0?"Player1":"Player2";
        cout << endl << currentplayer << ", please input your choice: ";
        cin >> currentInput;
        
        //check if input is valid, if not, ask player to reinput
        while(!checkValidInput(currentInput,board)&&currentInput!="Q"&&currentInput!="q"){
            cout << "!!Invalid input, please try again. Press Q to quit." << endl << "Try again: ";
            cin >> currentInput;
            if(currentInput=="q"||currentInput=="Q"){
                break;
            }
        }
        
        //analyze input and fill the board
        if(currentInput=="Q"||currentInput=="q"){
            cout << "Good Luck, Bye!" << endl;
            break;
        }else{
            row=currentInput[0]-'A';
            column=currentInput[1]-'1';
            board[row][column] = step%2==0?'X':'O';
            cout << endl;
            PrintTable(board);
            if(CheckWin(board)){
                cout << endl << currentplayer << " wins!! Congradulations!!";
                break;
            }
            step++;
        }
    }
    
    //if board filled but no one win, print tie
    if(!CheckWin(board)&&currentInput!="q"&&currentInput!="Q"){
        cout << "Game Tied." << endl;
    }
}

void oneplayer(vector<vector<char> > &board){
    int step=0;          //keep track on how many symbol are inputted, can't be larger than 9
    string currentInput; //store input value as a string
    char row,column;     //convert input infor to row and column in char type
    char firstStep='Y';  //store the player's choice whether he will player first or not
    int firstS=0;        //correspond with variable firstStep, when firstStep='N',firstS=0, otherwise firstS=1
    
    //start game until one player win or the board is filled
    while(!CheckWin(board)&&step<9){
        //if it's first time input, print out game tutorial messages
        //also initialize variable firstStep and firstS
        if(step==0){
            cout << "Do you want to move first?" << endl;
            cout << "Y/N?" << endl;
            cin >> firstStep;
            cout << endl;
            if(firstStep!='N'&&firstStep!='n'){
                cout << "*You will go first." << endl;
            }else{
                firstS=1;
                cout << "*Computer will go first." << endl;
            }
            cout << "*Input cell's label to place cross or circle on the board. i.e A2." << endl;
            cout << "*Press Enter when finish input." << endl;
            cout << "*Anytime you want to quit game, input Q." << endl;
            
        }
        
        //for each step, decide player or computer move firstly
        //if step%2==firstS, player's turn, else computer turn
        //following code is for player to make decision
        if(step%2==firstS){
            //ask player to input location
            cout << endl << "Input your move here: ";
            cin >> currentInput;
            
            //check if the input is valid, if not, ask player to reinput
            while(currentInput!="Q"&&currentInput!="q"&&!checkValidInput(currentInput,board)){
                cout << "!!Invalid input, please try again. Press Q to quit." << endl << "Try again: ";
                cin >> currentInput;
                if(currentInput=="q"||currentInput=="Q"){
                    break;
                }
            }
            
            //analyze the input and fill the board or quit
            if(currentInput=="Q"||currentInput=="q"){
                cout << "Good Luck, Bye!" << endl;
                break;
            }else{
                row=currentInput[0]-'A';
                column=currentInput[1]-'1';
                board[row][column] = step%2==firstS?'X':'O';
                cout << endl;
                PrintTable(board);
                if(CheckWin(board)){
                    cout << endl << "Congradulations you win!!" << endl;
                    break;
                }
            }
            //computer's decision start here
            // 1. its first rule is: if there is one move that can make it win, go
            // 2. rule number two: if there is no move that make it win,
            //    defend and protect player from making three in a roll
            // 3. rule number three: if first two requirements are met, but no move made,
            //    randomly select an empty cell to fill
        }else{
            
            cout << endl << "Computer's input:" << endl;
            bool movemade=false; //check is a move is made
            //rule #1
            if(!movemade){
                for(int l=0;l<3;l++){
                    for(int m=0;m<3;m++){
                        if(board[l][m]==' '&&!movemade){
                            board[l][m]='O';
                            if(CheckWin(board)){
                                movemade=true;
                                cout << endl;
                                PrintTable(board);
                                cout << endl << "Computer wins!" << endl;
                                break;
                            }else{
                                board[l][m]=' ';
                            }
                        }
                    }
                }
            }
            //rule #2
            if(!movemade){
                for(int l=0;l<3;l++){
                    for(int m=0;m<3;m++){
                        if(board[l][m]==' '&&!movemade){
                            board[l][m]='X';
                            if(CheckWin(board)){
                                movemade=true;
                                board[l][m]='O';
                                cout << endl;
                                PrintTable(board);
                                break;;
                            }else{
                                board[l][m]=' ';
                            }
                        }
                    }
                }
            }
            //rule #3
            if(!movemade){
                srand(unsigned(time(0)));
                int count=0;
                int celltofill=rand()%(9-step);
                for(int l=0;l<3;l++){
                    for(int m=0;m<3;m++){
                        if(board[l][m]==' '&&!movemade){
                            if(count==celltofill){
                                board[l][m]='O';
                                cout << endl;
                                PrintTable(board);
                            }
                            count++;
                        }
                        
                    }
                }
            }
            
        }
        step++;
    }
    
    //if board filled but no one win, print tied
    if(currentInput!="q"&&currentInput!="Q"&&!CheckWin(board)){
        cout << endl << "Game Tied." << endl;
    }
}
