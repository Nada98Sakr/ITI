<?php
    require_once("vendor/autoload.php");
    $parameters = isset($_GET["page"]) ? $_GET["page"] : "";
    if($parameters === "guzzlee"){
        require_once("view/homeGuzzlee.php");
    } else{
        require_once("view/home.php");
    }
?>