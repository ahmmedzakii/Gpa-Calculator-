#include<iostream>
#include<string>
using namespace std;


float calculateSemesterGPA(int semesterNumber, float& semesterCredits) {
    int numofcourse = 0;
    float totalpoints = 0.0;
    semesterCredits = 0.0;

    cout << "\n--- Semester " << semesterNumber << " ---";
    cout << "\nPlease Enter Number Of Courses: ";
    cin >> numofcourse;

    while (numofcourse <= 0 || numofcourse > 9) {
        cout << "Please Enter The Number Of Courses Again: ";
        cin >> numofcourse;
    }

    for (int i = 0; i < numofcourse; i++) {
        char degree;
        cout << "\nEnter The Grade of Course " << (i + 1) << " (A, B, C, D, F): ";
        cin >> degree;

        while (!(degree == 'A' || degree == 'a' || degree == 'B' || degree == 'b' ||
                 degree == 'C' || degree == 'c' || degree == 'D' || degree == 'd' ||
                 degree == 'F' || degree == 'f')) {
            cout << "Invalid Grade! Please Re-enter (A, B, C, D, F): ";
            cin >> degree;
        }

        int credits;
        cout << "Enter The Number Of Credits for Course " << (i + 1) << ": ";
        cin >> credits;

        while (credits <= 0 || credits > 6) {
            cout << "Invalid Credits! Please Re-enter (1 to 6): ";
            cin >> credits;
        }

        float gradepoint = 0.0;

        if (degree == 'A' || degree == 'a')
        {
            gradepoint = 4.0;

        }else if (degree == 'B' || degree == 'b') {
            gradepoint = 3.3;

        }else if (degree == 'C' || degree == 'c') {
            gradepoint = 2.0;

        }else if (degree == 'D' || degree == 'd') {
            gradepoint = 1.0;

        }else if (degree == 'D' || degree == 'd') {
            gradepoint = 0.0;
        }
        
        // This Is Calc Of The Gpa 
        totalpoints += gradepoint * credits;
        semesterCredits += credits;
    }

    return (semesterCredits > 0) ? (totalpoints / semesterCredits) : 0.0;
}


int main() {
    cout << "================== Welcome To GPA Calc App ========================\n";
    string name;
    cout << "Enter Your Name: ";
    getline(cin, name); 

    int id;
    cout << "Enter Your ID: ";
    cin >> id;

    int numberOfSemesters;
    cout << "\nEnter The Number Of Semesters You Want To Calculate: ";
    cin >> numberOfSemesters;

    float gpas[10];
    float credits[10];//array Store credits From 0 to 9 which Get From Void Fun.

    float totalAllPoints = 0.0; 
    float totalAllCredits = 0.0;
    float semesterCredits = 0.0;

    for (int i = 1; i <= numberOfSemesters; i++) {
        gpas[i] = calculateSemesterGPA(i , semesterCredits);
        credits[i] = semesterCredits;
        totalAllPoints += gpas[i] * semesterCredits;
        totalAllCredits += semesterCredits;
    }

    cout << "\n====================================================";
    cout << "\nHello " << name << ", with ID: " << id;
    for (int i = 0; i < numberOfSemesters; i++) {
        cout << "\nSemester " << (i + 1) << " GPA: " << gpas[i];
    }

    float overallGPA = (totalAllCredits > 0) ? (totalAllPoints / totalAllCredits) : 0.0;
    cout << "\n\nYour Overall GPA: " << overallGPA;
    cout << "\n====================================================";



char choice;
int semesterToView;

do {
    cout << "\n\nDo you want to view a specific semester GPA? (Y/N): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y' ) {
        cout << "Enter semester number (1 to " << numberOfSemesters << "): ";
        cin >> semesterToView; 

        if (semesterToView >= 1 && semesterToView <= numberOfSemesters) {
            cout << "GPA of Semester " << semesterToView << ": " << gpas[semesterToView] << endl;// هنا احنا بننده علي السمتر اللي اليوز عايز يشوفه تاني وعلي حسب رقم السمستر اللي هو هيختاره 
        } else {
            cout << "Invalid semester number!\n";
        }
    }

} while (choice == 'y' || choice == 'Y');
    cout << "\nThank you for using the GPA Calculator!\n";
    return 0;
}