<?php
$current_index = isset($_GET["next"]) && is_numeric($_GET["next"]) ? (int)$_GET["next"] : 0;
$rows_number = $_DB->getNumberOfRows();
$next_index = $current_index + _PAGE_REC_ < $rows_number ? $current_index + _PAGE_REC_ : $current_index;
$prev_index = ($current_index - _PAGE_REC_ > 0) ? $current_index - _PAGE_REC_ : 0;
$pagedItems = $_DB->getRecordsPagination(array(), $current_index);
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Products</title>
        <link 
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" 
            rel="stylesheet" 
            integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" 
            crossorigin="anonymous"
        >
        <style>
            *,
            *::before,
            *::after {
                margin: 0;
                padding: 0;
                box-sizing: inherit;
            }

            html {
                font-size: 62.5%;
                box-sizing: border-box;
            }

            body {
                padding: 2rem 10rem;
                line-height: 1.7;
                max-height: 100vh;
                background-image: url(../views/backgroung.gif);
            }

            h1 {
                font-family: 'Megrim', sans-serif;
                font-size: 6rem;
                color: white;
                text-align: center;
                word-spacing: 3px;
            }

            .card{
                border: none !important;
                overflow: hidden;
            }

            .card .onsale .badge{
                background-color: #129b29;
                color: #fff;
                text-align: center;
                padding: 5px 0;
                display: block;
                position: absolute;
                width: 120px;
                font-size: 13px;
                right: -40px;
                top: 13px;
                transform: rotate(45deg);
                overflow: hidden;
            }

            .noSale{
                display: none;
            }

            form input{
                width: 300px !important;
                padding: 10px 20px !important;
            }

            .card .icons{
                left: 10px;
                top: 10px;
                gap: 5px;
            }
            
            .card .icons a{
                text-decoration: none;
                color: black;
                background-color: rgb(0, 0, 0);
                box-shadow:0 10px 20px 0 rgba(0,0,0,0.03);
                border-radius: 50%;
                padding: 3px;
                color: black;
                display: none;
                z-index: 5;
            }

            .card:hover .card-img-top,
            .card:hover .card-body{
                opacity: 0.5;
            }
            .card:hover .icons a{
                display: block;
            }
        </style>
    </head>
    <body>
        <div class="container">
            <h1>sunglasses</h1>

            <div class="operation col-10 mx-auto my-5 col-lg-10 d-flex justify-content-between">
                <form action="" class="search">
                    <input class="form-control" type="text" placeholder="Search" name="search">
                    <input type="submit" style="display: none;">
                </form>
                <div class="ADDNew" >
                    <a href="/products/newItem"><button type="button" class="btn btn-primary fs-4 px-4 py-2">ADD ITEM</button></a>
                </div>
            </div>

            <div class="cardContainer col-12 d-flex flex-wrap justify-content-evenly">
                <?php foreach ($pagedItems as $item) :?>
                <div class="card position-relative mb-5 mb-lg-0" style="width: 18rem;">
                    <img src=<?= "../images/".$item['photo']?> class="card-img-top h-50" alt="...">
                    <div class="card-body">
                        <h5 class="card-title text-center p-2 fs-3"><?= $item['product_name']?></h5>
                        <p class="card-text">Price: <?= $item['list_price']?> $</p>
                        <p class="card-text">Rating: <?= $item['rating']?></p>
                    </div>
                    <div class="icons d-flex flex-column position-absolute">
                        <a href="/products/edit/<?= $item['id']?>">✎</a>
                        <a href="/products/delete/<?= $item['id']?>">🗑️</a>
                        <a class="viewMore" href="/products/item/<?= $item['id']?>">👁</a>
                    </div>

                    <div class="onsale <?= $item['discontinued'] ? "": "noSale"?>">
                        <span class="badge">SALE</span>
                    </div>
                </div>
                <?php endforeach;?>
            </div>

            <div class="paging col-10 col-lg-10 mx-auto my-5 d-flex justify-content-between">
                <a href=<?="/products?next=$prev_index"?>><button type="button" class="btn btn-danger fs-4 px-4 py-2">PREV</button></a>
                <a href=<?="/products?next=$next_index"?>><button type="button" class="btn btn-success fs-4 px-4 py-2">NEXT</button></a>
            </div>
        </div>
    </body>
</html>
