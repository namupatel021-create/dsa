#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Student
{
private:
    T id;
    string name;

public:
    Student(T id, string name)
    {
        this->id = id;
        this->name = name;
    }

    T getId()
    {
        return id;
    }

    void display()
    {
        cout << "ID   : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "----------------------" << endl;
    }
};

int main()
{
    vector<Student<int>> students;
    int choice;

    do
    {
        cout << "\n===== Student Management System =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove Student By ID" << endl;
        cout << "4. Search Student By ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name;

            cout << "Enter Student ID : ";
            cin >> id;
            cin.ignore();

            cout << "Enter Student Name : ";
            getline(cin, name);

            students.push_back(Student<int>(id, name));
            cout << "Student Added Successfully!" << endl;
            break;
        }

        case 2:
        {
            if (students.empty())
            {
                cout << "No Students Found!" << endl;
            }
            else
            {
                for (auto &s : students)
                    s.display();
            }
            break;
        }

        case 3:
        {
            int id;
            cout << "Enter ID to Remove : ";
            cin >> id;

            bool found = false;
            for (auto it = students.begin(); it != students.end(); it++)
            {
                if (it->getId() == id)
                {
                    students.erase(it);
                    found = true;
                    cout << "Student Removed Successfully!" << endl;
                    break;
                }
            }

            if (!found)
                cout << "Student Not Found!" << endl;

            break;
        }

        case 4:
        {
            int id;
            cout << "Enter ID to Search : ";
            cin >> id;

            bool found = false;
            for (auto &s : students)
            {
                if (s.getId() == id)
                {
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student Not Found!" << endl;

            break;
        }

        case 5:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
