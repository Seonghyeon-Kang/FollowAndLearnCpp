#include <iostream>
#include <string>
using namespace std;

int main(){
    // 1. syntax error
    //int x

    // 2. semantic errors
    int x;
    cin >> x;

    if (x >= 5) // 주석과 다른 부등호
        cout << "x is greater than 5" << endl;

    // 3. violated assumption
    string hello = "Hello. my name is Jack jack";

    cout << "Input from 0 to " << hello.size() - 1 << endl;

    int ix;

    while(true){
        cin >> ix; // 문자보다 긴 수를 입력하면?
        
        if (ix >=0 && ix <= hello.size()-1){
            cout << hello[ix] << endl;
            break;
        }
        else{
            cout << "Please try again" << endl;
        }
    }
    
    return 0;
}