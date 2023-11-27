FROM debian:buster

RUN apt-get update -y
RUN apt-get install mariadb-server -y

COPY ./configure.sh /etc/mariadb/
RUN chmod +x /etc/mariadb/configure.sh

ENTRYPOINT [ "/etc/mariadb/configure.sh" ]
