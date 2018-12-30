/* keywords
Pure virtual function : 바디가 없는 함수(class::function()으로 구현 가능하나 의미가 없음)
Abstract class        : 순수 가상함수를 포함
Interface class       : 순수 가상함수로만 구성
*/

#include <iostream>
#include <string>
using namespace std;

class IErrorLog{ // body가 없는 pure virtual function 으로만 구현했으므로 interface에 해당
    public:
    virtual bool reportError(const char* errorMessage) = 0;
    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog{
    public:
    bool reportError(const char* errorMessage) override{
        cout << "Writing error to a file" << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog{
    public:
    bool reportError(const char* errorMessage) override{
        cout << "Priting error to a file" << endl;
        return true;
    }
};

void doSomething(IErrorLog& log){
    log.reportError("Runtime error!!");
}

int main(){
    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    doSomething(file_log);
    doSomething(console_log);

    return 0;
}