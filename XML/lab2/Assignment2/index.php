<?php

session_start();

$xmlFilePath = "employee.xml";
$fileContent = file_get_contents($xmlFilePath);
$xmlDoc = new DOMDocument();
$xmlDoc->preserveWhiteSpace = false;
$xmlDoc->loadXML($fileContent);

$xpath = new DOMXPath($xmlDoc);
$NoOfElements = $xmlDoc->getElementsByTagName("employee")->length;

$index = isset($_SESSION["index"]) ? $_SESSION["index"] : 0;

$employees = $xmlDoc->documentElement;
$employee = @$employees->childNodes[$index];
$id = $employee->getAttribute('id');
$name = @$employee->childNodes[0]->nodeValue;
$email = @$employee->childNodes[1]->nodeValue;
$phone = @$employee->childNodes[2]->nodeValue;
$address = @$employee->childNodes[3]->nodeValue;

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $action = $_POST["action"];
    switch ($action) {
        case "insert":
            $id = uniqid();
            $employees = simplexml_load_file($xmlFilePath);
            $employee = $employees->addChild('employee');
            $employee->addAttribute("id", $id);
            $employee->addChild("name", $_POST['name']);
            $employee->addChild("email", $_POST['email']);
            $employee->addChild("phone", $_POST['phone']);
            $employee->addChild("address", $_POST['address']);
            $employees->asXML($xmlFilePath);
            echo "New employee created successfully!";
            $index = $NoOfElements;
            break;

        case "update":
            $xpath = new DOMXPath($xmlDoc);
            $employee = $xpath->query("/employees/employee[@id='$id']")->item(0);

            if ($employee !== null) {
                $employee->getElementsByTagName("name")->item(0)->nodeValue = $_POST['name'];
                $employee->getElementsByTagName("email")->item(0)->nodeValue = $_POST['email'];
                $employee->getElementsByTagName("phone")->item(0)->nodeValue = $_POST['phone'];
                $employee->getElementsByTagName("address")->item(0)->nodeValue = $_POST['address'];
                $xmlDoc->save($xmlFilePath);
                    echo "Employee updated successfully!";
                } else {
                    echo "Employee not found!";
                }
            break;
        
        case "delete":
            $employee = $xpath->query("/employees/employee[@id='$id']")->item(0);
            if ($employee !== null) {
                $employee->parentNode->removeChild($employee);
                $xmlDoc->save($xmlFilePath);
                $NoOfElements = $xmlDoc->getElementsByTagName("employee")->length;
                if ($index >= $NoOfElements) {
                    $_SESSION["index"] = $NoOfElements - 1;
                }
                echo "Employee deleted successfully!";
            } else {
                echo "Employee not found!";
            }
            break;

        case "next":
            $_SESSION["index"] += 1;
            if ($_SESSION["index"] >= $NoOfElements) {
                $_SESSION["index"] = 0;
            }
            break;

        case "previous":
            $_SESSION["index"] -= 1;
            if ($_SESSION["index"] < 0) {
                $_SESSION["index"] = $NoOfElements - 1;
            }
            break;
    }
}

require_once("views/form.php");
?>