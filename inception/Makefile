all: 
	@mkdir -p ./home/dapark/data/wordpress
	@mkdir -p ./home/dapark/data/mariadb
	@docker-compose -f ./srcs/docker-compose.yml up

down:
	@docker-compose -f ./srcs/docker-compose.yml down

re:
	@docker-compose -f srcs/docker-compose.yml up --build

clean:
	@docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker network rm $$(docker network ls -q);\

fclean	:
			docker-compose -f ./srcs/docker-compose.yml down --rmi all
			docker volume rm -f mariadb wordpress
			@rm -rf /home/dapark/data



# all		:	
# 			@if ! grep "127\.0\.0\.1[[:space:]]dapark.42.fr" "/etc/hosts"; then \
# 				echo "127.0.0.1	dapark.42.fr" >> /etc/hosts; \
# 			fi
# 			@mkdir -p ./home/daparkm/data/mariadb
# 			@mkdir -p ./home/dapark/data/wordpress
# 			docker-compose -f ./srcs/docker-compose.yml up -d --build

# clean	:
# 			docker-compose -f ./srcs/docker-compose.yml down


# re		:	fclean all


# up		:
# 			docker-compose -f ./srcs/docker-compose.yml up -d

# down	:
# 			docker-compose -f ./srcs/docker-compose.yml down

# restart	:
# 			docker-compose -f ./srcs/docker-compose.yml restart


# .PHONY	:	all clean fclean re up down restart


