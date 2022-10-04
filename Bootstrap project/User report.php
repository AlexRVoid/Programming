<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="twitter:card" content="summary_large_image"/>
    <meta name="twitter:title" content="Страница входа">
    <meta name="viewport" content="width=device-width, initial-scale=1, minimum-scale=1">
    <link rel="shortcut icon" href="assets/images/logo.png" type="image/x-icon">
    <meta name="description" content="login page">
    <title>User report</title>
    <link rel="stylesheet" href="assets/bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="assets/bootstrap/css/bootstrap-grid.min.css">
    <link rel="stylesheet" href="assets/bootstrap/css/bootstrap-reboot.min.css">
    <link rel="preload" href="https://fonts.googleapis.com/css2?family=Jost:ital,wght@0,400;0,700;1,400;1,700&display=swap&display=swap" as="style" onload="this.onload=null;this.rel='stylesheet'">
    <noscript><link rel="stylesheet" href=" https://fonts.googleapis.com/css2?family=Jost:ital,wght@0,400;0,700;1,400;1,700&display=swap&display=swap">
    </noscript>
</head>
<body>
		
	<div class="container">
			
		<nav class="navbar navbar-light bg-light">
		<a class="navbar-brand" href="https://www.romona.ru">
			<img src="assets/img/logo.png" class="d-inline-block align-top">
		</a>
		<div>
			<ul class = "nav nav-tabs justify-content-end">
				<li class = "nav-item">
					<a class="nav-link" aria-current="page" href="Report.php">
						Назад
					</a>
				</li>
			</ul>
		</div>
		</nav>


<?php
if(isset($_GET["id"]))
{
	include 'Config.php';
    $link = new mysqli($Host, $User, $Password, $Db);
    if($link->connect_error){
        die("Ошибка: " . $conn->connect_error);
    }
    $userid = $link->real_escape_string($_GET["id"]);
    $sql = "SELECT * FROM survey WHERE Pass = '$userid'";
    if($result = $link->query($sql)){
        if($result->num_rows > 0){
            foreach($result as $row){
                $username = $row["Name"];
                $userage = $row["Pass"];
				$date = $row["Date"];
				
				$Hazard1 = $row["Hazard1"];
				$Hazard2 = $row["Hazard2"];
				$Hazard3 = $row["Hazard3"];
				$Hazard4 = $row["Hazard4"];
				$Hazard5 = $row["Hazard5"];
				$Hazard6 = $row["Hazard6"];
				$Hazard7 = $row["Hazard7"];
				$Hazard8 = $row["Hazard8"];
				$Hazard9 = $row["Hazard9"];

				$PPE1 = $row["PPE1"];
				$PPE2 = $row["PPE2"];
				$PPE3 = $row["PPE3"];
				$PPE4 = $row["PPE4"];
				$PPE5 = $row["PPE5"];
				$PPE6 = $row["PPE6"];
				$PPE7 = $row["PPE7"];

				$Tools1 = $row["Tools1"];
				$Tools2 = $row["Tools2"];
				$Tools3 = $row["Tools3"];

				$Procedures1 = $row["Procedures1"];
				$Procedures2 = $row["Procedures2"];
				$Procedures3 = $row["Procedures3"];
				$Procedures4 = $row["Procedures4"];
				$Procedures5 = $row["Procedures5"];

				$Housekeeping1 = $row["Housekeeping1"];
				$Housekeeping2 = $row["Housekeeping2"];
				$Housekeeping3 = $row["Housekeeping3"];

				$Action1 = $row["Action1"];
				$Action2 = $row["Action2"];

				$Positiveobservation = $row["Positiveobservation"];

				$Unsafeactandactiontaken = $row["Unsafeactandactiontaken"];

				$Hazardandactiontaken = $row["Hazardandactiontaken"];
                echo "<div>
                        <h3>Информация о пользователе</h3>
                        <p>Имя: $username</p>
                        <p>ID: $userage</p>
						<p>Date: $date</p>
						<h4>Результат опроса пользователя:</h4>
                    </div>";
				echo "<h5>Опасный фактор\Hazard:</h5>";
					if ($Hazard1 == 1){
						echo "<p>Падение, поскальзывание, спотыкание, движение по лестнице / Slip, trip, fall</p>";
					}
					if ($Hazard2 == 1){
						echo "<p>Захват, затягивание, выброс предм., удар / Drawing in, trappping, ejection, impact </p>";
					}
					if ($Hazard3 == 1){
						echo "<p>Температура, освещение, шум, вибрация, пыль / Temperature, lighting, noise, vibration, dust</p>";
					}
					if ($Hazard4 == 1){
						echo "<p>Бактерии, вирусы, животные, расстения / Bacteria, viruses, animals, plants</p>";
					}
					if ($Hazard5 == 1){
						echo "<p>Опасные вещества, химикаты / Hazard substraction</p>";
					}
					if ($Hazard6 == 1){
						echo "<p>Электрический ток / Electricity</p>";
					}
					if ($Hazard7 == 1){
						echo "<p>Эргономика, усталость / Ergonomics</p>";
					}
					if ($Hazard8 == 1){
						echo "<p>Пожар / Fire</p>";
					}
					if ($Hazard9 == 1 || $Hazard1 == 0 && $Hazard2 == 0 && $Hazard3 == 0 && $Hazard4 == 0 && $Hazard5 == 0 && $Hazard6 == 0 && $Hazard7 == 0 && $Hazard8 == 0){
						echo "<p>Всё безопасно / All safe</p>";
					}
				
				echo "<h5>Средства индивидуальной защиты / PPE:</h5>";
					if ($PPE1 == 1){
						echo "<p>Голова / Head</p>";
					}
					if ($PPE2 == 1){
						echo "<p>Глаза, лицо / Eyes, face</p>";
					}
					if ($PPE3 == 1){
						echo "<p>Органы слуха / Ears</p>";
					}
					if ($PPE4 == 1){
						echo "<p>Кисть, руки, пальцы / Hands, arms, fingers</p>";
					}
					if ($PPE5 == 1){
						echo "<p>Тело, защита от падения (в воду) / Body, fall protection, PFD</p>";
					}
					if ($PPE6 == 1){
						echo "<p>Ноги / Feet</p>";
					}
					if ($PPE7 == 1 || $PPE1 == 0 && $PPE2 == 0 && $PPE3 == 0 && $PPE4 == 0 && $PPE5 == 0 && $PPE6 == 0){
						echo "<p>Всё безопасно / All safe</p>";
					}
				
				echo "<h5>Инструменты и оборудование / Tools and eqipment:</h5>";
					if ($Tools1 == 1){
						echo "<p>Используется неправильно/небезопасно / Used incorrectly/unsafely</p>";
					}
					if ($Tools2 == 1){
						echo "<p>В ненадлежащем состоянии или отсутствуют / Unsafe condition or absent</p>";
					}
					if ($Tools3 == 1 || $Tools1 == 0 && $Tools2 == 0 ){
						echo "<p>Всё безопасно / All safe</p>";
					}
				
				echo "<h5>Процедуры /  Procedures:</h5>";
					if ($Procedures1 == 1){
						echo "<p>Нет в наличии / Absent</p>";
					}
					if ($Procedures2 == 1){
						echo "<p>Неправильные / Incorrect</p>";
					}
					if ($Procedures3 == 1){
						echo "<p>Неизвестны / Unknown</p>";
					}
					if ($Procedures4 == 1){
						echo "<p>Не соблюдаются / Not followed</p>";
					}
					if ($Procedures5 == 1 || $Procedures1 == 0 && $Procedures2 == 0 && $Procedures3 == 0 && $Procedures4 == 0){
						echo "<p>Всё безопасно / All safe</p>";
					}
				
				echo "<h5>Содержание / Housekeeping:</h5>";
					if ($Housekeeping1 == 1){
						echo "<p>Беспорядок / Untidiness</p>";
					}
					if ($Housekeeping2 == 1){
						echo "<p>Загрязнение окружающей среды / Environmental pollution</p>";
					}
					if ($Housekeeping3 == 1 || $Housekeeping2 == 0 && $Housekeeping1 == 0){
						echo "<p>Всё безопасно / All safe</p>";
					}
				
				echo "<h5>Мои действия / Action taken:</h5>";
					if ($Action1 == 1){
						echo "<p>Обсудил с исполнителем / Discussed with performer</p>";
					}if ($Action2 == 1){
						echo "<p>Исправил опасное условие / Corrected unsafe condition</p>";
					}
					}if ($Action1 == 0 && $Action2 == 0){
						echo "<p>-</p>";
					}
				
				echo "<h5>Положительное наблюдение / Positive observation:</h5>";
					if ($Positiveobservation != ""){
						echo "<p>".$Positiveobservation."</p>";
					}else echo "<p>-</p>";
				
				echo "<h5>Опасное действие и предпринятые меры / Unsafe act and action taken:</h5>";
					if ($Unsafeactandactiontaken != ""){
						echo "<p>".$Unsafeactandactiontaken."</p>";
					}else echo "<p>-</p>";
				
				echo "<h5>Опасный фактор и предпринятые меры / Hazard and action taken:</h5>";
					if ($Hazardandactiontaken != ""){
						echo "<p>".$Hazardandactiontaken."</p>";
					}else echo "<p>-</p>";
            }
        }
        else{
            echo "<div>Пользователь не найден</div>";
        }
        $result->free();
    } else{
        echo "Ошибка: " . $link->error;
    }
    $link->close();
?>