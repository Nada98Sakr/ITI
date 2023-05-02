import mysql.connector

class MYSQLHandler:
    def __init__(self, host, user, password, database):
        self.user = user
        self.host = host
        self.password = password
        self.database = database
        self.db_connect = None
        self.cursor = None
    
    def connect(self):
        try:
            self.db_connect = mysql.connector.connect(
                                                        host = self.host, 
                                                        user = self.user, 
                                                        password = self.password, 
                                                        database = self.database
            )

            self.cursor = self.db_connect.cursor()
            return self.db_connect
        except mysql.connector.Error as e:
            print(f"Can not connect to {self.database} database")
            return
    
    def disconnect(self):
        self.db_connect.close()

    def add_record(self, data):
        columns = list(data.keys())
        value = [f"'{v}'" if isinstance(v, str) else str(v) for v in data.values()]
        query = f"INSERT INTO employees ({', '.join(columns)}) VALUES ({', '.join(value)})"
        flag = self.excute_query(query)
        return flag

    def get_all_records(self,cls):
        if cls.__name__ == "Employee":
            query = "SELECT * FROM employees WHERE managed_dep IS NULL"
        elif cls.__name__ == "Manager":
            query = "SELECT * FROM employees WHERE managed_dep IS NOT NULL"
        data = self.excute_query(query)
        return data

    def get_record_by_id(self, id):
        query = f"SELECT * FROM employees WHERE id = {id}"
        data = self.excute_query(query)
        return data[0]

    def update_department(self, id, edited_val):
        query = f"UPDATE employees SET department = {edited_val} WHERE id = {id}"
        flag = self.excute_query(query)
        return flag

    def delete_record(self, id):
        query = f"DELETE FROM employees WHERE id = {id}"
        flag = self.excute_query(query)
        return flag
    
    def excute_query(self, query):
        try:
            self.connection = self.connect()
            self.cursor = self.connection.cursor()
            self.cursor.execute(query)

            if query.upper().startswith('SELECT'):
                result = self.cursor.fetchall()
                self.disconnect()
                return result
            else:
                rows_affected = self.cursor.rowcount
                self.connection.commit()
                self.disconnect()
                if rows_affected > 0:
                    return True
                else:
                    return False
        except mysql.connector.Error as e:
            print(f"ERROR: {e}")
            return
        