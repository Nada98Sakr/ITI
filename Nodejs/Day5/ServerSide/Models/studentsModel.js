const mongoose = require("mongoose");
const DbURL = "mongoose://localhost:27017/ITI";
mongoose.connect(DbURL, { useNewUrlParser: true });

const StudentsSchema = mongoose.Schema({
    id: String,
    name: String,
    age: Number,
    track: String,
    coursesID: Array,
});

module.exports = mongoose.model("students", StudentsSchema);
