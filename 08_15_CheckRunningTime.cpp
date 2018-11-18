#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Timer{
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> start_time = clock_t::now(); // 만들어질 때 현재 time으로 초기화

public:
    void elapsed(){
        std::chrono::time_point<clock_t> end_time = clock_t::now();
        cout << std::chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
    }
};

int main(){

    random_device rnd_device;
    mt19937 mersenne_engine{ rnd_device() };

    vector<int> vec(10000);
    for(unsigned int i=0; i<vec.size(); ++i)
        vec[i] = i;

    std::shuffle(begin(vec), end(vec), mersenne_engine);

    // Show a initial vector
    for(auto &e : vec) cout << e << " ";
    cout << endl;

    // Check time // 릴리즈모드와 디버그모드는 10배 이상 차이남
    Timer timer;
    std::sort(begin(vec), end(vec));
    timer.elapsed();

    // Check a sorted vector
    for(auto &e : vec) cout << e << " ";
    cout << endl;

    return 0;
}