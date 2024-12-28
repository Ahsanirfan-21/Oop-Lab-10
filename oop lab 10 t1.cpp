#include <iostream>
#include <string>
using namespace std;
class Professor {
private:
    string name;
    string title;

public:
    Professor(const string& name, const string& title) : name(name), title(title) {}

    void display() const {
        cout << "Professor: " << name << ", Title: " << title << endl;
    }
};
class Department {
private:
    string name;
    Professor** professors;
    int professorCount;
    int capacity;
    void resize() {
        capacity *= 2;
        Professor** newProfessors = new Professor*[capacity];
        for (int i = 0; i < professorCount; i++) {
            newProfessors[i] = professors[i];
        }
        delete[] professors;
        professors = newProfessors;
    }

public:
    Department(const string& name) : name(name), professorCount(0), capacity(2) {
        professors = new Professor*[capacity];
    }

    ~Department() {
        delete[] professors;
    }

    void addProfessor(Professor* professor) {
        if (professorCount == capacity) {
            resize();
        }
        professors[professorCount++] = professor;
    }

    void display() const {
        cout << "Department: " << name << endl;
        for (int i = 0; i < professorCount; i++) {
            professors[i]->display();
        }
    }
};
class University {
private:
    string name;
    Department** departments;
    int departmentCount;
    int capacity;

    void resize() {
        capacity *= 2;
        Department** newDepartments = new Department*[capacity];
        for (int i = 0; i < departmentCount; i++) {
            newDepartments[i] = departments[i];
        }
        delete[] departments;
        departments = newDepartments;
    }

public:
    University(const string& name) : name(name), departmentCount(0), capacity(2) {
        departments = new Department*[capacity];
    }

    ~University() {
        delete[] departments;
    }
    void addDepartment(Department* department) {
        if (departmentCount == capacity) {
            resize();
        }
        departments[departmentCount++] = department;
    }
    void display() const {
        cout << "University: " << name << endl;
        for (int i = 0; i < departmentCount; i++) {
            departments[i]->display();
        }
    }
};
int main() {
    Professor prof1("Ali", "Professor of Mathematics");
    Professor prof2("Asad", "Professor of Computer Science");
    Professor prof3("Amir", "Professor of Physics");
    Department dept1("Mathematics Department");
    dept1.addProfessor(&prof1);
    Department dept2("Computer Science Department");
    dept2.addProfessor(&prof2);
    Department dept3("Physics Department");
    dept3.addProfessor(&prof3);
    University uni("UCP");
    uni.addDepartment(&dept1);
    uni.addDepartment(&dept2);
    uni.addDepartment(&dept3);

    uni.display();

    return 0;
}
