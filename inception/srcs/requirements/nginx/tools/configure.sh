#!/bin/bash

set -e

# Create a self-signed SSL certificate (for testing purposes)
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -keyout /etc/ssl/certs/nginx-selfsigned.key \
        -out /etc/ssl/certs/nginx-selfsigned.crt \
        -subj "/C=US/ST=State/L=City/O=Organization/CN=dapark.42.fr"

# Create parameters (for additional security)
openssl dhparam -out /etc/ssl/certs/dhparam.pem 2048

exec "$@"
