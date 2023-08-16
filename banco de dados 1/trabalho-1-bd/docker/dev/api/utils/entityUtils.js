const PROBLEM = 'problem';
const LANGUAGE = 'language';
const SITE = 'site';
const SITE_USER = 'site/user';

const EntityTypes = {
  PROBLEM,
  LANGUAGE,
  SITE,
  SITE_USER
};


function isValidEntity(entityType) {
  const validEntityTypes = Object.values(EntityTypes);
  return validEntityTypes.includes(entityType);
}


module.exports = { PROBLEM, LANGUAGE, SITE, SITE_USER, isValidEntity }

