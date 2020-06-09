#include "event.h"

#include <malloc.h>
#include <string.h>

extern void answerEvent(uint64_t id);

static event_handler_t event_handler;

void set_event_handler(event_handler_t handler) {
    event_handler = handler;
}

void send_event(event_t *event, const void *payload, size_t payload_length) {
    event_handler_t h = event_handler;
    if ( h != NULL ) {
        memcpy(event->payload, payload, payload_length);
        h(event);
    }
    else {
        answer_event(event->id);
        free(event);
    }
}

void answer_event(uint64_t id) {
    answerEvent(id);
}