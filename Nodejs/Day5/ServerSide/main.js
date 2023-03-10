//#region config
const express = require("express");
const app = express();
const PORT = process.env.PORT || 7005;
const bodyParser = require("body-parser");
const logingMiddleWare = require("./MiddleWares/logging")
const studentRouters = require("./Routers/studentsRouters");
const coursesRouters = require("./Routers/coursesRouters");
//#endregion

//#region middlewares
app.use(bodyParser.urlencoded({extended: true}));
app.use(bodyParser.json());
app.use(logingMiddleWare);
//#endregion

//#region students
app.use("/api/students", studentRouters)
//#endregion

//#region courses
app.use("/api/courses", coursesRouters);
//#endregion


app.listen(PORT, ()=>{console.log("http://localhost:"+PORT)})