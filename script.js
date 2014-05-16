$("document").ready(function() {
	$("#hero img").click(function() {
		$("video").addClass("visible");
		$("#close-video").removeClass("no-display");
		});
	$("#close-video").click(function() {
		$("video").removeClass("visible");
		$("#close-video").addClass("no-display");
		});
	});