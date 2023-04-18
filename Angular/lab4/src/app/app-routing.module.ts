import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { ErrorComponent } from './components/error/error.component';
import { StudentComponent } from './components/student/student.component';
import { StudentDetailsComponent } from './components/student-details/student-details.component';
import { RegestrationComponent } from './components/regestration/regestration.component';

const routes: Routes = [
  { path: '', component: RegestrationComponent },
  { path: 'students', component: StudentComponent },
  { path: 'students/:id', component: StudentDetailsComponent },
  { path: '**', component: ErrorComponent },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }