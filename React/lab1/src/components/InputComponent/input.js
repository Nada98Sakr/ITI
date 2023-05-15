import { Component } from "react";
import "./input.css";

class InputElement extends Component {
    constructor(props) {
        super(props);
        this.state = {
            data: "",
        };
        this.reset = this.reset.bind(this);
        this.handleChange = this.handleChange.bind(this);
    }

    reset() {
        this.setState({
            data: "",
        });
    }

    handleChange(event) {
        this.setState({
            data: event.target.value,
        });
    }

    render() {
        return (
            <div class="inputContainer">
                <input
                    type="text"
                    placeholder="enter text"
                    value={this.state.data}
                    onChange={this.handleChange}
                />
                <p>{this.state.data}</p>
                <input type="submit" value="RESET" onClick={this.reset} />
            </div>
        );
    }
}

export default InputElement;