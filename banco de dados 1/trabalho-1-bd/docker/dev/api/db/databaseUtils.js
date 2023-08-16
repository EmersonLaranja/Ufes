const db = require('./databaseConfiguration.js');

function connectToDatabase() {
  return new Promise((resolve) => {
    db.connect((err) => {
      if (err) {
        console.error("Error connecting to database: " + err);
      } else {
        console.log("Database connected!");
        resolve();
      }
    });
  });
}

async function executeQuery(query, name = "") {
  try {
    const result = await db.query(query);
    console.log(`Query ${name} executed successfully`);
    return result;
  } catch (error) {
    console.log("Error executing query: " + error);
    throw error;
  }
}

module.exports = {
  connectToDatabase,
  executeQuery
};
