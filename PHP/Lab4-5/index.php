<?php
    require_once("vendor/autoload.php");
    $_DB = new MySQLHandler("items");

    $uri = explode('/', $_SERVER['REQUEST_URI']);
    if(! isset($uri[2]))
    {
        require_once("views/AllItems.php");
    }else{
        if($uri[2] == "edit"){
            require_once("views/Edit.php");
        }else if($uri[2] == "item"){
            require_once("views/itemDetails.php");
        }else if($uri[2] == "delete"){
            $id = trim($_SERVER['REQUEST_URI'], '/products/delete/');
            if($_DB->DeleteRecordByID($id) == true){
                require_once("views/Delete.php");
            }else{
                echo "product not deleted";
            }
        }else if($uri[2] == "newItem"){
            require_once("views/NewItem.php");
        }else{
            echo "Page requested is not valid";
        }
    }
?>