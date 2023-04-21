import { Component, OnInit } from '@angular/core';
import { StudentService } from 'src/app/Services/student';

@Component({
  selector: 'app-student',
  templateUrl: './student.component.html',
  styleUrls: ['./student.component.css'],
})

export class StudentComponent implements OnInit {
  students: any;
  constructor(public MyStudents: StudentService) {}

  ngOnInit(): void {
    this.MyStudents.GetAllStds().subscribe({
      next: (data) => {
        this.students = data;
      },
      error: (err) => {
        console.log(err);
      },
    });
  }

  delete(id: any){
    this.MyStudents.DeleteStd(id).subscribe({
      next: (data) => { this.ngOnInit() },
      error: (err) => { console.log(err) }
    });
  }
}
