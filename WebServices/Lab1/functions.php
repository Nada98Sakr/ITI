<?php
use GuzzleHttp\Client;

function get_cities()
{
    $string = file_get_contents(_CITY_FILE_);
    $cities_array = json_decode($string, true);
    $egyptian_cities = array();

    foreach ($cities_array as $key => $value) {
        foreach ($value as $ke => $val) {
            if ($ke === "country" && $val === "EG") {
                array_push($egyptian_cities, $cities_array[$key]);
            }
        }
    }
    return $egyptian_cities;
}

function get_weather()
{
    if(!empty($_GET)){
        $API = _URL_ . $_GET["id"] ._API_KEY_;
        try {
            $ch = curl_init();
            curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
            curl_setopt($ch, CURLOPT_URL, $API);
            curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
            $data = curl_exec($ch);
            curl_close($ch);
            $data_arr = json_decode($data, true);
            return $data_arr;
        } catch (Exception $e) {
            echo "message : " . $e->getMessage();
        }
    }
}

function UsingGuzzlee(){
    if(!empty($_GET["id"])){
        $client = new Client([]);
        $response = $client -> request('GET', "https://api.openweathermap.org/data/2.5/weather", ['query' => ["id"=> $_GET["id"], "appid" => "b8ed96b363764e4c4233a87c0f88e757"]]);
        $body = $response -> getBody();
        $arr = json_decode($body, true);
        return ($arr);
        return $arr;
    }
}
?>