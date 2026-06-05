
#include "log.c"
#include <stdio.h>

#define APP_LOG_LEVEL LOG_TRACE

FILE *log_fn(const char *filename);

void log_feeback(log_Event *ev)
{
    char buf[16];
    buf[strftime(buf, sizeof(buf), "%H:%M:%S", ev->time)] = '\0';
    fprintf(stdout, "[%s] [%s] %-5s %s:%d: ",
            (char *)ev->udata, buf,
            log_level_string(ev->level), ev->file, ev->line);
    vfprintf(stdout, ev->fmt, ev->ap);
    fprintf(stdout, "\n");
    fflush(stdout);
}

int main(void)
{
    // set stderr out quiet
    // false : output to screen . default output
    log_set_quiet(true);

    // write to file
    log_add_fp(log_fn("app.log"), APP_LOG_LEVEL);

    // set log level
    log_set_level(APP_LOG_LEVEL);

    // load_add_feeback
    log_add_callback(log_feeback, "abc", APP_LOG_LEVEL);

    log_trace("hello world %d\n", 10);
    log_debug("hello world %d\n", 10);
    log_info("hello world %d\n", 10);
    log_warn("hello world %d\n", 10);
    log_error("hello world %d\n", 10);

    return 0;
}

FILE *log_fn(const char *filename)
{
    return fopen(filename, "a+");
}
