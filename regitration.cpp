#include #include using namespace std;

class temp { string userName, Email, Password; fstream file; public: void login(); void signUp(); void forgotPassword(); } obj;

int main() { char choice; cout << "\n1-Login"; cout << "\n2-Sign-up"; cout << "\n3-Forget Password"; cout << "\n4-Exit"; cout << "\nEnter Your choice:: "; cin >> choice;

switch (choice) {
case '1':
    cin.ignore();
    obj.login();
    break;
case '2':
    cin.ignore();
    obj.signUp();
    break;
case '3':
    cin.ignore();
    obj.forgotPassword();
    break;
case '4':
    return 0;
default:
    cout << "Invalid selection.....!";
}
}

void temp::signUp() { cout << "\nEnter Your User Name :: "; getline(cin, userName); cout << "Enter Your Email Address :: "; getline(cin, Email); cout << "Enter Your Password :: "; getline(cin, Password);

file.open("loginData.txt", ios::out | ios::app);
file << userName << "*" << Email << "*" << Password << endl;
file.close();
}

void temp::login() { string searchName, searchPassword; bool found = false;

cout << "-------------LOGIN-------------" << endl;
cout << "Enter Your User Name :: ";
getline(cin, searchName);
cout << "Enter Your Password :: ";
getline(cin, searchPassword);

file.open("loginData.txt", ios::in);
if (!file) {
    cout << "No data found!\n";
    return;
}

while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, Password)) {
    if (userName == searchName && Password == searchPassword) {
        cout << "\nAccount login is successful...!";
        cout << "\nUserName ::" << userName << endl;
        cout << "Email::" << Email << endl;
        found = true;
        break;
    }
}

if (!found) {
    cout << "Invalid username or password.\n";
}
file.close();
}

void temp::forgotPassword() { string searchName, searchEmail; bool found = false;

cout << "\nEnter Your UserName :: ";
getline(cin, searchName);
cout << "Enter Your Email Address :: ";
getline(cin, searchEmail);

file.open("loginData.txt", ios::in);
if (!file) {
    cout << "No data found!\n";
    return;
}

while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, Password)) {
    if (userName == searchName && Email == searchEmail) {
        cout << "\nAccount Found...!" << endl;
        cout << "Your Password :: " << Password << endl;
        found = true;
        break;
    }
}

if (!found) {
    cout << "Account not found!\n";
}
file.close();
}
