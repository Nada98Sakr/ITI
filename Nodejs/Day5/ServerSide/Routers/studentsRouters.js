const express = require("express");
const router = express.Router();
const studentsController = require("../Controllers/studentsControllers")

router.get("/", studentsController.GetAllStd);
router.get("/:id", studentsController.GetOneStd);
router.post("/", studentsController.AddNewStd)
router.put("/:id", studentsController.UpdateStd);
router.delete("/:id", studentsController.DeleteStd);

module.exports = router;