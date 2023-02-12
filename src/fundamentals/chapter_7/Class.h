#ifndef CLASS_H
#define CLASS_H

#include<string>

using namespace std;

class Class {
    private:
        int numberOfStudents;
        string subject;
    public:
        Class(int tally=10, string subject="C++");
        void setNumberOfStudents(int);
        void setSubject(string);
        int getNumberOfStudents() const;
        string getSubject() const;
};

#endif