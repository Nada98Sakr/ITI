<?php 
    $id = trim($_SERVER['REQUEST_URI'], '/products/item/');
    $item = $_DB->getRecordById($id)[0];
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link 
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" 
            rel="stylesheet" 
            integrity="sha384-GLhlTQ8iRABdZLl6O3oVMWSktQOp6b7In1Zl3/Jr59b6EGGoI1aFkw7cmDA6j6gD" 
            crossorigin="anonymous"
        >
        <title>Document</title>
    
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
                max-height: 100vh;
                background-image: url(../../views/backgroung.gif);
            }

            .AddProduct{
                background-color:rgba(0,0,0,0.7);
                box-shadow:0 10px 20px 0 rgba(0,0,0,0.03);
                border-radius: 10px;
                opacity:0.7;
                font-weight:bold;
                margin:auto;
                color: white;
            }

            table{
                color: white !important;
            }

            table td{
                padding: 10px !important;
                margin-bottom: 5px !important;
                border-bottom: 1px solid #eee;
            }

            input{
                background-color: transparent !important;
                border: none !important;
                color: white !important;
                font-size: 12px !important;
            }

            input::placeholder{
                color: #e2e3e5 !important;
                font-size: 12px !important;
            }
        </style>
    </head>

    <body>
        <div class="container d-flex justify-content-center align-items-center h-100">
            <div class="AddProduct col-12 col-md-8 p-5 rounded-4">
                <h1 class="text-uppercase text-center">Edit</h1>
                <form method="post" class = "row p-4 fs-3">
                    <table>
                        <tbody>
                            <tr >
                                <td class="col-4">Product code</td>
                                <td class="col-6">
                                    <input type="text" class="form-control p-3" name="PRODUCT_code" value=<?= $item["product_code"]?> placeholder="Enter item code" required>
                                </td>
                            </tr>

                            <tr >
                                <td>Product Name</td>
                                <td>
                                    <input type="text" class="form-control p-3" name="product_name" value=<?= $item["product_name"]?> placeholder="Enter item Name" required>
                                </td>
                            </tr>

                            <tr >
                                <td>Product Photo</td>
                                <td>
                                    <input type="text" class="form-control p-3" name="Photo" value=<?= $item["photo"]?> placeholder="Enter item photo name" required>
                                </td>
                            </tr>

                            <tr >
                                <td>Price</td>
                                <td>
                                    <input type="number" class="form-control p-3" name="list_price" value=<?= $item["list_price"]?> placeholder="product Price" required>
                                </td>
                            </tr>

                            <tr >
                                <td>reorder level</td>
                                <td>
                                    <input type="number" class="form-control p-3" name="reorder_level" value=<?= $item["reorder_level"]?> placeholder="enter reorder level" required>
                                </td>
                            </tr>

                            <tr >
                                <td>units in stock</td>
                                <td>
                                    <input type="number" class="form-control p-3" name="Units_In_Stock" value=<?= $item["units_in_stock"]?> placeholder="enter units in stock" required>
                                </td>
                            </tr>

                            <tr >
                                <td>category</td>
                                <td>
                                    <input type="text" class="form-control p-3" name="category" value=<?= $item["category"]?> placeholder="category" required>
                                </td>
                            </tr>
                            
                            <tr >
                                <td>country</td>
                                <td>
                                    <input type="text" class="form-control p-3"  name="CouNtry" value=<?= $item["country"]?> placeholder="enter country">
                                </td>
                            </tr>

                            <tr >
                                <td>Rating</td>
                                <td>
                                    <input type="float" class="form-control p-3" name="Rating" value=<?= $item["rating"]?> placeholder="Rating">
                                </td>
                            </tr>
                            
                            <tr >
                                <td>discontinued</td>
                                <td>
                                    <input type="number" class="form-control p-3"  name="discontinued" value=<?= $item["discontinued"]?> placeholder="discontinued">
                                </td>
                            </tr>
                            
                            <tr >
                                <td>Date</td>
                                <td>
                                    <input type="date" class="form-control p-3"  name="date" value=<?= $item["date"]?> placeholder="enter date">
                                </td>
                            </tr>
                        </tbody>
                    </table> 
                    <button class="btn btn-primary fs-3 ms-auto mt-5" style="max-width: fit-content !important; padding: 10px 20px;">CHANGE</button>
                </form>
            </div>
        </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js" integrity="sha384-w76AqPfDkMBDXo30jS1Sgez6pr3x5MlQ1ZAGC+nuZB+EYdgRZgiwxhTBTkF7CXvN" crossorigin="anonymous"></script>

</body>

</html>