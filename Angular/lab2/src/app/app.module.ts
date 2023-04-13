import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { FormsModule } from '@angular/forms';
import { SliderComponent } from './Components/slider/slider.component';
import { InputBindingComponent } from './Components/input-binding/input-binding.component';

@NgModule({
  declarations: [
    AppComponent,
    SliderComponent,
    InputBindingComponent,
  ],
  imports: [
    BrowserModule,
    FormsModule,
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
