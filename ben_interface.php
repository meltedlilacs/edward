<!DOCTYPE html>
<html>
	<head>
		<title>BEN Interface</title>
		<link rel="shortcut icon" href="https://lh5.googleusercontent.com/s0rv438A-AEXVk07QhB6NnCUedCbvdFRCcKgaRK3x_k=s188-p-no"/>
		<link type = "text/css" rel = "stylesheet" href = "stylesheet.css">
		<style>
			.heading .ben	{
				display: inherit;
				}
		</style>
	</head>
	<body>
		<?php
			include "menu.php";
		?>
		<div class = "content colorscheme1">
			<h1>B.E.N. Interface</h1>
			<h1>Page Unavailable</h1>
			<p>This page is under development. In the future it will be an interface to command BEN.</p>
			<form action="ben_interface.php" method="POST">
       	    <input type="hidden" name="action" value="delete"/>
            <?php
				//since this is online, and the sql isn't working anyway, this line which has my password is removed. it is stored in passwordline.txt
                if($mysqli->connect_error)      {
					die('Connect Error (' . $mysqli->connect_errno . ') '. $mysqli->connect_error);
                    }
                if(isset($_REQUEST["action"]))  {
                    switch($_REQUEST["action"])     {
                       	case "insert":
							if(ctype_digit($_REQUEST["loadx"]) and ctype_digit($_REQUEST["loady"]) and ctype_digit($_REQUEST["loadwidth"]) and ctype_digit($_REQUEST["loadheight"]) and ctype_digit($_REQUEST["depositx"]) and ctype_digit($_REQUEST["deposity"]) and ctype_digit($_REQUEST["depositwidth"]) and ctype_digit($_REQUEST["depositheight"]))  {
								$SQL="INSERT INTO goals (loadx, loady, loadwidth, loadheight, depositx, deposity, depositwidth, depositheight) VALUES (";
                                $SQL=$SQL . "'" . $_REQUEST["loadx"] . "',";
                                $SQL=$SQL . "'" . $_REQUEST["loady"] . "',";
                                $SQL=$SQL . "'" . $_REQUEST["loadwidth"] . "',";
                                $SQL=$SQL . "'" . $_REQUEST["loadheight"] . "',";
                                $SQL=$SQL . "'" . $_REQUEST["depositx"] . "',";
                                $SQL=$SQL . "'" . $_REQUEST["deposity"] . "',";
                                $SQL=$SQL . "'" . $_REQUEST["depositwidth"] . "',";
                                $SQL=$SQL . "'" . $_REQUEST["depositheight"] . "'";
                                $SQL=$SQL . ");";
                                if($mysqli->query($SQL)=== FALSE)       {
									printf("Error: Unable to insert data to table " . $mysqli->error);
                                    }
								}
							else	{
								printf("Error: Nothing to insert to table. All fields must contain an integer.");
								}
                            break;
                        case "delete":
							$SQL="DELETE FROM goals WHERE";
                            for($i=0; $i < count($_REQUEST['checkboxes']); $i++)    {
                               	$SQL=$SQL . " idnumber=" . $_REQUEST['checkboxes'][$i] . " or";
                                }
                            $SQL= rtrim($SQL, "or");
                            if ($mysqli->query($SQL)== FALSE) {
                               	printf("Error Unable to delete value " . $mysqli->error);
                               	}
                            break;
                        }
                    }
               	?>
               	<table>
					<thead>
						<tr>
							<th></th>
							<th>Load Zone X</th>
							<th>Load Zone Y</th>
							<th>Load Zone Width</th>
							<th>Load Zone Height</th>
							<th>Deposit Zone X</th>
							<th>Deposit Zone Y</th>
							<th>Deposit Zone Width</th>
							<th>Deposit Zone Height</th>
						</tr>
					</thead>
					<tbody>
						<?php
							$result = $mysqli->query("SELECT * FROM goals");
                           	while($row = $result->fetch_assoc()) {
                               	print "<tr>";
                                print "<td><input type='checkbox' name='checkboxes[]' value='" . $row["idnumber"] . "' /></td>";
                                print "<td>" . $row["loadx"] . "</td>";
                                print "<td>" . $row["loady"] . "</td>";
                                print "<td>" . $row["loadwidth"] . "</td>";
                                print "<td>" . $row["loadheight"] . "</td>";
                                print "<td>" . $row["depositx"] . "</td>";
                                print "<td>" . $row["deposity"] . "</td>";
                                print "<td>" . $row["depositwidth"] . "</td>";
                                print "<td>" . $row["depositheight"] . "</td>";
                                print "</tr>";
								}
                           	$mysqli->close();
                       	?>
					</tbody>
               	</table>
               	<input type="submit" value="delete"/>
            </form>
            <hr/>
			<form action="ben_interface.php" method="POST">
				<table>
					<tr>
						<td><input type="hidden" name="action" value="insert" /></td>
					</tr>
					<tr>
						<td>Load Zone X: </td><td><input name="loadx" /><br/></td>
					</tr>
					<tr>
						<td>Load Zone Y: </td><td><input name="loady" /><br/></td>
					</tr>
					<tr>
						<td>Load Zone Width: </td><td><input name="loadwidth" /><br/></td>
					</tr>
					<tr>
						<td>Load Zone Height: </td><td><input name="loadheight" /><br/></td>
					</tr>
					<tr>
						<td>Deposit Zone X: </td><td><input name="depositx" /><br/></td>
					</tr>
					<tr>
						<td>Deposit Zone Y: </td><td><input name="deposity" /><br/></td>
					</tr>
					<tr>
						<td>Deposit Zone Width: </td><td><input name="depositwidth" /><br/></td>
					</tr>
					<tr>
						<td>Deposit Zone Height: </td><td><input name="depositheight" /><br/></td>
					</tr>
					<tr>
						<td><input type="submit" value="add" /></td>
					</tr>
				</table>
			</form>
		</div>
	</body>
</html>
