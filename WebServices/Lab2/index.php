<?php
    require_once("./MySQLHandler.php");
    require_once("./config.php");
    
    $_DB = new MySQLHandler("products");
    $_connect = $_DB->connect();

    if($_connect){
        $uri = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
        $uri = explode('/', $uri);
        if ($uri[2] !== 'products') {
            header("HTTP/1.1 404 Not Found");
            exit();
        }
        $id = null;
        if (isset($uri[3])) {
            $id = (int) $uri[3];
        }
        $method = $_SERVER["REQUEST_METHOD"];

        switch($method){
            case 'POST':
                $post = json_decode(file_get_contents('php://input'), true);
                $response = $_DB->save($post);
                echo json_encode($response);
                break;
                
            case 'GET':
                if ($id) {
                    if(! $_DB->search("id", $id)){
                        $response = ["error" => "not Found"];
                        http_response_code(404);
                        header('Content-Type: application/json');
                    }else{
                        $response =  $_DB->get_record_by_id($id);
                    }
                }else{
                    $response = $_DB->get_data();
                }
                echo json_encode($response);
                break;
            case 'DELETE':
                $response = $_DB->delete($id);
                echo json_encode($response);
                break;

            case 'PUT':
                $data = json_decode(file_get_contents('php://input'), true);
                if(! $_DB->search("id", $id)){
                        $response = ["error" => "not Found"];
                        http_response_code(404);
                        header('Content-Type: application/json');
                }else{
                    $response = $_DB->update($data,$id);
                }
                echo json_encode($response);
                break;

            default:
                $response = ["error" => "Request method not supported"];
                http_response_code(405);
                header('Content-Type: application/json');
                echo json_encode($response);
                break;
        }
    }else{
        $response = ["error" => "database not connected."];
        http_response_code(500);
        header('Content-Type: application/json');
    }
    ?>