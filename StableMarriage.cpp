#include <iostream>
using namespace std;

void print(int q[], int& c, int& sol){

    cout << "Solution " << sol << endl;
    sol++;
    cout << "Man\tWoman" <<endl;

    for(int i = 0; i<c; i++){
        cout << i<< "\t"<<q[i]<<endl;
    }
    cout << endl;
    c--;
}

bool isOk(int q[], int c){

int mp[3][3]={
0,2,1,
0,2,1,
1,2,0
};

int wp[3][3]={
2,1,0,  //0
0,1,2,  //1
2,0,1   //2
};


for(int i = 0; i < c; i++){
    //If woman has already been assigned
    if(q[i] == q[c]) return false;
    //if the current man prefers the new woman to his partner and
    //if the new woman prefers the current man to her partner return false


//current man preference on new woman < current man preference on his wife
    if(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i]<wp[q[c]][c]){
                                // new woman preference on current man < new woman preference on her partner
        return false;
    }

    //man#c and man#i's wife like each more than their own spouse,
    if(mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[i][i]){
        return false;
    } 
 }// for loop 
 return true;
}//isOk 


int main(){
int q[3] = {};
int c = 0;
int sol = 1;
while(c>=0){
c++;  
    if(c==3){
        print(q,c, sol);
        c--;
    }else q[c] = -1;
    
    while(c>=0){
        q[c]++;

        if(q[c] == 3){
              c--;
        }
        else if(isOk(q,c)){
            break;
        }
    }
    
    
}//outside while loop

return 0;

}