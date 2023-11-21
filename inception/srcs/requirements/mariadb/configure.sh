#!/bin/bash

# Initialize MariaDB data directory if it's not initialized
if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --ldata=/var/lib/mysql

    # Start MariaDB
    mysqld_safe --datadir='/var/lib/mysql' &

    # Wait for MariaDB to start
    sleep 5

    # Secure MariaDB installation (set root password, remove anonymous users, etc.)
    mysql_secure_installation <<EOF

    y                   # Remove anonymous users
    y                   # Disallow root login remotely
    y                   # Remove test database and access to it
    y                   # Reload privilege tables now
    EOF

    # Stop MariaDB
    mysqladmin -uroot -p shutdown
fi

# Start MariaDB
mysqld_safe --datadir='/var/lib/mysql'