#include <thread>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;

void abrirArchivo(int argc, char *argv[])
{
    FILE *fp = fopen( argv[1], "r");
    char line[12];

    if (fp == NULL)
    {
        cout << ("No se ha podido abrir el archivo\n");
        exit(1);
    }
    while (fgets(line , 12 , fp) != NULL)
    {

        cout << ("%s",line);

    }
   fclose(fp) ;
 }

void enviar_ping( int ping_sockfd, struct sockaddr_in *ping_addr, char *ping_dom, char *ping_ip,
                char *rev_host)
{}

int main(int argc, char *argv[]) {
  thread threads[argc - 1];
  int i = 0;


  for (i=0; i < argc - 1; i++) {
    threads[i] = thread(abrirArchivo, argv[i+1]);
  }


  for (i=0; i< argc - 1; i++) {
    threads[i].join();
  }

  return 0;
}
