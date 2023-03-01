const http = require('http');
const fs = require("fs");

let htmlFile = fs.readFileSync("../clientSide/index.html").toString();
let htmlFile2 = fs.readFileSync("../clientSide/welcome.html").toString();
let cssFile = fs.readFileSync("../clientSide/style.css").toString();
let jsFile = fs.readFileSync("../clientSide/script.js").toString();
let favIcon = fs.readFileSync("../clientSide/favicon.ico");
let image = fs.readFileSync("../clientSide/landing.jpg");

let clietName = "";
let clietPhone = "";
let clietEmail = "";
let clietAddress = ""; 

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
                res.writeHead(300,"Hii",{"content-type":"text/javascript"})
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
            clietName = data[0].split('=')[1];
            clietPhone = data[1].split("=")[1];
            clietEmail = data[2].split("=")[1];
            clietAddress = data[3].split("=")[1];
            
        })
        req.on("end", () => {
            clietAddress = clietAddress.replace(/\+/g, "\ ");
            clietEmail = clietEmail.replace(/%/g, "@");
            htmlFile2 = htmlFile2.replace("{name}", clietName)
            htmlFile2 = htmlFile2.replace("{phone}", clietPhone)
            htmlFile2 = htmlFile2.replace("{address}", clietAddress);
            htmlFile2 = htmlFile2.replace("{email}", clietEmail);
            res.write(htmlFile2);
            res.end();
        });
    }  
    //#endregion
}).listen('7000', ()=> {
    console.log("http://localhost:7000")
})