
#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <iostream>
#include <queue>
#include <functional>
#include <inttypes.h>

class preprocessor
{
public:
    typedef std::function<char()> reader_t;

    preprocessor(reader_t reader);

    char next();
    char process(char c);

protected:
    // false by default, true if preprocessing of characters is blocked for some reason.
    // for example, if in a string or a comment the characters will not be processed.
    enum block_t
    {
        UNBLOCKED = 0,
        STRING,
        SL_COMMENT,
        ML_COMMENT
    };

    block_t m_block_status = UNBLOCKED;

    char handle_block(char c);

    std::queue<char> m_in_queue;
    std::queue<char> m_out_queue;

    // Function that reads raw characters.
    reader_t m_reader;

    char next_char();
};

#endif // PREPROCESSOR_H