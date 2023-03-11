const mongoose = require("mongoose");
const DbURL = "mongoose://localhost:27017/ITI";
mongoose.connect(DbURL, { useNewUrlParser: true });

const CoursesSchema = mongoose.Schema({
    name: String,
    duration: Number,
    coursesID: Array,
});

module.exports = mongoose.model("courses", CoursesSchema);

// let coursesArr = [];
// let id = 0;

// Array doesnot exist
// class Courses {
//     constructor(name, duration, stdIds){
//         this.id = ++id;
//         this.name = name;
//         this.duration = duration;
//         this.stdIds = stdIds;
//     }

//     AddCourse(){
//         coursesArr.push(this);
//     }

//     static GetAllCourses(){
//         return coursesArr;
//     }

//     static updatecourse(course){
//         let flag = false;
//         coursesArr.find((c) => {
//             if(c.id == course.id){
//                 c.name = course.name;
//                 c.duration = course.duration;
//                 c.stdIds = course.stdIds;
//                 flag = true;
//             }
//         });
//         return flag;
//     }

//     static deleteCourse(ID){
//         let flag = false;
//         coursesArr.find((c, i) => {
//             if(c.id == ID){
//                 coursesArr.splice(i, 1);
//                 flag = true;
//             }
//         })
//         return flag;
//     }
// }

// module.exports = Courses;
