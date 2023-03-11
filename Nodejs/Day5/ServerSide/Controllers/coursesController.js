let valid = require("../Utils/courseValidation");
let Courses = require("../Models/courseModel");

let GetAllcourses = async (req, res) => {
  let AllCourses = await Courses.find();
  res.json(AllCourses);
};

let GetOnecourse = async (req, res) => {
  let ID = req.params.id;
  let foundcourse = await Courses.findById(ID);
  res.json(foundcourse);
};

let AddNewcourse = async (req, res) => {
  let newCourse = new Courses(req.body);
  await newCourse.save();
  res.send("added successfully");
};

let Deletecourse = async (req, res) => {
  let ID = req.params.id;
  let flag = Courses.findByIdAndDelete(ID);
  if (flag) {
    res.send("deleted successfully");
  } else {
    res.status(400).send("course not found!!");
  }
};

let Updatecourse = (req, res) => {
  let ID = req.params.id;
  let updatedCourse = req.body;
  updatedCourse.id = ID;
  let flag = Courses.findByIdAndUpdate(ID, updatedCourse);
  if (flag) {
    res.json("updated successfuly");
  } else {
    res.status(400).send("student not found!!");
  }
};

module.exports = {
  GetAllcourses,
  GetOnecourse,
  AddNewcourse,
  Updatecourse,
  Deletecourse,
};
