#include <iostream>
#include <cstring>

using namespace std;

struct date
       {
       int day, month, year;
       };

struct student
       {
       int std_id;
       char std_name[20], std_surname[20];
       struct date reg_date;
       float cgpa;
       }student_directory[100];

int isValidInteger(string integer){
    for (int i{}; i < integer.length(); i++){
        if (integer[i] < 48 || integer[i] > 57) return 0;
    }
    return 1;
}

int isValidName(string name)
{
    for (int i{}; i < name.length(); i++){
        if (!isalpha(name[i])) return 0;
    }
    return 1;
}

int isValidCGPA(string cgpa){
    if (cgpa[0] < 48 || cgpa[0] > 52) return 0;
    else if (cgpa.length() == 1) return 1;
    else if (cgpa.length() > 4) return 0;
    else if (cgpa[1] != '.') return 0;
    else if (cgpa[2] < 48 || cgpa[2] > 57 || cgpa[3] < 48 || cgpa[3] > 57) return 0;
    else if (stof(cgpa) > 4) return 0;
    else return 1;
}

int isValidDate(int day, int month, int year){
    if (day < 0 || day > 31 || month < 0 || month > 12 || year < 0) return 0;
    else return 1;
}

int isSameString(string a, string b){
    if (a.length() != b.length()) return 0;
    for (int i{}; i < a.length(); i++){
        if (tolower(a[i]) != tolower(b[i])) return 0;
    }
    return 1;
}

int doesIDExist(student student_directory[], int *count, int ID){
    for (int i{}; i < *count; i++){
        if (student_directory[i].std_id == ID) return 1;
    }
    return 0;
}

void addStudent(student student_directory[], int *count)
{
    int index = *count;
    string tempDay, tempMonth, tempYear;
    string tempName;
    string tempInt;


    cout << "Enter the ID of the student: ";
    cin >> tempInt;

    while(!isValidInteger(tempInt) || doesIDExist(student_directory, count, stoi(tempInt))){
        cout << "The ID either exists already or is invalid! Please enter the ID using only numbers (0-9): ";
        cin >> tempInt;
    }

    student_directory[index].std_id = stoi(tempInt);

    cout << "Enter the name of the student: ";
    cin >> tempName;
    while(isValidName(tempName) == 0){
        cout << "That's not a valid name! Please enter the name of the student only using alphabets (a-z/A-Z): ";
        cin >> tempName;
    }

    strcpy(student_directory[index].std_name, tempName.c_str());

    cout << "Enter the surname of the student: ";
    cin >> tempName;
    while(isValidName(tempName) == 0){
        cout << "That's not a valid surname! Please enter the surname of the student only using alphabets (a-z/A-Z): ";
        cin >> tempName;
    }

    strcpy(student_directory[index].std_surname, tempName.c_str());

    cout << "Enter the date of the registeration (dd/mm/yyyy): ";
    cin >> tempDay >> tempMonth >> tempYear;
    while(!isValidInteger(tempDay) || !isValidInteger(tempMonth) || !isValidInteger(tempYear) || (!isValidDate(stoi(tempDay), stoi(tempMonth), stoi(tempYear) == 0))){
        cout << "Please enter a valid date with dd/mm/yyyy format and using integers only: ";
        cin >> tempDay >> tempMonth >> tempYear;
    }

    student_directory[index].reg_date.day = stoi(tempDay);
    student_directory[index].reg_date.month = stoi(tempMonth);
    student_directory[index].reg_date.year = stoi(tempYear);

    cout << "Enter the CGPA of the student (0-4): ";
    cin >> tempDay;
    while(isValidCGPA(tempDay) == 0){
        cout << "Please enter a valid CGPA (D.DD): ";
        cin >> tempDay;
    }

    student_directory[index].cgpa = stoi(tempDay);

    cout << endl;

    *count += 1;
}

void deleteStudent(student student_directory[], int *count){
    int tempInt;

    cout << "Enter the ID of the student to delete it from the list of the students: ";
    cin >> tempInt;

    for (int i{}; i < *count; i++){
        if (student_directory[i].std_id == tempInt){
            for (int j = i; j < *count; j++){
                student_directory[j] = student_directory[j+1];
            }
            *count -= 1;
            return;
        }
    }
    cout << "\nThe student is not in the list.\n" << endl;
}

void displayStudents(student student_directory[], int *count){
    cout << "\n\n";
    cout << "STUDENT ID" << "\tNAME" << "\tSURNAME" << "\tREGISTERATION DATE" << "\tCPGA" << "\n\n";
    for (int i{}; i < *count; i++){
        if (student_directory[i].std_id <= 0) continue;
        cout << student_directory[i].std_id << "\t" << student_directory[i].std_name << "\t" << student_directory[i].std_surname << "\t" <<
        student_directory[i].reg_date.day << "/" << student_directory[i].reg_date.month << "/" << student_directory[i].reg_date.year << "\t" << 
        student_directory[i].cgpa << endl;
    }
    cout << "\n" << endl;
}

void searchStudentID(student student_directory[], int *count){
    string temp;
    cout << "Enter the ID of the student to see their information: ";
    cin >> temp;
    while(!isValidInteger(temp)){
        cout << "That's not a valid ID! Please enter the ID of the student using only numbers (0-9): ";
        cin >> temp;
    }

    int tempInt = stoi(temp);

    for (int i{}; i < *count; i++){
        if (student_directory[i].std_id == tempInt){
            cout << "\nThe student with the ID " << tempInt << " is:\n" << student_directory[i].std_id << "\t" << student_directory[i].std_name << "\t" << student_directory[i].std_surname << "\t" <<
        student_directory[i].reg_date.day << "/" << student_directory[i].reg_date.month << "/" << student_directory[i].reg_date.year << "\t" << 
        student_directory[i].cgpa << "\n" << endl;
            return;
        }
    }
    cout << "\nThe student is not in the list.\n" << endl;
}

void searchStudentName(student student_directory[], int *count){
    string tempStr;
    cout << "Enter the name of the student to see their information: ";
    cin >> tempStr;
    while(!isValidName(tempStr)){
        cout << "That's not a valid name! Please enter the name of the student only using alphabets (a-z/A-Z): ";
        cin >> tempStr;
    }
    

    for (int i{}; i < *count; i++){
        if (isSameString(student_directory[i].std_name, tempStr)){
            cout << "\nThe student with the name " << tempStr << " is:\n\n" << "STUDENT ID" << "\tNAME" << "\tSURNAME" << "\tREGISTERATION DATE" << 
            "\tCPGA" << "\n\n" << student_directory[i].std_id << "\t" << student_directory[i].std_name << "\t" << student_directory[i].std_surname <<
            "\t" << student_directory[i].reg_date.day << "/" << student_directory[i].reg_date.month << "/" << student_directory[i].reg_date.year <<
            "\t" << student_directory[i].cgpa << "\n" << endl;
            return;
        }
    }
    cout << "\nThe student is not in the list.\n" << endl;
}

void searchStudent(int *count){
    string temp;
    int choice;
    

    do{
    cout << "How do you want to search for the student?\n" << "[1] According to ID\n" << "[2] According to name of the student\n" << "[3] Exit\n\n" << "Enter your choice: ";
    cin >> temp;
    cout << endl;

    while(!isValidInteger(temp)){
        cout << "Please enter a number (1-3): ";
        cin >> temp;
    }

    choice = stoi(temp);

    switch (choice)
    {
    case 1:
        searchStudentID(student_directory, count);
        break;
    case 2:
        searchStudentName(student_directory, count);
        break;
    case 3:
        break;
    default:
        cout << "\nThat's not a valid choice!\n" << endl;
        break;
    }
    }while(choice != 3);
}

void updateStudent(student student_directory[], int *count){
    string temp;
    int tempInt_;

    cout << "Enter the ID of the student to update the information of the given student: ";
    cin >> temp;
    while (!isValidInteger(temp)){
        cout << "Invalid ID! Please enter an ID using only numbers (0-9): ";
        cin >> temp;
    }

    tempInt_ = stoi(temp);    

    for (int i{}; i < *count; i++){
        
    }

    for (int i{}; i < *count; i++){
        if (student_directory[i].std_id == tempInt_){
            int index = i;
            string tempDay, tempMonth, tempYear;
            string tempName;
            string tempInt;

            cout << "Enter the ID of the student: ";
            cin >> tempInt;

            while(!isValidInteger(tempInt)){
                cout << "The ID is invalid! Please enter the ID using only numbers (0-9): ";
                cin >> tempInt;
            }

            while(doesIDExist(student_directory, count, stoi(tempInt)) && (stoi(tempInt) != tempInt_)){
                cout << "The ID already exists! Please enter a different ID: ";
                cin >> tempInt;
                while(!isValidInteger(tempInt)){
                    cout << "The ID is invalid! Please enter the ID using only numbers (0-9): ";
                    cin >> tempInt;
            }

            }

            int temp = stoi(tempInt);

            student_directory[index].std_id = temp;

            cout << "Enter the name of the student: ";
            cin >> tempName;
            while(isValidName(tempName) == 0){
                cout << "Invalid name! Please enter a valid name for the student: ";
                cin >> tempName;
            }

            strcpy(student_directory[index].std_name, tempName.c_str());

            cout << "Enter the surname of the student: ";
            cin >> tempName;
            while(isValidName(tempName) == 0){
                cout << "Invalid surname! Please enter a valid surname for the student: ";
                cin >> tempName;
            }

            strcpy(student_directory[index].std_surname, tempName.c_str());

            cout << "Enter the date of the registeration (dd/mm/yyyy): ";
            cin >> tempDay >> tempMonth >> tempYear;
            while(!isValidInteger(tempDay) || !isValidInteger(tempMonth) || !isValidInteger(tempYear) || (!isValidDate(stoi(tempDay), stoi(tempMonth), stoi(tempYear) == 0))){
                cout << "Please enter a valid date with dd/mm/yyyy format and using integers only: ";
                cin >> tempDay >> tempMonth >> tempYear;
            }

            student_directory[index].reg_date.day = stoi(tempDay);
            student_directory[index].reg_date.month = stoi(tempMonth);
            student_directory[index].reg_date.year = stoi(tempYear);

            cout << "Enter the CGPA of the student (0-4): ";
            cin >> tempDay;
            while(isValidCGPA(tempDay) == 0){
                cout << "Please enter a valid CGPA (D.DD): ";
                cin >> tempDay;
            }

            student_directory[index].cgpa = stoi(tempDay);
            return;
                }
            }
            cout << "\nThe student is not in the list.\n" << endl;
}

void sortID(student student_directory[], int *count){
    for (int i{}; i < *count-1; i++){
        for (int j = i+1; j < *count; j++){
            if (student_directory[j].std_id < student_directory[i].std_id){
                struct student temp;
                temp = student_directory[j];
                student_directory[j] = student_directory[i];
                student_directory[i] = temp;
            }
        }
    }
    displayStudents(student_directory, count);
}

void sortYear(student student_directory[], int *count){
    for (int i{}; i < *count-1; i++){
        for (int j = i+1; j < *count; j++){
            if (student_directory[j].reg_date.year > student_directory[i].reg_date.year){
                struct student temp;
                temp = student_directory[j];
                student_directory[j] = student_directory[i];
                student_directory[i] = temp;
            }
        }
    }
    displayStudents(student_directory, count);
}

void sortName(student student_directory[], int *count){
    for (int i{}; i < *count-1; i++){
        for (int j = i+1; j < *count; j++){
            if (strcmp(student_directory[j].std_name, student_directory[i].std_name) < 0){
                struct student temp;
                temp = student_directory[j];
                student_directory[j] = student_directory[i];
                student_directory[i] = temp;
            }
        }
    }
    displayStudents(student_directory, count);
}

void sort(int *count){
    string temp;
    int choice;
    
    do{
        cout << "How do you want to sort the list?\n" << "[1] According to ID (Ascending)\n" << "[2] According to name of the student (Alphabetic)\n" <<
    "[3] According to registeration year (Descending)\n" << "[4] Exit\n\n" << "Enter your choice: ";
    cin >> temp;

    while(!isValidInteger(temp)){
        cout << "Please enter a number (1-4): ";
        cin >> temp;
    }

    choice = stoi(temp);

    switch (choice)
    {
    case 1:
        sortID(student_directory, count);
        break;
    case 2:
        sortName(student_directory, count);
        break;
    case 3:
        sortYear(student_directory, count);
        break;
    case 4:
        break;
    default:
        cout << "\nThat's not a valid choice!\n" << endl;
        break;
    }
    }while(choice != 4);
}

void maxCGPA(student student_directory[], int *count){
    struct student temp = student_directory[0];
    for (int i = 1; i < *count; i++){
        if (student_directory[i].cgpa > temp.cgpa) temp = student_directory[i];
    }
    cout << "The student(s) with the highest CGPA is/are: \n";
    for (int i{}; i < *count; i++){
        if (student_directory[i].cgpa == temp.cgpa){
           cout << student_directory[i].std_id << "\t" << student_directory[i].std_name << "\t" << student_directory[i].std_surname << "\t" <<
        student_directory[i].reg_date.day << "/" << student_directory[i].reg_date.month << "/" << student_directory[i].reg_date.year << "\t" << 
        student_directory[i].cgpa << "\n";
        }
    }
    cout << endl;
}

int main()
{
    int count = 0;
    string temp;
    int choice;

    do{
        cout << "MENU:\n\n" << "[1] Add a student\t\t" << "[2] Delete a student\t" << "[3] Display the students\n" << "[4] Search for a student\t" << "[5] Update a student\t" << 
    "[6] Sort the students\n" << "[7] Show highest CGPA\t\t" << "[8] Quit\n" << endl;
        cout << "Enter your choice: "; cin >> temp; cout << endl;

    while (!isValidInteger(temp))
    {
        cout << "Please enter a number (1-8): ";
        cin >> temp;
    }
    
    choice = stoi(temp);

    switch (choice)
    {
    case 1:
        addStudent(student_directory, &count);
        break;
    case 2:
        deleteStudent(student_directory, &count);
        break;
    case 3:
        displayStudents(student_directory, &count);
        break;
    case 4:
        searchStudent(&count);
        break;
    case 5:
        updateStudent(student_directory, &count);
        break;
    case 6:
        sort(&count);
        break;
    case 7:
        maxCGPA(student_directory, &count);
        break;
    case 8:
        cout << "Quitting the program..." << endl;
        break;
    default:
        cout << "\nThat's not a valid choice! Please select from 1 to 8.\n" << endl;
        break;
    }
    } while (choice != 8);


    return 0;
}