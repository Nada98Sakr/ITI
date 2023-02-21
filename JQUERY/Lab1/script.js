$(function(){
    let SliderInterval = setInterval(MoveSlides,1000);
    function MoveSlides(){
        let slides = $(".activeSlide");
        let nextSlide;
        if(slides.next().length > 0){
            nextSlide = slides.next();
        }else{
            nextSlide = $(".Slide:first");
        }
        slides.removeClass("activeSlide");
        nextSlide.addClass("activeSlide");
    }
    $(".btn").on("click", function(){clearInterval(SliderInterval)});

    // Task2....
    $(".box").on("click", function(e){
        $(e.target).next().slideToggle("slow");
    })
})