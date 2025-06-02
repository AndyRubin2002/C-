#include <iostream>
#include <fstream>
using namespace std;

struct Contact {
    string name;
    string number;
};

Contact contacts[100]; // Array to store contacts
int contactCount = 0;  // Track number of contacts

void addContact() {
    if (contactCount >= 100) {
        cout << "Contact book is full!\n";
        return;
    }
    cout << "Enter Name: ";
    cin >> contacts[contactCount].name;
    cout << "Enter Number: ";
    cin >> contacts[contactCount].number;
    contactCount++;
    cout << "Contact added!\n";
}

void deleteContact() {
    string name;
    cout << "Enter name to delete: ";
    cin >> name;

    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].name == name) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            cout << "Contact deleted!\n";
            return;
        }
    }
    cout << "Contact not found!\n";
}

void searchContact() {
    string name;
    cout << "Enter name to search: ";
    cin >> name;

    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].name == name) {
            cout << "Name: " << contacts[i].name << ", Number: " << contacts[i].number << "\n";
            return;
        }
    }
    cout << "Contact not found!\n";
}

void displayContacts() {
    if (contactCount == 0) {
        cout << "No contacts found!\n";
        return;
    }
    for (int i = 0; i < contactCount; i++) {
        cout << "Name: " << contacts[i].name << ", Number: " << contacts[i].number << "\n";
    }
}

void saveToFile() {
    ofstream file("contacts.txt");
    for (int i = 0; i < contactCount; i++) {
        file << contacts[i].name << " " << contacts[i].number << "\n";
    }
    cout << "Contacts saved to file!\n";
}

void loadFromFile() {
    ifstream file("contacts.txt");
    contactCount = 0; // Reset contact count
    while (file >> contacts[contactCount].name >> contacts[contactCount].number) {
        contactCount++;
    }
    cout << "Contacts loaded from file!\n";
}

int main() {
    int choice;
    do {
        cout << "\n==== Contact Book ====\n";
        cout << "1. Add Contact\n";
        cout << "2. Delete Contact\n";
        cout << "3. Search Contact\n";
        cout << "4. Display Contacts\n";
        cout << "5. Save to File\n";
        cout << "6. Load from File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: deleteContact(); break;
            case 3: searchContact(); break;
            case 4: displayContacts(); break;
            case 5: saveToFile(); break;
            case 6: loadFromFile(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
