#include <string.h>
#include "unp.h"
/* China time server 210.72.145.8 */
int
main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 2) {
        err_sys("usage: a.out <IPaddress>\n");
        return 1;
    }

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        err_sys("socket error\n");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        err_quit("inet_pton error for %s\n", argv[1]);
    }

    if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0 ) {
        err_sys("connect error\n");
    }

    while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF) {
            err_sys("fputs error\n");
        }
    }

    if (n < 0) {
        err_sys("read error\n");
    }

    exit(0);
}