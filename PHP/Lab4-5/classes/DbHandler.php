<?php

interface DbHandler{
    public function getRecordsPagination($fields, $_start);
    public function getRecordById($id);
    public function getRecordByField($field, $value);
    public function DeleteRecordByID($id);
}

?>