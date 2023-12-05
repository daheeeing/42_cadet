#!/bin/bash

set -e

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/nginx_pkey.pem \
        -out /etc/ssl/certs/nginx-selfsigned.crt \
	-subj "/C=KR/L=SEOUL/O=42seoul/CN=dapark.42.fr"

exec "$@"

# set -e

# # Create a self-signed SSL certificate (for testing purposes)
# openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
#         -keyout /etc/ssl/private/nginx_pkey.pem \
#         -out /etc/ssl/certs/nginx-selfsigned.crt \
#         -subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/CN=dapark.42.fr"

# exec "$@"

#         # -keyout /etc/ssl/certs/nginx-selfsigned.key \
#         # -addext "subjectAltName=DNS:dapark.42.fr" \
#         # -batch

# # openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
# # 	-keyout $SSL_KEY -out $SSL_CERT \
# # 	-subj "/C=$CTY/L=$LOC/O=$ORG/CN=$DOMAIN_NAME"

