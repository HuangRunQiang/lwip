/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Simon Goldschmidt
 *
 */
#ifndef LWIP_HDR_LWIPOPTS_H__
#define LWIP_HDR_LWIPOPTS_H__

/* 防止链接 sys_arch.c（我们在单元测试中不测试 API 层） */
#define NO_SYS                          1 // 设置为1表示不使用系统架构层，简化测试环境

#define LWIP_NETCONN                    0 // 禁用 lwIP 网络连接 API。如果设置为1，则启用 lwIP 的 netconn API
#define LWIP_SOCKET                     0 // 禁用 lwIP 套接字 API。如果设置为1，则启用 lwIP 的 socket API
#define SYS_LIGHTWEIGHT_PROT            0 // 禁用轻量级保护，适用于不需要线程保护的情况

#define LWIP_IPV6                       1 // 启用 IPv6 支持
#define IPV6_FRAG_COPYHEADER            1 // 启用 IPv6 分片时复制头部
#define LWIP_IPV6_DUP_DETECT_ATTEMPTS   0 // 设置 IPv6 重复检测尝试次数为0

/* 启用一些协议以进行测试 */
#define LWIP_DHCP                       1 // 启用 DHCP 协议，以便自动获取 IP 地址
#define LWIP_AUTOIP                     1 // 启用 AutoIP 协议，以便在没有 DHCP 服务器时自动配置 IP 地址

#define LWIP_IGMP                       1 // 启用 IGMP 协议，用于组播管理
#define LWIP_DNS                        1 // 启用 DNS 协议，以便进行域名解析

#define LWIP_ALTCP                      1 // 启用高级 TCP，提供更复杂的 TCP 功能

/* 关闭模糊数据的校验和验证 */
#define CHECKSUM_CHECK_IP               0 // 禁用 IP 校验和检查
#define CHECKSUM_CHECK_UDP              0 // 禁用 UDP 校验和检查
#define CHECKSUM_CHECK_TCP              0 // 禁用 TCP 校验和检查
#define CHECKSUM_CHECK_ICMP             0 // 禁用 ICMP 校验和检查
#define CHECKSUM_CHECK_ICMP6            0 // 禁用 ICMPv6 校验和检查

/* tcp 单元测试所需的 opt.h 的最小更改： */
#define MEM_SIZE                        16000 // 设置内存池大小为16KB
#define TCP_SND_QUEUELEN                40 // 设置 TCP 发送队列长度为40
#define MEMP_NUM_TCP_SEG                TCP_SND_QUEUELEN // 设置 TCP 段的内存池数量为发送队列长度
#define TCP_OVERSIZE                    1 // 启用 TCP 段的超大尺寸支持
#define TCP_SND_BUF                     (12 * TCP_MSS) // 设置 TCP 发送缓冲区为12倍的最大报文段大小
#define TCP_WND                         (10 * TCP_MSS) // 设置 TCP 窗口大小为10倍的最大报文段大小
#define LWIP_WND_SCALE                  1 // 启用 TCP 窗口缩放
#define TCP_RCV_SCALE                   2 // 设置 TCP 接收窗口缩放因子为2
#define PBUF_POOL_SIZE                  400 // 设置 pbuf 池的大小，约需要200KB内存

/* etharp 单元测试所需的 opt.h 的最小更改： */
#define ETHARP_SUPPORT_STATIC_ENTRIES   1 // 启用以太网ARP的静态条目支持

#define LWIP_NUM_NETIF_CLIENT_DATA      1 // 设置网络接口的客户端数据数量为1
#define LWIP_SNMP                       1 // 启用 SNMP 协议支持
#define MIB2_STATS                      1 // 启用 MIB2 统计信息
#define LWIP_MDNS_RESPONDER             1 // 启用 mDNS 响应功能

#endif /* LWIP_HDR_LWIPOPTS_H__ */

