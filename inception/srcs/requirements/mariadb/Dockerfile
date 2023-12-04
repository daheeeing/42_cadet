FROM debian:buster

RUN apt-get update -y && \
    apt-get install mariadb-server -y && \
    mkdir -p /var/run/mysqld && \
    chmod 777 /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld && \
    rm -f /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./default.cnf /etc/mysql/mariadb.conf.d/

EXPOSE 3306

COPY ./configure.sh /
RUN chmod +x /configure.sh

ENTRYPOINT [ "/configure.sh" ]

CMD ["mysqld"]
