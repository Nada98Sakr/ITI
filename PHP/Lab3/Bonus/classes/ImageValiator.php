<?php 

class ImageValiator{
    private $message;

    public function __construct(){
        $this->message = "";
    }

    public function ValidateImage(){
        if($_FILES["fileUpload"]["size"] > 3000000){
            $this->message = "file is too large";
            return false;
        }else if(! stristr($_FILES["fileUpload"]["type"], "image")){
            $this->message = "file type is not supported!!";
            return false;
        }else {
            $this->message = "file is valid";
            return true;
        }
    }

    public function GetMessage(){
        return $this->message;
    }
}
?>