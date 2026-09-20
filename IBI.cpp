#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
private:
    int employeeID;
    string name;
    double salary;
    string department;
public:
    Employee(int id, string n, double s, string d)
    {
        employeeID = id;
        name = n;
        salary = s;
        department = d;
    }
    int getEmployeeID()
    {
        return employeeID;
    }
    string getName()
    {
        return name;
    }
    double getSalary()
    {
        return salary;
    }
    string getDepartment()
    {
        return department;
    }
    void setSalary(double s)
    {
        salary = s;
    }
    void setDepartment(string d)
    {
        department = d;
    }
    double getSalaryAfterTax()
    {
        return salary - (salary * 0.10);
    }
    void displayEmployee()
    {
        cout << "Employee ID : " << employeeID << endl;
        cout << "Name        : " << name << endl;
        cout << "Salary      : " << fixed << setprecision(2) << salary << endl;
        cout << "Department  : " << department << endl;
        cout << "After Tax   : " << fixed << setprecision(2)
            << getSalaryAfterTax() << endl;
        cout << "-----------------------------" << endl;
    }
};

bool employeeExists(vector<Employee>& employees, int id)
{
    for (Employee& employee : employees)
    {
        if (employee.getEmployeeID() == id)
        {
            return true;
        }
    }
    return false;
}

void addEmployee(vector<Employee>& employees)
{
    int id;
    string name;
    double salary;
    string department;
    cout << "\nEnter Employee ID: ";
    cin >> id;
    if (employeeExists(employees, id))
    {
        cout << "Employee with this ID already exists.\n";
        return;
    }
    cin.ignore();
    cout << "Enter Employee Name: ";
    getline(cin, name);
    cout << "Enter Salary: ";
    cin >> salary;
    if (salary < 0)
    {
        cout << "Salary cannot be negative.\n";
        return;
    }
    cin.ignore();
    cout << "Enter Department: ";
    getline(cin, department);
    Employee newEmployee(id, name, salary, department);
    employees.push_back(newEmployee);
    cout << "\nEmployee added successfully!\n";
}

void viewEmployees(vector<Employee>& employees)
{
    if (employees.empty())
    {
        cout << "\nNo employees found.\n";
        return;
    }
    cout << "\n========== EMPLOYEE LIST ==========\n";
    for (Employee& employee : employees)
    {
        employee.displayEmployee();
    }
}

void updateEmployee(vector<Employee>& employees)
{
    int id;
    cout << "\nEnter Employee ID to update: ";
    cin >> id;
    for (Employee& employee : employees)
    {
        if (employee.getEmployeeID() == id)
        {
            int choice;
            cout << "\nEmployee found!\n";
            cout << "1. Update Salary\n";
            cout << "2. Update Department\n";
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 1)
            {
                double newSalary;
                cout << "Enter new salary: ";
                cin >> newSalary;
                if (newSalary < 0)
                {
                    cout << "Salary cannot be negative.\n";
                    return;
                }
                employee.setSalary(newSalary);
                cout << "Salary updated successfully!\n";
            }
            else if (choice == 2)
            {
                string newDepartment;
                cin.ignore();
                cout << "Enter new department: ";
                getline(cin, newDepartment);
                employee.setDepartment(newDepartment);
                cout << "Department updated successfully!\n";
            }
            else
            {
                cout << "Invalid choice.\n";
            }
            return;
        }
    }
    cout << "Employee with ID " << id << " was not found.\n";
}

void deleteEmployee(vector<Employee>& employees)
{
    int id;
    cout << "\nEnter Employee ID to delete: ";
    cin >> id;
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i].getEmployeeID() == id)
        {
            employees.erase(employees.begin() + i);
            cout << "Employee deleted successfully!\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " was not found.\n";
}


int main()
{
    vector<Employee> employees;
    int choice;
    cout << "====================================\n";
    cout << "     EMPLOYEE MANAGEMENT SYSTEM\n";
    cout << "====================================\n";
    while (true)
    {
        cout << "\n";
        cout << "1. Add Employee\n";
        cout << "2. View Employees\n";
        cout << "3. Update Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addEmployee(employees);
            break;
        case 2:
            viewEmployees(employees);
            break;
        case 3:
            updateEmployee(employees);
            break;
        case 4:
            deleteEmployee(employees);
            break;
        case 5:
            cout << "\nThank you for using Employee Management System!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}