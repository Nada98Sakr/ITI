from Employee import *

class Manager(Employee):
    def __init__(self, first_name, last_name, age, department, salary, managed_dep):
        super().__init__(first_name, last_name, age, department, salary)
        self.managed_dep = managed_dep
        self.data["managed_dep"] = self.managed_dep

    @staticmethod
    def show():
        Managers = Manager.get_all()
        if Managers:
            print("{:^5} {:^15} {:^15} {:<5} {:^15} {:^15} {:^15}".format("ID", "First Name", "Last Name", "Age", "Department", "Salary", "Managed Department"))
            for manager in Managers:
                id, first_name, last_name, age, department, salary, managed_dep = manager
                print("{:^5} {:^15} {:^15} {:<5} {:^15} {:^15} {:^15}".format(id, first_name, last_name, age, department, salary, managed_dep))
        else:
            print("No managers found.")
