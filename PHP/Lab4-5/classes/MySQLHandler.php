<?php
class MySQLHandler implements DbHandler{
    private $_dbHandler;
    private $_table;

    public function __construct($table){
        $this->_table = $table;
        $this->connect();
    }

    private function connect(){
        try{
            $handler = mysqli_connect(_HOST_,_USER_,_PASSWORD_,_DB_NAME_);
            if($handler){
                $this->_dbHandler = $handler;
                return true;
            }else{
                return false;
            }
        }catch(Exception $e){
            die("Could not connect to db, please come back later.");
        }
    }

    private  function disconnect(){
        if ($this->_dbHandler)
            mysqli_close($this->_dbHandler);
    }

    public function getRecordsPagination($fields = array(), $_start = 0){
        $table = $this->_table;
        if(empty($fields)){
            $sql = "select * from `$table`";
        }else{
            $sql = "select ";
            foreach ($fields as $field) {
                $sql .= " `$field`, ";
            }
            $sql .= "from  `$table` ";
            $sql = str_replace(", from", "from", $sql);
        }
        $sql.= "limit $_start," . _PAGE_REC_;
        return $this->getResult($sql);
    }

    public function getRecordById($id){
        $table = $this->_table;
        $sql = "SELECT * FROM $table WHERE id = $id";
        return $this->getResult($sql);
    }

    public function getRecordByField($field, $value){
        $table = $this->_table;
        $sql = "SELECT * FROM $table WHERE $field = '$value'";
        return $this->getResult($sql);
    }

    public function DeleteRecordByID($id){
        $table = $this->_table;
        $sql = "DELETE FROM $table WHERE id = $id";
        $sql = "delete  from `" . $table . "` where id = $id";
        if (mysqli_query($this->_dbHandler, $sql)) {
            $this->disconnect();
            return true;
        } else {
            $this->disconnect();
            return false;
        }
    }

    public function getNumberOfRows(){
        $table = $this->_table;
        $_handler_results = mysqli_query($this->_dbHandler, "select * from `$table`");
        $RowsNum = mysqli_num_rows($_handler_results);
        return $RowsNum;
    }

    public function getResult($sql){
        $this->debug($sql);

        try{
            $_result_handler = mysqli_query($this->_dbHandler, $sql);
            $_arr_result = array();

            if($_result_handler){
                while($row = mysqli_fetch_array($_result_handler, MYSQLI_ASSOC)){
                    $_arr_result[] = array_change_key_case($row);
                }
                return $_arr_result;
            }else{
                return false;
            }
        }catch(Exception $e){
            
        }
    }

    private function debug($sql) {
        if (_DEBUG_MOD_ === 1)
            return "<h5>Sent Query: </h5>" . $sql . "<br/> <br/>";
    }
}
?>