const dotenv = require("dotenv");
dotenv.config();
const pg = require("pg");

const dbConfig = new pg.Pool({
  user: process.env.DB_USER,
  host: process.env.DB_HOST,
  database: process.env.DB_NAME,
  password: process.env.DB_PASSWORD,
  port: process.env.DB_PORT,
});

module.exports = dbConfig;
