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
        <div class="AllUsers">
            <?php
                $users = readUsersFile();
                foreach($users as $user){
                    $userData = explode(",",$user);
                    echo "<div class='userData'>"
                    ."<p id='userHeading'>user data: </p>"
                    ."<ul>"
                    ."<li><strong>Date: </strong>$userData[0]</li>"
                    ."<li><strong>IP: </strong>$userData[1]</li>"
                    ."<li><strong>name: </strong>$userData[2]</li>"
                    ."<li><strong>email: </strong>$userData[3]</li>"
                    ."<li><strong>message: </strong>$userData[4]</li>"
                    ."</li>"
                    ."</div>";
                    echo str_repeat("*",50);
                }
            ?>
        </div>
	</div>
</body>
</html>
