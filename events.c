#include <stdio.h>

/* Callback is pointer to function, which we can pass to
 * another function as a parameter
 * */

typedef int (*callback)(int, int);

int sum(int a, int b)
{
    return a+b;
}

int diff(int a, int b)
{
    return  a-b;
}

int operation(callback fun, int a, int b)
{
    return fun(a,b);
}

void example_1()
{
    printf("\nEXAMPLE 1\n");

    int x = 4, y = 1;
    printf("x + y = %i\n", operation(sum, x, y));
    printf("x - y = %i\n", operation(diff, x, y));
}

/* Event handler is a callback which is related to event
 * */

struct event;

typedef void (*callback_t)(const struct event *evt, void *user_data);

struct event
{
    callback_t ptr_fun;
    void *data;
};

void event_register(struct event *evt, callback_t cb, void *data)
{
    evt->ptr_fun = cb;
    evt->data = (const char*) data;
}

static void my_event_handler(const struct event *evt, void *data)
{
    printf("in %s\n", __func__);
    printf("data: %s\n", (const char *)data);
    printf("evt->data: %s\n", (const char *)evt->data);
}

void emit_event(const struct event *evt, const char *str)
{
    printf("Emit signal\n");
    evt->ptr_fun(evt, str);
}

void example_2()
{
    printf("\nEXAMPLE 2\n");

    struct event my_evt;
    const char *str = "Hello World!";

    event_register(&my_evt, my_event_handler, str);

    for(int i = 0; i< 3; ++i)
    {
        if(i == 1) emit_event(&my_evt, str);
    }
}

int main(int argc, char** argv)
{
    example_1();
    example_2();

    return 0;
}
