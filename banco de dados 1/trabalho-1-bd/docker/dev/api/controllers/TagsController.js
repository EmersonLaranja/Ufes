const Contest = require("../models/Contest.js");
const Tag = require("../models/Tag.js");
const { isValidEntity } = require("../utils/entityUtils.js");

class TagsController {

  async getTags(req, res) {
    try {
      let { contestId, entityType, entityId } = req.params;
      const { tagId, tagName, tagValue } = req.query;

      if (!entityType) {
        entityType = "site/user"
        entityId = `${req.params.siteId}/${req.params.userId}`
      }
      // Verificar se os parâmetros obrigatórios estão presentes
      if (!contestId || !entityType || !entityId) {
        return res.json({ error: 'Bad Request: Pelo menos um dos parâmetros fornecidos na requisição é inválido.' }).status(400);
      }

      // Verificar se o contest existe
      const contestInfo = await Contest.findContestById(contestId);
      const contest = contestInfo.rows[0];
      if (!contest) {
        return res.json({ error: 'Not Found: O ID da competição ou da entidade especificado na requisição não existe.' }).status(404);
      }

      // Obter as tags da entidade
      const entityTags = await Tag.getEntityTags(entityType, entityId, tagId, tagName, tagValue);
      // Formatar a resposta
      const response = {
        entityType,
        entityTag: entityTags.map(tag => ({
          entityId,
          tag: {
            id: tag.id,
            name: tag.name,
            value: tag.value
          }
        }))
      };

      res.json(response).status(200);
    } catch (error) {
      console.error(error);
      res.json(error).status(400);
    }
  }

  async createTag(req, res) {
    try {
      const { contestId } = req.params;
      const { entityTag } = req.body; // array de tags

      if (contestId == null) {
        return res.json({ error: 'Bad Request: O ID da competição ou o JSON fornecido no corpo da requisição é inválido.' }).status(400); // Resposta de erro: 400 Bad Request
      }

      const contestInfo = await Contest.findContestById(contestId)

      const contest = contestInfo.rows[0];

      if (contest == null) {
        return res.json({ error: 'Not Found: O ID da competição especificado na requisição não existe.' }).status(400);
      }

      for (const entityObject of entityTag) {
        const { entityType, entityId, tag } = entityObject;

        if (!entityId || !entityType || !tag) {
          return res.json({ error: 'Bad Request: O ID da competição ou o JSON fornecido no corpo da requisição é inválido.' }).status(400); // Resposta de erro: 400 Bad Request
        }

        // Verifica se o tipo da entidade é válido
        if (!isValidEntity(entityType)) {
          return res.json({ error: `Bad Request: ${entityType} não é válido` }).status(400); // Resposta de erro: 400 Bad Request
        }

        // Insere as tags para cada entidade
        for (const tagData of tag) {
          const { id, name, value } = tagData;

          const values = [id, name, value, entityId, entityType, contestId];
          await Tag.createTag(values);
        }
      }

      res.json({ message: "Sucess: tag(s) atualizad(s)." }).status(204); // Resposta de sucesso: 204 No Content
    }
    catch (error) {
      console.error(error);
      res.json(error).status(400); // Resposta de erro: 400 Bad Request
    }
  }


  async updateTag(req, res) {
    try {
      const { contestId } = req.params;
      const { entityTag } = req.body; // array de tags

      if (contestId == null) {
        return res.json({ error: 'Bad Request: O ID da competição ou o JSON fornecido no corpo da requisição é inválido.' }).status(400);
      }

      const contestInfo = await Contest.findContestById(contestId);
      const contest = contestInfo.rows[0];

      if (contest == null) {
        return res.json({ error: 'Not Found: O ID da competição especificado na requisição não existe.' }).status(404);
      }

      for (const entityObject of entityTag) {
        const { entityType, entityId, tag } = entityObject;

        if (!entityId || !entityType || !tag) {
          return res.json({ error: 'Bad Request: O ID da competição ou o JSON fornecido no corpo da requisição é inválido.' }).status(400);
        }

        // Verifica se o tipo da entidade é válido
        if (!isValidEntity(entityType)) {
          return res.json({ error: `Bad Request: ${entityType} não é válido` }).status(400);
        }

        // Insere as novas tags para a entidade
        for (const tagData of tag) {
          const { id, name, value } = tagData;
          await Tag.updateTag(name, value, entityType, entityId, id);
        }
      }

      res.json({ message: "Sucess: tag(s) atualizad(s)." }).status(204);
    } catch (error) {
      console.error(error);
      res.json(error).status(400);
    }
  }

  async deleteTag(req, res) {
    try {
      const { contestId } = req.params;
      const { entityTag } = req.body; // array de tags

      if (contestId == null) {
        return res.status(400).json({ error: 'Bad Request: O ID da competição ou o JSON fornecido no corpo da requisição é inválido.' }); // Resposta de erro: 400 Bad Request
      }

      for (const entityObject of entityTag) {
        const { entityType, entityId, tag } = entityObject;

        if (!entityId || !entityType || !tag) {
          return res.status(400).json({ error: 'Bad Request: O ID da competição ou o JSON fornecido no corpo da requisição é inválido.' }); // Resposta de erro: 400 Bad Request
        }

        // Verifica se o tipo da entidade é válido
        if (!isValidEntity(entityType)) {
          return res.status(400).json({ error: `Bad Request: ${entityType} não é válido` }); // Resposta de erro: 400 Bad Request
        }

        // deleta as tags para cada entidade
        for (const tagData of tag) {
          const { id, name, value } = tagData;

          const values = [id, entityId, entityType, contestId];
          await Tag.deleteTag(values);
        }
      }

      res.json({ message: "Sucess: tag(s) excluída(s)." }).status(204); // Resposta de sucesso: 204 No Content
    }
    catch (error) {
      console.error(error);
      res.json(error).status(400); // Resposta de erro: 400 Bad Request
    }

  }

}


module.exports = TagsController;
