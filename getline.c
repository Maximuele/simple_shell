#include "main.h"
#define BUFFERSIZE 1024
/**
 * proces_line - handles memory allocation
 * @lineptr: double to the first char of the buffer
 * @n: pointer to the size of lin *buffer
 * @buffer: input buffer from *STREAM
 * @len: len of the input buffer
*/


void proces_line(char **lineptr, size_t *n, char *buffer, size_t len)
{
    char *new_pointer;

    if (*lineptr == NULL || *n < len)
    {
        if (len > BUFFERSIZE)
        {
            *n = 1;
        }
        else
        {
            *n = BUFFERSIZE;

        }

        new_pointer = realloc(*lineptr, *n);
        if (!new_pointer)
        {
            perror("memory realloc failed");
            free(lineptr);
            exit(1);

        }
        *lineptr = new_pointer;
    }
    string_cpy(*lineptr, buffer);
}

/**
 * _getline - reads line line from file stream
 *@lineptr: pointer to line buffer
 *@n: pointer to size of line pointer
 *@sream: File to read from
 * Return: number characters read
 */

 ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t retrival = -1;
    static int inputval;
    char *buffer2, container;

    if (inputval != 0)
        return (-1);
    fflush(stream);
    inputval = 0;
    buffer2 = malloc(sizeof(char) *BUFFERSIZE);

    if (buffer2 == NULL)
        return (-1);

    while ((container = getc(stream)) != '\n')
    {
        if (container == EOF && inputval == 0)
        {
            free (buffer2);
            return (-1);
        }
        if (inputval >= BUFFERSIZE -1 )
        {
                size_t sizenew = (*n > BUFFERSIZE) ? *g : BUFFERSIZE;
                char *newbuffer = realloc(buffer2, sizenew * 2);

                if (newbuffer == NULL)
                {
                        free(buffer2);
                        return (-1);
                }
              *n = sizenew * 2;
              buffer2 = newbuffer;
        }
        buffer2[inputval] = container;
        inputval++;
    }
    buffer2[inputval] = '\0';
    process_line(lineptr, n, buffer2, inputval);
    retrival = inputval;
    free(buffer2);
    return (retrival);
}