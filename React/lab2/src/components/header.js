import { NavLink } from "react-router-dom";

let Header = () => {
    return (
        <nav className="navbar navbar-expand-lg bg-body-tertiary">
            <div className="container-fluid">
                <button
                    className="navbar-toggler"
                    type="button"
                    data-bs-toggle="collapse"
                    data-bs-target="#navbarNavAltMarkup"
                    aria-controls="navbarNavAltMarkup"
                    aria-expanded="false"
                    aria-label="Toggle navigation"
                >
                    <span className="navbar-toggler-icon"></span>
                </button>
                <div className="collapse navbar-collapse text-center" id="navbarNavAltMarkup">
                    <div className="navbar-nav">
                        <NavLink
                            className="nav-link mx-1 text-decoration-none"
                            style={({ isActive }) => ({
                                color: isActive ? "blue" : "black",
                            })}
                            to={"/"}
                        >
                            Home
                        </NavLink>

                        <NavLink
                            className="nav-link mx-1 text-decoration-none"
                            style={({ isActive }) => ({
                                color: isActive ? "blue" : "black",
                            })}
                            to={"/students/5"}
                        >
                            Student Details
                        </NavLink>

                        <NavLink
                            className="nav-link mx-1 text-decoration-none"
                            style={({ isActive }) => ({
                                color: isActive ? "blue" : "black",
                            })}
                            to={"/profile"}
                        >
                            Profile
                        </NavLink>

                        <NavLink
                            className="nav-link mx-1 text-decoration-none"
                            style={({ isActive }) => ({
                                color: isActive ? "blue" : "black",
                            })}
                            to={"/error"}
                        >
                            Error
                        </NavLink>
                    </div>
                </div>
            </div>
        </nav>
    );
};
export default Header;
