<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>weather</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" crossorigin="anonymous">
</head>
<body>
    <div class="btn-group w-100">
        <button class="btn btn-primary dropdown-toggle m-auto" type="button" data-bs-toggle="dropdown" aria-expanded="false">
            --- Choose a city ---
        </button>
        <ul class="dropdown-menu">
            <?php 
                $cities = get_cities();
                foreach($cities as $city){
            ?>
                <li><a class="dropdown-item" href="?id=<?php echo $city["id"]; ?>"><?php echo $city["name"];?></a></li>
            <?php 
                }
            ?>
        </ul>
    </div>
    <?php 
        if(! empty($_GET)){
            $data = get_weather();
            echo '<div class = "card w-50 m-t-5">';
            echo '<div class="card-body d-flex flex-column">';
            echo '<h2 class="card-title">' .$data["name"].' weather status' . '</h2>';
            echo '<ul class="list-group list-group-flush">';
            echo '<li class="list-group-item">'.$data["weather"][0]["description"].'.</li>';
            foreach ($data as $key => $value) {
                if ($key === 'main' || $key === 'wind') {
                    foreach ($value as $ke => $v) {
                        if ($ke === "temp") echo '<li class="list-group-item"><strong>'.$ke.': </strong>'.$v.'.</li>';
                        if ($ke === "humidity") echo'<li class="list-group-item"><strong>'.$ke.': </strong>'.$v.'%. </li>';
                        if ($ke === 'speed')  echo '<li class="list-group-item"><strong>'.$ke.': </strong>'.$v.' Km/h.</li>';
                    }
                }
            }
            echo '</ul>';
            echo'</div>';
            echo'</div>';
        }
    ?>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js" integrity="sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN" crossorigin="anonymous"></script>
</body>
</html>