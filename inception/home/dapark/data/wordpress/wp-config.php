<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'dapark' );

/** Database password */
define( 'DB_PASSWORD', '4242' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          'FRMPI}c8+b5!g<3x}3].).b*d(v_O%60;hG>cY,|D_%={}hx <*DV&]em;!K[y9H' );
define( 'SECURE_AUTH_KEY',   'fZ<l+hi<+7>Tb;|rq&61_ox>LC;*t_nQufR{`F&i*c+CZb;`ZOr[4R-XC9~nbj,~' );
define( 'LOGGED_IN_KEY',     'u,&q(oCDie5]!=K+naCUj6;4LW/a(Ta<lj{QI G$t!m^% Hk!AAk;{{=,<>@UGL:' );
define( 'NONCE_KEY',         'T0bfGJ(L!N1.?HJ2oS3GpYK,{d/P~*(:Xe8mS7!P*F+n /d@z)??6zZ633Ud]OJ4' );
define( 'AUTH_SALT',         '_^$0+IL^t8^0fTUm(4y>JShT5AVLEIkB]^z4A8ezPdP62?}okwnrR40M>:t(x:%A' );
define( 'SECURE_AUTH_SALT',  '6nK~*A(0hah#g$Z=U,xORg~1gM ;$fsqY@<3l}W@kY^iNDY*[;{wZpYW~L%Nn;p.' );
define( 'LOGGED_IN_SALT',    'qauZx8sQL:ZCIU:eAzb$*|hT{4uZkf3v5$O,</)w)|G5}2H:Ov#dU$j7B.:BzoKC' );
define( 'NONCE_SALT',        '2gmt`,[Eq1N8XpPNTr86&.yeJ};0/zO=gvR{Bh6WqB8@>LWjb;~e$nFF2_<7Pab7' );
define( 'WP_CACHE_KEY_SALT', 'EB=nsP;L_flQSsUE50(DmNH9W[~!V][6RKcw)dP?jppk,Z^dek-<oB()G8:4?bi<' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
