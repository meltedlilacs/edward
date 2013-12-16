// this was for the old menu, but no animation is used any longer :(
/*
$(document).ready(function()	{
	// to make the menus slide 
	$(".subheading").hide();
	var eMenuTimer;
	var bMenuTimer;
	var gMenuTimer;
	
	$(".menu .edward").hover(function() {
    	// Slide down the submenu
    	$(".edward .subheading").fadeIn();
		}, 
	function() {
    	// Create a 200ms timer, after which it will close the sub_menu
    	eMenuTimer = setTimeout(function() {$(".edward .subheading").fadeOut();},200);
		});
	
	$(".edward .subheading").mouseenter(function() {
    	// The user entered the submenu, so cancel the timer (don't close the submenu)
    	clearTimeout(eMenuTimer);
		});
	
	$(".menu .ben").hover(function() {
    	// Slide down the submenu
    	$(".ben .subheading").fadeIn();
		}, 
	function() {
    	// Create a 200ms timer, after which it will close the sub_menu
    	bMenuTimer = setTimeout(function() {$(".ben .subheading").fadeOut();},200);
		});
	
	$(".ben .subheading").mouseenter(function() {
    	// The user entered the submenu, so cancel the timer (don't close the submenu)
    	clearTimeout(bMenuTimer);
		});
	
	$(".menu .gabriel").hover(function() {
    	// Slide down the submenu
    	$(".gabriel .subheading").fadeIn();
		}, 
	function() {
    	// Create a 200ms timer, after which it will close the sub_menu
    	gMenuTimer = setTimeout(function() {$(".gabriel .subheading").fadeOut();},200);
		});
	
	$(".gabriel .subheading").mouseenter(function() {
    	// The user entered the submenu, so cancel the timer (don't close the submenu)
    	clearTimeout(gMenuTimer);
		});
	});
*/