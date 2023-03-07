<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>contatc us</title>
    <link rel="stylesheet" href="./style.css">
</head>
<body>
	<div class="main">
        <div class="signUp">
            <form action="index.php" method="post" >
                <p id="heading">contact us</p>
                <h5 class="errMsg"><?php echo $error; ?></h5>
                <input type="text" name="name" value="<?php echo RemeberData("name") ?>" placeholder="Name" >
                <input type="email" name="email" value="<?php echo RemeberData("email") ?>" placeholder="Email" >
                <input type="text" name="message" value="<?php echo RemeberData("message") ?>" id="message" placeholder="Message">
                
                <button>send email</button>
            </form>
        </div>
	</div>
</body>
</html>