const express = require("express");
const router = express.Router();
const coursesController = require("../Controllers/coursesController")

router.get("/", coursesController.GetAllcourses)
router.get("/:id", coursesController.GetOnecourse);
router.post("/", coursesController.AddNewcourse)
router.delete("/:id", coursesController.Deletecourse)
router.put("/:id", coursesController.Updatecourse)

module.exports = router;