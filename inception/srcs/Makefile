all:
	docker-compose -f ./srcs/docker-compose.yml up -d --build

clean:
	docker-compose -f ./srcs/docker-compose.yml down

fclean:
	docker-compose -f ./srcs/docker-compose.yml down --rmi all
	docker volume rm -f mariadb wordpress
	rm -rf ./srcs/data/web/*
	rm -rf ./srcs/data/db/*

re: fclean all

up:
	docker-compose -f ./srcs/docker-compose.yml up -d

down:
	docker-compose -f ./srcs/docker-compose.yml down

start:
	docker-compose -f ./srcs/docker-compose.yml start

stop:
	docker-compose -f ./srcs/docker-compose.yml stop

restart:
	docker-compose -f ./srcs/docker-compose.yml restart

.PHONY: all clean fclean re up down restart