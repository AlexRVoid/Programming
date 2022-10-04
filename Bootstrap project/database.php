<?php
session_start();
$User = $_POST["User"];
$Pass = $_POST["Password"];
echo $User;
echo $Pass;
$_SESSION["Name"] = $User;
$_SESSION["Pass"] = $Pass;
include 'Config.php';
$link = new mysqli($Host, $User, $Password, $Db);

if ($link == false){
    print("Ошибка: Невозможно подключиться к MySQL " . mysqli_connect_error());
}
else {
    print("Соединение установлено успешно");
	$table = "SELECT * FROM survey";
	if ($link->query($table)){
        echo "Таблица уже создана";
		$link->close();
		header ('Location: Survey.php');
	}else {
		$sql = "CREATE TABLE survey (Date DATETIME, Name VARCHAR(30), Pass VARCHAR(30),
		Hazard1 BOOL, Hazard2 BOOL, Hazard3 BOOL, Hazard4 BOOL, Hazard5 BOOL, Hazard6 BOOL, Hazard7 BOOL, Hazard8 BOOL, Hazard9 BOOL,
		PPE1 BOOL, PPE2 BOOL, PPE3 BOOL, PPE4 BOOL, PPE5 BOOL, PPE6 BOOL, PPE7 BOOL,
		Tools1 BOOL, Tools2 BOOL, Tools3 BOOL,
		Procedures1 BOOL, Procedures2 BOOL, Procedures3 BOOL, Procedures4 BOOL, Procedures5 BOOL,
		Housekeeping1 BOOL, Housekeeping2 BOOL, Housekeeping3 BOOL,
		Action1 BOOL, Action2 BOOL,
		Positiveobservation TEXT, Unsafeactandactiontaken TEXT, Hazardandactiontaken TEXT);";
		if($link->query($sql)){
			echo "Таблица Users успешно создана";
			$link->close();
			header ('Location: Survey.php');
		} else{
			echo "Ошибка: " . $link->error;
		}
	}
	
}
?>