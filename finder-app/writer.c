#include <syslog.h>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    int result = 0;
    openlog(NULL, (LOG_CONS), LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid arguments; writer {path/file} {string}");
        printf("Invalid arguments; writer {path/file} {string}\n");
        result = 1; // 1 indicates error
    }
    else {
        char * writefile = argv[1]; // destination path/file
        char * writestr  = argv[2]; // string to write
        FILE *outFile = fopen(writefile, "w");

        if( outFile ) {
            syslog(LOG_DEBUG, "Writing %s to file %s", writestr, writefile);
            fprintf(outFile, "%s", writestr);
    	    fclose(outFile);
        }
        else {
            syslog(LOG_ERR, "Failed to open : %s", writefile);
            printf("Failed to open : %s\n", writefile);
            result = 1; // 1 indicates error
        }
    }
    closelog();
    return( result );
}

