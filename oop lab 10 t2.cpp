#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    char* name;
    char* registrationNo;
    char* city;
    void copyString(char*& dest, const char* src) {
        int length = 0;
        while (src[length] != '\0') {
            length++;
        }
        dest = new char[length + 1];
        for (int i = 0; i <= length; i++) {
            dest[i] = src[i];
        }
    }
public:
    Student(const char* name = "", const char* registrationNo = "", const char* city = "") {
        copyString(this->name, name);
        copyString(this->registrationNo, registrationNo);
        copyString(this->city, city);
    }
    ~Student() {
        delete[] name;
        delete[] registrationNo;
        delete[] city;
    }
    Student(const Student& other) {
        copyString(name, other.name);
        copyString(registrationNo, other.registrationNo);
        copyString(city, other.city);
    }
    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] name;
            delete[] registrationNo;
            delete[] city;
            copyString(name, other.name);
            copyString(registrationNo, other.registrationNo);
            copyString(city, other.city);
        }
        return *this;
    }
    void setName(const char* name) {
        delete[] this->name;
        copyString(this->name, name);
    }
    const char* getName() const {
        return name;
    }
    void setRegistrationNo(const char* registrationNo) {
        delete[] this->registrationNo;
        copyString(this->registrationNo, registrationNo);
    }

    const char* getRegistrationNo() const {
        return registrationNo;
    }

    void setCity(const char* city) {
        delete[] this->city;
        copyString(this->city, city);
    }

    const char* getCity() const {
        return city;
    }

    void display() const {
        cout << "Name: " << name << " Registration No: " << registrationNo << " City: " << city << endl;
    }
};

class Instructor {
private:
    char* name;
    char* education;
    void copyString(char*& dest, const char* src) {
        int length = 0;
        while (src[length] != '\0') {
            length++;
        }
        dest = new char[length + 1];
        for (int i = 0; i <= length; i++) {
            dest[i] = src[i];
        }
    }

public:
    Instructor(const char* name = "", const char* education = "") {
        copyString(this->name, name);
        copyString(this->education, education);
    }

    ~Instructor() {
        delete[] name;
        delete[] education;
    }

    Instructor(const Instructor& other) {
        copyString(name, other.name);
        copyString(education, other.education);
    }

    Instructor& operator=(const Instructor& other) {
        if (this != &other) {
            delete[] name;
            delete[] education;
            copyString(name, other.name);
            copyString(education, other.education);
        }
        return *this;
    }

    void setName(const char* name) {
        delete[] this->name;
        copyString(this->name, name);
    }

    const char* getName() const {
        return name;
    }

    void setEducation(const char* education) {
        delete[] this->education;
        copyString(this->education, education);
    }

    const char* getEducation() const {
        return education;
    }

    void display() const {
        cout << "Instructor Name: " << name << ", Education: " << education << endl;
    }
};
class Course {
private:
    char* courseName;
    Instructor* instructor;
    Student** students;
    int studentCount;
    const int maxStudents;
    void copyString(char*& dest, const char* src) {
        int length = 0;
        while (src[length] != '\0') {
            ++length;
        }
        dest = new char[length + 1];
        for (int i = 0; i <= length; i++) {
            dest[i] = src[i];
        }
    }

public:
    Course() : courseName(nullptr), instructor(nullptr), students(nullptr), studentCount(0), maxStudents(30) {
        students = new Student*[maxStudents];
    }

    Course(const char* courseName) : courseName(nullptr), instructor(nullptr), students(nullptr), studentCount(0), maxStudents(30) {
        copyString(this->courseName, courseName);
        students = new Student*[maxStudents];
    }
    ~Course() {
        delete[] courseName;
        delete instructor;
        for (int i = 0; i < studentCount; ++i) {
            delete students[i];
        }
        delete[] students;
    }

    Course(const Course& other) : maxStudents(30) {
        copyString(courseName, other.courseName);
        instructor = new Instructor(*other.instructor);
        students = new Student*[maxStudents];
        studentCount = other.studentCount;
        for (int i = 0; i < studentCount; i++) {
            students[i] = new Student(*other.students[i]);
        }
    }

    Course& operator=(const Course& other) {
        if (this != &other) {
            delete[] courseName;
            delete instructor;
            for (int i = 0; i < studentCount; ++i) {
                delete students[i];
            }
            delete[] students;
            copyString(courseName, other.courseName);
            instructor = new Instructor(*other.instructor);
            students = new Student*[maxStudents];
            studentCount = other.studentCount;
            for (int i = 0; i < studentCount; ++i) {
                students[i] = new Student(*other.students[i]);
            }
        }
        return *this;
    }

    void setCourseName(const char* courseName) {
        delete[] this->courseName;
        copyString(this->courseName, courseName);
    }

    const char* getCourseName() const {
        return courseName;
    }

    void setInstructor(const Instructor& instructor) {
        delete this->instructor;
        this->instructor = new Instructor(instructor);
    }

    const Instructor* getInstructor() const {
        return instructor;
    }

    bool addStudent(const Student& student) {
        if (studentCount < maxStudents) {
            students[studentCount++] = new Student(student);
            return true;
        }
        return false;
    }

    int getStudentCount() const {
        return studentCount;
    }
    void display() const {
        cout << "Course Name: " << courseName << endl;
        if (instructor) {
            instructor->display();
        }
        for (int i = 0; i < studentCount; ++i) {
            students[i]->display();
        }
    }
};
int main() {
    Student s1("Ali", "L1F1YBSCS1ABC", "Lahore");
    Student s2("Ahmad", "L1F1YBSCS2ABC", "Islamabad");
    Student s3("Ammar", "L1F1YBSCS3ABC", "Lahore");
    Course oopLabSecC4;
    oopLabSecC4.setCourseName("OOPFall2023SecC4Lab");
    cout << "Total Students in oopLabSecC4: " << oopLabSecC4.getStudentCount() << endl;

    oopLabSecC4.addStudent(s1);
    oopLabSecC4.addStudent(s2);
    oopLabSecC4.addStudent(s3);

    cout << "Total Students in oopLabSecC4: " << oopLabSecC4.getStudentCount() << endl;

    Instructor inst1("SAMRA ZAFAR", "MPHIL");
    oopLabSecC4.setInstructor(inst1);

    oopLabSecC4.display();

    Course oopLabSecC2;
    oopLabSecC2.addStudent(s1);
    oopLabSecC2.addStudent(s3);

    Instructor inst2("USAMA PERVAIZ", "MPHIL");
    oopLabSecC2.setInstructor(inst2);

    oopLabSecC4.display();
    oopLabSecC2.display();

    cout << "Instructor 1: " << inst1.getName() << endl;

    return 0;
}
