let userBtn = document.querySelector(".showUser");
let dataTable = document.querySelector(".usersTable");
let userArray = [];

userBtn.addEventListener("click", () => {
    document.querySelector("#FormSubmit").style.display = "none";
    dataTable.style.display = "block";

    fetch("../serverSide/users.json")
    .then((res) => {
        console.log(res.json);
        return res.json();
    })
    .then((data) => {
        console.log(data.users)
        data.users.forEach(user => {
            dataTable.insertAdjacentHTML(
                "beforeend",
                `<tr>
                    <td>${user.clientName}</td>
                    <td>${user.clientEmail}</td>
                    <td>${user.clientPhone}</td>
                    <td>${user.clientAddress}</td>
                </tr>`
            );
        });
    })

})