#ifndef DB_CONFIG_H
#define DB_CONFIG_H

#include <IPAddress.h>
const IPAddress DB_HOST(127, 0, 0, 1); // FIXME: Change to HOST IP
#define DB_USER "root"
#define DB_PASSWORD
#define DB_PORT 3306
#define DB_NAME 'egarden_db'

#endif // DB_CONFIG_H