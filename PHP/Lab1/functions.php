<?php 
    function validateForm(){
        $name = isset($_POST["name"]) ? $_POST["name"] : "";
        $email = isset($_POST["email"]) ? $_POST["email"] : "";
        $message = isset($_POST["message"]) ? $_POST["message"] : "";
        if(empty($name) || empty($email) || empty($message)){
            return "a field is empty";
        }elseif(strlen($name) > _MAX_NAME_LEN_ ){
            return "name length is too long";
        }elseif(!filter_var($email, FILTER_VALIDATE_EMAIL) ){
            return "email formate is wrong";
        }elseif(strlen($message) > _MAX_MSG_LEN_ ){
            return "message length is too long";
        }else{
            return "";
        }
    }

    function RemeberData($var){
        if(isset( $_POST[$var]) && !empty( $_POST[$var])){
            return $_POST[$var];
        }
    }
?>