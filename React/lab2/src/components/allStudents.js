import { Link } from "react-router-dom";

let Students = ({ list }) => {
    let RenderStudents = (All) => {
        if (All) {
            return All.map((student) => {
                return (
                    <tr>
                        <td>{student.id}</td>
                        <td>{student.name}</td>
                        <td>{student.age}</td>
                        <td>{student.email}</td>
                        <td>
                            <Link
                                className="nav-link mx-1 text-decoration-none"
                                to={`/students/${student.id}`}
                            >
                                View
                            </Link>
                        </td>
                    </tr>
                );
            });
        } else {
            return (
                <tr>
                    <td colSpan={5}>No Students</td>
                </tr>
            );
        }
    };

    return (
        <div>
            <h2 className="mb-4 text-center p-1 pt-5">All students</h2>
            <table className="table table-dark w-50 text-center mx-auto">
                <thead>
                    <tr>
                        <th scope="col">#</th>
                        <th scope="col">Name</th>
                        <th scope="col">Age</th>
                        <th scope="col">Email</th>
                        <th scope="col">Action</th>
                    </tr>
                </thead>

                <tbody>{RenderStudents(list)}</tbody>
            </table>
        </div>
    );
};

export default Students;
