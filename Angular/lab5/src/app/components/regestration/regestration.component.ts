import { Component, HostListener, EventEmitter } from '@angular/core';
import { FormControl, FormGroup, Validators } from '@angular/forms';
import { StudentService } from 'src/app/Services/student';
import { Router } from '@angular/router';

@Component({
  selector: 'app-regestration',
  templateUrl: './regestration.component.html',
  styleUrls: ['./regestration.component.css'],
})

export class RegestrationComponent{
  constructor(private router: Router, public MyStudents: StudentService) {}

  @HostListener('window:keydown.enter') enterEvent() {
    this.Add();
  }

  validationForm = new FormGroup({
    name: new FormControl(null, Validators.minLength(3)),
    email: new FormControl(null, Validators.email),
    age: new FormControl(null, [Validators.min(20), Validators.max(40)]),
    phone: new FormControl(null, [
      Validators.minLength(11),
      Validators.maxLength(11),
    ]),
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

  get PhoneValidation() {
    return this.validationForm.controls['phone'].valid;
  }

  Add() {
    if (this.validationForm.valid) {
      let newStd = {
        name: this.validationForm.controls['name'].value,
        age: this.validationForm.controls['age'].value,
        email: this.validationForm.controls['email'].value,
        phone: this.validationForm.controls['phone'].value,
      };
      this.MyStudents.AddNewStd(newStd).subscribe();
      this.validationForm.reset();
      this.router.navigate(['/']);
    } else {
      alert('Invalid Data!');
    }
  }
}
