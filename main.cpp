#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

bool isPasswordValid(const string& password) {
    // Check the length of the password
    if (password.length() < 8) {
        return false;
    }

    // Check if the password contains at least one uppercase letter
    bool hasUppercase = false;
    for (char c : password) {
        if (isupper(c)) {
            hasUppercase = true;
            break;
        }
    }
    if (!hasUppercase) {
        return false;
    }

    // Check if the password contains at least one lowercase letter
    bool hasLowercase = false;
    for (char c : password) {
        if (islower(c)) {
            hasLowercase = true;
            break;
        }
    }
    if (!hasLowercase) {
        return false;
    }

    // Check if the password contains at least one digit
    bool hasDigit = false;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        return false;
    }

    // All conditions passed, the password is valid
    return true;
}

void registerUser(map<string, string>& userPasswords) {
    string username;
    string password;

    cout << "Enter a username: ";
    getline(cin, username);

    cout << "Enter a password: ";
    getline(cin, password);

    if (isPasswordValid(password)) {
        userPasswords[username] = password;
        cout << "Username and password stored successfully." << endl;
    } else {
        cout << "Password does not meet the requirements." << endl;
        cout << "Minimum length of password should be 8 characters." << endl;
        cout << "Make sure that your password contains at least one uppercase letter, one lowercase letter, and one digit." << endl;
    }
}

void loginUser(const map<string, string>& userPasswords) {
    string username;
    string password;

    cout << "Enter your username: ";
    getline(cin, username);

    cout << "Enter your password: ";
    getline(cin, password);

    // Check if the username exists in the map and if the password matches
    if (userPasswords.count(username) > 0 && userPasswords.at(username) == password) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password." << endl;
    }
}

int main() {
    map<string, string> userPasswords;

    cout << "Welcome to the program!" << endl;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character

        switch (choice) {
            case 1:
                registerUser(userPasswords);
                break;
            case 2:
                loginUser(userPasswords);
                break;
            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
