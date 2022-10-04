<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="twitter:card" content="summary_large_image"/>
    <meta name="twitter:title" content="Страница входа">
    <meta name="viewport" content="width=device-width, initial-scale=1, minimum-scale=1">
    <link rel="shortcut icon" href="assets/images/logo.png" type="image/x-icon">
    <meta name="description" content="login page">
    <title>List of reports</title>
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
					<a class="nav-link" aria-current="page" href="index.php">
						На главную
					</a>
				</li>
			</ul>
		</div>
		</nav>
		
		
		<?php
		session_start();
	
			$link = new mysqli("localhost", "root", "", "my_db");
			
			echo "<h4>Список опрошенных:</h4>";
			$sql = "SELECT * FROM survey";
			if($result = $link->query($sql)){
		?>
		<table cellpadding = "5">
			<thead>
				<tr>
					<th>ID</th>
					<th>Name</th>
				</tr>
			</thead>
		<tbody>
			<?php foreach ($result as $row): ?>
			<tr>
				<td><?php echo $row['Pass']; ?></td>
				<td><?php echo $row['Name']; ?></td>
				<?php echo "<td><a href='User report.php?id=" . $row["Pass"] . "'>Выдать отчёт</a></td>"; ?>
				
			</tr>
			<?php endforeach; ?>    
		</tbody>
	</table>
	
			<?php
			} else{
				echo "Ошибка: " . $link->error;
			}
		
		?>
		
		
		
	</div>	
</body>
</html>		