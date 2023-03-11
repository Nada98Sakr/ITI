const Ajv = require("ajv");
const ajv = new Ajv();

const CoursesSchema = {
  type: "object",
  properties: {
    name: { type: "string"},
    duration: { type: "number"},
    stdIds: { type: "array" },
  },
  required: ["name", "duration", "stdIds"],
  additionalProperties: false,
};

module.exports = ajv.compile(CoursesSchema);