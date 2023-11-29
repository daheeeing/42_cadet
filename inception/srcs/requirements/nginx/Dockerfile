FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx openssl

EXPOSE 443

COPY ./default.conf /etc/nginx/sites-available/

# Copy your configure.sh script into the container
COPY ./configure.sh /etc/nginx
RUN chmod +x /etc/nginx/configure.sh

ENTRYPOINT [ "/etc/nginx/configure.sh" ]

CMD ["nginx", "-g", "daemon off;"]
