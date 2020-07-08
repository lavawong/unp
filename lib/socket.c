#include "unp.h"

int Socket(int family, int type, int protocol) {
    int fd;
    if ((fd = socket(family, type, protocol)) < 0) {
        err_sys("socket error");
    }
    
    return fd;
}

void Bind(int fd, const struct sockaddr *addr, socklen_t len) {
    if (bind(fd, addr, len) < 0) {
        err_sys("bind error");
    }
}

void Listen(int fd, int port) {
    if (listen(fd, port) < 0) {
        err_sys("listen error");
    }
}

void Connect(int fd, const struct sockaddr *addr, socklen_t len) {
    if (connect(fd, addr, len) < 0) {
        err_sys("connect error");
    }
}

int Accept(int listenfd, const struct sockaddr *addr,
           socklen_t *__restrict addr_len) {
    int connfd;
    again:
    if ((connfd = accept(listenfd, addr, addr_len)) < 0) {
#ifdef    EPROTO
        if (errno == EPROTO || errno == ECONNABORTED)
#else
        if (errno == ECONNABORTED)
#endif
            goto again;
        else
            err_sys("accept error");
    }
    return connfd;
}

void Close(int fd) {
    if (fd != -1) {
        close(fd);
    }
}

ssize_t Write(int fd, const void *buff, size_t nbyte) {
    ssize_t ret;
    if ( (ret = write(fd, buff, nbyte)) < 0) {
        err_sys("write error");
    }
    return ret;
}