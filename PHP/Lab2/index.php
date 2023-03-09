<style><?php include "views/style.css"; ?></style>
<?php
    require_once("./config.php");
    require_once("./functions.php");
    $error = "";
    if(! empty($_POST)){
        $error = validateForm();
        if(empty($error)){
            printConfirmationMessage();
            exit();
        }
    }

    $parameters = isset($_GET["page"]) ? $_GET["page"] : "";
    if($parameters === "users"){
        require_once("views/AllUsers.php");
    } else{
        require_once("views/contactUs.php");
    }
?>