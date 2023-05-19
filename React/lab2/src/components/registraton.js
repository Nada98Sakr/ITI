import { Component } from "react";

export default class Registeration extends Component {
    constructor(props) {
        super(props);
        this.state = {
            name: "",
            age: "",
            email: "",
        };
    }

    setStudent = (e) => {
        this.setState({ [e.target.name]: e.target.value });
    };
    
    submitStd = (e) => {
        // e.preventDefault();
        this.props.onSubmit({ ...this.state });
    };

    render() {
        return (
            <div className="w-50 mx-auto mt-4 p-4 border rounded-2">
                <h2 className="mb-4 text-center p-1">Add new student</h2>

                <div className="row g-3 align-items-center">
                    <div className="col-1">
                        <label for="inputName" className="col-form-label">
                            Name
                        </label>
                    </div>
                    <div className="col-11">
                        <input
                            type="text"
                            id="inputName"
                            name="name"
                            className="form-control"
                            onChange={this.setStudent}
                        />
                    </div>
                </div>

                <div className="row g-3 align-items-center my-3">
                    <div className="col-1">
                        <label for="inputEmail" className="col-form-label">
                            Email
                        </label>
                    </div>
                    <div className="col-11">
                        <input
                            type="email"
                            id="inputEmail"
                            name="email"
                            className="form-control"
                            onChange={this.setStudent}
                        />
                    </div>
                </div>

                <div className="row g-3 align-items-center">
                    <div className="col-1">
                        <label for="inputAge" className="col-form-label">
                            Age
                        </label>
                    </div>
                    <div className="col-11">
                        <input
                            type="text"
                            id="inputAge"
                            name="age"
                            className="form-control"
                            onChange={this.setStudent}
                        />
                    </div>
                </div>

                <div className="d-flex justify-content-end">
                    <input
                        type="button"
                        className="btn btn-primary mt-5"
                        value="ADD"
                        onClick={this.submitStd}
                    />
                </div>
            </div>
        );
    }
};
