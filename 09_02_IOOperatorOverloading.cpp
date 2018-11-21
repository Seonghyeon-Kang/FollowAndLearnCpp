#include <iostream>
#include <fstream>
using namespace std;

class Point{

private:
    double m_x, m_y, m_z;

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
        :m_x(x), m_y(y), m_z(z)
    {}

    double getX(){ return m_x; }
    double getY(){ return m_y; }
    double getZ(){ return m_z; }

    void print(){
        cout << m_x << " " << m_y << " " << m_z << endl; 
    }

    // 파일 출력과 콘솔 출력을 담당
    friend std::ostream& operator << (std::ostream &out, const Point &point){
        out << "(" << point.m_x << " " << point.m_y << " " << point.m_z << ")" ;
        return out; // chaining
    }

    // 콘솔 입력을 담당
    friend std::istream& operator >> (std::istream &in, Point &point){
        in >> point.m_x >> point.m_y >> point.m_z;
        return in; // chaining
    }
};

int main(){
    Point p1(0.0, 0.1, 0.2);
    Point p2(3.4, 1.5, 2.0);

    // 일반함수
    p1.print();

    // 콘솔 출력
    cout << p1 << " " << p2 << endl;

    // 파일 출력
    ofstream of("out.txt");
    of << p1 << " " << p2 << endl;
    of.close();

    // 콘솔 입력
    Point p3, p4;
    cin >> p3 >> p4;
    cout << p3 << " " << p4 << endl;

    return 0;
}