#include <stdio.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include "simple.pb.h"
#include "mbed.h"

const uint16_t STRING_LENGTH = 20U;
    uint8_t buffer[20];

    size_t message_length;
    bool status;
    char testString[STRING_LENGTH];

pb_callback_t f_callbackEncode;
pb_callback_t f_callbackDecode;

static bool _decode_string(pb_istream_t *stream, const pb_field_t *field, void **arg)
{
    bool retVal;
    uint16_t length = stream->bytes_left;
    retVal = pb_read(stream, ((pb_byte_t*)testString), length);
    return retVal ;
}
static bool _encode_string(pb_ostream_t *stream, const pb_field_t *field, void * const *arg)
{
    bool retVal = true;
    do
    {
        retVal = pb_encode_tag_for_field(stream, field);
        if (retVal == false)
        {
            break;
        }
        retVal = pb_encode_string(stream, (const pb_byte_t*)testString, STRING_LENGTH);
        if (retVal == false)
        {
            break;
        }
    } while (0);
    return retVal ;
}


static bool _receive_data(void)
{
    /* Allocate space for the decoded message. */
    SimpleMessage message = SimpleMessage_init_zero;
    message.test_string = f_callbackEncode;

    /* Create a stream that reads from the buffer. */
    pb_istream_t stream = pb_istream_from_buffer(buffer, message_length);

    /* Now we are ready to decode the message. */
    status = pb_decode(&stream, SimpleMessage_fields, &message);

    /* Check for errors... */
    if (!status)
    {
        return false;
    }

    return true;
}


static bool _send_data(void)
{
    /* Allocate space on the stack to store the message data.
         *
         * Nanopb generates simple struct definitions for all the messages.
         * - check out the contents of simple.pb.h!
         * It is a good idea to always initialize your structures
         * so that you do not have garbage data from RAM in there.
         */
    SimpleMessage message = SimpleMessage_init_zero;

    /* Create a stream that will write to our buffer. */
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

    message.test_uint32 = 1;
    message.test_uint64 = 2;
    message.test_string = f_callbackDecode;

    /* Now we are ready to encode the message! */
    status = pb_encode(&stream, SimpleMessage_fields, &message);
    message_length = stream.bytes_written;

    /* Then just check for any errors.. */
    if (!status)
    {
        return false;
    }
    return true;
}

int main()
{
    while (1)
    {
        f_callbackEncode.funcs.encode = &_encode_string;
        f_callbackDecode.funcs.decode = &_decode_string;

        _send_data();
        _receive_data();

        ThisThread::sleep_for(1s);
    }

    return 0;
}
