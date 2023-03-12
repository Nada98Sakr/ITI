let Courses = require("../schema/courseSchema");

let GetAllcourses = async (req, res) => {
    try {
        let AllCourses = await Courses.find();
        res.json(AllCourses);
    } catch (err) {
        res.json(err);
    }
};

let GetOnecourse = async (req, res) => {
    try {
        let ID = req.params.id;
        let foundcourse = await Courses.findById(ID);
        res.json(foundcourse);
    } catch (err) {
        res.json(err);
    }
};

let AddNewcourse = async (req, res) => {
    try {
        let newCourse = await Courses.create(req.body);
        res.send("added successfully");
    } catch (err) {
        res.json(err);
    }
};

let Deletecourse = async (req, res) => {
    try {
        let ID = req.params.id;
        await Courses.findByIdAndDelete(ID);
        res.send("deleted successfully");
    } catch (err) {
        res.json(err);
    }
};

let Updatecourse = async (req, res) => {
    try {
        let ID = req.params.id;
        let updatedCourse = req.body;
        await Courses.findByIdAndUpdate(ID, updatedCourse);
        res.json("updated successfuly");
    } catch (err) {
        res.json(err);
    }
};

module.exports = {
    GetAllcourses,
    GetOnecourse,
    AddNewcourse,
    Updatecourse,
    Deletecourse,
};
