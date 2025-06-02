#include <iostream>
#include <string.h> // For strcpy and strlen

using namespace std;

// Base class representing a general person
class Person {
protected:
    int id; // Unique ID for the person
    char *name; // Name of the person stored dynamically
    int age; // Age of the person

public:
    // Constructor to initialize person details
    Person(int id, const char *name, int age) : id(id), age(age) {
        this->name = new char[strlen(name) + 1]; // Allocate memory for name
        strcpy(this->name, name); // Copy name
    }
    
    // Virtual function to display person information
    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age;
    }
    
    // Virtual destructor to free dynamically allocated memory
    virtual ~Person() {
        delete[] name;
    }
};

// Derived class representing a student
class Student : public Person {
    float percentage; // Percentage obtained by the student
    bool attendance[30]; // Attendance data for 30 days (true for present, false for absent)
    
public:
    // Constructor to initialize student details
    Student(int id, const char *name, int age, float percentage) : Person(id, name, age), percentage(percentage) {
        // Initialize all attendance to false (absent)
        for (int i = 0; i < 30; i++) {
            attendance[i] = false;
        }
    }
    
    // Overridden function to display student information
    void displayInfo() const override {
        Person::displayInfo();
        cout << ", Percentage: " << percentage << "%" << endl;
    }
    
    // Getter function for percentage
    float getPercentage() const { return percentage; }
    
    // Getter function for student ID
    int getId() const { return id; }
    
    // Function to update student details
    void updateStudent(const char *newName, int newAge, float newPercentage) {
        delete[] name; // Free old memory
        name = new char[strlen(newName) + 1]; // Allocate new memory
        strcpy(name, newName); // Copy new name
        age = newAge;
        percentage = newPercentage;
    }

    // Function to mark attendance for a specific day
    void markAttendance(int day, bool isPresent) {
        if (day >= 1 && day <= 30) {
            attendance[day - 1] = isPresent;
        } else {
            cout << "Invalid day!" << endl;
        }
    }

    // Function to calculate the attendance percentage
    float calculateAttendance() const {
        int totalDays = 30;
        int classesAttended = 0;
        for (int i = 0; i < totalDays; i++) {
            if (attendance[i]) {
                classesAttended++;
            }
        }
        return (static_cast<float>(classesAttended) / totalDays) * 100;
    }

    // Function to display attendance
    void displayAttendance() const {
        cout << "Attendance Record for " << name << " (" << id << "):\n";
        for (int i = 0; i < 30; i++) {
            cout << "Day " << (i + 1) << ": " << (attendance[i] ? "Present" : "Absent") << endl;
        }
        cout << "Attendance Percentage: " << calculateAttendance() << "%" << endl;
    }
};

int main() {
    // Array of student pointers to store student objects dynamically
    Student *students[100];
    int count = 0; // Counter to keep track of the number of students
    int choice; // Variable to store user menu choice
    
    do {
        // Display menu options
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Mark Attendance\n";
        cout << "7. View Attendance Report\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Adding a new student with unique ID validation
            int id, age;
            char name[100];
            float percentage;
            bool idExists;
            
            do {
                idExists = false;
                cout << "Enter Student ID: ";
                cin >> id;
                for (int i = 0; i < count; i++) {
                    if (students[i]->getId() == id) {
                        cout << "Error: Student ID already exists. Please enter a unique ID.\n";
                        idExists = true;
                        break;
                    }
                }
            } while (idExists);
            
            cout << "Enter Name: ";
            cin.ignore(); // Ignore newline character from previous input
            cin.getline(name, 100);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Percentage: ";
            cin >> percentage;
            students[count++] = new Student(id, name, age, percentage);
            cout << "Student Added Successfully!\n";
        } else if (choice == 2) {
            // View all students
            if (count == 0) {
                cout << "No students to display.\n";
            } else {
                cout << "\n--- Student List ---\n";
                for (int i = 0; i < count; i++) {
                    students[i]->displayInfo();
                }
            }
        } else if (choice == 3) {
            // Search student by ID
            int searchId;
            cout << "Enter Student ID to search: ";
            cin >> searchId;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i]->getId() == searchId) {
                    students[i]->displayInfo();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student not found!\n";
            }
        } else if (choice == 4) {
            // Delete student by ID
            int deleteId;
            cout << "Enter Student ID to delete: ";
            cin >> deleteId;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i]->getId() == deleteId) {
                    delete students[i];
                    // Shift remaining elements to fill the gap
                    for (int j = i; j < count - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    count--;
                    found = true;
                    cout << "Student deleted successfully!\n";
                    break;
                }
            }
            if (!found) {
                cout << "Student not found!\n";
            }
        } else if (choice == 5) {
            // Update student details
            int updateId;
            cout << "Enter Student ID to update: ";
            cin >> updateId;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i]->getId() == updateId) {
                    char newName[100];
                    int newAge;
                    float newPercentage;
                    cout << "Enter new name: ";
                    cin.ignore();
                    cin.getline(newName, 100);
                    cout << "Enter new age: ";
                    cin >> newAge;
                    cout << "Enter new percentage: ";
                    cin >> newPercentage;
                    students[i]->updateStudent(newName, newAge, newPercentage);
                    cout << "Student updated successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student not found!\n";
            }
        } else if (choice == 6) {
            // Mark attendance
            int studentId, day;
            char present;
            cout << "Enter Student ID: ";
            cin >> studentId;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i]->getId() == studentId) {
                    cout << "Enter day (1-30): ";
                    cin >> day;
                    cout << "Present (Y/N): ";
                    cin >> present;
                    students[i]->markAttendance(day, (present == 'Y' || present == 'y'));
                    cout << "Attendance marked!\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student not found!\n";
            }
        } else if (choice == 7) {
            // View attendance report
            int studentId;
            cout << "Enter Student ID: ";
            cin >> studentId;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i]->getId() == studentId) {
                    students[i]->displayAttendance();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student not found!\n";
            }
        } else if (choice == 8) {
            // Exiting the program
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    // Deallocating memory before exiting
    for (int i = 0; i < count; i++) {
        delete students[i];
    }

    return 0;
}
