<?php

use Aws\S3\S3Client;

class S3Uploader{
    private $_s3 ;
    private $_message;

    public function __construct(){
        if(!empty($_FILES)){
            $this->ConnectTOS3();
            $this->uploadFile();
        }else{
            $this->_message = "No file selected";
        }
    }

    public function uploadFile(){
        try{
            $id = uniqid();
            $file = $_FILES["fileUpload"]['tmp_name'];
            $this->_s3->putObject(
                array(
                    'Bucket' => _BUCKET_NAME_,
                    'Key' =>  $id,
                    'SourceFile' => $file,
                    'StorageClass' => 'REDUCED_REDUNDANCY'
                )
            );
            $this->_message = "File Uploaded Successfuly";
        }catch(Exception $e){
            $this->_message = $e;
        }
    }

    private function ConnectTOS3(){
        $this->_s3 = S3Client::factory(array(
            'credentials' => array(
                'key' =>  _ACCESS_KEY_,
                'secret' => _SECRET_ACCESS_KEY_,
            ),  'region' => _REGION_,
            'version' => 'latest'
        ),);
    }

    public function GetMessage(){
        return $this->_message;
    }
}
?>