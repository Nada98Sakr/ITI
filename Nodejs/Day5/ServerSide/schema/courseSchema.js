const mongoose = require("mongoose");
const DbURL = "mongodb://localhost:27017/ITI";
mongoose.connect(DbURL, { useNewUrlParser: true });
var Schema = mongoose.Schema;


const CoursesSchema = Schema({
    name: { type: String },
    duration: { type: Number },
    instructor: { type: String },
});

module.exports = mongoose.model("courses", CoursesSchema);
