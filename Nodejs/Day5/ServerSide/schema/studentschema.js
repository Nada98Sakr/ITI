const mongoose = require("mongoose");
const DbURL = "mongodb://localhost:27017/ITI";
mongoose.connect(DbURL, { useNewUrlParser: true });
var Schema = mongoose.Schema;

const StudentsSchema = Schema({
    name: { type: String, minlength: 3 },
    age: { type: Number },
});

module.exports = mongoose.model("students", StudentsSchema);
