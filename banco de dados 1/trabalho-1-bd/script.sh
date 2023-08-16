#!/bin/bash

if [ "$1" = "clean" ]; then
    # Parar e remover todos os containers
    sudo docker stop $(sudo docker ps -aq) || true
    sudo docker rm $(sudo docker ps -aq) || true

    # Remover todos os volumes
    sudo docker volume rm $(sudo docker volume ls -q) || true

    # Remover todas as imagens
    sudo docker rmi $(sudo docker images -q) || true
elif [ "$1" = "db" ]; then
    # Comandos específicos para o alvo 'db'
    docker compose -f docker-compose.prod.yml -f docker-compose.yml up --build
elif [ "$1" = "run" ]; then
    # Comandos específicos para o alvo 'run'
    docker compose -f docker-compose.prod.yml -f docker-compose.yml up --build
else
    echo "Argumento inválido. Use 'clean', 'db' ou 'run'."
fi
