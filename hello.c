/*---------------------------------------------------------------------------
 * Copyright (c) 2023 Arm Limited (or its affiliates). All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *---------------------------------------------------------------------------*/

#include "cmsis_os2.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
static const char message[] = {"The quick brown fox jumps over the lazy dog."};

/*---------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/

static void app_main(void *argument) {
  (void)argument;

  for (int count = 0; count < 10; count++) {
    printf("Hello World %d\r\n", count);
    osDelay(1000U);
  }
  osDelay(osWaitForever);
}

/*---------------------------------------------------------------------------
 * Application initialization
 *---------------------------------------------------------------------------*/
void app_initialize(void) { osThreadNew(app_main, NULL, NULL); }

// void Echo_Client_Thread(void *arg) {
//   uint8_t ip[4] = {192U, 168U, 0U, 100U};
//   int32_t sock, res;
//   char dbuf[120];

//   while (1) {
//     sock = iotSocketCreate(IOT_SOCKET_AF_INET, IOT_SOCKET_SOCK_STREAM,
//                            IOT_SOCKET_IPPROTO_TCP);

//     res = iotSocketConnect(sock, (uint8_t *)ip, sizeof(ip), 7U);
//     if (res == 0) {
//       while (1) {
//         iotSocketSend(sock, message, sizeof(message));
//         res = iotSocketRecv(sock, dbuf, sizeof(dbuf));
//         if (res < 0) {
//           break; // Receive error
//         }
//         if (res > 0) {
//           if (memcmp(dbuf, message, res) != 0) {
//             break; // Message error, echoed message is not the same
//           }
//         }
//         osDelay(1000U);
//       }
//     }
//     iotSocketClose(sock);
//   }
// }
