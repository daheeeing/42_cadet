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

    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_certificate /etc/nginx/certs/nginx-selfsigned.crt;
    ssl_certificate_key /etc/nginx/certs/nginx-selfsigned.key;

    location ~ \.php {
        fastcgi_pass wordpress:9000;
        fastcgi_split_path_info ^(.+\.php)(.*)$;
        fastcgi_index index.php;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param PATH_INFO $fastcgi_path_info;
        include fastcgi_params;
    }
}

# Start NGINX
nginx -g "daemon off;"
