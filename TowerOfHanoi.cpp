#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> t[3]; //three towers
    int n, candidate = 1, to, from = 0, move=0;// move counts the numbers of moves

    cout << "Please enter a number of rings to move:";
    cin >> n;
    cout << endl;

    //Creating the three towers

    for(int i = n+1; i>=1; i--){
        t[0].push_back(i);
    }
    
    t[1].push_back(n+1);
    t[2].push_back(n+1);
    


    //initilize towers and candidate from 0 to 1.
if(n%2==1){
    to=1;
    while(t[1].size() != n+1){//while there are still rings to be transferred to tower b
        cout << "move number: " << ++move << ": Transfer ring" << candidate << " from tower " << char(from+65) << " to tower " << char(to+65) << endl;

    //moving the rings around

    t[to].push_back(t[from].back());//moves the top of the from tower to the to tower
    t[from].pop_back();



    //determines the new from value
    if(t[(to+1)%3].back() < t[(to+2)%3].back()){
        from = (to+1)%3;
    }
    else{
        from = (to+2)%3;
    }

    //canidate
    candidate = t[from].back();

    if(t[from].back()<t[(from+1)%3].back()){
        to = (from+1)%3;
    }
    else{
        to = (from+2)%3;
    }
    
    }
}

if(n%2==0){
    to=2;
    while(t[1].size() != n+1){//while there are still rings to be transferred to tower b
        cout << "move number: " << ++move << ": Transfer ring" << candidate << " from tower " << char(from+65) << " to tower " << char(to+65) << endl;

    //moving the rings around

    t[to].push_back(t[from].back());//moves the top of the from tower to the to tower
    t[from].pop_back();



    //determines the new from value
    if(t[(to+2)%3].back() < t[(to+1)%3].back()){
        from = (to+2)%3;
    }
    else{
        from = (to+1)%3;
    }

    //canidate
    candidate = t[from].back();

    if(t[from].back()>t[(from+2)%3].back()){
        to = (from+1)%3;
    }
    else{
        to = (from+2)%3;
    }
    
    }
}
    
    
    return 0;
}