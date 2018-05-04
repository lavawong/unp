#include "unp.h"
int Socket(int d, int type, int protocol) {
    int socket fd;
    if ( (fd = socket(d, type , protocol)) < 0) {
        err_sys("socket error\n");
    }
    return fd;
}
