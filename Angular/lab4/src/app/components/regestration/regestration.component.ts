import { Component, HostListener, EventEmitter } from '@angular/core';
import { FormControl, FormGroup, Validators } from '@angular/forms';

@Component({
  selector: 'app-regestration',
  templateUrl: './regestration.component.html',
  styleUrls: ['./regestration.component.css'],
})
export class RegestrationComponent {
  @HostListener('window:keydown.enter') enterEvent() {
    this.Add();
  }

  validationForm = new FormGroup({
    name: new FormControl(null, Validators.minLength(3)),
    email: new FormControl(null, Validators.email),
    age: new FormControl(null, [Validators.min(20), Validators.max(40)]),
  });

  get AgeValidation() {
    return this.validationForm.controls['age'].valid;
  }
  get NameValidation() {
    return this.validationForm.controls['name'].valid;
  }
  get EmailValidation() {
    return this.validationForm.controls['email'].valid;
  }

  Add() {
    console.log(this.validationForm);
    if (this.validationForm.valid) {
      alert('Student Added Successfully!');
    } else {
      alert('Invalid Data!');
    }
  }
}
