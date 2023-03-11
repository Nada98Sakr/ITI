const Ajv = require("ajv");
const ajv = new Ajv();

const StudentsSchema = {
    type: "object",
    properties: {
        name: {type: "string"},
        age: {type: "number"},
        track: {type: "string"},
        coursesID: {type: "array"}
    },
    required: ["name", "age", "track", "coursesID"],
    additionalProperties: false
};


module.exports = ajv.compile(StudentsSchema);