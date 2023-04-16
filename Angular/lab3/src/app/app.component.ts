import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
})
export class AppComponent {
  title = 'lab3';
  students:{name: String, age:String}[] = [];
  getStdData(stdData:any){
    this.students.push(stdData)
  }
}
