const http = require('http');
const fs = require("fs");

let htmlFile = fs.readFileSync("../clientSide/index.html").toString();
let htmlFile2 = fs.readFileSync("../clientSide/welcome.html").toString();
let cssFile = fs.readFileSync("../clientSide/style.css").toString();
let jsFile = fs.readFileSync("../clientSide/script.js").toString();
let jsonFile = fs.readFileSync("./users.json").toString();
let favIcon = fs.readFileSync("../clientSide/favicon.ico");
let image = fs.readFileSync("../clientSide/landing.jpg");

let clientName = "";
let clientPhone = "";
let clientEmail = "";
let clientAddress = ""; 

http.createServer((req, res) => {
    //#region GET
    if (req.method == "GET") {
        switch (req.url) {
            case "/index.html":
                res.setHeader("Access-Control-Allow-Origin", "*");
                res.write(htmlFile)
                break;

            case "/style.css":
                res.writeHead(200, "Ok", { "content-type": "text/css" });
                res.write(cssFile);
                break;
            
            case "/script.js":
                res.writeHead(200,"ok",{"content-type":"text/javascript"})
                res.write(jsFile);
                break;
        
            case "/favicon.ico":
                res.writeHead(200,"ok",{"content-type":"image/vnd.microsoft.icon"})
                res.write(favIcon)
                break;
        
            case "/landing.jpg":
                res.writeHead(200,"ok",{"content-type":"image/jpeg"})
                res.write(image)
                break;

            case "/welcome.html":
                res.setHeader("Access-Control-Allow-Origin","*")
                res.write(htmlFile2);
                break;

            case "/serverSide/users.json":
                res.writeHead(200, "ok",{"content-type":"application/json"})
                res.write(jsonFile);
                break;

            default:
                res.write("<h1>No Page Found</h1>");
                break;
        }
        res.end();
    }
    //#endregion
    //#region POST
    else if (req.method == "POST") {
        
        req.on("data", (data) => {
            data = data.toString().split("&");
            clientName = data[0].split('=')[1];
            clientPhone = data[1].split("=")[1];
            clientEmail = data[2].split("=")[1];
            clientAddress = data[3].split("=")[1];
            clientAddress = clientAddress.replace(/\+/g, " ");
            clientEmail = clientEmail.replace(/%/g, "@");
            let user = {
                clientName,
                clientEmail,
                clientPhone,
                clientAddress
            };

            let AllUsers;
            fs.readFile("./users.json","utf-8",(err, data) => {
                if(err) throw err;
                else{
                    AllUsers = JSON.parse(data);
                    AllUsers.users.push(user);
                    fs.writeFile("./users.json",JSON.stringify(AllUsers),(err)=>{if(err) throw err;})
                }
            })
        })
        req.on("end", () => {
            htmlFile2 = htmlFile2.replace("{name}", clientName)
            htmlFile2 = htmlFile2.replace("{phone}", clientPhone)
            htmlFile2 = htmlFile2.replace("{address}", clientAddress);
            htmlFile2 = htmlFile2.replace("{email}", clientEmail);
            
            res.write(htmlFile2);
            res.end();
        });
    }  
    //#endregion
}).listen('7001', ()=> {
    console.log("http://localhost:7001")
})