<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="twitter:card" content="summary_large_image"/>
    <meta name="twitter:title" content="Страница входа">
    <meta name="viewport" content="width=device-width, initial-scale=1, minimum-scale=1">
    <link rel="shortcut icon" href="assets/images/logo.png" type="image/x-icon">
    <meta name="description" content="login page">
    <title>login page</title>
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
		<a class="navbar-brand" href="#">
			<img src="assets/img/logo.png" class="d-inline-block align-top">
		</a>
		</nav>
		
        <form>
            <div class="form-group">
              <label for="Login-Input">Имя</label>
              <input type="text" class="form-control" id="Login-Input" placeholder="Имя">
            </div>
            <div class="form-group">
              <label for="Password-Input">Пароль</label>
              <input type="password" class="form-control" id="Password-Input" placeholder="Пароль">
            </div>
            <button type="submit" class="btn btn-primary" href = "Survey.php">Submit</button>
          </form>
		  
		  </div>
    </body>