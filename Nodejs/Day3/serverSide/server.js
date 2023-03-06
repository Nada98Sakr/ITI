const express = require("express");
const path = require("path");
const fs = require("fs");
const app = express();
const PORT = process.env.PORT || "7001";

let welcomeHtml = fs.readFileSync("../clientSide/welcome.html").toString();


app.use(express.json());
app.use(express.urlencoded({ extended: true }));

function getPath(urPath) {
  return path.join(__dirname, urPath);
}

app.get("/index.html", (req, res) => {
  res.sendFile(getPath("../clientSide/index.html"));
});

app.post("/welcome.html", (req, res, next) => {
    let user = {
      clientName: req.body["clientName"],
      clientEmail: req.body["clientEmail"],
      clientPhone: req.body["clientPhone"],
      clientAddress: req.body["clientAddress"],
    };

    welcomeHtml = welcomeHtml.replace("{name}", user.clientName);
    welcomeHtml = welcomeHtml.replace("{phone}", user.clientPhone);
    welcomeHtml = welcomeHtml.replace("{address}", user.clientAddress);
    welcomeHtml = welcomeHtml.replace("{email}", user.clientEmail);

    let AllUsers = [];

    fs.readFile("./users.json","utf-8",(err, data) => {
        if(err) throw err;
        else{
            AllUsers = JSON.parse(data);
            AllUsers.push(user);
            fs.writeFile("./users.json",JSON.stringify(AllUsers),(err)=>{if(err) throw err;})
        }
    })
    next();
  },
  (req, res) => {
    res.send(welcomeHtml);
  }
);

app.get("/landing.jpg", (req, res) => {
  res.sendFile(getPath("../clientSide/landing.jpg"));
});

app.get("/style.css", (req, res) => {
  res.sendFile(getPath("../clientSide/style.css"));
});

app.get("/favicon.ico", (req, res) => {
  res.sendFile(getPath("../clientSide/favicon.ico"));
});

app.get("/serverSide/users.json", (req, res) => {
  res.sendFile(getPath("../serverSide/users.json"));
});

app.get("/script.js", (req, res) => {
  res.sendFile(getPath("../clientSide/script.js"));
});



app.listen(PORT, () => {
  console.log("http://localhost:" + PORT);
});
