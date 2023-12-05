FROM debian:buster

RUN apt-get update && \
    apt-get install -y curl php7.3 php7.3-fpm php7.3-mysql default-mysql-client

WORKDIR /var/www/html

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/configure.sh /
RUN chmod +x /configure.sh

ENTRYPOINT ["/configure.sh"]

CMD ["php-fpm7.3", "--nodaemonize"]



# FROM debian:buster

# RUN apt-get update && \
#     apt-get -y install php7.3 php-mysqli php-fpm curl default-mysql-client

# EXPOSE 9000

# WORKDIR /var/www/html

# # Copy your configure.sh script into the container
# COPY ./tools/configure.sh /
# RUN chmod +x /configure.sh

# # Set the entrypoint to run configure.sh script
# ENTRYPOINT ["/configure.sh"]

# CMD ["php-fpm7.3", "--nodaemonize"]
