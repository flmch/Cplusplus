//
//  main.cpp
//  test11
//
//  Created by ZHANG Xi on 5/25/13.
//  Copyright (c) 2013 ZHANG Xi. All rights reserved.
//
#include<iostream>
#include<string.h>
using namespace std;


int NumOfMOnLeft = 0;
int NumOfCOnLeft = 0;
int NumOfMOnRight = 3;
int NumOfCOnRight = 3;
int NumOfMOnBoat = 0;
int NumOfCOnBoat = 0;
char BoatPosition = 'R';

void boatswitch(char &a);

int main()
{
    cout << "Please input what you want to transfer (C/M), " << endl;
    cout << "Maximum two objects on the boat. " << endl;
    cout << "Input N if leave position empty" << endl;

    do{
        char BoatPositionOne, BoatPositionTwo;  //Define two passengers on boat
        int NumCheck = 0;    //Used to check if there's illegal input
        
        cout << "---------------------------" << endl;
        cout << "Right Dock: ";   // Print out right dock situation
        for(int i=0;i<NumOfCOnRight;i++){
            cout << "C, ";}
        for(int i=0;i<NumOfMOnRight;i++){
            cout << "M, ";}
        cout << endl;
            
        cout << "Left Dock: ";    // Print out left dock situation
        for(int i=0;i<NumOfCOnLeft;i++){
            cout << "C, ";}
        for(int i=0;i<NumOfMOnLeft;i++){
            cout << "M, ";}
        cout << endl;
        
        cout << "Boat Position: " << BoatPosition << endl;   // Print out where's the boat

        
        //First passenger input
        do{
        cout << "First position: ";
        cin >> BoatPositionOne;
            NumCheck = 0;
        if(BoatPositionOne == 'C'){
            if(BoatPosition == 'R'){

                if(NumOfCOnRight-1 < 0){NumCheck = 1; cout << "Illegal Input!Choose Again.11"<<endl;}
                else{ NumOfCOnBoat++; NumOfCOnRight--;}
                
            }else{
                
                if(NumOfCOnLeft-1 < 0){NumCheck = 1;cout << "Illegal Input!Choose Again.22"<<endl;}
                else{ NumOfCOnBoat++; NumOfCOnLeft--;}
                
            }
        }else if(BoatPositionOne == 'M'){
            if(BoatPosition == 'R'){

                if(NumOfMOnRight-1 < 0){NumCheck = 1;cout << "Illegal Input!Choose Again.33"<<endl;}
                else{ NumOfMOnBoat++;NumOfMOnRight--;}
                
            }else{

                if(NumOfMOnLeft-1 < 0){NumCheck = 1;cout << "Illegal Input!Choose Again.44"<<endl;}
                else{ NumOfMOnBoat++;NumOfMOnLeft--;}
            }
        }else if(BoatPositionOne == 'N'){
            NumCheck = 1;
            cout << "First Passengar can't be empty. Choose again." << endl;
        }else{
            cout << "Invalid input, choose again. " << endl;
        }
            
            
        }while(NumCheck == 1);
        
        //Second passenger input
        do{
            cout << "Second position: ";
            cin >> BoatPositionTwo;
            NumCheck = 0;
            if(BoatPositionTwo == 'C'){
                if(BoatPosition == 'R'){
                    
                    if((NumOfCOnRight-1<0)||((NumOfCOnRight-1<NumOfMOnRight)&&(NumOfCOnRight-1!=0))){NumCheck = 1; cout << "Too few C on one side"<<endl; }
                    else{ NumOfCOnBoat++; NumOfCOnRight--;}
                    
                }else{
                    
                    if((NumOfCOnLeft-1<0)||((NumOfCOnLeft-1<NumOfMOnLeft)&&(NumOfCOnLeft-1!=0))){NumCheck = 1;cout << "Too few C on one side"<<endl;}
                    else{ NumOfCOnBoat++; NumOfCOnLeft--;}
                    
                }
                
                
            }else if(BoatPositionTwo == 'M'){
                if(BoatPosition == 'R'){
                    
                    if((NumOfMOnRight-1)< 0){NumCheck = 1;cout << "Too few C on one side"<<endl;}
                    else{ NumOfMOnBoat++; NumOfMOnRight--;}
                    
                }else{
                    
                    if((NumOfMOnLeft-1) < 0){NumCheck = 1;cout << "Too few C on one side"<<endl;}
                    else{ NumOfMOnBoat++; NumOfMOnLeft--;}
                }
            }else if(BoatPositionTwo != 'N'){
                NumCheck = 1;
                cout << "Invalid input, choose again. " << endl;
            }
            
            //Check if C is less than M
            if(NumCheck == 0){
            if(BoatPosition == 'R'){
                if(((NumOfCOnLeft + NumOfCOnBoat<NumOfMOnLeft + NumOfMOnBoat)&&(NumOfCOnLeft + NumOfCOnBoat!=0))||((NumOfCOnRight <NumOfMOnRight)&&(NumOfCOnRight!=0))){
                    NumCheck = 1;
                    cout << "C less than M!! NNNNOOOO!!" << endl;
                }
            }else{
                if(((NumOfCOnRight + NumOfCOnBoat<NumOfMOnRight + NumOfMOnBoat)&&(NumOfCOnRight + NumOfCOnBoat!=0))||((NumOfCOnLeft <NumOfMOnLeft)&&(NumOfCOnLeft!=0))){
                    NumCheck = 1;
                   cout << "C less than M43!! HELPPP!!!!" << endl;
                }
            }
            }
                
        }while(NumCheck == 1);
   
        
        if(BoatPosition == 'R'){
                NumOfCOnLeft = NumOfCOnLeft + NumOfCOnBoat;
                NumOfMOnLeft = NumOfMOnLeft + NumOfMOnBoat;
                boatswitch(BoatPosition);
        }else{
                NumOfCOnRight = NumOfCOnRight + NumOfCOnBoat;
                NumOfMOnRight = NumOfMOnRight + NumOfMOnBoat;
                boatswitch(BoatPosition);
        }
        NumOfCOnBoat = 0;
        NumOfMOnBoat = 0;
        
            
        cout << "---------------------------" << endl;  // Input finished
        

        /*cout << NumOfMOnLeft << endl;
        cout << NumOfCOnLeft << endl;
        cout << NumOfMOnRight << endl;
        cout << NumOfCOnRight << endl;
        cout << BoatPositionOne << endl;
        cout << BoatPositionTwo << endl;
        cout << NumOfCOnBoat << endl;
        cout << NumOfMOnBoat << endl;
        cout << BoatPosition << endl;*/
        
        
    }while( (NumOfCOnLeft+NumOfMOnLeft) < 6);
    
    cout << "You Win!!" << endl;
    
    
    return 0;
}

void boatswitch(char &a){
    if(a == 'R'){
        a = 'L';
    }else{
        a = 'R';
    }
}


