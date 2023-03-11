let studentsArr = [];
let id = 0;

class Students {
    constructor(name, age, track, coursesID) {
        this.id = ++id;
        this.name = name;
        this.age = age;
        this.track = track;
        this.coursesID =coursesID;
    }

    AddStd() {
        studentsArr.push(this);
    }

    static GetAllStds() {
        return studentsArr;
    }

    static updateStd(std) {
        let flag = false;
        studentsArr.find((s) => {
        if (s.id == std.id) {
            s.name = std.name;
            s.age = std.age;
            s.track = std.track;
            s.coursesID = std.coursesID;
            flag = true;
        }
        });
        return flag;
    }

    static deleteStd(ID) {
        let flag = false;
        studentsArr.find((s, i) => {
        if (s.id == ID) {
            studentsArr.splice(i, 1);
            flag = true;
        }
        });
        return flag;
    }
}

module.exports = Students;
