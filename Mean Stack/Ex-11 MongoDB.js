const { MongoClient } = require("mongodb");
const url ="mongodb+srv://btechcseian:20021a05xx@cluster0.xpt8gau.mongodb.net/?retryWrites=true&w=majority";

// Database and Collection names
const dbName = 'mydatabase';
const collectionName = 'students';

// Create a new MongoClient
const client = new MongoClient(url);

async function run() {
  try {
    // Connect to the MongoDB server
    await client.connect();

    // Create a new database
    const db = client.db(dbName);
    console.log(`Connected to database: ${dbName}`);

    // Create a new collection
    const collection = db.collection(collectionName);
    console.log(`Created collection: ${collectionName}`);

    // Insert data
    const data = [
      { name: 'John', age: 20 },
      { name: 'Jane', age: 22 },
      { name: 'Alice', age: 19 },
    ];
    const insertResult = await collection.insertMany(data);
    console.log(`${insertResult.insertedCount} documents inserted`);

    // Find documents
    const findResult = await collection.find().toArray();
    console.log('All documents:');
    console.log(findResult);

    // Find one document
    const findOneResult = await collection.findOne({ name: 'John' });
    console.log('Found document:');
    console.log(findOneResult);

    // Sort documents
    const sortResult = await collection.find().sort({ age: 1 }).toArray();
    console.log('Sorted documents (ascending order by age):');
    console.log(sortResult);

    // Limit results
    const limitResult = await collection.find().limit(2).toArray();
    console.log('Limited documents:');
    console.log(limitResult);

    // Skip documents
    const skipResult = await collection.find().skip(1).toArray();
    console.log('Documents after skipping one:');
    console.log(skipResult);

    // Distinct values
    const distinctResult = await collection.distinct('name');
    console.log('Distinct names:');
    console.log(distinctResult);

    // Projection
    const projectionResult = await collection.find({}, { projection: { _id: 0, name: 1 } }).toArray();
    console.log('Projected documents (only name field):');
    console.log(projectionResult);
  } catch (error) {
    console.error('Error:', error);
  } finally {
    // Close the connection
    await client.close();
    console.log('Connection closed');
  }
}

run().catch(console.error);
