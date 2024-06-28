/**
 * - circular_buf_t
 * Opaque circular buffeer structure
 * 
 * - cbuf_handle_t
 * Handle type, the way users interact with the API
 */

#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct circular_buf_t circular_buf_t;
typedef circular_buf_t *cbuf_handle_t;

struct circular_buf_t {
    uint8_t *buffer;
    size_t head;
    size_t tail;
    size_t max;
    bool full;
};

cbuf_handle_t circular_buf_init(uint8_t *pBuffer, size_t size);

void circular_buf_free(cbuf_handle_t hcb);
void circular_buf_reset(cbuf_handle_t hcb);

void circular_buf_put(cbuf_handle_t hcb, uint8_t data);
int circular_buf_put2(cbuf_handle_t hcb, uint8_t data);
int circular_buf_get(cbuf_handle_t hcb, uint8_t *data);

bool circular_buf_empty(cbuf_handle_t hcb);
bool circluar_buf_full(cbuf_handle_t hcb);
size_t circular_buf_capacity(cbuf_handle_t hcb);
size_t circular_buf_size(cbuf_handle_t hcb);