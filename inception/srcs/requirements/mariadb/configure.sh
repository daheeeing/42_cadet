#!/bin/bash

set -e

service mysql start

sed -i "s/bind-address/#bind-address/g" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i 's/socket\s*=\s*\/run\/mysqld\/mysqld.sock/socket = \/var\/run\/mysqld\/mysqld.sock/g' /etc/mysql/mariadb.conf.d/50-server.cnf

mysql -u root -p"$MYSQL_ROOT_PASSWORD" <<EOSQL
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
FLUSH PRIVILEGES;
EOSQL

service mysql stop

mysqld

exec "$@"
