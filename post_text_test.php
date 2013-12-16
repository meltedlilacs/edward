<?php
	$editor_data = $_POST[ 'editor1' ];
	$file=fopen("custom.php","w");
	fwrite($file,$editor_data);
	fclose($file);
	header('Location: custom.php');
	exit();
?>