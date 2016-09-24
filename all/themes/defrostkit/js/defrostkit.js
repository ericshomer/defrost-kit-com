(function (Drupal, $) {
	$(document).ready(function() {
/*******************************************************************************
**
** Homepage image call to actions
**
******************************************************************************/
	//if window size < 400px remove overlay and hoverclass
	var overlay = $('<div class="overlay"></div>');

	if ($(window).width() <= 420) {
		$(overlay).detach();
	} 
	else {
		$('.view-homepage-callout-beans').prepend(overlay);
		//mouse enter
		$('.view-homepage-callout-beans').on('mouseenter', function() {
			$(this).find('.overlay').css('opacity', '0.5');
			//on hover of parent div trigger the hover state of the call to action
			$(this).find('.call-to-action').addClass('hoverClass');
			$(this).find('.views-field-title h2').css('color', '#2b98b0');
		 });
		//mouse leave
		$('.view-homepage-callout-beans').on('mouseleave', function() {
			$(this).find('.overlay').css('opacity', '0');
			$(this).find('.call-to-action').removeClass('hoverClass');
			$(this).find('.views-field-title h2').css('color', '#ffffff');
		 });
	}

/*******************************************************************************
**
** Form elements // Decorative Radio & checkboxes
**
******************************************************************************/
	var check = $('<div class="check"></div>');
	var checkbox = $('<div class="checkbox-dv"></div>');
		$('.form-type-radio').append(check);
		$('.form-type-checkbox').append(checkbox);


 });
})(Drupal, jQuery);

