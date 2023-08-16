const db = require("../db/databaseConfiguration.js");

class Contest {
  async findAll() {
    return await db.query('SELECT * FROM "contesttable";');
  }

  async findContestById(contestId) {
    return await db.query(`SELECT * FROM "contesttable" WHERE "contestnumber" = ${contestId};`);
  }

}

module.exports = new Contest();