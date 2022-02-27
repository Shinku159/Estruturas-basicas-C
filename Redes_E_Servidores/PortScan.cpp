#include <stdio.h>
  #include <sys/types.h>
#include <winsock2.h> //Inclui as funções do socket para windowns
  #include <stdlib.h>
// #include <netdb.h>

int main(int argc, char *argv[]){
  //inicializa a biblioteca do scoket
  WSADATA wsa; 
  WSAStartup(MAKEWORD(2, 0), &wsa);

  //cria so scoket cliente usando os protocolos AF_INET do IPv6 e SOCK_STREAM para comunicação em rede
  SOCKET socketCliente;
  SOCKET socketServidor;
  for(int i = 1; i < 65535; i++){
  socketCliente = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  socketServidor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  //define o endereço do sistema final que o socket se conectara
  struct sockaddr_in enderecoCliente;
  enderecoCliente.sin_family = AF_INET;
  enderecoCliente.sin_addr.s_addr = inet_addr("25.131.154.129");
  enderecoCliente.sin_port = htons(i);

  int statusDaConexao = 0;
  int statusDaConexao2 = 0;
  //conecta o nosso socket cliente ao endereço do cliente que vai tratar
  statusDaConexao = bind(socketServidor, (struct sockaddr *)&enderecoCliente, sizeof(enderecoCliente));
  statusDaConexao2 = connect(socketCliente, (struct sockaddr *)&enderecoCliente, sizeof(enderecoCliente));

  //verifica se a conexão foi bem sucedida
  if(statusDaConexao != SOCKET_ERROR){
    printf("Porta %d - STATUS [ABERTA]\n", i);
  }
  //encerra o socket e finaliza o programa
  closesocket(socketCliente);
  closesocket(socketServidor);
  closesocket(statusDaConexao2);
  }
  return EXIT_SUCCESS;
}