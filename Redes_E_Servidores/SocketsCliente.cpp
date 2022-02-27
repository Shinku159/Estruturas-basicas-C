#include <stdio.h>
  #include <sys/types.h>
#include <winsock2.h> //Inclui as funções do socket para windowns
  #include <stdlib.h>
// #include <netdb.h>

int main(int argc, char *argv[]){
  char buffer[256]; //Buffer para a comunicação

  //inicializa a biblioteca do scoket
  WSADATA wsa; 
  WSAStartup(MAKEWORD(2, 0), &wsa);

  //cria so scoket cliente usando os protocolos AF_INET do IPv6 e SOCK_STREAM para comunicação em rede
  SOCKET socketCliente;
  socketCliente = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  //define o endereço do sistema final que o socket se conectara
  struct sockaddr_in enderecoCliente;
  enderecoCliente.sin_family = AF_INET;
  enderecoCliente.sin_addr.s_addr = inet_addr("25.131.154.129");
  enderecoCliente.sin_port = htons(135);

  //conecta o nosso socket cliente ao endereço do cliente que vai tratar
  int statusDaConexao = connect(socketCliente, (struct sockaddr *)&enderecoCliente, sizeof(enderecoCliente));

  //verifica se a conexão foi bem sucedida
  if(statusDaConexao == -1){
    printf("Erro na conexao");
  }
  //recebe menssagem do servidor e imprime
  recv(socketCliente, buffer, sizeof(buffer), 0);
  printf("The Sever Sent: %s\n", buffer);

  //encerra o socket e finaliza o programa
  closesocket(socketCliente);
  closesocket(statusDaConexao);
  return EXIT_SUCCESS;
}