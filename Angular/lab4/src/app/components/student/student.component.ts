import { Component } from '@angular/core';

@Component({
  selector: 'app-student',
  templateUrl: './student.component.html',
  styleUrls: ['./student.component.css'],
})
export class StudentComponent {
  students = [
    { id: 1, name: 'nada', age: 25, email: 'nada@gmail.com' },
    { id: 2, name: 'nourhan', age: 28, email: 'nourhan@gmail.com' },
    { id: 3, name: 'salma', age: 24, email: 'salma@gmail.com' },
  ];
}
