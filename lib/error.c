#include "unp.h"
#include <stdarg.h>
#include <syslog.h>

static void err_doit(int, int, const char *, va_list);

/* Fatal error related to system call
 * Print message, dump core, and terminate */

void
err_dump(const char *fmt, ...)
{
    va_list		ap;

    va_start(ap, fmt);
    err_doit(1, LOG_ERR, fmt, ap);
    va_end(ap);
    abort();		/* dump core and terminate */
    exit(1);		/* shouldn't get here */
}

void err_sys(const char *fmt, ...)
{
    va_list a_list;

    va_start(a_list, fmt);
    err_doit(1, LOG_ERR, fmt, a_list);
    va_end(a_list);
    exit(1);
}

void err_quit(const char *fmt, ...)
{
    va_list a_list;

    va_start(a_list, fmt);
    err_doit(0, 0, fmt, a_list);
    va_end(a_list);
    exit(1);
}

void err_exit(int err, const char *fmt, ...)
{
    va_list a_list;

    va_start(a_list, fmt);
    err_doit(1, err, fmt, a_list);
    va_end(a_list);
    exit(err);

}

void
err_ret(const char *fmt, ...)
{
    va_list		ap;

    va_start(ap, fmt);
    err_doit(1, LOG_INFO, fmt, ap);
    va_end(ap);
    return;
}

static void err_doit(
                int errnoflag,
                int error,
                const char *fmt,
                va_list a_list
            )
{
    char buf[MAXLINE];
    vsnprintf(buf, MAXLINE, fmt, a_list);

    if (errnoflag)
    {
        size_t buf_len = strlen(buf);
        snprintf(buf+buf_len, MAXLINE-strlen(buf), ": %s", strerror(error));
    }

    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
}

