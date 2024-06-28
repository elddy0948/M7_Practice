#include "ring_buffer.h"

cbuf_handle_t circular_buf_init(uint8_t *pBuffer, size_t size)
{
    assert(pBuffer && size);

    cbuf_handle_t cbuf = malloc(sizeof(circular_buf_t));

    assert(cbuf);

    cbuf->buffer = pBuffer;
    cbuf->max = size;

    circular_buf_reset(cbuf);

    assert(circular_buf_empty(cbuf));

    return cbuf;
}

void circular_buf_free(cbuf_handle_t hcb)
{
    assert(hcb);
    free(hcb);
}

void circular_buf_reset(cbuf_handle_t hcb)
{
    assert(hcb);

    hcb->head = 0;
    hcb->tail = 0;
    hcb->full = false;
}

void circular_buf_put(cbuf_handle_t hcb, uint8_t data)
{
    assert(hcb && hcb->buffer);
    hcb->buffer[hcb->head] = data;
    advance_pointer(hcb);
}

int circular_buf_put2(cbuf_handle_t hcb, uint8_t data)
{
    int r = -1;
    assert(hcb && hcb->buffer);

    if (!circluar_buf_full(hcb)) {
        hcb->buffer[hcb->head] = data;
        advance_pointer(hcb);
        r = 0;
    }

    return r;
}

int circular_buf_get(cbuf_handle_t hcb, uint8_t *data)
{
    assert(hcb && data && hcb->buffer);

    int r = -1;

    if (!circular_buf_empty(hcb)) {
        *data = hcb->buffer[hcb->tail];
        retreat_pointer(hcb);
        r = 0;
    }

    return r;
}

bool circular_buf_empty(cbuf_handle_t hcb)
{
    assert(hcb);
    return (!hcb->full && (hcb->head == hcb->tail));
}

bool circluar_buf_full(cbuf_handle_t hcb)
{
    assert(hcb);
    return hcb->full;
}

size_t circular_buf_capacity(cbuf_handle_t hcb)
{
    assert(hcb);
    return hcb->max;
}

size_t circular_buf_size(cbuf_handle_t hcb)
{
    assert(hcb);

    size_t size = hcb->max;

    if (!hcb->full) {
        if (hcb->head >= hcb->tail) {
            size = (hcb->head - hcb->tail);
        } else {
            size = (hcb->max + hcb->head - hcb->tail);
        }
    }

    return size;
}

static void advance_pointer(cbuf_handle_t hcb)
{
    assert(hcb);

    /**
     * This is expensive logic
     * if (hcb->full)
     *  hcb->tail = (hcb->tail + 1) % hcb->max;
     */
    if (hcb->full) {
        if (++(hcb->tail) == hcb->max)
            hcb->tail = 0;
    }

    if (++(hcb->head) == hcb->max)
        hcb->head = 0;
    
    hcb->full = (hcb->head == hcb->tail);
}

static void retreat_pointer(cbuf_handle_t hcb)
{
    assert(hcb);
    hcb->full = false;
    if (++(hcb->tail) == hcb->max)
        hcb->tail = 0;
}