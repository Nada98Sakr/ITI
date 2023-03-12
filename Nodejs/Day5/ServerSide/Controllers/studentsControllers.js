let StudentsSchema = require("../schema/studentschema");
let uuid = require("uuid");

let GetAllStd = async (req, res) => {
    try{
        let AllStd = await StudentsSchema.find();
        res.json(AllStd);
    }catch(err){
        res.json(err);
    }
};

let GetOneStd = async (req, res) => {
    try {
        let ID = req.params.id;
        let foundStd = await StudentsSchema.findById(ID);
        res.json(foundStd);
    } catch (err) {
        res.json(err);
    }
};

let AddNewStd = async (req, res) => {
    try {
        let std = await StudentsSchema.create(req.body);
        res.send("added successfully");
    } catch (err) {
        res.json(err);
    }
};

let UpdateStd = async (req, res) => {
    try {
        let ID = req.params.id;
        let updatedStd = req.body;
        await StudentsSchema.findByIdAndUpdate(ID, updatedStd);
        res.json("updated successfuly");
    } catch (err) {
        res.json(err);
    }
};

let DeleteStd = async (req, res) => {
    try{
        let ID = req.params.id;
        await StudentsSchema.findByIdAndDelete(ID);
        res.send("deleted successfully"); 
    }catch(err){
        res.json(err);
    }
};

module.exports = {
    GetAllStd,
    GetOneStd,
    AddNewStd,
    UpdateStd,
    DeleteStd,
};
