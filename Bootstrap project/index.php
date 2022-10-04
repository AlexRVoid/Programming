<html>
<head>
<meta charset="UTF-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<meta name="twitter:card" content="summary_large_image"/>
<meta name="twitter:title" content="Страница входа">
<meta name="viewport" content="width=device-width, initial-scale=1, minimum-scale=1">
<link rel="shortcut icon" href="assets/images/logo.png" type="image/x-icon">
<meta name="description" content="login page">
<title>Login page</title>
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
					<a class="nav-link active" aria-current="page" href="#">
						Главная
					</a>
				</li>
				<li class = "nav-item">
					<a class="nav-link" href="Report login.php">
						Отчёт
					</a>

				</li>
				
			</ul>
		</div>
		</nav>
		
       
		<form action = "database.php" method="post">
           
			<div class="form-group">
			<label for="User">Имя</label>
			<input type="text" class="form-control" name="User" placeholder="Имя">
			</div>
			
			<div class="form-group">
			<label for="Password">Пароль</label>
			<input type="password" class="form-control" name="Password" placeholder="Пароль">
			</div>
		
			<button type="submit" class="btn btn-primary">Submit</button>
			
		</form>
		
	</div>
	
</body>
</html>	