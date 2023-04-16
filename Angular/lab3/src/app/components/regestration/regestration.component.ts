import { Component, Output, EventEmitter} from '@angular/core';

@Component({
  selector: 'app-regestration',
  templateUrl: './regestration.component.html',
  styleUrls: ['./regestration.component.css'],
})
export class RegestrationComponent {
  stdName = '';
  stdAge = '';
  @Output() stdEvent = new EventEmitter();

  Add() {
    if(this.stdName.length >= 3 && (+this.stdAge <= 40 && +this.stdAge >= 20)){
      let NewStd = {
        name: this.stdName,
        age: this.stdAge,
      };
      this.stdName = this.stdAge = '';

      this.stdEvent.emit(NewStd);
    }
  }
}
