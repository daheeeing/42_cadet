#!/bin/bash

# Create a self-signed SSL certificate (for testing purposes)
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/certs/nginx-selfsigned.key -out /etc/nginx/certs/nginx-selfsigned.crt -subj "/C=US/ST=State/L=City/O=Organization/CN=login.42.fr"

# Create DH parameters (for additional security)
openssl dhparam -out /etc/nginx/certs/dhparam.pem 2048

# NGINX configuration
server {
    listen 443 ssl http2;
    listen [::]:443 ssl http2;

    server_name dapark.42.fr;

    ssl_certificate /etc/nginx/certs/nginx-selfsigned.crt;
    ssl_certificate_key /etc/nginx/certs/nginx-selfsigned.key;

    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_prefer_server_ciphers on;
    ssl_dhparam /etc/nginx/certs/dhparam.pem;

    location / {
        # Your NGINX configuration directives here
        # For example:
        # root /var/www/html;
        # index index.html index.htm;
    }
}

# Start NGINX
nginx -g "daemon off;"
