#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){ // 첫번째 인수는 Arg 수, 두번째 인수는 문자배열
    for(int count=0 ; count < argc; ++count){
        std::string argv_single = argv[count];

        if (count == 1){
            int input_number = std::stoi(argv_single); // 문자를 정수로
            cout << input_number + 1 << std::endl;
        }
    }
}

// Boost.Program_options 제어 기능은 준 표준 라이브러리와 같으므로 
// 공부해볼 필요가 있음 