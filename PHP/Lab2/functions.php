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

    function printConfirmationMessage(){
        saveToFile();
        echo "<div class='submittedMsg'>"
            ."<h3>"._THANK_U_."</h3>"
            ."You submitted data as:<br><br>"
            ."name: ".$_POST["name"]."<br><br>"
            ."email: ".$_POST["email"]."<br><br>"
            ."message: ".$_POST["message"]."<br><br>"
            ."</div>";
    }

    function saveToFile(){
        $fp = fopen(_SAVING_FILE_,"a+");
        fwrite($fp, date("M d Y h:i a") . ", ".$_SERVER['REMOTE_ADDR'].", " .$_POST["name"]. ", " . $_POST["email"].", " . $_POST["message"]."\n");
        fclose($fp);
    }

    function readUsersFile(){
        return file(_SAVING_FILE_);
    }
?>