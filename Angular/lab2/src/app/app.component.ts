import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
})
export class AppComponent {
  title = 'lab2';
  inputStyle = 'none';
  sliderStyle = 'none';
  InpVal = 'Show input';
  SliderVal = 'Show Slider';

  ShowInp() {
    this.sliderStyle = 'none';
    this.SliderVal = 'show slider';
    if(this.inputStyle == 'none'){
      this.inputStyle = 'block';
      this.InpVal = 'hide input';
    }else{
      this.inputStyle = 'none';
      this.InpVal = 'show input';
    }
  }

  ShowSlider() {
    this.inputStyle = 'none';
    this.InpVal = 'show input';
    if (this.sliderStyle == 'none') {
      this.sliderStyle = 'block';
      this.SliderVal = 'hide slider';
    } else {
      this.sliderStyle = 'none';
      this.SliderVal = 'show slider';
    }
  }
}
