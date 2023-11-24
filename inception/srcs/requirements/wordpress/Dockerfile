FROM debian:buster

RUN apt-get update
RUN apt-get -y install php7.3 php-mysqli php-fpm wget sendmail

# Copy your configure.sh script into the container
COPY configure.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/configure.sh

# Expose the WordPress port
EXPOSE 80

# Set the entrypoint to run configure.sh script
ENTRYPOINT ["configure.sh"]
