<?php
    require_once("vendor/autoload.php");
    $ResponseMessage = "";

    if(!empty($_FILES)){
        $validateImage = new ImageValiator();
        $isValid = $validateImage->ValidateImage();
        if($isValid){
            $s3Uploader = new S3Uploader();
            $ResponseMessage =  $s3Uploader->GetMessage();
        }else{
            $ResponseMessage = $validateImage->GetMessage();
        }
    }

    require_once("views/upload.php");

?> 