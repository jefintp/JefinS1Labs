<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>welcome</title>
</head>
<body>
    <h1>welcome 
        <?php
            session_start();
            echo $_SESSION['name'];
        ?>
    </h1>

    <br><br><br>
    <h3><a href="login.php">logout</a></h3>
</body>
</html>