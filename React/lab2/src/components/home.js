import { Component } from "react";
import Students from "./allStudents";
import Registeration from "./registraton";

class Home extends Component {
    studentsList = [
        { id: 1, name: "nada", email: "nada@gmail.com", age: 25 },
        { id: 2, name: "nourhan", email: "nourhan@gmail.com", age: 27 },
        { id: 3, name: "salma", email: "salma@gmail.com", age: 24 },
    ];

    handleSubmit = (std) => {
        std.id = this.studentsList.length + 1;
        this.studentsList.push(std);
        this.setState({
            students: this.studentsList,
        });
    }

    constructor() {
        super();
        this.state = {
            students: this.studentsList,
        };
    }

    render() {
        return (
            <div className="p-4">
                <Registeration onSubmit={this.handleSubmit}/>
                <Students list={this.state.students} />
            </div>
        );
    }
}

export default Home;
