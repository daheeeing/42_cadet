FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx openssl

CMD ["nginx", "-g", "daemon off;"]

EXPOSE 443