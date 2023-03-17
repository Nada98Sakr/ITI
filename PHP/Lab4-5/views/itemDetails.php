<?php
    $id = trim($_SERVER['REQUEST_URI'], '/products/item/');
    $item = $_DB->getRecordById($id)[0];
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <meta http-equiv="X-UA-Compatible" content="ie=edge" />
        <title>Item Details</title>

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
                padding: 5rem 5rem 10rem;
                line-height: 1.7;
                background-image: url(../../views/backgroung.gif);
            }

            .container {
                width: 95rem;
                margin: 0 auto;
            }

            .product {
                width: 60rem;
                margin: 0 auto;
                margin-top: 2rem;
                background: white;
                box-shadow: 0 3rem 6rem 1rem rgba(0, 0, 0, 0.2);
                position: relative;
                overflow: hidden;
            }

            .product .onsale{
                background-color: #129b29;
                color: #fff;
                text-align: center;
                padding: 5px 0;
                display: block;
                position: absolute;
                width: 120px;
                font-size: 13px;
                right: -30px;
                top: 13px;
                transform: rotate(45deg);
                overflow: hidden;
                z-index: 200;
            }

            .product .noSale{
                display: none;
            }

            .product__image {
                position: relative;
                height: 22rem;
                overflow: hidden;
            }

            .product__image::before {
                content: '';
                display: block;
                height: 100%;
                width: 100%;
                position: absolute;
                top: 0;
                left: 0;
                background: rgba(0, 0, 0, 0.6);
                opacity: 0.5;
                z-index: 100;
            }
            
            .product__image img{
                width: 100%;
                margin-top: -14rem;
            }

            .product__back:link,
            .product__back:visited {
                position: absolute;
                top: 2rem;
                left: 2rem;
                font-size: 1.5rem;
                font-weight: 700;
                text-transform: uppercase;
                text-decoration: none;
                z-index: 1000;
                color: #555;
                background-color: white;
                box-shadow: 0 1rem 3rem rgba(0, 0, 0, 0.3);
                border-radius: 100rem;
                padding: 0 2rem;
                transition: all 0.3s;
                display: flex;
                align-items: center;
            }

            .product__back:hover,
            .product__back:active {
                background-color: #00000099;
                color: white;
            }

            .product__name {
                background: linear-gradient(to bottom, #00000099, #000000);
                padding: 1rem;
                font-family: 'Megrim', sans-serif;
                font-size: 4rem;
                color: white;
                text-align: center;
                word-spacing: 2px;
            }

            .product__details {
                background-color: #eee;
                padding: 4rem 6rem;
                font-size: 1.9rem;
                display: grid;
                grid-template-columns: 1fr 1fr;
                grid-gap: 0.8rem;
            }

            .emoji-left {
                font-size: 2rem;
                margin-right: 1rem;
            }
        </style>
    </head>

    <body>
        <div class="container">
            <figure class="product">
                <div class="onsale <?= $item['discontinued'] ? "": "noSale"?>">
                    <span class="badge">SALE</span>
                </div>
                <a href="/products" class="product__back">
                <span class="emoji-left">👈</span>Back
                </a>
                <div class="product__image">
                    <?php $image = $item['photo']?> 
                <img src=<?="../../images/$image"?> alt="">
                </div>
                <h2 class="product__name"><?= $item['product_name']?></h2>
                <div class="product__details">
                    <p><strong>code: </strong><?= $item["product_code"]?></p>
                    <p><strong>country: </strong><?= $item['country']?></p>
                    <p><strong>price: </strong><?= $item ['list_price']?>€</p>
                    <p><strong>units in stock: </strong><?= $item ['units_in_stock']?> units</p>
                    <p><strong>reorder level: </strong><?= $item ['reorder_level']?></p>
                    <p><strong>category: </strong><?= $item ['category']?></p>
                    <p><strong>rating: 
                        </strong><?php 
                            for ($i = 0; $i < (int)$item['rating']; $i++) {
                                echo ' ⭐';
                            }
                        ?>
                    </p>
                </div>
            </figure> 
        </div>
    </body>
</html>