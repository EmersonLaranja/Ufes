const express = require('express');
const { connectToDatabase, executeQuery } = require('./db/databaseUtils.js');
const { createTagTableQuery } = require('./db/queries/M1_create_tagtable.js');
const routes = require('./routes/routes.js');
const swaggerUi = require('swagger-ui-express');
const swaggerDocument = require('./docs/swagger.json'); // Arquivo Swagger gerado

async function startServer() {
  // Constants
  const PORT = 3000;
  const HOST = '0.0.0.0';

  // App
  const app = express();
  app.use(express.json())
  app.use(routes)
  app.use('/docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument));

  app.listen(PORT, HOST, () => {
    console.log(`Server running on http://${HOST}:${PORT}`);
  });

  // Connect to database
  await connectToDatabase();

  // Create table Tag
  try {
    await executeQuery(createTagTableQuery, "Tag");
    console.log("Tag table created successfully")
  } catch (error) {
    console.error("Error creating Tag table: " + error);
  }
}

startServer();