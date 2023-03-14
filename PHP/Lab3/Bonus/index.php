<?php
    require_once("vendor/autoload.php");
    $ResponseMessage = "";

    if(!empty($_FILES)){
        $s3Uploader = new S3Uploader();
        $ResponseMessage =  $s3Uploader->GetMessage();
    }

    require_once("views/upload.php");

?> 