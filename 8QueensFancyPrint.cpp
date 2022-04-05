
#include <iostream>
using namespace std;

void print(int b[], int sol){


cout << "Solution #" << sol << ":";
cout << endl;

for (int i = 0; i < 8; i++)
      
	{
	  cout << b[i];
	}
    cout << "\n\n";

//string queen[5][7];
//string blankqueen[5][7];

typedef string box[5][7];

box queen;
for(int r= 0; r < 5; r++){
    for(int c = 0; c<7; c++){
        if((r==2 || r==3 || c==1 || c==3 || c==5) && c!=0 && c!=6 && r!=0 && r!=4){
            queen[r][c] = ' ';
        }else {queen[r][c] = "\u2588";}

        
    }
    //cout << endl;
}

box blankqueen;
for(int r= 0; r < 5; r++){
    for(int c = 0; c<7; c++){
        if((r==2 || r==3 || c==1 || c==3 || c==5) && c!=0 && c!=6 && r!=0 && r!=4){
            blankqueen[r][c] = "\u2588";
        
        }else {blankqueen[r][c] = ' ';}

        
    }
   // cout << endl;
}
box bb,wb, *board[8][8];


for(int i = 0; i < 5; i++){
    for(int j = 0; j<7; j++){
        bb[i][j] = ' ';
        wb[i][j] = "\u2588";
    }
}

for(int i = 0; i < 8; i++){

    for(int j = 0; j<8; j++){
        if((j+i)%2==0) {
            if(b[j]==i) board[i][j] = &queen;
            else board[i][j]= &wb;
            }
        else{
            if(b[j]==i) board[i][j] = &blankqueen;
            else board[i][j] = &bb;
        }
    }
}

for(int i = 0; i < 8; i++){
    for(int k = 0; k < 5; k++){
        for(int j = 0; j<8; j++){
            for(int l = 0; l<7; l++){
                cout << (*board[i][j])[k][l];
        
            }
        }
        cout << endl;
    }
    //cout << endl;
}
cout << endl;

}//print

bool isSafe(int b[], int col){
//row and diag test
    for(int i = 0; i < col; i++){
        if(b[col] == b[i] || abs(b[col] - b[i]) == col-i){
            return false;

        }//if

    }//for
    return true;
}//isSafe



int main(){
int b[8] = {};
int c=0;
b[0] = 0;
int solutions = 0;

    while(c>=0){
        c++;
        
        if(c==8){
            solutions++;
            print(b,solutions);
            c--;  
        } else b[c] = -1;
        while(c>=0){
            b[c]++;
            if(b[c]==8){
                c--; //backtrack
            }//if statement
            else if(isSafe(b,c)){
                break;
            }
        }//third while

    }//second while


return 0;
}//main 

