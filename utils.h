/*
 * @Author: Liu Yuchen
 * @Date: 2021-04-02 19:46:17
 * @LastEditors: Liu Yuchen
 * @LastEditTime: 2021-04-02 08:03:34
 * @Description: 
 * @FilePath: /C_ChatRoom/utils.h
 * @GitHub: https://github.com/liuyuchen777
 */
#ifndef CHATROOM_UTILS_H_
#define CHATROOM_UTILS_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>


//color codes
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

//Enum of different messages possible.
typedef enum
{
  CONNECT,
  DISCONNECT,
  GET_USERS,
  SET_USERNAME,
  PUBLIC_MESSAGE,
  PRIVATE_MESSAGE,
  TOO_FULL,
  USERNAME_ERROR,
  SUCCESS,
  ERROR
} message_type;


//message structure
typedef struct
{
  message_type type;
  char username[21];
  char data[256];
} message;

//structure to hold client connection information
typedef struct connection_info
{
  int socket;
  struct sockaddr_in address;
  char username[20];
} connection_info;


// Removes the trailing newline character from a string.
void trim_newline(char *text);

// discard any remaining data on stdin buffer.
void clear_stdin_buffer();

#endif
