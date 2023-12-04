FROM debian:buster

RUN apt-get update && \
    apt-get -y install php7.3 php-mysqli php-fpm curl default-mysql-client

EXPOSE 9000

WORKDIR /var/www/html

# Copy your configure.sh script into the container
COPY configure.sh /
RUN chmod +x /configure.sh

# COPY ./www.conf /etc/php/7.3/fpm/pool.d/www.conf

# Set the entrypoint to run configure.sh script
ENTRYPOINT ["/configure.sh"]

CMD ["php-fpm7.3", "--nodaemonize"]
