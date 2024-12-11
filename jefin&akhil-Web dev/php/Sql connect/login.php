<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
</head>
<body>
    <H1>Login</H1>

    <form action="" method="POST">
        <label>email:</label><input type="email" placeholder="Enter your email" name="email"><br>
        <label>Password:</label><input type="password" placeholder="Enter your password" name="pass"><br>
        <input type="submit" name="sub">

        <br><br>
        <P>Not a user? <br>Click here to <a href="register.php">register</a></P>
    </form>
</body>
</html>

<?php

    if (isset($_POST['sub']))
    {
        $email=$_POST['email'];
        $pass=$_POST['pass'];

        $conn=mysqli_connect('localhost', 'root', '', 'register');
        if (!$conn)
        {
            die("Connection failed: " . mysqli_connect_error());
        }
        else
        {
            $q = "Select name from users where email='$email' and password='$pass';";
            $query=mysqli_query($conn,$q);
            if (mysqli_num_rows($query)==1)
            {
                $data=mysqli_fetch_assoc($query);
            }

            if($query)
            {
                session_start();
                $_SESSION['name']=$data['name'];
                header("Location:welcome.php");
            }
            else
            {
                die("Invalid credentials!");
            }

        }
        mysqli_close($conn);
    }


?>