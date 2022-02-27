#include <stdio.h>
  #include <sys/types.h>
#include <winsock2.h> //Inclui as funções do socket para windowns
  #include <stdlib.h>

int main(int argc, char *argv[]){
  // char buffer[256]; //buffer para troca de menssagens.
  char mensagem[256] = "Tenha Um Bom Dia!!!";

  //inicializa a biblioteca do scoket.  
  WSADATA wsa; 
  WSAStartup(MAKEWORD(2, 0), &wsa);

  //criar o socket servidor.
  SOCKET socketServidor;
  socketServidor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  //define o endereço do sistema final que o socket se conectara
  struct sockaddr_in enderecoServidor;
  enderecoServidor.sin_family = AF_INET;
  enderecoServidor.sin_addr.s_addr = inet_addr("25.131.154.129");
  enderecoServidor.sin_port = htons(5);

  //liga o endereço do servidor ao socket do servidor.
  if(bind(socketServidor, (SOCKADDR  *) &enderecoServidor, sizeof(enderecoServidor)) == SOCKET_ERROR){
    wprintf(L"bind failed with error %u\n", WSAGetLastError());
    printf("Erro na ligacao");
    closesocket(socketServidor);
    WSACleanup();
    return 1;
  }
  
  //espera escutando para ver se alguem quer se conectar.
  if(listen(socketServidor, 1) == SOCKET_ERROR){
    printf("Erro com o \"Listen\" ");
    closesocket(socketServidor);
    WSACleanup();
    return 1;
  }

  //aceita a conexão com um cliente e guarda as informaçõe do seu socket e endereço
  SOCKET socketCliente;
  // struct sockaddr_in enderecoCliente;
  // int csize = sizeof(enderecoCliente); //tamanho do endereço do cliente
  socketCliente = accept(socketServidor, NULL, NULL);
  if(socketCliente == INVALID_SOCKET){
    wprintf(L"accept failed with error: %ld\n", WSAGetLastError());
      closesocket(socketServidor);
      WSACleanup();
      return 1;
  } else
      wprintf(L"Client connected.\n");

  //envia mensagem ao socket do cliente.
  send(socketCliente, mensagem, sizeof(mensagem), 0);

  //fecha o socket e finaliza o programa.
  closesocket(socketServidor);
  return EXIT_SUCCESS;
  }