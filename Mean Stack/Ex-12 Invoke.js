const { MongoClient } = require("mongodb");

async function run() {
  const uri ="mongodb+srv://Sai_Vijay:2005@my-cluster.0uuox.mongodb.net/mybase?retryWrites=true&w=majority";
  const client = new MongoClient(uri);
  await client.connect();
  
  const database = client.db("mybase");
  const collection = database.collection("Class");

  try {
    const cursor = await collection.find({});
    await cursor.forEach(st => {
      console.log(`${st.Roll_No} ${st.Student_Name} `);
    });
    console.log();
  } catch (err) {
    console.error(`Something went wrong trying to find the documents: ${err}\n`);
  }
  await client.close();
}
run().catch(console.dir);
