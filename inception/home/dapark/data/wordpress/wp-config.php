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
define( 'DB_NAME', 'WORDPRESS' );

/** Database username */
define( 'DB_USER', 'dapark' );

/** Database password */
define( 'DB_PASSWORD', '4242' );

/** Database hostname */
define( 'DB_HOST', 'MARIADB' );

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
define( 'AUTH_KEY',          '*rc.+8{{EIbtu+O[`G($@K`-Q@3:iR2@AcWA6)286ni-&ZV5{RTvF@O7*)R0{+:9' );
define( 'SECURE_AUTH_KEY',   'yn%;#|#(b/II7cr;t*;$6~o>w,osK)YkQN}EIc[>rD]k(!{CJ9%xmis8vIfvT-SW' );
define( 'LOGGED_IN_KEY',     'VcN4! f0NNz;O.J@FJl{>c Dbkvscf`%{E-{W}IAIN;-pM(LwEv$b-Ax,Wda[-IS' );
define( 'NONCE_KEY',         'S}F.+M)HgeSj=gG83SB=#-^0}71694m0%M~) gp>bw96z2={)bUGy;x.;tz4Oc8/' );
define( 'AUTH_SALT',         '(a-^pxwG%Dm1mXZy?wtd~V-7|[QrACmS:Rd~C2}O:yLPWP:!M e*&^VvcJi596aT' );
define( 'SECURE_AUTH_SALT',  '/%<5f1|^P!s<DmV|DM0*mSf?.>i6x5;aq4|t]jSblHK3sRmTClcRV5^NV-%b5<]>' );
define( 'LOGGED_IN_SALT',    '4]X$>,`{jRl0S|.EqT9B:K8<-ZOlAY`~XdOLs_*:.>oJ9wtPTJA<h-ATC%AGil_|' );
define( 'NONCE_SALT',        ';8W{.<zyH^~z9,U!pd)SE[k6.pNs^-%G6kr>X-;^/^l<%SIaSvjtN}h<+@js}&F1' );
define( 'WP_CACHE_KEY_SALT', 'GwVBOsnRo3,h@6;P4HoJfIZ2Hxu)Ja9.}Z#Rq7ONWB9Y7+r _%cV9I`$#=Aa9u :' );


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
