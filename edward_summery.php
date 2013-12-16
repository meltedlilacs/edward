<!DOCTYPE html>
<html>
	<head>
		<title>EDWARD</title>
		<link rel="shortcut icon" href="https://lh6.googleusercontent.com/nlvWqgABeIvZokLrf-bAGCmt-PGvxq4KPuYzTQ7lRVo=s188-p-no"/>
		<link type="text/css" rel="stylesheet" href="stylesheet.css">
		<style>
			.heading .edward	{
				display: inherit;
				}
		</style>
	</head>
	<body>
		<?php
			include "menu.php";
		?>
		<div class = "content colorscheme1">
			<h2><b>E</b>lectronically <b>D</b>riven <b>W</b>ireless <b>A</b>utonomous <b>R</b>oving <b>D</b>roid</h2>
			<h2>My Maze-Walking Robot</h2>
			<p>This is a robot that I built. With alot of help. It took me close to a year to build, not counting the time I took learning to program and designing in my head. It performs a function, and performs it relatively well. But it is not done. I doubt it will ever be done. This website is a continuation of this mammoth project. This website in itself is a project. <span class="important">EDWARD</span> is a project of projects. Welcome to one such project.</p>
			<p><b>Note:</b> The name of my robot has nothing to do with vampires. I have never read/watched those books/movies and I have no intention to. I like acroynms and I like making up acroynms. I have nothing against vampires in general, just the Twilight variety.</p>
			<iframe width="560" height="315" src="http://www.youtube.com/embed/QmvR7w3AyIg" allowfullscreen></iframe>
			<p>Included below is a brief summery of my process to build the robot. For a more in-depth look at my project, please view my <a href = "essay.php">essay</a>.</p>
			<h2>The Body of The Robot</h2>
			<p>My original idea for the body of the robot was to laser-cut it out of compressed wood board at a new business downtown called <a href="http://www.makersfactory.com">Makers' Factory</a> where one can use all sorts of proto-typing machines, such as a laser-cutter. I designed a slot system to hold the sides together.</p>
			<img alt="Laser Cut Robot Body Design" src="https://lh6.googleusercontent.com/XsSq4iRetPZ5mafKX3us_wqt6GJMK0JEu6pz_GuYok4=w229-h227-p-no"/>
			<p>I was talking to metal artist Ralph Royer about the robot I was going to build and he offered to help me build it at his <a href="http://www.rcrfabrication.com/">metal-working shop</a>! I worked with him at his house for a few nights, creating this 3-D drawing of the body.</p>
			<img alt="3d Moduled Aluminum Robot Body Design" src="https://lh3.googleusercontent.com/TYbeHgcPQdP6tPnTG0VkYkKpQhes5Qve9rAZMD24V9E=s188-p-no"/>
			<p>Ralph used his water-jet to cut the parts of my robot. We bent the parts to create the three pieces of the shell. We created a mounting plate for the brain and one that fit between the motors and the wheels. Then we installed the motors.</p>
			<img alt="Cut Metal Robot Parts" src="https://lh4.googleusercontent.com/GKjrd-CXo4iQUocS05TEF-_XBR8G3VgNcm41CzfYuYs=s207-p-no"/>
			<p>I installed the various electronics and other components into my robot the next day.</p>
			<img alt="My Robot EDWARD" src="https://lh6.googleusercontent.com/nlvWqgABeIvZokLrf-bAGCmt-PGvxq4KPuYzTQ7lRVo=s188-p-no"/>
			<p><span class="important">EDWARD</span>'s brain, the Arduino Uno is a microcontroller (electronics prototyping platform) that is intended for artists, designers and hobbyists and so is easy to use in many applications, such as building robots.</p>
			<img alt="The Arduino Uno" src="http://store.arduino.cc/ww/bmz_cache/1/1dc367f27fa91c37d3cd4bf98f30c032.image.550x550.jpg"/>
			<p><span class="important">EDWARD</span>'s eyes/ears, the ultrasonic ping sensor measures distance using sonar. An ultrasonic pulse is transmitted from the unit and the distance to the nearest object can be determined by measuring the time required for the echo to return.</p>
			<img  alt="The Ultrasonic Ping))) Sensor" src="http://www.parallax.com/sites/default/files/styles/full-size-product/public/28015_0.png?itok=_PnhW7fv"/>
			<p><span class="important">EDWARD</span>'s neck is a type of motor that can be accurately controlled by a source such as a microcontroller. This motor is small, light and strong enough to turn the ping sensor so that it can rotate.</p>
			<img alt="Servo Motor" src="http://store.3drobotics.com/spree/products/251/product/SRV-HTC-HS55-2.jpg?1354322217"/>
			<p><span class="important">EDWARD</span>'s feet/wheels, This of motor is perfect for controlling wheels because both the speed and direction can be easily changed by a microcontroller.</p>
			<img alt="Continous Rotation Servo Motor" src="http://www.parallax.com/sites/default/files/styles/full-size-product/public/900-00025.png?itok=gnB0quJ7"/>
			<p>Installing all these parts resulted in a huge mess (below) and my robot taking his first "steps".</p>
			<img alt="The Guts of EDWARD" src="https://lh6.googleusercontent.com/ez7QTII95_HiaQ4fYBBezcfTkY_g2YQohUhWuvegxgQ=s207-p-no"/>
			<h2>Programming the Robot</h2>
			<img alt="EDWARD Behaviour Flowchart" class="normalsize alignelementright" src="https://lh5.googleusercontent.com/-3q1Td0s9QU0/UgBN35jeZ4I/AAAAAAAAAbk/p7w_slVwvmY/w721-h521-no/flowChart.bmp"/>
			<p>I programmed <span class="important">EDWARD</span> using the language C++. I wrote the majority of the code by myself then worked with Aimen al-Rafi, a computer scientist, to refine it. Over the course of the project he was able to give me valuable insight on methods used to create maze-navigating robots. He also helped me to fix many of the bugs that plagued my program. One problem I encountered was that although one part of code I had written worked on my computer; it crashed on the Arduino. Aimen was able to help me fix that. Once each segment of code worked individually, I tried the main program but nothing happened. After getting help on the Arduino Forum, I discovered my problem. The brain needs time to initialize itself and I was trying to use it before it was ready. To fix this I had to delay the start of the robot. Yet another problem lay behind that. This time I had no idea what was wrong. So I tried running just a little bit of the code at a time, adding more to the program each time it worked. At last I came to the problem: I did not have enough memory in the brain! This was a hard problem to fix. I had to look through thousands of lines of code to find all the places where I could use less memory. Another problem was that the ping sensor often thought there were walls where in fact there was nothing. Aimen helped me discover and then fix this problem as well.</p>
			<p>This is a flow-chart showing my robot's behaviour. &#8594;</p>
			<p>This is a diagram showing the different classes I wrote for the program. A class describes the properties, traits and actions of something such as a robot or a square in a maze. &#8595;</p>
			<table style="clear: both">
				<tr>
					<td colspan = "5">
						<h3>Class Robot</h3>
						<p>Contains classes that manipulate the physical parts of the robot as well as class Map to remember everything the robot has learned. This class also remembers some things itself.</p>
					</td>
				</tr>
				<tr>
					<td colspan = "2">
						<h3>Class Locomotion</h3>
						<p>Coordinates the two wheels of the robot.</p>
					</td>
					<td colspan = "2">
						<h3>Class Motorized Sensor</h3>
						<p>Syncronizes the ping sensor and the motor on which it is mounted.</p>
					</td>
					<td colspan = "1">
						<h3>Class Map</h3>
						<p>Stores information about the maze. It consists of a grid of Class Squares.</p>
					</td>
				</tr>
				<tr>
					<td colspan = "1">
						<h3>Class Motor Right</h3>
						<p>This motor can turn both directions at varying speeds.</p>
					</td>
					<td colspan = "1">
						<h3>Class Motor Left</h3>
						<p>This motor can turn both directions at varying speeds.</p>
					</td>
					<td colspan = "1">
						<h3>Class Ping Sensor</h3>
						<p>Sends out a pulse of sound. The time it takes to bounce off an object is used to infer the distance to the wall.</p>
					</td>
					<td colspan = "1">
						<h3>Class Neck Motor</h3>
						<p>This motor can only turn 180 degrees, but this is enough for the ping sensor to scan on all sides.</p>
					</td>
					<td colspan = "1">
						<h3>Class Square</h3>
						<p>Keeps track of where walls are; if the square has been mapped yet; if an opening has been passed through by the robot; if an opening leads to a dead-end; and where the square was first entered.</p>
					</td>
				</tr>
			</table>
		</div>
	</body>
</html>
