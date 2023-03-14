<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Uplad Image</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
</head>
<body>
    <div class="container-fluid">
        <form action="index.php" method="post" id="file-upload-form" class="uploader m-auto mt-5 p-5 rounded-4" style="background-color:rgba(0,0,0,0.8) ;margin-top: 100px !important; width:450px;" enctype="multipart/form-data">
            <div class="image col-2 mx-auto pb-5" >
                <svg class="box__icon" style="fill: #92b0b3;" xmlns="http://www.w3.org/2000/svg" width="50" height="43" viewBox="0 0 50 43"><path d="M48.4 26.5c-.9 0-1.7.7-1.7 1.7v11.6h-43.3v-11.6c0-.9-.7-1.7-1.7-1.7s-1.7.7-1.7 1.7v13.2c0 .9.7 1.7 1.7 1.7h46.7c.9 0 1.7-.7 1.7-1.7v-13.2c0-1-.7-1.7-1.7-1.7zm-24.5 6.1c.3.3.8.5 1.2.5.4 0 .9-.2 1.2-.5l10-11.6c.7-.7.7-1.7 0-2.4s-1.7-.7-2.4 0l-7.1 8.3v-25.3c0-.9-.7-1.7-1.7-1.7s-1.7.7-1.7 1.7v25.3l-7.1-8.3c-.7-.7-1.7-.7-2.4 0s-.7 1.7 0 2.4l10 11.6z"></path></svg>
            </div>
            <p class="text-white text-center">Choose File</p>
            <input id="file-upload" type="file" class="form-control my-3" name="fileUpload" />
            <button type="submit" class="btn btn-primary mb-3 col-12">upload</button>
            <p class="Message text-center" style="color: #92b0b3;"><?php echo $ResponseMessage ?></p>
        </form>
    </div>
</body>
</html>