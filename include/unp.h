//
// Created by lava on 18-5-4.
//

#ifndef UNP_UNP_H
#define UNP_UNP_H

#define _POSIX_C_SOURCE 200809L

#if defined(SOLARIS)        /* Solaris 10 */
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 700
#endif

#include <sys/types.h>      /* some systems still require this */
#include <sys/stat.h>
#include <sys/termios.h>    /* for winsize */
#if defined(MACOS) || !defined(TIOCGWINSZ)
#include <sys/ioctl.h>
#endif

#include <stdio.h>      /* for convenience */
#include <stdlib.h>     /* for convenience */
#include <stddef.h>     /* for offsetof */
#include <string.h>     /* for convenience */
#include <unistd.h>     /* for convenience */
#include <signal.h>     /* for SIG_ERR */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <errno.h>
/* Miscellaneous constants */
#define	MAXLINE		4096	/* max text line length */
#define	BUFFSIZE	8192	/* buffer size for reads and writes */
/* Following shortens all the typecasts of pointer arguments: */
#define	SA	struct sockaddr
/* define wrapper function which should exit when error occurred */
int Socket(int domain, int type, int protocol) __THROW;
int Bind (int fd, __CONST_SOCKADDR_ARG addr, socklen_t len);
int Connect (int fd, __CONST_SOCKADDR_ARG addr, socklen_t len);
int Accept (int fd, __SOCKADDR_ARG addr,
            socklen_t *__restrict __addr_len);

void err_dump(const char *, ...); /* {App misc_source} */
void err_msg(const char *, ...);
void err_quit(const char *, ...);
void err_exit(int, const char *, ...);
void err_ret(const char *, ...);
void err_sys(const char *, ...);

void log_msg(const char *, ...); /* {App misc_source} */
void log_open(const char *, int, int);
void log_quit(const char *, ...);
void log_ret(const char *, ...);
void log_sys(const char *, ...);

void TELL_WAIT(void); /* parent/child from {Sec race_conditions} */
void TELL_PARENT(pid_t);
void TELL_CHILD(pid_t);
void WAIT_PARENT(void);
void WAIT_CHILD(void);

void pr_exit(int);




#endif //UNP_UNP_H
