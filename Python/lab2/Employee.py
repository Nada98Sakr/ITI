from MYSQL_Handler import *
from config import mysql

class Employee:
    db_handler = MYSQLHandler(mysql["host"], mysql["user"], mysql["password"], mysql["database"])

    def __init__(self, first_name, last_name, age, department, salary):
        self.id = 0
        self.data = {
            "first_name": first_name,
            "last_name": last_name,
            "age": age,
            "department": department,
            "salary": salary
        }

    def add_new(self):
        print(self.data)
        flag = Employee.db_handler.add_record(self.data)
        self.id= self.db_handler.cursor.lastrowid
        if(flag):
            return True
        else:
            return False

    def transfer(self, dep):
        self.department = dep
        flag = self.db_handler.update_department(self.id, self.data['department'])
        if(flag):
            return True
        else:
            return False

    @classmethod
    def fire(cls, id):
        employee = cls.search(id)
        if employee:
            flag = cls.db_handler.delete_record(id)
            if(flag):
                return True
            else:
                return False
        else:
            return False

    @classmethod
    def search(cls, value):
        for employee in cls.get_all():
            if value == employee[0]:
                return employee
        return False

    @staticmethod
    def show():
        employees = Employee.get_all()
        if employees:
            print("{:<5} {:<15} {:<15} {:<5} {:<15} {:<10}".format("ID", "First Name", "Last Name", "Age", "Department", "Salary"))
            for employee in employees:
                print("{:<5} {:<15} {:<15} {:<5} {:<15} {:<10}".format(*employee))
        else:
            print("No employees found.")

    @classmethod
    def get_all(cls):
        return  cls.db_handler.get_all_records(cls)
