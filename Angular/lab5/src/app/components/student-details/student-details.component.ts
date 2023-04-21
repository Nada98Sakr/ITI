import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { StudentService } from 'src/app/Services/student';

@Component({
  selector: 'app-student-details',
  templateUrl: './student-details.component.html',
  styleUrls: [],
})
export class StudentDetailsComponent implements OnInit {
  ID: any;
  student:any;
  
  constructor(route: ActivatedRoute, public MyStudents: StudentService) {
    this.ID = route.snapshot.params['id'];
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
}
