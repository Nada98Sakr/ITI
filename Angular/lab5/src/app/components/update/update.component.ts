import { Component, HostListener, OnInit } from '@angular/core';
import { FormControl, FormGroup, Validators } from '@angular/forms';
import { ActivatedRoute, Router } from '@angular/router';
import { StudentService } from 'src/app/Services/student';

@Component({
  selector: 'app-update',
  templateUrl: './update.component.html',
  styleUrls: [],
})

export class UpdateComponent implements OnInit {
  ID: any;
  student: any;
  constructor(route: ActivatedRoute, private router: Router, public MyStudents: StudentService) {
    this.ID = route.snapshot.params['id'];
    this.student = {};
  }

  @HostListener('window:keydown.enter') enterEvent() {
    this.edit();
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

  ngOnInit(): void {
    this.MyStudents.GetStdByID(this.ID).subscribe({
      next: (data) => {
        this.student = data;
      },
      error: (err) => {
        console.log(err);
      },
    });
  }

  edit() {
    if (this.validationForm.valid) {
      let editedStd = {
        name: this.validationForm.controls['name'].value || this.student.name,
        age: this.validationForm.controls['age'].value || this.student.age,
        email: this.validationForm.controls['email'].value || this.student.email,
        phone: this.validationForm.controls['phone'].value || this.student.phone,
      };
      
      this.MyStudents.UpdateStd(this.ID, editedStd).subscribe({
        next: (data) => {},
        error: (err) => {
          console.log(err);
        },
      });
      this.validationForm.reset();
      this.router.navigate(['/']);
    } else {
      alert('Invalid Data!');
    }
  }
}
