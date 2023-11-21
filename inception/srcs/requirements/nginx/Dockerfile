FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx openssl

CMD ["nginx", "-g", "daemon off;"]

# Copy your configure.sh script into the container
COPY configure.sh /etc/nginx
RUN chmod +x ./nginx/configure.sh

EXPOSE 443