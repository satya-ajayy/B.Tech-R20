<?php 
    $connect = mysqli_connect("localhost", "root", "", "test"); 
    $data = json_decode(file_get_contents("php://input"));
    if(count($data) > 0) { 
        $id_received = mysqli_real_escape_string($connect, $data->id_ajax); 
        $name_received = mysqli_real_escape_string($connect, $data->name_ajax);
        $query = "INSERT INTO country(id, name) VALUES ('$id_received', '$name_received')"; 
        if(mysqli_query($connect, $query)) { 
            echo "Data Inserted..."; 
        } 
        else {
            echo 'Error'; 
        }
    } 
?>
