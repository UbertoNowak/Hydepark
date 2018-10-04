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

struct event_handler;

enum EV_TYPE{
    EV_CLICK,
    EV_CLOSE,
    EV_TYPE_MAX
};

typedef void (*callback_t)(void *user_data);

struct event_handler
{
    callback_t ptr_fun;
    void *data;
};

static struct event_handler events[EV_TYPE_MAX];

static void ev_handler_click(void*data)
{
    printf("Click window: %s\n", (char*)data);
}

static void ev_handler_close(void*data)
{
    printf("Close window: %s\n", (char*)data);
}

// we register event handler to type
void event_register(enum EV_TYPE type, callback_t cb, void *data)
{
    switch(type)
    {
    case EV_CLICK:
        events[EV_CLICK].ptr_fun = cb;
        events[EV_CLICK].data = data;
        break;
    case EV_CLOSE:
        events[EV_CLOSE].ptr_fun = cb;
        events[EV_CLOSE].data = data;
        break;
    case EV_TYPE_MAX:
        printf("Wrong type\n");
        break;
    }
}

void example_2()
{
    printf("\nEXAMPLE 2\n");

    event_register(EV_CLICK, ev_handler_click, NULL);
    event_register(EV_CLOSE, ev_handler_close, NULL);

    for(int i = 0; i< 6; ++i)
    {
        for(int x = 0; x<EV_TYPE_MAX; ++x)
        {
            if(events[x].data != NULL)
            {
                events[x].ptr_fun(events[x].data);
                events[x].data = NULL;
            }
        }

        if( i < 2)
        {
            // register event
            events[0].data = (void*)"first";
        }

        if( i > 3)
        {
            // register event
            events[1].data = (void*)"second";
        }

    }
}

int main(int argc, char** argv)
{
    example_1();
    example_2();

    return 0;
}
