# include <iostream>
# include <vector>
# include <string>
using namespace std;

class Doctor; // forward declaration, 서로 동등한 관계이기 때문에 전방 선언이 필요함

class Patient{
private:
    string m_name;
    vector<Doctor*> m_pDoctors;

public:
    Patient(std::string name_in)
        : m_name(name_in)
    {}

    void addDoctor(Doctor* new_pDoctor){
        m_pDoctors.push_back(new_pDoctor);
    }

    void meetDoctors();

    friend class Doctor;
};

class Doctor{
private:
    string m_name;
    vector<Patient*> m_pPatient;

public:
    Doctor(string name_in)
        : m_name(name_in)
    {}

    void addPatient(Patient* new_pPatient){
        m_pPatient.push_back(new_pPatient);
    }

    void meetPatient(){
        for (auto & ele : m_pPatient)
            cout << ele->m_name << endl;
    }

    friend class Patient;    
};

void Patient::meetDoctors(){ // 전방 선언과 유사한 경우로 따로 구현해야 한다.
    for (auto & ele : m_pDoctors){
        cout << "Meet doctor : " << ele->m_name << endl;
    }
}

int main(){
    Patient *p1 = new Patient("Jack Jack");
    Patient *p2 = new Patient("Dash");
    Patient *p3 = new Patient("Violet");

    Doctor *d1 = new Doctor("Doctor K");
    Doctor *d2 = new Doctor("Doctor J");

    p1->addDoctor(d1); // 상호 등록함
    d1->addPatient(p1);

    p2->addDoctor(d2);
    d2->addPatient(p2);

    p2->addDoctor(d1);
    d1->addPatient(p2);

    // patients meet doctors
    p1->meetDoctors();

    // doctors meet patients
    d1->meetPatient();

    // deletes
    delete p1;
    delete p2;
    delete p3;
    delete d1;
    delete d2;
}