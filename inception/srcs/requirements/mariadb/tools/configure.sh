#!/bin/bash

set -e

if [ ! -d "/var/lib/mysql/$MYSQL_DB" ]; then
  mysql_install_db --datadir=/var/lib/mysql --auth-root-authentication-method=normal >/dev/null
  mysqld --bootstrap << EOF
use mysql;

flush privileges;

mysql -u root -p"$MYSQL_ROOT_PASSWORD"
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
FLUSH PRIVILEGES;

flush privileges;
EOF
fi

exec mysqld --datadir=/var/lib/mysql

exec "$@"
