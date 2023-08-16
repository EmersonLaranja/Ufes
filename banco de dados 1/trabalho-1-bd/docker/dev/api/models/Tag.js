const db = require("../db/databaseConfiguration.js");

class Tag {
  async findAll() {
    return await db.query('SELECT * FROM "tagtable";');
  }

  async createTag(params) {
    return await db.query(`
      INSERT INTO tagtable (tagid,name,value,entityid,entitytype,contestid)
      VALUES ($1, $2, $3, $4, $5, $6)
    `, params);
  }

  async getEntityTags(entityType, entityId, tagId, tagName, tagValue) {
    let query = 'SELECT * FROM tagtable WHERE entitytype = $1 AND entityid = $2';
    let queryParams = [entityType, entityId];
    let paramCount = 2;

    // Verifica se o parâmetro tagId está presente
    if (tagId) {
      paramCount++;
      query += ' AND tagid = $' + paramCount;
      // query+=` AND tagid = $${paramCount}`
      queryParams.push(tagId);
    }

    // Verifica se o parâmetro tagName está presente
    if (tagName) {
      paramCount++;
      query += ' AND name = $' + paramCount;
      queryParams.push(tagName);
    }

    // Verifica se o parâmetro tagValue está presente
    if (tagValue) {
      paramCount++;
      query += ' AND value = $' + paramCount;
      queryParams.push(tagValue);
    }

    const result = await db.query(query, queryParams);
    return result.rows;
  }

  async updateTag(name, value, entity_type, entity_id, id) {
    const query = `
    UPDATE tagtable
    SET name = $1, value = $2
    WHERE entitytype = $3 AND entityid = $4 AND tagid = $5
  `;

    const values = [name, value, entity_type, entity_id, id];

    return await db.query(query, values);
  }

  async deleteTag(params) {
    return await db.query(`
      DELETE FROM tagtable WHERE tagid = $1 AND entityid = $2 AND entitytype = $3 AND contestid = $4
    `, params);
  }


}

module.exports = new Tag();
