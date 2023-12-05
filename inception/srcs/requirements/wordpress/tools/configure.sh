#!/bin/bash

set -e

sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:$WORDPRESS_PORT/g" /etc/php/7.3/fpm/pool.d/www.conf
mkdir -p /run/php

if [ ! -f /var/www/html/wp-config.php ]; then
wp core download --path=/var/www/html --allow-root
wp core config --path=/var/www/html --dbname=$WORDPRESS_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$WORDPRESS_DB_HOST --allow-root
wp core install --path=/var/www/html --url=https://$DOMAIN_NAME --title=inception \
	--admin_user=$WORDPRESS_ADMIN --admin_password=$WORDPRESS_ADMIN_PASS --admin_email=$WORDPRESS_ADMIN_EMAIL --skip-email --allow-root
wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --role=subscriber --user_pass=$WORDPRESS_USER_PASS --allow-root
fi

chmod -R 755 /var/www/html
chown -R www-data:www-data /var/www/html

exec "$@"



# set -e

# curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# chmod +x wp-cli.phar
# mv wp-cli.phar /usr/local/bin/wp

# sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/g' /etc/php/7.3/fpm/pool.d/www.conf
# mkdir -p /run/php

# if [ ! -f /var/www/html/wp-config.php ]; then
# wp core download --path=/var/www/html --allow-root
# wp config create --path=/var/www/html --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOST --allow-root
# wp core install --path=/var/www/html --url=https://$DOMAIN_NAME --title=inception \
#     			--admin_user=$WORDPRESS_ADMIN --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --skip-email --allow-root
# wp user create $WORDPRESS_USER $WORDPRESS_USER_EMAIL --role=subscriber --user_pass=$WORDPRESS_USER_PASS --path=/var/www/html --allow-root
# fi


# exec "$@"
