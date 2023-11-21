FROM debian:buster

RUN apt-get update -y
RUN apt-get install mariadb-server -y

COPY configure.sh /etc/mariadb
RUN chmod +x ./mariadb/configure.sh