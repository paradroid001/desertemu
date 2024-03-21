#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 32
#define PWDLEN 10

typedef struct {
  char buf[BUFLEN];
  char pwd[PWDLEN];
} PASS_DATA;

static PASS_DATA data;

/* Mock function to generate a password,
     optimally we would use the seed
*/
void gen_pwd(char seed[BUFLEN], char output[PWDLEN]) {
  // Generate
  for (int i = 0; i < PWDLEN - 1; i++) {
    output[i] = 'A' + (random() % 26);
  }
  // null terminate
  output[PWDLEN - 1] = '\0';
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("No action taken.\n");
  } else {
    // Copy the input into the buffer
    strcpy(data.buf, argv[1]);
    // Generate a password
    gen_pwd(data.buf, data.pwd);
    printf("Generated password with following seed: %s\n", data.buf);
  }
  return 0;
}
