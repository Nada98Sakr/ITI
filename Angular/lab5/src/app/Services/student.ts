import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root',
})

export class StudentService {
  constructor(private readonly MyStudents: HttpClient) {}
  private readonly Base_URL = 'http://localhost:3000/students';

  GetAllStds() {
    return this.MyStudents.get(this.Base_URL);
  }

  GetStdByID(id: any) {
    return this.MyStudents.get(this.Base_URL + '/' + id);
  }

  AddNewStd(newstd: any) {
    return this.MyStudents.post(this.Base_URL, newstd);
  }

  UpdateStd(id:any, editedStd: any) {
    return this.MyStudents.patch(this.Base_URL + '/' + id, editedStd);
  }

  DeleteStd(id:any) {
    return this.MyStudents.delete(this.Base_URL + '/' + id);
  }
}
