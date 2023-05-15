import { Component } from "react";
import "./slider.css";

class SliderElement extends Component {
    SlideIndex = 0;
    intervalId;

    MoveSlides = (n) => {
        const slides = document.querySelectorAll('.slide');
        this.SlideIndex += n;
        if (this.SlideIndex >= slides.length) this.SlideIndex = 0;
        if (this.SlideIndex < 0) this.SlideIndex = slides.length - 1;
        for (let i = 0; i < slides.length; i++) {
            if (slides[i].classList.contains("active"))
                slides[i].classList.remove("active");
        }
        slides[this.SlideIndex].classList.add("active");
    };

    plusSlides = (n) => {
        this.MoveSlides(n);
    };

    StartSlider = () => {
        this.intervalId = setInterval(() => {
            this.MoveSlides(1);
        }, 2000);
    };

    StopSlider = () => {
        clearInterval(this.intervalId);
    };

    render() {
        return (
            <div className="Slider">
                <div className="slideContainer">
                    <img
                        src="assets/images/img1.jpg"
                        className="slide active"
                        alt="slide 1"
                    />
                    <img
                        src="assets/images/img3.jpg"
                        alt="slide 1"
                        className="slide"
                    />
                    <img
                        src="assets/images/img2.jpg"
                        alt="slide 1"
                        className="slide"
                    />
                </div>

                <div className="inputs">
                    <input
                        type="submit"
                        value="Next"
                        onClick={() => this.MoveSlides(1)}
                    />
                    <input
                        type="submit"
                        value="Prev"
                        onClick={() => this.MoveSlides(-1)}
                    />
                    <input
                        type="submit"
                        value="Slide"
                        onClick={() => this.StartSlider()}
                    />
                    <input
                        type="submit"
                        value="Stop"
                        onClick={() => this.StopSlider()}
                    />
                </div>
            </div>
        );
    }
}

export default SliderElement;
