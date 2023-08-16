FROM node:19

WORKDIR /usr/src/app

COPY docker/dev/api/package*.json ./

RUN npm install

COPY docker/dev/api/ .

EXPOSE 3000

#O comando eu coloco no docker-compose.yml
# CMD [ "npm", "run","dev" ]