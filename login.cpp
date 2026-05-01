#include <iostream>
#include <fstream>
using namespace std;

// Registration Function
void registerUser() {
    string username, password, fileUser, filePass;

    cout << "\n--- Registration ---\n";
    cout << "Enter Username: ";
    cin.ignore(); // important line
    getline(cin, username);

    cout << "Enter Password: ";
    getline(cin, password);

    // Check duplicate username
    ifstream readFile("users.txt");
    while (readFile >> fileUser >> filePass) {
        if (fileUser == username) {
            cout << "❌ Username already exists!\n";
            readFile.close();
            return;
        }
    }
    readFile.close();

    // Save new user
    ofstream writeFile("users.txt", ios::app);
    writeFile << username << " " << password << endl;
    writeFile.close();

    cout << "✅ Registration Successful!\n";
}

// Login Function
void loginUser() {
    string username, password, fileUser, filePass;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter Username: ";
    cin.ignore(); // important line
    getline(cin, username);

    cout << "Enter Password: ";
    getline(cin, password);

    ifstream readFile("users.txt");
    while (readFile >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            found = true;
            break;
        }
    }
    readFile.close();

    if (found)
        cout << "✅ Login Successful! Welcome " << username << " 🎉\n";
    else
        cout << "❌ Invalid Username or Password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "❌ Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}