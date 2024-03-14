// NAME ¬¬ BILILIGN YIBGETA

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

fstream gradeHeader;
struct data
{
   
    float age_bilu;
    string id_bilu;
    string name_bilu;

} student;

void getdata()
{
    cout << "\t\t ADD NEW STUDENT" << endl;
    cout << "please Enter student Full Name" << endl;
    cin.ignore();
    getline(cin, student.name_bilu);
    cout << "please Enter student age" << endl;
    cin >> student.age_bilu;
    cout << "please Enter student id" << endl;
    cin >> student.id_bilu;
}

void toFile()
{
    ofstream display;
    display.open("studlist.doc", ios::app);
    // if (fout.is_open())
    // {
    display << student.id_bilu << "\t" << student.name_bilu << "\t" << student.age_bilu << "\t" << endl;
    display.close();

}

// void find()
// {
//     string line, name;
//     cout << "Enter student name" << endl;
//     cin >> name;
//     ifstream srch("studlist.doc");
//     if (srch.is_open())
//     {
//         while (getline(srch, line))
//         {
//             size_t pos = line.find(name);
//             if (pos != string::npos)
//                 cout << line << endl;
//         }
//     }
// }

void view()
{
    string holder;
    ifstream fin("studlist.doc");
    if (fin.is_open())
    {
        while (getline(fin, holder))
        {
            cout << holder << endl;
        }
    }
}

void Grade_report()
{
    int courseNum;
    gradeHeader << "Student ID \t\t"
                << " Name \t"
                << "Course\t"
                << "Score \t"
                << "Credit Hour "
                << " Grade \t"
                << "Point" << endl;
    gradeHeader.close();
    gradeHeader.open("Report.doc", ios::out | ios::app);
    cout << "How many course did you take " << endl;
    cin >> courseNum;

    struct gradeRep
    {
        /* structure for holding course name and grade */
        string name;
        string id;
        string course, grade;
        int score;
        int ch;
        float gradeValue;

    } gradeData;
    int i = 1;
    ofstream gradeFile;
    while (i <= courseNum)
    {
        cout << "please Enter student First name" << endl;
        cin >> gradeData.name;
        cout << "please Enter student ID" << endl;
        cin >> gradeData.id;
        cout << "please Enter course name" << endl;
        cin >> gradeData.course;
        cout << "please Enter student score out of 100%" << endl;
        cin >> gradeData.score;
        cout << "please Enter credit hour of the course" << endl;
        cin >> gradeData.ch;

        //  grade scale
        if (gradeData.score >= 85)
        {
            gradeData.grade = "A";
            gradeData.gradeValue = 4;
        }
        else if (gradeData.score >= 80)
        {
            gradeData.grade = "A-";
            gradeData.gradeValue = 3.75;
        }
        else if (gradeData.score >= 75)
        {
            gradeData.grade = "B+";
            gradeData.gradeValue = 3.5;
        }
        else if (gradeData.score >= 70)
        {
            gradeData.grade = "B";
            gradeData.gradeValue = 3;
        }
        else if (gradeData.score >= 65)
        {
            gradeData.grade = "B-";
            gradeData.gradeValue = 2.75;
        }
        else if (gradeData.score >= 60)
        {
            gradeData.grade = "C+";
            gradeData.gradeValue = 2.5;
        }
        else if (gradeData.score >= 55)
        {
            gradeData.grade = "C";
            gradeData.gradeValue = 2;
        }
        else if (gradeData.score >= 50)
        {
            gradeData.grade = "C-";
            gradeData.gradeValue = 1.75;
        }
        else if (gradeData.score >= 45)
        {
            gradeData.grade = "D";
            gradeData.gradeValue = 1;
        }
        else
        {
            gradeData.grade = "F";
            gradeData.gradeValue = 0;
        }
        gradeFile.open("Report.doc", ios::app);
        gradeFile << gradeData.id << "  " << gradeData.name << "  " << gradeData.course << "  " << gradeData.score << "\t\t " << gradeData.ch << "\t\t  " << gradeData.grade << "\t\t  " << gradeData.gradeValue * gradeData.ch << endl;
        i++;

        //
        gradeFile.close();
    }
}

void viewGrade()
{
    string holder;
    ifstream fout("Report.doc");
    if (fout.is_open())
    {
        while (getline(fout, holder))
        {
            cout << holder << endl;
        }
    }
}

void erase()
{
    int choice;
    do
    {
        cout << "\t\t\t delete informations !!!" << endl;
        cout << "Are you sure you want to delete informations ?" << endl;
        cout << "1.Yes delete" << endl;
        cout << "0.cancel" << endl;
        cin >> choice;
        if (choice == 0)
            return;
        else if (choice == 1)
        {
            remove("Report.doc");
            remove("studlist.doc");
            cout << "informations delete succesfully " << endl;
        }
        else
        {
            cout << "Please Enter Valid choice" << endl;
        }
    } while (choice != 0 || choice != 1);
}

int menu()
{
    int choice = 0;
    cout << "\n\n\n\t\t\t Student Data Management" << endl;
    cout << "select the operation you want to perform" << endl;
    cout << "1.Add new Student" << endl;
    cout << "2.Search " << endl;
    cout << "3.to View all Students" << endl;
    cout << "4.Add  grade" << endl;
    cout << "5.view student course grade list" << endl;
    cout << "6.delete information" << endl;
    cout << "0.Exit" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    gradeHeader.open("Report.doc", ios::out);
    do
    {
        choice = menu();
        if (choice == 0)
        {
            return 0;
        }
        switch (choice)
        {
        case 1:
            getdata();
            toFile();
            break;
        case 2:
            find();
            break;
        case 3:
            view();
            break;
        case 4:
            Grade_report();
            break;
        case 5:
            viewGrade();
            break;
        case 6:
            erase();
            break;
        default:
            cout << "Invalid entry please enter 1-3 or 0 exit" << endl;
            break;
        }
    } while (choice != 0 || choice != 1 || choice != 2 || choice != 3);

    return 0;
}
