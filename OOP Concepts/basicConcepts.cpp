#include<iostream>
using namespace std;

class student{
    public:
    string name;
    int age;
    bool gender;

    student(){
        cout<< "default constructor"<< endl;
    };


    student(student &a){
        name = a.name;
        age = a.age;
        gender = a.gender;
        cout << "Copy Constructor" << endl;
    };
    student(string s,int a,bool g){
        name = s;
        gender =g;
        age = a;
        cout << "parameterised constructor" << endl;
    }// Parameterised constructor.
    
    
    //Destructor 
    ~student(){
        cout<< "Destructor" << endl;;
    };


    // Operator Overloding 
    bool operator == (student &a){
        if(name == a.name && age ==a.age && gender == a.gender){
            return true;
        }
        return false;
    }


    void printInfo(){
    cout << "Name = ";
    cout << name<< endl;
    cout << "Age = ";
    cout << age<< endl;
    cout << "Gender = ";
    cout << gender << endl;
    };
};


int main(){
    // student s[3];
    // for(int i=0;i<3;i++){
    //     cin >> s[i].name;
    //     cin >> s[i].age;
    //     cin >> s[i].gender;
    // }
    // for(int i = 0;i<3;i++){
    //     s[i].printInfo();
    // }

    student a("Omkar",20,true);
    student b;
    student c = a; // c(a);
    if(c==a){
        cout << "SAME" << endl;
    }
    return 0;
}