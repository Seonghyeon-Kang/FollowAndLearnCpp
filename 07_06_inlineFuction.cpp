#include <istream>

inline int min(int x, int y){ // inline 키워드만으로 인라인 함수가 됨
    return x > y ? y : x;
}

int main (){
    cout << min(5, 6) << endl;
    cout << min(3, 2) << endl;

    cout << (5 > 6 ? 6 : 5) << endl; // 컴파일러의 판단 하에 
    cout << (3 > 2 ? 2 : 3) << endl; // inline이 선언한 함수를 직접 코드로 전환함

    // ※ 함수 호출을 위해 로컬 변수를 생성하는 등 부가 작업이 없어지기 때문에 빠른 실행 가능
    // ※ 컴파일러 발전에 따라 inline의 효용성이 점차 모호해지고 있음(알아서 최적화)
    // ※ 또한 코드가 길어질 수 있는 단점이 있음
}