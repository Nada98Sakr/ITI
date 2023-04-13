import { Component } from '@angular/core';

@Component({
  selector: 'app-slider',
  templateUrl: './slider.component.html',
  styleUrls: ['./slider.component.css'],
})
export class SliderComponent {
  SlideIndex = 0;
  intervalId:any;

  MoveSlides(n: any) {
    const slides = document.querySelectorAll('.slide');
    this.SlideIndex += n;
    if (this.SlideIndex >= slides.length) this.SlideIndex = 0;
    if (this.SlideIndex < 0) this.SlideIndex = slides.length - 1;
    for (let i = 0; i < slides.length; i++) {
      if (slides[i].classList.contains('active'))
        slides[i].classList.remove('active');
    }
    slides[this.SlideIndex].classList.add('active');
  }

  plusSlides(n: any) {
    this.MoveSlides(n);
  }

  StartSlider(){
    this.intervalId = setInterval(() => {this.MoveSlides(1)},2000);
  }

  StopSlider(){
    clearInterval(this.intervalId);
  }
}
