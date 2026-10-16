#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Credential {
    string websiteName;
    string username;
    string password;
};

class PasswordManager {
private:
    vector<Credential> credentials;
    string masterEmail;
    string masterCode;
    bool isAuthenticated;

public:
    PasswordManager(string email, string code) {
        masterEmail = email;
        masterCode = code;
        isAuthenticated = false;
    }

    
    bool authenticate() {
        string inputEmail, inputCode;
        cout << "=== Key Storage Authentication ===" << endl;
        cout << "Enter your registered email: ";
        cin >> inputEmail;
        
        
        cout << "[System]: A login code has been sent to " << inputEmail << " (Simulated Code: " << masterCode << ")" << endl;
        cout << "Enter the login code: ";
        cin >> inputCode;

        if (inputEmail == masterEmail && inputCode == masterCode) {
            isAuthenticated = true;
            cout << "Authentication successful!\n" << endl;
            return true;
        } else {
            cout << "Authentication failed. Incorrect email or code.\n" << endl;
            return false;
        }
    }

    
    void addCredential() {
        if (!isAuthenticated) return;
        Credential c;
        cout << "\n--- Add New Credential ---" << endl;
        cout << "Enter website name: ";
        cin >> c.websiteName;
        cout << "Enter username/email: ";
        cin >> c.username;
        cout << "Enter password: ";
        cin >> c.password;

        credentials.push_back(c);
        cout << "Credential added successfully!\n" << endl;
    }

    void viewCredentials() {
        if (!isAuthenticated) return;
        if (credentials.empty()) {
            cout << "\nNo credentials stored yet.\n" << endl;
            return;
        }

        cout << "\n--- Stored Credentials ---" << endl;
        for (size_t i = 0; i < credentials.size(); ++i) {
            cout << i + 1 << ". Website: " << credentials[i].websiteName 
                 << " | Username: " << credentials[i].username 
                 << " | Password: " << credentials[i].password << endl;
        }
        cout << endl;
    }

    void editCredential() {
        if (!isAuthenticated) return;
        viewCredentials();
        if (credentials.empty()) return;

        size_t index;
        cout << "Enter the number of the credential you want to edit: ";
        cin >> index;

        if (index > 0 && index <= credentials.size()) {
            cout << "Enter new website name: ";
            cin >> credentials[index - 1].websiteName;
            cout << "Enter new username: ";
            cin >> credentials[index - 1].username;
            cout << "Enter new password: ";
            cin >> credentials[index - 1].password;
            cout << "Credential updated successfully!\n" << endl;
        } else {
            cout << "Invalid selection.\n" << endl;
        }
    }

    void deleteCredential() {
        if (!isAuthenticated) return;
        viewCredentials();
        if (credentials.empty()) return;

        size_t index;
        cout << "Enter the number of the credential you want to delete: ";
        cin >> index;

        if (index > 0 && index <= credentials.size()) {
            credentials.erase(credentials.begin() + (index - 1));
            cout << "Credential deleted successfully!\n" << endl;
        } else {
            cout << "Invalid selection.\n" << endl;
        }
    }
};

int main() {
    PasswordManager manager("user@example.com", "12345");

    if (!manager.authenticate()) {
        return 0;
    }

    int choice;
    do {
        cout << "=== Key Storage Menu ===" << endl;
        cout << "1. Add Credential" << endl;
        cout << "2. View Credentials" << endl;
        cout << "3. Edit Credential" << endl;
        cout << "4. Delete Credential" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addCredential();
                break;
            case 2:
                manager.viewCredentials();
                break;
            case 3:
                manager.editCredential();
                break;
            case 4:
                manager.deleteCredential();
                break;
            case 5:
                cout << "Exiting Key Storage. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n" << endl;
        }
    } while (choice != 5);

    return 0;
}