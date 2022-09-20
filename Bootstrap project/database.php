<?php
	error_reporting(0);
	if ($_POST['User'] && $_POST ['Password']){
		$user = trim($_POST['login']);
		mysqli_report(MYSQLI_REPORT_OFF);
		$mysqli = new mysqli("localhost", 'User', 'Password', "my_db");
		if ($mysqli->connect_errno) {
			throw new RuntimeException('ошибка соединения mysqli: ' . $mysqli->connect_error);
		}else header('Location: Survey.php');
	}else header('Location: index.php');

?>