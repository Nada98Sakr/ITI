let valid = require("../Utils/courseValidation");
let Courses = require("../Models/courseModel");

var courses = Courses.GetAllCourses();

let GetAllcourses = (req, res) => {
  res.json(courses);
};

let GetOnecourse = (req, res) => {
  let ID = req.params.id;
  let foundcourse = courses.find((c) => {
    return c.id == ID;
  });
  res.json(foundcourse);
};

let AddNewcourse = (req, res) => {
    if(valid(req.body)){
        let newCourse = new Courses(req.body.name, req.body.duration, req.body.stdIds);
        newCourse.AddCourse();
        res.send("added successfully");
    }else{
        res.status(400).send("wrong Data!!");
    }
};

let Deletecourse = (req, res) => {
  let ID = req.params.id;
  let flag = Courses.deleteCourse(ID);
  if (flag) {
    res.send("deleted successfully");
  } else {
    res.status(400).send("course not found!!");
  }
};

let Updatecourse = (req, res) => {
  let ID = req.params.id;
  let updatedCourse = req.body;
  if (valid(updatedCourse)) {
    updatedCourse.id = ID;
    let flag = Courses.updatecourse(updatedCourse);
    if (flag) {
      res.json("updated successfuly");
    } else {
      res.status(400).send("student not found!!");
    }
  } else {
    res.status(400).send("wrong Data!!");
  }
};

module.exports = {
  GetAllcourses,
  GetOnecourse,
  AddNewcourse,
  Updatecourse,
  Deletecourse,
};
