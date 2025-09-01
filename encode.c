#include <stdio.h>

#include "encode.h"
#include "types.h"


#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

/* Function Definitions */
/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf(" [INFO]    Width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf(" [INFO]    Height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    //Source Image file
    printf(" [INFO]    Opening source image file: %s\n", encInfo->src_image_fname);
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	perror(" fopen");
    	fprintf(stderr, RED " [ERROR]   Unable to open souce file %s\n" RESET, encInfo->src_image_fname);

    	return e_failure;
    }
    printf(" [SUCCESS] Source image file opened successfully.\n");

    // Secret file
    printf(" [INFO]    Opening secret file: %s\n", encInfo->secret_fname);
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror(" fopen");
    	fprintf(stderr, RED " [ERROR]   Unable to open secret file %s\n" RESET, encInfo->secret_fname);

    	return e_failure;
    }
    printf(" [SUCCESS] Secret file opened successfully.\n");

    // Stego Image file
    printf(" [INFO]    Opening output image file: %s\n", encInfo->stego_image_fname);
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror(" fopen");
    	fprintf(stderr, RED " [ERROR]   Unable to open output file %s\n" RESET, encInfo->stego_image_fname);

    	return e_failure;
    }
    printf(" [SUCCESS] Output image file created successfully.\n");

    printf(" [SUCCESS] All files opened successfully.\n");
    // No failure return e_success
    return e_success;
}
