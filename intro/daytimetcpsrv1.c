#include "unp.h"
#include <time.h>

int
main(int argc, char **argv) {
    int listenfd, connfd;
    char buff[MAXLINE + 1];
    struct sockaddr_in servaddr;
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(9999);

    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    for (;;) {
        connfd = Accept(listenfd, (SA *) NULL, NULL);
        printf("accept connection: %d", connfd);
        ticks = time(NULL);
        size_t len = strlen(buff);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        for (int i = 0; i < len; i++)
            Write(connfd, &buff[i], 1);
        Close(connfd);
    }
    return 0;
}