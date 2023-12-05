#!/bin/bash

set -e

if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
  chown -R mysql:mysql /var/lib/mysql
  chmod -R 777 /var/lib/mysql
  mysql_install_db --datadir=/var/lib/mysql --auth-root-authentication-method=normal >/dev/null
use mysql;

mysql -u root -p"$MYSQL_ROOT_PASSWORD" <<EOSQL
CREATE DATABASE IF NOT EXISTS $WORDPRESS_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $WORDPRESS_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
FLUSH PRIVILEGES;
EOSQL
fi


exec "$@"

# set -e

# if [ ! -d "/var/lib/mysql/$MYSQL_DB" ]; then
#   mysql_install_db --datadir=/var/lib/mysql --auth-root-authentication-method=normal >/dev/null
# use mysql;

# mysql -u root -p"$MYSQL_ROOT_PASSWORD" << EOF
# CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
# CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
# GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
# FLUSH PRIVILEGES;
# EOF
# fi

# exec mysqld --datadir=/var/lib/mysql

# exec "$@"
