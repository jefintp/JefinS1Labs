<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
</head>
<body>
    <H1>Register</H1>

    <form action="" method="POST">
        <label>Name:</label><input type="text" placeholder="Enter your Name" name="name"><br>
        <label>email:</label><input type="email" placeholder="Enter your email" name="email"><br>
        <label>Phone No:</label><input type="number" placeholder="Enter your Phone No" name="phone"><br>
        <label>Password:</label><input type="password" placeholder="Enter Password" name="pass"><br>
        <label>Retype Password:</label><input type="password" placeholder="Retype Password" name="pass1"><br>
        <input type="submit" name="sub">

        <br><br>
        <P>Already a user? <br>Click here to <a href="login.php">login</a></P>
    </form>
</body>
</html>

<?php

    if (isset($_POST['sub']))
    {
        $name=$_POST['name'];
        $email=$_POST['email'];
        $phone=$_POST['phone'];
        $pass=$_POST['pass'];
        $pass1=$_POST['pass1'];

        if($pass!=$pass1){
            die("Password does not match");
        }

        $conn=mysqli_connect('localhost', 'root', '', 'register');
        if (!$conn)
        {
            die("Connection failed: " . mysqli_connect_error());
        }
        else
        {
            $q = "INSERT INTO users (name, email, phone, password) values ('$name','$email','$phone','$pass')";
            $query=mysqli_query($conn,$q);

            if($query)
            {
                echo "Registration Successfull";
            }
            else
            {
                echo "Registration Failed";
            }

        }
        mysqli_close($conn);
    }

    
?>