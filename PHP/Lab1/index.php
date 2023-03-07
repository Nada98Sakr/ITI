<style><?php include "views/style.css"; ?></style>
<?php
    require_once("./config.php");
    require_once("./functions.php");
    $error = "";
    if(! empty($_POST)){
        $error = validateForm();
        if(empty($error)){
            die(
                "<div class='submittedMsg'>"
                ."<h3>"._THANK_U_."</h3>"
                ."You submitted data as:<br><br>"
                ."name = ".$_POST["name"]."<br><br>"
                ."email = ".$_POST["email"]."<br><br>"
                ."message = ".$_POST["message"]."<br><br>"
                ."</div>"
            );
        }
    }
    require_once("views/contactUs.php");
?>