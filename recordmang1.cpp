#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class sms
{
	public:
    string rollNum,name,fName,address,search;
    fstream file;
    void addStu();
    void viewStu();
    void searchStu();
    void deleteStu();
};

int main(){
    sms obj;
    int choice,var=1;
    while(var==1)
    {
	
    cout<<"---------------------------"<<endl;
    cout<<"1- Add Student Record"<<endl;
    cout<<"2- View All Student Record"<<endl;
    cout<<"3- Search Student Record"<<endl;
    cout<<"4- Delete the record"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;

    switch(choice){
        case 1:
        cin.ignore();
            obj.addStu();
        break;
        case 2:
        cin.ignore();
            obj.viewStu();
        break;
        case 3:
      cin.ignore();
            obj.searchStu();
        break;
       case 4:
            cin.ignore();
            obj.deleteStu();
        break;
        default:
            cout<<"Invalid Choice...!"<<endl;
    }
    cout<<"To continue press 1 otherwise press any key: "<<endl;
    cin>>var;
    }
return 0;

}

void sms::addStu() {
    cout << "Enter Student Roll Number :: ";
    string inputRollNum;
    getline(cin, inputRollNum);

    
    bool isNumeric = true;
    for (char c : inputRollNum) {
        if (!isdigit(c)) {
            isNumeric = false;
            break;
        }
    }

    if (!isNumeric) {
        cout << "Invalid input! Roll Number should contain only numeric characters." << endl;
        return;
    }

    rollNum = inputRollNum;

   
    file.open("stuData.txt", ios::in);
    string line;
    bool rollNumExists = false;
    string existingRollNum;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, existingRollNum, '*');
        if (rollNum == existingRollNum) {
            rollNumExists = true;
            break;
        }
    }
    file.close();

    if (rollNumExists) {
        cout << "Record with this Roll Number already exists!" << endl;
        return;
    }

    cout << "Enter Student Name :: ";
    getline(cin, name);

    
    bool isAlphaName = true;
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            isAlphaName = false;
            break;
        }
    }

    if (!isAlphaName) {
        cout << "Invalid input! Name should contain only alphabetic characters." << endl;
        return;
    }

    
    if (name == fName) {
        cout << "Student's Name and Father's Name cannot be the same!" << endl;
        return;
    }

    
    file.open("stuData.txt", ios::in);
    bool nameExists = false;
    string existingName;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, existingRollNum, '*');
        getline(ss, existingName, '*');
        if (name == existingName) {
            nameExists = true;
            break;
        }
    }
    file.close();

    if (nameExists) {
        cout << "Record with this Name already exists!" << endl;
        return;
    }

    cout << "Enter Student Father Name :: ";
    getline(cin, fName);

    
    bool isAlphaFatherName = true;
    for (char c : fName) {
        if (!isalpha(c) && c != ' ') {
            isAlphaFatherName = false;
            break;
        }
    }

    if (!isAlphaFatherName) {
        cout << "Invalid input! Father's Name should contain only alphabetic characters." << endl;
        return;
    }

    
    file.open("stuData.txt", ios::in);
    bool fNameExists = false;
    string existingFName;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, existingRollNum, '*');
        getline(ss, existingName, '*');
        getline(ss, existingFName, '*');
        if (fName == existingFName) {
            fNameExists = true;
            break;
        }
    }
    file.close();

    if (fNameExists) {
        cout << "Record with this Father's Name already exists!" << endl;
        return;
    }

    cout << "Enter Student Address :: ";
    getline(cin, address);

    
    bool isAlphaAddress = true;
    for (char c : address) {
        if (!isalpha(c) && c != ' ') {
            isAlphaAddress = false;
            break;
        }
    }

    if (!isAlphaAddress) {
        cout << "Invalid input! Address should contain only alphabetic characters and spaces." << endl;
        return;
    }

    file.open("stuData.txt", ios::out | ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << rollNum << "*";
    file << name << "*";
    file << fName << "*";
    file << address << endl;
    file.close();

    cout << "Record added successfully!" << endl;
}

void sms :: viewStu(){

    file.open("stuData.txt",ios :: in);
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,fName,'*');
    getline(file,address,'\n');
    while(!file.eof()){
        cout<<"\n";
        cout<<"Student Roll Number :: "<<rollNum<<endl;
        cout<<"Student Name :: "<<name<<endl;
        cout<<"Student Father Name :: "<<fName<<endl;
        cout<<"Student Address :: "<<address<<endl;

        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');
    }
    file.close();
}

void sms::searchStu() {
    bool found = false;
    cout << "Enter Student Roll Number :: ";
    getline(cin, search);

    file.open("stuData.txt", ios::in);
    if (!file.is_open()) {
        cout << "Unable to open file!" << endl;
        return;
    }

    string rollNum, name, fName, address;
    while (getline(file, rollNum, '*')) {
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');

        if (rollNum == search) {
            found = true;
            cout << endl;
            cout << "Student Roll Number :: " << rollNum << endl;
            cout << "Student Name :: " << name << endl;
            cout << "Student Father Name :: " << fName << endl;
            cout << "Student Address :: " << address << endl;
            break; // Student found, no need to continue searching
        }
    }

    file.close();

    if (!found) {
        cout << "Student with Roll Number " << search << " not found." << endl;
    }
}

void sms::deleteStu() {
    string deleteRollNum;
    cout << "Enter Student Roll Number to delete: ";
    getline(cin, deleteRollNum);

    ifstream inFile("stuData.txt");
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, rollNum, '*');
        getline(ss, name, '*');
        getline(ss, fName, '*');
        getline(ss, address, '\n');

        if (rollNum == deleteRollNum) {
            found = true;
            cout << "Record with Roll Number " << deleteRollNum << " has been deleted." << endl;
        } else {
            tempFile << line << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("stuData.txt");
    rename("temp.txt", "stuData.txt");

    if (!found) {
        cout << "Record with Roll Number " << deleteRollNum << " not found." << endl;
    }
}