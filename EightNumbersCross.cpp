//Venai Seepersaud Eight Numbers Cross


#include <iostream>
using namespace std;


bool isSafe(int a[], int b){

int restrictions[8][5] = {
    
    {-1},          //0
    {0,-1},        //1
    {0,-1},        //2
    {0,1,2,-1},    //3
    {0,1,3,-1},    //4
    {1,4,-1},      //5
    {2,3,4,-1},    //6
    {3,4,5,6,-1}   //7
   
};

//row test
for(int i = 0; i<b; i++){
    if(a[i] == a[b]) return false;
}


//test using restrictions


for(int i = 0; restrictions[b][i]>=0; i++){
    if(a[b] == a[restrictions[b][i]] + 1 || a[b] == a[restrictions[b][i]] -1) return false;
}

return true;
}//isSafe end

void print(int a[], int sol){
    cout << "Solution #"<< sol << endl;
    cout << " "  << a[0] << a[1] << endl;
    cout << a[2] << a[3] << a[4] << a[5] <<endl;
    cout << " "  << a[6] << a[7] << endl;
    cout << endl;
}//print


int main(){
    int q[8] = {};
    int c = 0;
    int sol = 0;
    //nextIndex(cross, 0);
        while(c>=0){
        c++;
        if(c==8){
            sol++;
            print(q, sol);
            c--;
        } else q[c] = -1;
            while(c>=0){
                q[c]++;
                if(q[c] == 8){
                    c--;
                }else if(isSafe(q,c)) break;
            }
        }
    return 0;

}