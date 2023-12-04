FROM debian:buster

COPY ./configure.sh /etc/nginx/

RUN apt-get update && \
    apt-get install -y nginx openssl && \
    mkdir -p /etc/ssl && \
    chmod +x /etc/nginx/configure.sh

EXPOSE 443

COPY ./default.conf /etc/nginx/conf.d/default.conf

# Copy your configure.sh script into the container
ENTRYPOINT [ "/etc/nginx/configure.sh" ]

CMD ["nginx", "-g", "daemon off;"]


# FROM debian:buster

# EXPOSE 443

# COPY ./tools/install.sh /install.sh

# RUN apt-get update && \
#     apt-get upgrade -y && \
#     apt-get install -y nginx openssl && \
#     mkdir -p /etc/ssl && \
#     chmod +x install.sh

# COPY conf/default.conf /etc/nginx/conf.d/default.conf

# ENTRYPOINT ["sh", "/install.sh"]
