const express = require("express");
const router = express.Router();

const TagsController = require("../controllers/TagsController.js");
const tagsController = new TagsController();


router.post("/api/contest/:contestId/tags", tagsController.createTag);
router.put("/api/contest/:contestId/tags", tagsController.updateTag);
router.delete("/api/contest/:contestId/tags", tagsController.deleteTag);
router.get("/api/contest/:contestId/tags/site/user/:siteId/:userId/:tagId?/:tagName?/:tagValue?", tagsController.getTags);
router.get("/api/contest/:contestId/tags/:entityType/:entityId/:tagId?/:tagName?/:tagValue?", tagsController.getTags);



module.exports = router;