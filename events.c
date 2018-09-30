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

struct event_cb;

typedef void (*event_cb_t)(const struct event_cb *evt, void *user_data);

struct event_cb
{
    event_cb_t cb;
    void *data;
};

static struct event_cb saved = { 0, 0 };

void event_cb_register(event_cb_t cb, void *user_data)
{
    saved.cb = cb;
    saved.data = user_data;
}

static void my_event_cb(const struct event_cb *evt, void *data)
{
    printf("in %s\n", __func__);
    printf("data1: %s\n", (const char *)data);
    printf("data2: %s\n", (const char *)evt->data);
}

void example_2()
{
    printf("\nEXAMPLE 2\n");

    char* ptr = "Hello!";
    char* start = "start data";
    event_cb_register(my_event_cb, start);
    for(int i = 0; i< 3; ++i)
    {
        printf("%i: ", i);
        saved.cb(&saved, saved.data);
        if(i == 1) event_cb_register(my_event_cb, ptr);
    }
}

int main(int argc, char** argv)
{
    example_1();
    example_2();

    return 0;
}
