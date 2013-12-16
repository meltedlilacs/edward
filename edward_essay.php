<!DOCTYPE html>
<html>
	<head>
		<title>EDWARD Essay</title>
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
		<div class="content colorscheme1">
			<h1>E.D.W.A.R.D. Essay</h1>
			<h2>Robotics</h2>
			<p>Did I build a robot? That depends on the definition of the word. The word robot was coined by the brother of Czech playwright <a href = "http://en.wikipedia.org/wiki/Karel_%C4%8Capek">Karel Capek</a> in 1920. It is derived from the Czech word "robota", which means servitude. It first appeared in Capek's play <a href = "http://en.wikipedia.org/wiki/R.U.R._(Rossum%27s_Universal_Robots)">Rossum's Universal Robots</a> (R.U.R.). In his play, robots were not made out of metal. They were of flesh and blood, more similar to a genetic clone than our idea of a robot. Capek's robots were identical to humans, but my robot is a little square box on wheels.  However, my creation IS a robot according to the current definition of the word: a machine capable of carrying out a complex series of actions automatically(according to Google).</p>
			<img class="alignelementleft" alt="Elsie the Turtle Robot" src = "http://www.extremenxt.com/elsie.jpg"/>
			<p>Robots have come a long way since R.U.R.  A series of amazing robots, called tortoise robots (example below), were developed in 1948 by the neurophysiologist <a href = "http://en.wikipedia.org/wiki/William_Grey_Walter">William Grey Walter</a>. Contrary to other roboticists of the time, Walter believed that complex behavior could be derived from a few, simple analog components. (Unlike binaray-on or off-components, analog components can vary voltages or positions.) Walter was quite successful and produced several <em>Machina Speculatrix</em>, as he called them. These were three-wheeled and had clear plastic shells enclosing their "brains" (vacuum tubes) that were sensitive to being bumped. Utilizing a rotating light sensor, they would seek light while shying away from brightness. However, as their batteries drained, their sensitivity diminished, allowing them to be attracted to their bright charging stations. Walter experimented with additional behaviors with varied success. Two of his most famous robots were named Elmer and Elsie. (My robot's name is homage to this genius of behavior and his creations.)</p>
			<p>Another important robot is <a href="http://en.wikipedia.org/wiki/Shakey_the_robot">Shakey</a> (pictured below).  So named because it would violently shake whenever it moved, Shakey was able to complete complicated goals such as pushing a block off a table. Built 1966-1972, it was able to accomplish these feats because it had an internal list of possible actions it could take. These were actions such as go to (location), go through (doorway), block (doorway) and unblock (doorway). Obviously, Shakey could only perform these actions on objects of which it  was aware. Therefore, whenever it could see an unknown area, Shakey would remember it using its video camera. It was able to detect objects using a method called the <a href = "http://en.wikipedia.org/wiki/Hough_Transform">Hough Transform</a>, which could find corners and edges. Shakey was the test subject of a new algorithm for navigation, called the <a href = "http://en.wikipedia.org/wiki/A*_search_algorithm">A* Search Algorithm</a> and also of a system to solve problems, called <a href = "http://en.wikipedia.org/wiki/STRIPS">STRIPS</a> (Stanford Research Institute Problem Solver). STRIPS used a database of sub-routines and previous actions to help Shakey complete its task. Another remarkable aspect of Shakey was that it was able to adapt to unforeseen changes in its environment, an ability my robot does not share. My robot is very similar to Shakey in that it uses an algorithm, albeit a very primitive one, to navigate through a field of physical objects to get to a goal.</p>
			<img class="alignelementright normalheight" alt="Shakey the Robot" src="http://upload.wikimedia.org/wikipedia/commons/0/0c/SRI_Shakey_with_callouts.jpg"/>
			<p>Much of robotics revolves around the development and pursuit of <span class="important">A</span>rtificial <span class="important">I</span>ntelligence (<span class="important">AI</span>). <span class="important">AI</span> is the state wherein a robot or computer can learn and make decisions based on its newly acquired knowledge. The problem of <span class="important">AI</span> is that it must define its own surroundings completely and in terms that it can understand. In effect, one must create a technological "baby".  If an <span class="important">AI</span> measured its world in cubic inches, for example, without knowing what a cubic inch is, then its measurements would be meaningless. The necessity of defining its own world is one major problem preventing the creation of <span class="important">AI</span>. In order for <span class="important">AI</span> to exist, it has to be independent in creating all its definitions. I do not think we currently have the means to tell something to think without telling it how to think. However, many robots, such as Shakey, have developed remarkable problem-solving techniques. Shakey does not exhibit "true" <span class="important">AI</span> because, although it comes up with its own solutions, its solutions are based, in part, on information provided by the programmers. The definition of block, for example, is encoded into its brain so, although it can manipulate the block, all it thinks it is doing is moving in relation to a specific set of x/y coordinates.</p>
			<p>To certify that a machine has <span class="important">AI</span>, the <a href="http://en.wikipedia.org/wiki/Turing_test">Turing Test</a> was proposed by Alan Turing in 1950 in a paper on the subject of "Computing Machinery and Intelligence". The idea was that if a (human) judge could not tell the difference between a machine and a human via communication through a text interface, then the machine passed the Turing Test. Although a machine could have <span class="important">AI</span> without passing the Turing Test, a machine that passed the Turing Test would most likely use something closely resembling <span class="important">AI</span> and could be used as a basis for the creation of <span class="important">AI</span> intended for other tasks.</p>
			<img class="alignelementleft" alt="Makey the Robot" src="http://www.jameco.com/Jameco/content/makeyrobot.jpg"/>
			<p>In 2009, for my 11th birthday I received a subscription to <a href = "http://makezine.com/">Make: Magazine</a>. Make: is a magazine about people who make interesting, often technological, things and articles on how to do it yourself. The first issue I received happened to be on the topic of robots and one of the projects was how to build the robot shown below. I had always wanted to build a robot, but I did not have the skills, resources or time to follow these directions. But the seed of inspiration was planted in my head.</p>
			<p>Two years later, in 6th grade, I got an edition of Make: that was about microcontrollers. A microcontroller is a small computer with a very limited memory that is able to interface with the physical world via pins. A pin is a small piece of metal to which connections can easily be made. There are two kinds: digital, which can only be on or off, or analog, in which the voltage can be varied in strength. Make: recommended one new microcontroller called the <a href = "http://arduino.cc/">Arduino</a>. The Arduino was originally designed for use by artists and designers and so was very easy to use (or so I read). Then I remembered! That robot that I had wanted to build all those years back also used the Arduino. I immediately decided I was going to learn how to program an Arduino. The Arduino runs on <a href = "http://en.wikipedia.org/wiki/C_programming_language">C</a>/<a href = "http://en.wikipedia.org/wiki/C%2B%2B">C++</a>, two related and respectable programming languages.</p>
			<div class="aside colorscheme3">
				<h3>Terminology</h3>
				<ul>
					<li><p><b>Variable:</b> a space in memory that can store a number, a letter, or many other things</p></li>
					<li><p><b>Function:</b> a piece of code that can be used multiple times</p></li>
					<li><p><b>Class:</b> self- contained code that describes the properties, traits and actions of a thing</p></li>
					<li><p><b>Method:</b> a function in a class</p></li>
					<li><p><b>Object/Instance:</b> whereas a class is an idea, an object is an instance of that idea. For example, an object of class box could be a box in my garage. One can create multiple instances of an object (very few people have only one box in their garage) and each box can have a different size, shape and have different things in it</p></li>
				</ul>
			</div>
			<p>I had begun to teach myself a simple programming language called <a href = "http://www.python.org/">Python</a>. Python is a very good beginning language because it can almost be read as if it were English, but as I was quickly discovering, it had some constraints. For one thing, although it had classes (see definition at right); it was not a truly object-oriented programming language. Object-oriented is a style of programming where the focus is on objects and classes. (See definitions at right.)</p>
			<p>Once I decided to build a robot, I started teaching myself C++. I checked out <a href = "http://www.cs.uah.edu/~rcoleman/Common/C_Reference/C++%20For%20DUMMIES.pdf">C++ For Dummies</a> from the library and got started. During the summer of 2012, I did very little except program and by September, I had a good basic knowledge of how to program in C++. I then acquired the <a href = "http://www.makershed.com/Getting_Started_with_Arduino_Kit_V3_0_p/msgsa.htm">Getting Started with Arduino kit</a> and instruction book and within a few months I knew how to apply my C++ knowledge to the Arduino and had completed some simple projects.</p>
			<p>Towards the end of seventh grade, I began to think what I was going to do for my eighth grade project. Then it struck me! I had wanted to build a robot. Here was the perfect opportunity! At first I was thinking of building a robot that would be able to mimic the behavior of a creature (perhaps a canine) in the wild. It would scout for food, water and search for shelter. I would have also looked into interaction between two robots.</p>
			<p>As I thought more about it, I decided that I would focus on the obstacle avoidance part. Eventually I became so fixated on that portion that I decided to drop the animal mimicking behavior and create instead a maze-walking robot. At first my plan was to have it traverse from one end of an area to the other, going around obstacles as it went. As if this was not hard enough already, I decided instead that it should be able to navigate between any two given coordinates.</p>
			<p>The rest of the summer I spent deciding exactly what it would do, how it would work, and ordering parts. Using the parts list from the robot that initially inspired me as a guide; I purchased most of the parts by the end of June. But I was stuck on the wireless communication. I had two options: cheap radio frequency (RF) communicators or the more expensive <a href = "http://www.digi.com/xbee/">XBEE</a> wireless modules. At first the RF option looked like the obvious choice, but, after some research, I found that although the individual RF module was cheaper, I would have had to get five pieces of hardware to use that method. So the price would actually be about the same either way. The tipping point was that XBEEs are widely and extensively used, so I could get a large amount of support for them, including from my mentor, Aimen, who had used them before.</p>
			<h2>Body Design and Creation</h2>
			<img class="alignelementleft" alt="My Laser-cut Robot Body Design" src="https://lh6.googleusercontent.com/XsSq4iRetPZ5mafKX3us_wqt6GJMK0JEu6pz_GuYok4=w229-h227-p-no"/>
			<p>My original idea for the body of the robot was to laser-cut it out of compressed wood board at a business downtown called <a href = "http://makersfactory.com/">Makers' Factory</a> where one can use all sorts of proto-typing machines, such as a laser-cutter. I designed a slot system to hold the sides together and my robot would have looked like the image above if not for metal artist Ralph Royer. I was talking to him about the robot I was going to build and he offered to help me build it at his <a href = "http://www.rcrfabrication.com/">metal-working shop</a>! So I worked with him at his house for a few nights, creating the 3-D drawing of the body below. Unlike the drawing I made, this was accurate down to the millimeter. Another difference was that with this new drawing, he could extrapolate cutting instructions for his machines.  So in about a month, he emailed me saying that his water-jet had cut the parts out. (A water jet shoots a high-powered blast of water mixed with ground stone.)</p>
			<img class="alignelementright" alt="My 3d Moduled Fabricated Metal Robot Body Design" src="https://lh3.googleusercontent.com/TYbeHgcPQdP6tPnTG0VkYkKpQhes5Qve9rAZMD24V9E=s188-p-no"/>
			<p>I went to <a href="http://www.rcrfabrication.com/">his machine shop</a>. There we took the parts and bent them in 90 degree angles in order to create the three pieces of the shell: the base plate, the back plate and the front plate. Then we worked to create a mounting plate for the Arduino, the brain. We were able to install all the motors that first night. The second night, we finished the mounting for the brain but mostly worked on the wheels. These were slightly problematic because the motor had four mounting holes, whereas the wheel had only three. Since the holes did not line up we had to manufacture another piece with three holes for one side and four for the other. The very next day <a href = "edward_summery.php">EDWARD</a> took his very first steps... going in a circle. I finally figured out why and fixed the problem: because the motors are installed in opposite directions in order to be symmetrical, if I tell them both to turn forward, one will turn backward relative to the robot. Even after correcting the programming, the robot veered slightly to one side. That is because the motors can go faster one direction than the other, so if I order full speed ahead  on both, it will have a slight lean.</p>
			<h2>Software Design</h2>
			<p>Much of the robot I designed over the summer of 2012, but my design evolved as the project progressed. The first thing I did was to decide which classes (see definitions above) I would create to represent my robot. Here is my design:</p>
			<table>
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
			<ul>
				<li><p><b>Class Robot:</b> contains all the other classes. It also slightly modifies some of the methods of the classes so that it can keep track of information that is only necessary to the robot and not to the other classes, such as the current location and direction of the robot.</p></li>
				<li><p><b>Class Locomotion:</b> coordinates the two wheels of the robot with methods moveForward, turnLeft, turnRight and uTurn. Class Servo is provided by the Arduino software so I did not have to create it.</p></li>
				<li><p><b>Class Map:</b> this is where information about the maze is stored. It consists of a grid of instances of class Square, which is where the information about each square is stored.  It keeps track of where walls are, if the square has been mapped by the ping sensor yet, if an opening has been passed through by the robot yet, if the opening leads to a dead-end, where the robot first entered the square, and many other things.</p></li>
			</ul>
			<p>I also decided to have two functions, scanWalls and whichWay. scanWalls would use the ping sensor to determine where the walls are and whichWay would determine the direction to go. whichWay works by keeping track of which sides cannot be traversed. whichWay eliminates a direction that has a wall or leads to a dead end. If there are no ways out, the robot goes back the way it came. But if there are ways out, then whichWay eliminates any path it has already traversed. If there are still multiple options, then whichWay uses the Pythagorean Theorem to determine the optimal way to go. It does this by calculating the distance between where the robot would be if it moved one square in any direction and the goal. It then compares the distances and takes the path that decreases the distance to the goal the most. I later dropped the Pythagorean Theorem after inconsistent runs and seemingly random choices.</p>
			<p>The main program then works like this: The instance of class robot is created and the robot is informed of its destination. Then, until the robot reaches its goal, it repeats these instructions: First it checks to see if it has reached its goal. Then, if the square it is in has not been mapped yet, it will map it by calling the function scanWalls. Next, it checks to see if the robot has gotten out of a dead end and if it has, it labels the way it came a dead end. It also checks to see if it just entered a dead-end and if it has, remembers that it has. Then it decides which way to go by calling whichWay. Lastly it goes the way it decided by using class Locomotion in class Robot.</p>
			<h2>Programming</h2>
			<p>After designing the conceptual framework, I started writing the easy classes. PingSensor, of course, was easy since all I had to do was restructure an example program into a class. MotorizedSensor was easy as well because I just had to combine PingSensor with class Servo, which is provided with the Arduino. Locomotion also wasn&#39;t very hard, but I could not complete it for a long time because I did not know the exact distances the motors needed to move until the physical robot could move. I started the Zigbee class, but it took a long time to finish. Class Square was the easiest as it was just a collection of variables describing the different aspects of each square.</p>
			<div class="aside colorscheme3">
				<h3>Terminology</h3>
				<ul>
					<li><p><b>Array:</b> a series of variables. This is useful for storing lists.</p></li>
					<li><p><b>Matrix:</b> whereas an array is a list, a matrix is a grid. This is especially helpful if one needs to store x/y coordinates.</p></li>
				</ul>
			</div>
			<p>Class Map was the most challenging class. It needed to be a matrix of Squares. But because more of the map can be discovered, this matrix had to be able to change size and changing size is not a feature of arrays or matrixes in C++. So I had to create my own version of an array. The most used custom array is a linked list. A linked list is a class that knows where the first object and last object are located. Each object in the list also knows which object is before it and which is after it. To add another object to the array, class linked list creates the new object, then tells it what is before it and what is after it. To find an object in the array, the linked list just has to count up from the start or down from the end until it reaches the desired object.</p>
			<img class="alignelementleft normalsize" alt="Diagram of a Typical Linked List" src="https://lh3.googleusercontent.com/ZoAgcel6H6KeKyE1UkyiACOz8-CxmkbEg-bL25KhAOM=w560-h299-no"/>
			<p>However, my skills were inadequate to create a linked list. So I came up with my own alternative.</p>
			<p>My version is a class that has a normal array in it. When that array needs to change size, a new array of the correct size is created, all the data from the old array is copied into it, and then the old array is deleted. Although this is slower than a linked list because of all the copying, it seemed to work. That is, until I tried to create a matrix using the same concept.</p>
			<p>The problem with making my class into a matrix is that, when I declare the matrix within the class, I have to provide one of the sizes of the array if it has more dimensions than two. Because I cannot know the size of the matrix until the user creates it, this approach does not work.</p>
			<p>After trying various work-arounds that did not get around the problem, I gave up and tried yet another approach. The idea this time was just to have one array, never creating a new one, but instead moving the data inside it around. If the robot discovers more of the map to one side, all the data is shoved over to make room for the new data (see below). This can end up with old data being forgotten, but the good thing about that is that the maximum amount of memory is set and so cannot crash the Arduino.</p>
			<img class="alignelementright normalsize" alt="My Alternative to a Linked List" src="https://lh3.googleusercontent.com/-FdJFVXhsOJ4/UgBOI-MXo_I/AAAAAAAAAcU/I9U5hmyogGE/w552-h298-no/my_list.bmp"/>
			<p>Later, towards the end of the project, I was still having trouble with the Map class. Then I realized that I had enough memory to remember any maze I had enough space to conceivably build. So I used the built-static array option after all.</p>
			<p>Class Robot was not that hard. It just contained all the other classes. The only thing I had to be careful with is that whenever the robot moves, interior variables such as current position and current facing must be updated.</p>
			<p>After I finished writing the main program, I uploaded it onto the robot. But the robot did nothing. I tried testing the Locomotion, MotorizedSensor and Zigbee classes individually, but none of them functioned. After getting help on the <a href = "http://arduino.cc/forum/">Arduino Forum</a>, I discovered my problem. Arduino provides a function init() that is called automatically just before the main program begins. init() lets all the Arduino functions, such as interfacing with pins, operate properly. If I tried to use the pins of the Arduino in any of my classes&#39; constructors, nothing would happen. So I created a function start() in each of my classes to do what the constructor of that class had previously done.</p>
			<p>I uploaded my program onto the Arduino once more. But still nothing happened. I tried testing each class by itself. They all worked, but not together. After trying many possibilities, I found the problem: The Arduino did not have enough memory!</p>
			<div class="aside colorscheme3">
				<h3>Terminology</h3>
				<ul>
					<li><p><b>Constructor:</b> a constructor is a special method present in all classes. When an instance of a class is created, the constructor is called to initialize the variables of class so that the class may be used.</p></li>
				</ul>
			</div>
			<p>When a variable is declared in C++, it must be of one type. Some types store a letter, others can store words. Other variable types can store decimal numbers, but some only whole numbers. The most commonly used variable type is int (short for integer). An int can store a whole number big or small enough that it can be used for almost anything. I was using many ints in my program, to store everything from which pin is used for what to how far the nearest wall is. To fix my memory problem, I replaced every int I could with a variable type half the size, a byte. Some ints I could not replace because I needed their size for what I was storing. But most of my variables never exceed 255 so the byte was perfect.</p>
			<p>My program now functioned, but the robot consistently performed incorrectly. If a wall was in front, it would still choose to go that way. I did not have a very good way to see what the robot was thinking because the XBEE was not working. So I built a simulation of the robot on my computer. Instead of scanning walls, it asked the user whether or not there was a wall in each direction. I was able to have it print the state of all the variables on the computer screen so that I could better understand its process. The logic was very faulty in many ways, all stemming from two issues. The first issue was that in some places, I was labeling the walls 1-4 but in most of the code I had named the walls 0-3. I quickly fixed this inconsistency. The other problem was more complicated. I had to use two different direction systems for my robot. One was the cardinal direction system, with 0 being north, 1 standing for east, 2 representing south and 3 as west. But I also had to keep track of direction relative to the robot. And for that, I was using 0 for in front of the robot, 1 to the right, 2 to the back and 3 to the left. Since I was using the same numbering system for both sets of directions, it was very easy to confuse them. I spent a lot of time going through all the code and making sure I was using the correct set of directions everywhere. At last, the simulation of my robot successfully made it through a simple maze shown below, from the lower star to the upper one.</p>
			<img class="alignelementleft" alt="My Robot's First Maze" src="https://lh3.googleusercontent.com/Q2Plrnlv7POby4jDE91SdMnzDYnISSOsyl_MVP3S0Ao=w187-h188-p-no"/>
			<p>Now I needed the actual robot to traverse the same maze. First I transferred the files back on the robot. I still could not get the XBEE to work, so I dropped that feature and instead just programmed in the destination coordinates as (0, 3). The logic still would not work, however. In order to simplify, I removed the part of the program that used the Pythagorean Theorem and chose which way to move using a different method. The robot now went forward if there was no wall in front of it. If there was, but no wall to the right, it would go that way. If there was a wall to the right as well, it would try left. If it could go none of these ways, it would turn around and go the way it came.</p>
			<p>I spent many hours tweaking all the physical aspects of the robot. I straightened out my robot's movement then started it in the maze. But I was often getting inaccurate and inconsistent results.  It was choosing to go through as many walls as my simulation once had. At last I discovered the source of the inconsistencies. The pulse of sound from the ping sensor was occasionally bouncing off a nearer wall that was to the side, so the robot thought there were walls where there was an opening. To fix this I had to adjust the maze so the edges of the walls never interfered. But at last, <a href = "edward_summery.php">EDWARD</a> made it through the same maze his simulation had already traversed!</p>
			<h2><span class="important">E.D.W.A.R.D.</span></h2>
			<p> Sometimes my robot spun in circles and sometimes my simulation rammed through walls as if they were not there, but I managed to overcome these and many other problems. I also learned what not to do when building a robot, such as making the circuitry hard to access and relying on motors which constantly change speeds. My programming skills have improved immensely, especially in C++ and on the Arduino. I did not quite realize when I conceived my project what a huge undertaking it would be. I was never sure if I would finish. But with the help of experts who were willing to lend their valuable time, I created a robot that can find its way through any maze.</p>
			<h2>Bibliography</h2>
			<ul>
				<li><p><span style = "text-decoration: underline">Arduino Cookbook</span>, by Michael Margolis</p></li>
				<li><p><span style = "text-decoration: underline">C++ For Dummies</span>, by Stephen Randy Davis</p></li>
				<li><p><span style = "text-decoration: underline">C++: Effective Object-Oriented Software Construction: Concepts, Principles, Industrial Strategies and Practices</span>, by Kayshav Dattatri</p></li>
				<li><p><span style = "text-decoration: underline">My Robot, Makey</span>, by Kris Magri from <span style = "text-decoration: underline">Make: Magazine Volume 19</span></p></li>
				<li><p><span style = "text-decoration: underline">Make: Magazine Volume 25</span></p></li>
				<li><p><a href = "http://stackoverflow.com/">http://stackoverflow.com/</a></p></li>
				<li><p><a href = "http://arduino.cc/forum/">http://arduino.cc/forum/</a></p></li>
				<li><p><a href = "www.instructables.com/id/arduino-motor-shield-tutorial/">www.instructables.com/id/arduino-motor-shield-tutorial/</a></p></li>
				<li><p><a href = "http://code.google.com/p/arduino/issues/detail?id=857">http://code.google.com/p/arduino/issues/detail?id=857</a></p></li>
				<li><p><a href = "http://code.google.com/p/arduino/issues/detail?id=468">http://code.google.com/p/arduino/issues/detail?id=468</a></p></li>
				<li><p><a href = "http://en.wikipedia.org/wiki/history_of_robots">http://en.wikipedia.org/wiki/history_of_robots</a></p></li>
				<li><p><a href = "http://en.wikipedia.org/wiki/robot">http://en.wikipedia.org/wiki/robot</a></p></li>
				<li><p><a href = "http://en.wikipedia.org/wiki/william_grey_walter">http://en.wikipedia.org/wiki/william_grey_walter</a></p></li>
				<li><p><a href = "http://en.wikipedia.org/wiki/rur">http://en.wikipedia.org/wiki/rur</a></p></li>
				<li><p><a href = "http://en.wikipedia.org/wiki/a*_search_algorithm">http://en.wikipedia.org/wiki/a*_search_algorithm</a></p></li>
				<li><p><a href = "http://en.wikipedia.org/wiki/hough_transform">http://en.wikipedia.org/wiki/hough_transform</a></p></li>
				<li><p><a href = "http://www.youtube.com/watch?v=qxdn6ynwpii">http://www.youtube.com/watch?v=qxdn6ynwpii</a></p></li>
				<li><p><a href = "http://en.wikipedia.org/wiki/turing_test">http://en.wikipedia.org/wiki/turing_test</a></p></li>
				<li><p><a href = "http://en.wikipedia.org/wiki/shakey_the_robot">http://en.wikipedia.org/wiki/shakey_the_robot</a></p></li>
				<li><p><a href = "http://en.wikipedia.org/wiki/strips">http://en.wikipedia.org/wiki/strips</a></p></li>
				<li><p><a href = "http://cplusplus">http://cplusplus</a></p></li>
			</ul>
			<h2>Mentors</h2>
			<ul>
				<li><p>Aimen al-Rafi, MA Computer Science</p></li>
				<li><p>Ralph Royer, Metal Artist</p></li>
				<li><p>Ashton Andrews, Computer Programmer, my Uncle</p></li>
			</ul>
		</div>
	</body>
</html>
