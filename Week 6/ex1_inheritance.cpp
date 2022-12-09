#include <iostream>
#include <vector>
using std::cout; 
using std::cin;
using std::string;

class Student {
public:
    string name;
    int studentID; 
public:
    Student(string nameVal = "", int studentIDval = 0) 
        : name(nameVal), studentID(studentIDval){
        //cout << "STUDENT constructor \n";
    }
    //~Student(){ cout << "STUDENT destructor \n"; }

    virtual string toString(){
        return "name = " + name + ", Student ID = " + std::to_string(studentID);
    }
};


class Staff {
public:
    string name;
    int staffID;
public:
    Staff(string nameVal = "", int staffIDval = 0)
        : name(nameVal), staffID(staffIDval) {
        //cout << "STAFF constructor \n";
    }
    //~Staff(){ cout << "STAFF destructor \n"; }    

    virtual string toString(){
        return "name = " + name + ", Staff ID = " + std::to_string(staffID);
    }
};


class Tutor : public Student, public Staff{
public:
    //inherited attributes: Student::name, Staff::name, studentID, staffID.

    Tutor(string nameVal, int studentIDval, int staffIDval)
        : Student(nameVal, studentIDval), Staff(nameVal, staffIDval){
        //cout << "TUTOR constructor \n";
    }
    //~Tutor(){ cout << "STAFF destructor \n"; }   

    void Consultation(){
        cout << "Doing consultation !\n";
    }

    //Note: there are two versions of name attribute (from two inherited classes)
    //--> should only use one consistenly, e.g. Student::name  
    void setName(string nameVal){
        Student::name = nameVal;
    }

    string toString(){
        return  Student::toString() + ", staffID = " + std::to_string(staffID);
    }
};


void showInfoStudent(Student &stu){
    cout << stu.toString() << "\n";
}

void showInfoStaff(Staff &staff){
    cout << staff.toString() << "\n";;
}

int main() {
    //Test written functions
    Tutor tutor1("An", 12345, 123);
    tutor1.setName("An Nguyen");
    cout << tutor1.toString() << "\n\n";

    Student stu1("Huy", 12346);
    showInfoStudent(stu1);
    showInfoStudent(tutor1); 
    cout << "\n";

    Staff staff1("Andrew", 145);
    showInfoStaff(staff1);
    showInfoStaff(tutor1); 

    return 0;
}