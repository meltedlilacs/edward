<!DOCTYPE html>
<html>
	<head>
		<title>Blog Test</title>
		<link rel="shortcut icon" href="g3gears.jpg"/>
		<link type = "text/css" rel = "stylesheet" href = "stylesheet.css">
		<script src="ckeditor/ckeditor.js"></script>
		<script>
			window.onload = function() {
        		CKEDITOR.replace( 'editor1' );
    			};
		</script>
	</head>
	<body>
		<?php
			include "./menu.php";
		?>
		<div class = "content colorscheme1">
			<h1 contenteditable="true">This is a Test</h1>
			<br/>
			<br/>
			<p>
			I am testing the online text editor ckeditor and the comment engine disqus on one page. This is mainly for Laura's site but also for general experiance. At this point what I'm typing is really just filler text. There is no point in reading this. I might as well just switch over to lorem ipsum
			</p>
			<form method="post" action="post_text_test.php">
				<textarea name="editor1">&lt;p&gt;Here is some default text!&lt;/p&gt;</textarea>
				<input type="submit"/>
			</form>
			<div id="disqus_thread"></div>
    		<script type="text/javascript">
        		/* * * CONFIGURATION VARIABLES: EDIT BEFORE PASTING INTO YOUR WEBPAGE * * */
        		var disqus_shortname = 'gabrieldamonsprojects'; // required: replace example with your forum shortname

        		/* * * DON'T EDIT BELOW THIS LINE * * */
        		(function() {
            		var dsq = document.createElement('script'); dsq.type = 'text/javascript'; dsq.async = true;
            		dsq.src = '//' + disqus_shortname + '.disqus.com/embed.js';
            		(document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(dsq);
    			    })();
    		</script>
    		<noscript>Please enable JavaScript to view the <a href="http://disqus.com/?ref_noscript">comments powered by Disqus.</a></noscript>
    		<a href="http://disqus.com" class="dsq-brlink">comments powered by <span class="logo-disqus">Disqus</span></a>
		</div>
	</body>
</html>
