let httpRequire = require("http");
let fs = require("fs");
fs.writeFileSync("claculator.txt","Welcome to calculator file");

httpRequire.createServer((req, res) => {
    let urlArr = req.url.split("/");
    let operator = urlArr[1];
    let numArr = [];
    let result = 0;
    if(req.url !== '/favicon.ico'){
        for(let i = 2; i < urlArr.length - 1; i++){
            numArr.push(Number(urlArr[i]));
        }
        switch(operator){
            case 'add':
                numArr.forEach(numb => {
                    result += numb
                })
                break;
                
            case 'sub':
                numArr.forEach(numb => {
                    result -= numb
                })
                break;
                
            case 'mul':
                numArr.forEach((numb) => {
                  result *= numb;
                });
                break;
                
            case 'div':
                numArr.forEach((numb) => {
                  result /= numb;
                });
                break;
        }
        res.writeHead(200);
        fs.appendFileSync(
          "claculator.txt",
          `\nThe result of ${operator} of ${numArr} = ${result}`
        );
    }
    res.end(`<p>The result of ${operator} of ${numArr} = ${result}</p>`)
})

.listen("7000",()=>{

})