from Employee import *
from Manager import *

def Menu():
    print("Menu:")
    print("1 - Add New Employee")
    print("2 - Add New Manager")
    print("3 - Fire Employee")
    print("4 - Fire Manager")
    print("5 - Show All Employees")
    print("6 - Show All Managers")
    print("7 - Exit")
    print("")

def add_employee():
    print("Adding new employee")
    print("")
    first_name = input("Enter employee's first name: ")
    last_name = input("Enter employee's last name: ")
    age = input("Enter employee's age: ")
    department = input("Enter employee's department: ")
    salary = input("Enter employee's salary: ")
    emp = Employee(first_name, last_name, age, department, salary)
    flag = emp.add_new()
    if(flag):
        print("Employee is Added successfully")
    else:
        print("Something went wrong and Employee is not added")

def add_manager():
    print("Adding new manager")
    print("")
    first_name = input("Enter manager's first name: ")
    last_name = input("Enter manager's last name: ")
    age = input("Enter manager's age: ")
    department = input("Enter manager's department: ")
    salary = input("Enter manager's salary: ")
    managed_dep = input("Enter manager's managed_dep: ")
    manager = Manager(first_name, last_name, age, department, salary, managed_dep)
    flag = manager.add_new()
    if(flag):
        print("Manager is Added successfully")
    else:
        print("Something went wrong and Manager is not added")

def fire_employee():
    print("Fireing employee")
    id = int(input("Enter employee's id to fire: "))
    flag = Employee.fire(id)
    if(flag):
        print("Employee is Fired")
    else:
        print("Employee is not found")

def fire_manager():
    print("Fireing manager")
    id = int(input("Enter manager's id to fire: "))
    flag = Manager.fire(id)
    if(flag):
        print("Manager is Fired")
    else:
        print("Manager is not found")

def show_all_employees():
    print("Viewing all employees")
    print("")
    Employee.show()

def show_all_managers():
    print("Viewing all managers")
    print("")
    Manager.show()

def main():
    while (True):
        print("")
        Menu()
        choice = input("Enter your choice: ")
        print("")
        print("-"*70)
        if choice == "1":
            add_employee()
        elif choice == "2":
            add_manager()
        elif choice == "3":
            fire_employee()
        elif choice == "4":
            fire_manager()
        elif choice == "5":
            show_all_employees()
        elif choice == "6":
            show_all_managers()
        elif choice == "7":
            print("Goodbye!")
            break
        else:
            print("Invalid choice, Please Try Again")
        print("-"*70)
main()