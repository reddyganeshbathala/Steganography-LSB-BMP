#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>
#include "types.h"   // Contains e_success, e_failure, and Status enum

/* Structure to store information required for decoding */
typedef struct _DecodeInfo
{
    // Stego image info
    char *stego_image_fname;
    FILE *fptr_stego_image;

    // Output file info
    char *secret_image_fname;
    FILE *fptr_secret_image;

    // Secret file extension
    char extn_secret_file[10];
    int extn_size;

    // Secret file size
    int secret_file_size;

} DecodeInfo;

/* Check decoding operation type */
OperationType check_operation_type(char *argv[]);

/* Read and validate decode arguments */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decodeInfo);

/* Perform decoding */
Status do_decoding(DecodeInfo *decodeInfo);

/* Open files for decoding */
Status open_file(DecodeInfo *decodeInfo);

/* Decode magic string */
Status decode_magic_string(DecodeInfo *decodeInfo);

/* Skip BMP header (usually 54 bytes) */
Status skip_bmp_header(FILE *fptr_stego_image);

/* Decode secret file extension size */
Status decode_secret_file_extn_size(DecodeInfo *decodeInfo);

/* Decode secret file extension */
Status decode_secret_file_extn(char *extn, int size, DecodeInfo *decInfo);

/* Decode secret file size */
Status decode_secret_file_size(DecodeInfo *decodeInfo);

/* Decode secret file data */
Status decode_secret_file_data(DecodeInfo *decInfo);

/* Decode a byte from LSBs of image data */
char decode_byte_from_lsb(char *ch, char *image_buffer);

/* Decode an integer (32 bits) from LSBs of image data */
int decode_int_from_lsb(int *value, char *image_buffer);

#endif // DECODE_H


