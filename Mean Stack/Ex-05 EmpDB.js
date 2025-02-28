var mysql = require('mysql');

var con = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "",
  database: "mydb"
});


function create_tb() {
  con.connect(function(err) {
    if (err) throw err;
    console.log("Connected!");
    var sql = "CREATE TABLE students (Roll_No VARCHAR(10), Marks int);";
    con.query(sql, function (err, result) {
      if (err) throw err;
      console.log("Table created");
    });
  });
}

function insert_rw(roll, marks){
  con.connect(function(err) {
    if (err) throw err;
    console.log("Connected!");
    var sql = `INSERT INTO students VALUES ('${roll}', ${marks})`;
    con.query(sql, function (err, result) {
      if (err) throw err;
      console.log("1 record inserted");
    });
  });
}

function delete_rw(roll){
  con.connect(function(err) {
    if (err) throw err;
    var sql = `DELETE FROM students WHERE Roll_No = '${roll}'`;
    con.query(sql, function (err, result) {
      if (err) throw err;
      console.log("Number of records deleted: " + result.affectedRows);
    });
  });
}


function drop_tb() {
  con.connect(function(err) {
    if (err) throw err;
    var sql = "DROP TABLE students";
    con.query(sql, function (err, result) {
      if (err) throw err;
      console.log("Table deleted");
    });
  });
}

create_tb()
// insert_rw('20021A0515',99)
// delete_rw('20021A0515')
// drop_tb();