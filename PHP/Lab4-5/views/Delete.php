<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link 
        href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" 
        rel="stylesheet" 
        integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" 
        crossorigin="anonymous"
    >
    <style>
        body {
            padding: 7rem 0;
            line-height: 1.7;
            background-image: url(../../views/backgroung.gif);
            max-height: 100vh;
        }

    </style>
</head>
<body>
    <div class="Messagecontainer w-100 d-flex justify-content-center" >
        <div class="message text-center rounded-3 col-11 col-md-6 bg-secondary-subtle p-4 ">
            <img src="../../views/pop-up.png" alt="" style="width: 80px; height: 80px;">
            <p>Product Deleted Successfully</p>
            <a href=<?="/products"?>><button class="btn btn-primary fs-4 px-4 py-2" type="button">BACK TO Products</button></a>
        </div>
    </div>
</body>
</html>