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
define( 'AUTH_KEY',          '.%b- E!<6k^ka[[leL^nz$n]Sm$aj~~Y;F#n4/0/*`sAcEIk<JiyOgKLm~LB.,y<' );
define( 'SECURE_AUTH_KEY',   'x8O. T44bQ)7B0orre88*E{eZnn/wXyl,MP+{$nhCQ9$^U^MU1(l0Wf8[.7jK. .' );
define( 'LOGGED_IN_KEY',     '~SGue:4WB*h]s3V4E1xu,J9+T4~uC/cZQOosPw3 M=L98Gk EVWj:M3X`wpu4Tf!' );
define( 'NONCE_KEY',         'BG.~c4e>jPz|mTs@lgkiDCElyzq2TYb-<D!scg;4Ot>]6cU&u=}$J1*[wgD1JCn_' );
define( 'AUTH_SALT',         'sl4X:LdYw=VGgPTK]6HJuKHec%I/2:M~cBb_.WBNBn;IZG:z]FCdPJ-2/CLfDwBc' );
define( 'SECURE_AUTH_SALT',  'rZ< By_+~M/QZ0^|B^zj)/pxNIhEITMAo~0l(*[=ZY8y)+VT3W|g&9wK}WEVkpKC' );
define( 'LOGGED_IN_SALT',    '@acdBF[LL$T6*KKPHV9/NwM?JbL-Zka$_r0IT &Zu]((6n!]6Wn_-wkG/4x8DsEP' );
define( 'NONCE_SALT',        'B*Tn4:M5i=EH?8_! qQ$NxZGcU!c[|Ehy, dxN%}T!tYy^OFZY8EbTi~Sd9l~e,p' );
define( 'WP_CACHE_KEY_SALT', '}NGlt@Xj#]=9qZF!co4b2HsZM#~l7.{< [OIyXu[0E}iOM>!V>y4-8/liWZ5.WxV' );


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
