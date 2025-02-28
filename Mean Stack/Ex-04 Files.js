const fs = require("fs")
const prompt = require("prompt-sync")({sigint : true})

console.log("1. Create a File");
console.log("2. Read a File");
console.log("3. Write to a File");
console.log("4. Delete a File");

var ch = Number(prompt("Enter your Choice :"))
switch(ch)
{
    case 1: 
        var name = prompt("Enter the Name of the File : ")
        fs.open(name, 'w', function (err, file) {
        if (err) throw err;
            console.log('Created');
        });
        break;
    case 2: 
        var name = prompt("Enter the Name of the File : ")
        fs.readFile(name, "utf-8",function (err, file) {
        if (err) throw err;
        console.log(file);
        });
        break;
    case 3:
        var name = prompt("Enter the Name of the File : ")
        var con = prompt("Enter the Content ")
        fs.appendFile(name, con, function (err) {
        if (err) throw err;
        console.log('Content Written');
        }); 
        break;
    case 4: 
        var name = prompt("Enter the Name of the File : ")
        fs.unlink(name, function (err) {
        if (err) throw err;
        console.log('File deleted!');
        }); 
        break;
}