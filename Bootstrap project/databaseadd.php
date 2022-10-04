<?php
session_start();

$Name = $_SESSION["Name"];
$Pass = $_SESSION["Pass"];
echo $Name;
echo $Pass;

$Hazard1 = "0";
$Hazard2 = "0";
$Hazard3 = "0";
$Hazard4 = "0";
$Hazard5 = "0";
$Hazard6 = "0";
$Hazard7 = "0";
$Hazard8 = "0";
$Hazard9 = "0";

$PPE1 = "0";
$PPE2 = "0";
$PPE3 = "0";
$PPE4 = "0";
$PPE5 = "0";
$PPE6 = "0";
$PPE7 = "0";

$Tools1 = "0";
$Tools2 = "0";
$Tools3 = "0";

$Procedures1 = "0";
$Procedures2 = "0";
$Procedures3 = "0";
$Procedures4 = "0";
$Procedures5 = "0";

$Housekeeping1 = "0";
$Housekeeping2 = "0";
$Housekeeping3 = "0";

$Action1 = "0";
$Action2 = "0";

$Positiveobservation = "0";

$Unsafeactandactiontaken = "0";

$Hazardandactiontaken = "0";

if (isset($_POST["Hazard1"])){
$Hazard1 = $_POST["Hazard1"];
echo $Hazard1;
}
if (isset($_POST["Hazard2"])){
$Hazard2 = $_POST["Hazard2"];
}
if (isset($_POST["Hazard3"])){
$Hazard3 = $_POST["Hazard3"];
}
if (isset($_POST["Hazard4"])){
$Hazard4 = $_POST["Hazard4"];
}
if (isset($_POST["Hazard5"])){
$Hazard5 = $_POST["Hazard5"];
}
if (isset($_POST["Hazard6"])){
$Hazard6 = $_POST["Hazard6"];
}
if (isset($_POST["Hazard7"])){
$Hazard7 = $_POST["Hazard7"];
}
if (isset($_POST["Hazard8"])){
$Hazard8 = $_POST["Hazard8"];
}
if (isset($_POST["Hazard9"])){
$Hazard9 = $_POST["Hazard9"];
}

if (isset($_POST["PPE1"])){
$PPE1 = $_POST["PPE1"];
}
if (isset($_POST["PPE2"])){
$PPE2 = $_POST["PPE2"];
}
if (isset($_POST["PPE3"])){
$PPE3 = $_POST["PPE3"];
}
if (isset($_POST["PPE4"])){
$PPE4 = $_POST["PPE4"];
}
if (isset($_POST["PPE5"])){
$PPE5 = $_POST["PPE5"];
}
if (isset($_POST["PPE6"])){
$PPE6 = $_POST["PPE6"];
}
if (isset($_POST["PPE7"])){
$PPE7 = $_POST["PPE7"];
}

if (isset($_POST["Tools1"])){
$Tools1 = $_POST["Tools1"];
}
if (isset($_POST["Tools2"])){
$Tools2 = $_POST["Tools2"];
}
if (isset($_POST["Tools3"])){
$Tools3 = $_POST["Tools3"];
}

if (isset($_POST["Procedures1"])){
$Procedures1 = $_POST["Procedures1"];
}
if (isset($_POST["Procedures2"])){
$Procedures2 = $_POST["Procedures2"];
}
if (isset($_POST["Procedures3"])){
$Procedures3 = $_POST["Procedures3"];
}
if (isset($_POST["Procedures4"])){
$Procedures4 = $_POST["Procedures4"];
}
if (isset($_POST["Procedures5"])){
$Procedures5 = $_POST["Procedures5"];
}

if (isset($_POST["Housekeeping1"])){
$Housekeeping1 = $_POST["Housekeeping1"];
}
if (isset($_POST["Housekeeping2"])){
$Housekeeping2 = $_POST["Housekeeping2"];
}
if (isset($_POST["Housekeeping3"])){
$Housekeeping3 = $_POST["Housekeeping3"];
}

if (isset($_POST["Action1"])){
$Action1 = $_POST["Action1"];
}
if (isset($_POST["Action2"])){
$Action2 = $_POST["Action2"];
}

if (isset($_POST["Positive-observation"])){
$Positiveobservation = $_POST["Positive-observation"];
}

if (isset($_POST["Unsafe-act-and-action-taken"])){
$Unsafeactandactiontaken = $_POST["Unsafe-act-and-action-taken"];
}

if (isset($_POST["Hazard-and-action-taken"])){
$Hazardandactiontaken = $_POST["Hazard-and-action-taken"];
}

$date = date('Y-m-d H:i:s');

include 'Config.php';
$link = new mysqli($Host, $User, $Password, $Db);

if ($link == false){
    print("Ошибка: Невозможно подключиться к MySQL " . mysqli_connect_error());
}else{
	$insertdb = "INSERT INTO survey (Date, Name, Pass, 
		Hazard1, Hazard2, Hazard3, Hazard4, Hazard5, Hazard6, Hazard7, Hazard8, Hazard9,
		PPE1, PPE2, PPE3, PPE4, PPE5, PPE6, PPE7,
		Tools1, Tools2, Tools3,
		Procedures1, Procedures2, Procedures3, Procedures4, Procedures5,
		Housekeeping1, Housekeeping2, Housekeeping3,
		Action1, Action2,
		Positiveobservation, Unsafeactandactiontaken, Hazardandactiontaken) VALUES ('$date', '$Name', '$Pass', 
		'$Hazard1', '$Hazard2', '$Hazard3', '$Hazard4', '$Hazard5', '$Hazard6', '$Hazard7', '$Hazard8', '$Hazard9',
		'$PPE1', '$PPE2', '$PPE3', '$PPE4', '$PPE5', '$PPE6', '$PPE7',
		'$Tools1', '$Tools2', '$Tools3',
		'$Procedures1', '$Procedures2', '$Procedures3', '$Procedures4', '$Procedures5',
		'$Housekeeping1', '$Housekeeping2', '$Housekeeping3',
		'$Action1', '$Action2',
		'$Positiveobservation', '$Unsafeactandactiontaken', '$Hazardandactiontaken')";
	if ($link->query($insertdb)){
		echo "Данные успешно добавлены";
		$link->close();
		header ('Location: index.php');
	} else{
		echo "Ошибка: " . $link->error;
	}
}
?>