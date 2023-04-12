#include<iostream>
using namespace std;

int main()
{
    
     {
    // Set default values
    int balance = 1000;
    int pin = 0;
    int attempts = 0;
    bool authenticated = true;
    
    // Main menu
    while (true) {
        cout << "Welcome to the MOMO system.\n";
        cout << "1. Enter PIN\n";
        cout << "2. Reset/Change PIN\n";
        cout << "3. Check Balance\n";
        cout << "4. Send Money\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        cout << endl;
        
        switch (choice) {
            case 1: // Enter PIN
                if (!authenticated) {
                    if (attempts >= 3) {
                        cout << "Too many attempts. Exiting...\n";
                        return 0;
                    }
              
                    cout << "Enter your PIN: ";
                    cin >> pin;
                    cout << endl;
                    
                    if (pin == 0000) {
                        authenticated = true;
                        attempts = 0;
                        cout << "Authentication successful.\n";
                    } else {
                        attempts++;
                        cout << "Invalid PIN. Please try again.\n";
                    }
                } else {
                    cout << "You are already authenticated.\n";
                }
                break;
                
            case 2: // Reset/Change PIN
                if (authenticated) {
                    cout << "Enter your new PIN: ";
                    cin >> pin;
                    cout << endl;
                    
                    cout << "PIN successfully changed.\n";
                } else {
                    cout << "You need to authenticate first.\n";
                }
                break;
                
            case 3: // Check Balance
                if (authenticated) {
                    cout << "Your balance is $" << balance << ".\n";
                } else {
                    cout << "You need to authenticate first.\n";
                }
                break;
                
            case 4: // Send Money
                if (authenticated) {
                    cout << "Enter the amount to send: ";
                    int amount;
                    cin >> amount;
                    cout << endl;
                    
                    if (amount > balance) {
                        cout << "Insufficient balance.\n";
                    } else {
                        balance -= amount;
                        cout << "Money sent successfully.\n";
                        cout << "Your new balance is $" << balance << ".\n";
                    }
                } else {
                    cout << "You need to authenticate first.\n";
                }
                break;
                
            case 5: // Exit
                cout << "Exiting...\n";
                return 0;
                
            default:
                cout << "Invalid choice.\n";
        }
        
        cout << endl;
    }
}

    
    
    
    
    return 0;
}