#include<string>
#include"Class.h"

using namespace std;

Class::Class(int tally, string newSubject) {
    numberOfStudents = tally > 0 ? tally : numberOfStudents;
    subject = newSubject;
}

void Class::setNumberOfStudents(int tally) {
    numberOfStudents = tally > 0 ? tally : numberOfStudents;
}

void Class::setSubject(string newSubject) {
    subject = newSubject;
}

int Class::getNumberOfStudents() const {
    return numberOfStudents;
}

string Class::getSubject() const {
    return subject;
}