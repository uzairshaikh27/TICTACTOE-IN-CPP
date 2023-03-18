#include<iostream>
#include<stdlib.h>
using namespace std;

    char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    void display(){
cout<<"Player -1 [X] \t    Player -2 [O]\n";
cout<<"\t |       |\t\n";
cout<<"    "<<arr[0][0]<<"    |   "<<arr[0][1]<<"   |   "<<arr[0][2]<<endl;
cout<<" ________|_______|_______\n";
cout<<"\t |       |\t\n";
cout<<"    "<<arr[1][0]<<"    |   "<<arr[1][1]<<"   |   "<<arr[1][2]<<endl;
cout<<" ________|_______|_______\n";
cout<<"\t |       |\t\n";
cout<<"    "<<arr[2][0]<<"    |   "<<arr[2][1]<<"   |   "<<arr[2][2]<<endl;
cout<<"\t |       |\t\n";
    }


char turn='X';
int choice,row,column;

bool draw= false;//edited here
void playerturn(){
    if(turn=='X'){
        cout<<"Player-1 [X] turn"<<endl;
    }
    else{
        cout<<"Player-2 [0] turn"<<endl;
    }

cout<<"enter your choice"<<endl;
cin>>choice;
switch(choice){
    case 1:{
        row=0;
        column=0;
    break;
    }
    case 2:{
    row=0;
    column=1;
    break;
    }
    case 3:{
        row=0;
        column=2;
    break;
    }
    case 4:{
        row=1;
        column=0;
    break;
    }
    case 5:{
        row=1;
        column=1;
    break;
    }
    case 6:{
        row=1;
        column=2;
    break;
    }
    case 7:{
         row=2;
        column=0;
    break;
    }
    case 8:{
        row=2;
        column=1;
    break;
    }
    case 9:{
       row=2;
        column=2;
    break;
    }
default:{
    cout<<"enter valid choice";
}}
if(turn=='X'&& arr[row][column]!='X' && arr[row][column]!='0'){
    arr[row][column]='X';
    turn='0';

}else if(turn=='0' && arr[row][column]!='0' && arr[row][column]!='X'){
    arr[row][column]='0';
    turn='X';
}else{
    cout<<"that box is already filled, choose other box"<<endl;
    playerturn();
}
display();
}
bool gameover(){
    for(int i=0;i<3;i++){
        if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2]  ||  arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i]){
            return false;
        }
    }
    if(arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2] || arr[0][2]==arr[1][1] && arr[0][2]==arr[2][0])
    return false;

    for(int i=0;i<2;i++){
        for(int j=0; j<2;j++){
            if(arr[i][j]!='X' && arr[i][j]!='0')
            return true;

        }
    }
    
            draw=true;
            return false;
}
int main(){
while(gameover()){
    display();
    playerturn();
    gameover();
}
if(turn=='X' && draw==false){
    cout<<"Congratulations.....Player-2 WON !!!"<<endl;
}
else if(turn=='0' && draw==false){
    cout<<"Congratulations.....Player-1 WON !!!"<<endl;
}
else{
    cout<<"Game DRAW !!!"<<endl;
}
    return 0;
}





