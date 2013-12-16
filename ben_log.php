<!DOCTYPE html>
<html>
	<head>
		<title>BEN Logfile</title>
		<link rel="shortcut icon" href="https://lh5.googleusercontent.com/s0rv438A-AEXVk07QhB6NnCUedCbvdFRCcKgaRK3x_k=s188-p-no"/>
		<link type = "text/css" rel = "stylesheet" href = "stylesheet.css">
		<style>
			.heading .ben	{
				display: inherit;
				}
		</style>
		<meta http-equiv="refresh" content="5">
	</head>
	<body>
		<?php
			include "menu.php";
		?>
		<div class = "content colorscheme1">
		<h1>B.E.N. Logfile</h1>
		<h1>Page Unavailable</h1>
			<p>This page is under development. In the future, it will be a log of what BEN has done recently. This information will mainly be here for debugging purposes.</p>
			<?php
				//since this is online, and the sql isn't working anyway, this line which has my password is removed. it is stored in passwordline.txt
				if($mysqli->connect_error)      {
					die('Connect Error (' . $mysqli->connect_errno . ') '. $mysqli->connect_error);
					}
			?>
			<table>
				<thead>
					<tr>
						<th>Time</th>
						<th>Process</th>
						<th>Action</th>
					</tr>
				</thead>
				<tbody>
					<?php
						$result = $mysqli->query("SELECT * FROM log");
						while($row = $result->fetch_assoc()) {
							print "<tr>";
							print "<td>" . $row["time"] . "</td>";
							print "<td>" . $row["process"] . "</td>";
							print "<td>" . $row["action"] . "</td>";
							print "</tr>";
							}
						$mysqli->close();
					?>
				</tbody>
			</table>
   		</div>
	</body>
</html>
