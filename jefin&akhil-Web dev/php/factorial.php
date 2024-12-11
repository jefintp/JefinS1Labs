<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Factorial</title>
</head>
<body>
    <H1>Factorial</H1>

    <form action="" method="POST">
        <label>Enter the number:</label><input type="number" placeholder="to find factorial" name="number"><br>
        <input type="submit" name="sub">

        <br><br>
    </form>
</body>
</html>

<?php

    if (isset($_POST['sub']))
    {
        $number=$_POST['number'];

        function factorial($n)
        {
            if ($n == 0)
                return 1;

            else
                return $n * factorial($n-1);
        }


        echo "Factorial of $number is ".factorial($number);
    }
?>