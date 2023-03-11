let valid = require("../Utils/studentValidation");
let StudentsSchema = require("../Models/studentsModel");

let id = 0;

let GetAllStd = async (req, res) =>{
    let AllStd = StudentsSchema.find();
    res.json(AllStd);
};

let GetOneStd = (req, res) => {
    let ID = req.params.id;
    let foundStd = students.findById(ID);
    res.json(foundStd);
};

let AddNewStd = (req, res) => {
    if(valid(req.body)){
        let std = new StudentsSchema(
            req.body.name,
            req.body.age,
            req.body.track,
            req.body.coursesID
        );
        std.save();
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