#include "peanuts.h"

char *create_mail(char *from, char *to)
{
	char *str = BODY_1;
	
	str = ft_strjoin(str, from);
	str = ft_strjoin(str, BODY_2);
	str = ft_strjoin(str, to);
	return (str);
}

int send_mail(char *obj, char *mailer) 
{

        char cmd[100];  // to hold the command.
        char *to = mailer; // email id of the recepient.
        char *body = obj; // email body.
        char tempFile[100];     // name of tempfile.

        strcpy(tempFile,tempnam("/tmp","sendmail")); // generate temp file name.

        FILE *fp = fopen(tempFile,"w"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        sprintf(cmd,"sendmail %s < %s",to,tempFile); // prepare command.
        system(cmd);     // execute it.

        return 0;
}
