let valid = require("../Utils/studentValidation");
let Students = require("../Models/studentsModel");

var students = Students.GetAllStds();

let GetAllStd = (req, res) =>{
    res.json(students);
};

let GetOneStd = (req, res) => {
    let ID = req.params.id;
    let foundStd = students.find((std) => {return std.id == ID});
    res.json(foundStd);
};

let AddNewStd = (req, res) => {
    if(valid(req.body)){
        let std = new Students(
            req.body.name,
            req.body.age,
            req.body.track,
            req.body.coursesID
        );
        std.AddStd();
        res.send("added successfully")
    }else{
        res.status(400).send("wrong Data!!");
    }
};

let UpdateStd = (req, res) => {
    let ID = req.params.id;
    let updatedStd = req.body;
    if(valid(updatedStd)){
        updatedStd.id = ID;
        let flag = Students.updateStd(updatedStd);
        if(flag){
            res.json("updated successfuly");
        }else{
            res.status(400).send("student not found!!");
        }
    }else{
        res.status(400).send("wrong Data!!");
    }
};

let DeleteStd = (req, res) => {
    let ID = req.params.id;
    let flag = Students.deleteStd(ID);
    if(flag){
        res.send("deleted successfully");
    }else{
        res.status(400).send("student not found!!");
    }
};

module.exports = {
    GetAllStd,
    GetOneStd,
    AddNewStd,
    UpdateStd,
    DeleteStd
}