<!DOCTYPE html>
<html>
	<head>
		<title>BEN</title>
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
			<h1><b>B</b>right <b>E</b>nough to <b>N</b>avigate</h1>
			<p>This robot will be a continuation and an improvement on my first robot, <a href = "edward_summery.php">EDWARD</a>.</p>
			<p>BEN's goal will be to move objects from zones to zones. He will also constantly record his surroundings into a map of 1" squares. I think I will eventually use the <a href = "http://en.wikipedia.org/wiki/A*_search_algorithm">A* Search Algorithm</a> to route find. BEN will have a remote control mode of operation in addition to autonomous. However, while in r/c mode, he will still never run into walls, and will update his position and map for when he is switched back to autonomous. The robot can be interacted with over this <a href = "ben_interface.php">website</a> which sends information to the PI.</p>
			<h2>Hardware:</h2>
			<table>
				<thead>
				</thead>
				<tbody>
					<tr>
						<td><img alt="Raspberry Pi" src="http://images.bit-tech.net/content_images/2013/03/raspberry-pi-case-competition-update/pi1l.jpg"/></td>
						<td><p class="aligntextleft">Raspberry PI for multi-threaded Arduino command and CPU x1</p></td>
						<td><img alt="Arduino on a breadboard" src="http://cdn.instructables.com/FGD/JDV8/H3Z3UM6N/FGDJDV8H3Z3UM6N.SMALL.jpg"/></td>
						<td><p class="aligntextleft">Breadboarded Arduino Uno for hardware control x2</p></td>
					</tr>
					<tr>
						<td><img alt="Continous Rotation Servo Motor" src="http://www.parallax.com/sites/default/files/styles/full-size-product/public/900-00025.png?itok=gnB0quJ7"/></td>
						<td><p class="aligntextleft">Continuous rotation servos for locomotion x3</p></td>
						<td><img alt="Omnidirectional Wheel" src="http://www.hanitech.co.kr/image_robot/robot_parts/R76-4CM-ROLLER.jpg"/></td>
						<td><p class="aligntextleft">Omnidirectional wheels for locomotion x3</p></td>
					</tr>
					<tr>
						<td><img alt="Servo Motor" src="http://store.3drobotics.com/spree/products/251/product/SRV-HTC-HS55-2.jpg?1354322217"/></td>
						<td><p class="aligntextleft">Servos for arm x4</p></td>
						<td><img alt="Ultrasonic Ping))) Sensor" src="http://www.parallax.com/sites/default/files/styles/full-size-product/public/28015_0.png?itok=_PnhW7fv"/></td>
						<td><p class="aligntextleft">Ultrasonic sensors for mapping x9</p></td>
					</tr>
					<tr>
						<td><img alt="Webcam" src="https://encrypted-tbn1.gstatic.com/images?q=tbn:ANd9GcRmZh5TIF3xmzqNAsQ5N7BoNEyXG4WLWhCf_2gYy2eg2p50BPPc"/></td>
						<td><p class="aligntextleft">Webcam for veiwer's pleasure x1</p></td>
					</tr>
				</tbody>
			</table>
			<h2>Software:</h2>
			<p>Software can be divided into three parts: the interface that the user interacts with, the main decision making programs on the pi and the hardware commanding programs on the Arduinos and the Pi.</p>
			<p>There will be two Arduino programs, one on each microcontroller. The first program takes x/y/z coordinates for the arm and moves it there. The other Arduino takes the movement directions for the wheels and follows them. The Pi also takes readings from every sensor not blocked by the arm and records the information in the robot's map.</p>
			<p>The interface will display the video from the webcam and it will show a graphical map of the robot's known surroundings. It will have controls for when the robot is in r/c mode and give the user an easy way to edit the robots list of goals. The interface and this entire website is a LAMP(Linux Apache MySQL PHP) Server running on the Raspbery Pi.</p>
			<p>This is a mockup I made of what the interface may look like. To the right is the live video feed from the robot and to the left is the map of what it knows. The blue dot is the robot, and it is trying to move objects from the red zone to the green zone. There are a few option buttons in the middle.</p>
			<img alt="Interface Mockup" class = "normalwidth" src = "https://lh5.googleusercontent.com/-3ujb1KeD--I/UgBqsQMWgiI/AAAAAAAAAdw/K4lYi-9Q-Lk/w782-h265-no/interfaceMockup.bmp"/>
			<p>Switching to R/C mode will superimpose controls on the robot's view to control it.</p>
			<img alt="Interface Mockup" class = "normalwidth" src = "https://lh4.googleusercontent.com/-yFSXUlOVvKw/UgBqsZQhZwI/AAAAAAAAAdo/IptacWvtTHE/w782-h265-no/interfaceRC.bmp"/>
			<p>This is what you would get if you pressed the add goal icon. A mouse is drawing a new pickup area on the map, and the exact x/y coordinates can be adjusted by typing in the buttons.</p>
			<img alt="Interface Mockup" class = "normalwidth" src = "https://lh5.googleusercontent.com/-gp4a8OHRh_E/UgBqsFJnuMI/AAAAAAAAAdk/0AcoYXhMekk/w782-h265-no/interfaceAuto.bmp"/>
			<p>The main proccessing will probably be all C++. It will be composed of many smaller programs, since i am taking advantage of the Pi's ability to be muti-threaded. One program will update the map with readings from the sensors. Another will identify all moveable objects for the robot to pick up. Another will find the best path to the robot's goal. Another program will tell the robot its next immediate movement. That is by no means a complete list of the different programs, and I will work on expanding it.</p>
		</div>
	</body>
</html>
