FROM debian:buster

RUN apt-get update -y
RUN apt-get install mariadb-server -y

EXPOSE 3306

COPY ./configure.sh /
RUN chmod +x /configure.sh

ENTRYPOINT [ "/configure.sh" ]

CMD ["mysqld"]
